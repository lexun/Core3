/*
 *	server/zone/objects/tangible/Inventory.h generated by engine3 IDL compiler 0.55
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "engine/orb/DistributedObjectBroker.h"

class Container;

class CreatureObject;

#include "Container.h"

class Inventory : public Container {
protected:
	Inventory();
	Inventory(DistributedObjectServant* obj);
	Inventory(Inventory& ref);

	virtual ~Inventory();

public:
	Inventory* clone();

	friend class InventoryHelper;
};

class InventoryImplementation;

class InventoryAdapter : public ContainerAdapter {
public:
	InventoryAdapter(InventoryImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class InventoryHelper : public DistributedObjectClassHelper, public Singleton<InventoryHelper> {
public:
	InventoryHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<InventoryHelper>;
};

#include "ContainerImplementation.h"

class InventoryServant : public ContainerImplementation {
public:
	Inventory* _this;

public:
	InventoryServant(unsigned long long oid);
	virtual ~InventoryServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*INVENTORY_H_*/
