/*
 *	server/zone/objects/tangible/weapons/MeleeWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef MELEEWEAPON_H_
#define MELEEWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class Weapon;

#include "Weapon.h"

class MeleeWeapon : public Weapon {
protected:
	MeleeWeapon();
	MeleeWeapon(DistributedObjectServant* obj);
	MeleeWeapon(MeleeWeapon& ref);

	virtual ~MeleeWeapon();

public:
	MeleeWeapon* clone();

	friend class MeleeWeaponHelper;
};

class MeleeWeaponImplementation;

class MeleeWeaponAdapter : public WeaponAdapter {
public:
	MeleeWeaponAdapter(MeleeWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class MeleeWeaponHelper : public DistributedObjectClassHelper, public Singleton<MeleeWeaponHelper> {
public:
	MeleeWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<MeleeWeaponHelper>;
};

#include "WeaponImplementation.h"

class MeleeWeaponServant : public WeaponImplementation {
public:
	MeleeWeapon* _this;

public:
	MeleeWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, bool eqp, int tp, int cat);
	MeleeWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, bool eqp, int tp, int cat);
	virtual ~MeleeWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*MELEEWEAPON_H_*/
