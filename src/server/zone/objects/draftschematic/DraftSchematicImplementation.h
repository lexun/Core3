/*
Copyright (C) 2007 <SWGEmu>
 
This File is part of Core3.
 
This program is free software; you can redistribute 
it and/or modify it under the terms of the GNU Lesser 
General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU Lesser General Public License for
more details.
 
You should have received a copy of the GNU Lesser General 
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
Linking Engine3 statically or dynamically with other modules 
is making a combined work based on Engine3. 
Thus, the terms and conditions of the GNU Lesser General Public License 
cover the whole combination.
 
In addition, as a special exception, the copyright holders of Engine3 
give you permission to combine Engine3 program with free software 
programs or libraries that are released under the GNU LGPL and with 
code included in the standard release of Core3 under the GNU LGPL 
license (or modified versions of such code, with unchanged license). 
You may copy and distribute such a system following the terms of the 
GNU LGPL for Engine3 and the licenses of the other code concerned, 
provided that you include the source code of that other code when 
and as the GNU LGPL requires distribution of source code.
 
Note that people who make modified versions of Engine3 are not obligated 
to grant this special exception for their modified versions; 
it is their choice whether to do so. The GNU Lesser General Public License 
gives permission to release a modified version without this exception; 
this exception also makes it possible to release a modified version 
which carries forward this exception.
*/

#ifndef DRAFTSCHEMATICIMPLEMENTATION_H_
#define DRAFTSCHEMATICIMPLEMENTATION_H_

#include "engine/engine.h"

#include "../../packets.h"

#include "DraftSchematic.h" 
#include "DraftSchematicImplementation.h"

#include "DraftSchematicIngredient.h"
#include "DraftSchematicIngredientImplementation.h"

#include "DraftSchematicExpPropGroup.h"
#include "DraftSchematicExpPropGroupImplementation.h"

class Player;


class DraftSchematicImplementation : public DraftSchematicServant {
	// example: 0x838FF623
	uint32 schematicID;
	
	// example: 0x838FF623
	uint32 schematicCRC; 
	
	// example: Bofa Treat
	string objName; 
	// example: craftArtisanNewbieGroupA
	string groupName;
	
	// example: 3
	uint32 complexity;
	// example: 1
	uint32 schematicSize;
	
	// The number that tells the client which crafting tool tab to put the DS in
	/*
	 * BITMASK FOR TABS
	 * 0 = unknown													0000
	 * 1 = weapons													0001
	 * 2 = armor													0010
	 * 4 = food														0100
	 * 8 = clothing													1000
	 * 16 = vehicle											   0001 0000
	 * 32 =	droid											   0010 0000
	 * 64 = chemical										   0100 0000
	 * 128 = tissues									  	   1000 0000
	 * 256 = creatures									  0001 0000 0000
	 * 512 = furniture									  0010 0000 0000
	 * 1024 = installation								  0100 0000 0000
	 * 2048 = lightsaber							 	  1000 0000 0000
	 * 4096 = generic item							 0001 0000 0000 0000
	 * 8192 = genetics								 0010 0000 0000 0000
	 * 16384 = talior, Mandalorian					 0100 0000 0000 0000
	 * 32768 = armorsmith, Mandalorian				 1000 0000 0000 0000
	 * 65536 = Droid Engineer, Mandalorian		0001 0000 0000 0000 0000
	 * 131072 = Starship Components				0010 0000 0000 0000 0000
	 * 262144 = Ship Tools						0100 0000 0000 0000 0000
	 * 524288 = Misc							1000 0000 0000 0000 0000				
	 * * */
	int craftingToolTab;
	
	// For when it becomes and object during crafting
	uint64 objectID;
	
	// Ingredient List
	Vector<DraftSchematicIngredient*> dsIngredients;
	
	// Experimental Property List With Padding
	Vector<DraftSchematicExpPropGroup*> dsExpPropGroups;

	Vector<string> expPropTitleList;
	
	// Tano Attributes
	string tanoAttributes;
	
