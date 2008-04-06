/*
 *	server/zone/objects/tangible/weapons/JediWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef JEDIWEAPON_H_
#define JEDIWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class Weapon;

#include "Weapon.h"

class JediWeapon : public Weapon {
protected:
	JediWeapon();
	JediWeapon(DistributedObjectServant* obj);
	JediWeapon(JediWeapon& ref);

	virtual ~JediWeapon();

public:
	JediWeapon* clone();

	int getForceCost();

	void setForceCost(int fcost);

protected:
	friend class JediWeaponHelper;
};

class JediWeaponImplementation;

class JediWeaponAdapter : public WeaponAdapter {
public:
	JediWeaponAdapter(JediWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int getForceCost();

	void setForceCost(int fcost);

};

class JediWeaponHelper : public DistributedObjectClassHelper, public Singleton<JediWeaponHelper> {
public:
	JediWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<JediWeaponHelper>;
};

#include "WeaponImplementation.h"

class JediWeaponServant : public WeaponImplementation {
public:
	JediWeapon* _this;

public:
	JediWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, bool eqp, int tp, int cat);
	JediWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, bool eqp, int tp, int cat);
	virtual ~JediWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*JEDIWEAPON_H_*/
