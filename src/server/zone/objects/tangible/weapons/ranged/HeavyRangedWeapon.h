/*
 *	server/zone/objects/tangible/weapons/ranged/HeavyRangedWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef HEAVYRANGEDWEAPON_H_
#define HEAVYRANGEDWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class Player;

class RangedWeapon;

#include "../RangedWeapon.h"

class HeavyRangedWeapon : public RangedWeapon {
protected:
	HeavyRangedWeapon();
	HeavyRangedWeapon(DistributedObjectServant* obj);
	HeavyRangedWeapon(HeavyRangedWeapon& ref);

	virtual ~HeavyRangedWeapon();

public:
	HeavyRangedWeapon* clone();

	int useObject(Player* player);

protected:
	friend class HeavyRangedWeaponHelper;
};

class HeavyRangedWeaponImplementation;

class HeavyRangedWeaponAdapter : public RangedWeaponAdapter {
public:
	HeavyRangedWeaponAdapter(HeavyRangedWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

};

class HeavyRangedWeaponHelper : public DistributedObjectClassHelper, public Singleton<HeavyRangedWeaponHelper> {
public:
	HeavyRangedWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<HeavyRangedWeaponHelper>;
};

#include "../RangedWeaponImplementation.h"

class HeavyRangedWeaponServant : public RangedWeaponImplementation {
public:
	HeavyRangedWeapon* _this;

public:
	HeavyRangedWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, int tp, bool eqp);
	HeavyRangedWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, int tp, bool eqp);
	virtual ~HeavyRangedWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*HEAVYRANGEDWEAPON_H_*/