	bool persistent;
	
public:
	DraftSchematicImplementation(uint32 schematicID, const string& objName, uint32 objCRC, const string& groupName, 
			uint32 complexity, uint32 schematicSize, int craftingToolTab) :	DraftSchematicServant() {
		this->schematicID = schematicID;
		this->objName = objName;
		this->schematicCRC = objCRC;
		this->groupName = groupName;
		this->complexity = complexity; 
		this->schematicSize = schematicSize; 
		this->craftingToolTab = craftingToolTab;
		
		persistent = false;
	}
	
	DraftSchematicImplementation(DraftSchematic* ds) :	DraftSchematicServant() {
		DraftSchematicImplementation* dsImp = (DraftSchematicImplementation*) ds->_getImplementation();	
		this->schematicID = dsImp->schematicID;
		this->objName = dsImp->objName;
		this->schematicCRC = dsImp->schematicCRC;
		this->groupName = dsImp->groupName;
		this->complexity = dsImp->complexity;
		this->schematicSize = dsImp->schematicSize;
		this->craftingToolTab = dsImp->craftingToolTab;
		
		persistent = dsImp->persistent;
 
		dsImp->dsIngredients.clone(this->dsIngredients);
		dsImp->dsExpPropGroups.clone(this->dsExpPropGroups);
		dsImp->expPropTitleList.clone(this->expPropTitleList);
		this->tanoAttributes = dsImp->tanoAttributes;
	}
 
	DraftSchematic* dsClone(DraftSchematic* ds) { 
		if(ds != NULL) {
			DraftSchematicImplementation* dsImpl = new DraftSchematicImplementation(ds);
			DraftSchematic* newDS = (DraftSchematic*) dsImpl->deploy();
			return newDS;
		} else {
			return NULL;
		}
	}
	
	DraftSchematic* deploy() {
		return (DraftSchematic*) DistributedObjectServant::deploy();
	}
	
	int getIngredientListSize() {
		return dsIngredients.size();
	}
	
	DraftSchematicIngredient* getIngredient(int index) {
		return dsIngredients.get(index);
	}
	
	int getExpPropGroupListSize() {
		return dsExpPropGroups.size();
	}
	
	DraftSchematicExpPropGroup* getExpPropGroup(int index) {
		return dsExpPropGroups.get(index);
	}
	
	// Ingredient Methods
	void addIngredient(const string& ingredientTemplateName, const string& ingredientTitleName,
			bool optional, const string& resourceType, uint32 resourceQuantity) {
		DraftSchematicIngredientImplementation* dsiImp = new DraftSchematicIngredientImplementation(ingredientTemplateName, 
				ingredientTitleName, optional, resourceType, resourceQuantity);
	
		DraftSchematicIngredient* dsi = (DraftSchematicIngredient*) dsiImp->deploy();
		
		dsIngredients.add(dsi);
	}
	
	// THERE IS A BUG WHEN YOU LEAVE YOUR DATAPAD UP AND SURRENDER A SKILL, THE DRAFT SCHEMATICS
	// STILL ARE IN YOUR DATAPAD, SO IF YOU CLICK THEM, IT WILL SAY SCHEMATIC NOT FOUND AND WILL
	// SCREW UP THE CLIENT TRYING TO GET THE INGREDIENTS AND EXP PROPS FROM THERE ON UNTIL THE CLIENT
	// FULLY EXITS THE GAME
	void sendIngredientsToPlayer(Player* player) {
		ObjectControllerMessage* msg = new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x01BF);
		
		msg->insertInt(schematicID);  	// ex: 0x838FF623838FF623 (objID is always the crc value in the upper 4 bytes and the lower 4 bytes)
		msg->insertInt(schematicCRC);
		msg->insertInt(complexity);  // ex: 3
		msg->insertInt(schematicSize); // ex: 1
		msg->insertByte(1);
		
		helperSendIngredientsToPlayer(msg);
		
