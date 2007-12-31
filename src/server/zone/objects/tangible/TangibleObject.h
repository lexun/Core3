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

/*
 *	server/zone/objects/tangible/TangibleObject.h generated by Engine3 IDL compiler 0.51
 */

#ifndef TANGIBLEOBJECT_H_
#define TANGIBLEOBJECT_H_

#include "engine/orb/ObjectRequestBroker.h"

class SceneObject;

class Player;

class Zone;

#include "engine/service/Message.h"

#include "../scene/SceneObject.h"

class TangibleObject : public SceneObject {
public:
	TangibleObject();
	TangibleObject(ORBObjectServant* obj);
	TangibleObject(TangibleObject& ref);

	TangibleObject* clone();

	virtual ~TangibleObject();

	void insertToZone(Zone* zone);

	void removeFromZone();

	void close(Player* player);

	void setEquipped(bool eqp);

	void setContainer(SceneObject* cont, unsigned int type = 04);

	void sendTo(Player* player, bool doClose = true);

	bool isPersistent();

	bool isUpdated();

	bool isEquipped();

	bool isWeapon();

	bool isArmor();

	bool isTicket();

	void setPersistent(bool pers);

	void setUpdated(bool upd);

	void setConditionDamage(int damage);

	SceneObject* getContainer();

	unicode& getName();

	string& getTemplateName();

	string& getTemplateTypeName();

	string& getCustomizationString();

	int getObjectSubType();

	unsigned int getTemplateID();

	int getObjectCount();

	int getConditionDamage();

	int getMaxCondition();

	int getCondition();

protected:
	string _return_getCustomizationString;

	string _return_getTemplateTypeName;

	string _return_getTemplateName;

	unicode _return_getName;

};

class TangibleObjectImplementation;

class TangibleObjectAdapter : public SceneObjectAdapter {
public:
	TangibleObjectAdapter(TangibleObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, ORBMethodInvocation* inv);

	void insertToZone(Zone* zone);

	void removeFromZone();

	void close(Player* player);

	void setEquipped(bool eqp);

	void setContainer(SceneObject* cont, unsigned int type);

	void sendTo(Player* player, bool doClose);

	bool isPersistent();

	bool isUpdated();

	bool isEquipped();

	bool isWeapon();

	bool isArmor();

	bool isTicket();

	void setPersistent(bool pers);

	void setUpdated(bool upd);

	void setConditionDamage(int damage);

	SceneObject* getContainer();

	unicode& getName();

	string& getTemplateName();

	string& getTemplateTypeName();

	string& getCustomizationString();

	int getObjectSubType();

	unsigned int getTemplateID();

	int getObjectCount();

	int getConditionDamage();

	int getMaxCondition();

	int getCondition();

};

class TangibleObjectHelper : public ORBClassHelper {
	static ORBClassHelper* instance;

public:
	TangibleObjectHelper();

	static ORBClassHelper* getInstance();

	ORBObject* instantiateObject();

	ORBObjectAdapter* createAdapter(ORBObjectServant* obj);

};

#include "../scene/SceneObjectImplementation.h"

class TangibleObjectServant : public SceneObjectImplementation {
public:
	TangibleObject* _this;

public:
	TangibleObjectServant();
	TangibleObjectServant(unsigned long long oid);
	virtual ~TangibleObjectServant();

	void _setStub(ORBObjectStub* stub);
	ORBObjectStub* _getStub();

};

#endif /*TANGIBLEOBJECT_H_*/
