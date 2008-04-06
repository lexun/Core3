/*
 *	server/zone/objects/tangible/crafting/CraftingStation.h generated by engine3 IDL compiler 0.55
 */

#ifndef CRAFTINGSTATION_H_
#define CRAFTINGSTATION_H_

#include "engine/orb/DistributedObjectBroker.h"

class TangibleObject;

class packets;

class Player;

class CreatureObject;

#include "engine/service/Message.h"

#include "../TangibleObject.h"

class CraftingStation : public TangibleObject {
protected:
	CraftingStation();
	CraftingStation(DistributedObjectServant* obj);
	CraftingStation(CraftingStation& ref);

	virtual ~CraftingStation();

public:
	CraftingStation* clone();

	void generateAttributes(Player* player);

	int useObject(Player* player);

	void setStationEffectiveness(float eff);

	float getStationEffectiveness();

protected:
	friend class CraftingStationHelper;
};

class CraftingStationImplementation;

class CraftingStationAdapter : public TangibleObjectAdapter {
public:
	CraftingStationAdapter(CraftingStationImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void generateAttributes(Player* player);

	int useObject(Player* player);

	void setStationEffectiveness(float eff);

	float getStationEffectiveness();

};

class CraftingStationHelper : public DistributedObjectClassHelper, public Singleton<CraftingStationHelper> {
public:
	CraftingStationHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<CraftingStationHelper>;
};

#include "../TangibleObjectImplementation.h"

class CraftingStationServant : public TangibleObjectImplementation {
public:
	CraftingStation* _this;

public:
	CraftingStationServant(unsigned long long oid, const unicode& n, const string& tempn, int tempCRC, int tp);
	CraftingStationServant(CreatureObject* creature, const unicode& n, const string& tempn, int tempCRC, int tp);
	virtual ~CraftingStationServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*CRAFTINGSTATION_H_*/