		player->sendMessage(msg);
	}
	
	inline void helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg) {
		int listSize = dsIngredients.size();
		objMsg->insertInt(listSize);
		
		// Send all the ingredient data
		for(int i = 0; i < listSize; i++) {
			DraftSchematicIngredient* dsi = dsIngredients.get(i);
			dsi->helperSendToPlayer(objMsg);
		}
		
		/* for debugging
		stringstream ss;
		ss << msg->toString();
		player->info(ss.str());*/
		
		objMsg->insertShort(0);
	}
	
	void addExpPropTitle(const string& title) {
		expPropTitleList.add(title);
	}
	
	int getExpPropTitlesListSize() {
		return expPropTitleList.size();
	}
	
	string& getExpPropTitle(int index) {
		return expPropTitleList.get(index);
	}
	
	// Experimental Property Methods
	// UPDATE THIS METHOD WHEN WE CAN PASS VECTORS AROUND IN IDL
	void addExperimentalProperty(uint32 groupNumber, const string& experimentalProperty, uint32 weight) {
		if (groupNumber < dsExpPropGroups.size()) {
			dsExpPropGroups.get(groupNumber)->addExperimentalProperty(experimentalProperty, weight);
		} else {
			DraftSchematicExpPropGroupImplementation* dsEpgImp = new DraftSchematicExpPropGroupImplementation();
			DraftSchematicExpPropGroup* dsEpg = (DraftSchematicExpPropGroup*) dsEpgImp->deploy();
			
			dsEpg->addExperimentalProperty(experimentalProperty, weight);
			
			dsExpPropGroups.add(dsEpg);
		}
	}
	
	void sendExperimentalPropertiesToPlayer(Player* player) {
		ObjectControllerMessage* msg = new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x0207);
				
		msg->insertInt(schematicID);
		msg->insertInt(schematicCRC);
		
		uint8 listSize = dsExpPropGroups.size();
		
		/*uint32 padding = 0;
		if (draftSchematicIngredients.size() > 0) {
			string templateName = draftSchematicIngredients.get(0)->getTemplateName();
			
			if( templateName == "craft_chemical_ingredients_n" || templateName == "craft_droid_ingredients_n" 
					|| templateName == "craft_munition_ingredients_n" || templateName == "craft_structure_ingredients_n"
						|| templateName == "craft_tissue_ingredients_n" || templateName == "craft_vehicle_ingredients_n" 
							|| templateName == "craft_weapon_ingredients_n") {
				padding = 2;
			} else {
				padding = 3;
			}
		}*/

		// Have to run the loop twice.  Ask soe why :/
		for (int soeFtl = 0; soeFtl < 2; soeFtl++) {
			// The +3 is for the padding
			//msg->insertByte(listSize + padding);
			msg->insertByte(listSize);
			
			/* This loop adds the padding required for this packet to work
			for (int soeIsDumb = 0; soeIsDumb < padding; soeIsDumb++) {
				msg->insertByte(1);
				msg->insertByte(0);
			}*/
			
			// Send all the experimental property data
			for (int i = 0; i < listSize; i++) {
				DraftSchematicExpPropGroup* dsEpg = dsExpPropGroups.get(i);
				dsEpg->sendToPlayer(msg);
			}
		}
		
		player->sendMessage(msg);
	}

	// setters
	inline void setPersistent(bool status) {
		persistent = status;
	}
	inline void setObjectID(uint64 objID){
		objectID = objID;
	}
	
	inline void setTanoAttributes(string attributes){
		tanoAttributes = attributes;
	}

	//getters
	inline uint32 getSchematicID() {
		return schematicID;
	}
		
	inline uint32 getSchematicCRC() {
		return schematicCRC;
	}
		
	inline string& getName() {
		return objName;
	}
		
	inline string& getGroupName() {
		return groupName;
	}
	
	inline uint32 getComplexity() {
		return complexity;
	}
		
	inline uint32 getSchematicSize() {
		return schematicSize;
	}
	
	inline uint64 getObjectID(){
		return objectID;
	}
	
	inline string& getTanoAttributes(){
		return tanoAttributes;
	}
	
	inline int getCraftingToolTab() {
		return craftingToolTab;
	}

};

#endif /*DRAFTSCHEMATICIMPLEMENTATION_H_*/
