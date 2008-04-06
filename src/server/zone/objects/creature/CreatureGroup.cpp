/*
 *	server/zone/objects/creature/CreatureGroup.cpp generated by engine3 IDL compiler 0.55
 */

#include "Creature.h"

#include "CreatureObject.h"

#include "CreatureGroup.h"

#include "CreatureGroupImplementation.h"

/*
 *	CreatureGroupStub
 */

CreatureGroup::CreatureGroup() : DistributedObjectStub(NULL) {
}

CreatureGroup::CreatureGroup(DistributedObjectServant* obj) : DistributedObjectStub(obj) {
}

CreatureGroup::CreatureGroup(CreatureGroup& ref) : DistributedObjectStub(ref) {
}

CreatureGroup::~CreatureGroup() {
}

CreatureGroup* CreatureGroup::clone() {
	return new CreatureGroup(*this);
}


void CreatureGroup::addCreature(Creature* creature) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		((CreatureGroupImplementation*) _impl)->addCreature(creature);
}

void CreatureGroup::setTarget(CreatureObject* targ) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addObjectParameter(targ);

		method.executeWithVoidReturn();
	} else
		((CreatureGroupImplementation*) _impl)->setTarget(targ);
}

/*
 *	CreatureGroupAdapter
 */

CreatureGroupAdapter::CreatureGroupAdapter(CreatureGroupImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* CreatureGroupAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		addCreature((Creature*) inv->getObjectParameter());
		break;
	case 7:
		setTarget((CreatureObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CreatureGroupAdapter::addCreature(Creature* creature) {
	return ((CreatureGroupImplementation*) impl)->addCreature(creature);
}

void CreatureGroupAdapter::setTarget(CreatureObject* targ) {
	return ((CreatureGroupImplementation*) impl)->setTarget(targ);
}

/*
 *	CreatureGroupHelper
 */

CreatureGroupHelper::CreatureGroupHelper() {
	className = "CreatureGroup";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureGroupHelper::finalizeHelper() {
	CreatureGroupHelper::finalize();
}

DistributedObject* CreatureGroupHelper::instantiateObject() {
	return new CreatureGroup();
}

DistributedObjectAdapter* CreatureGroupHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new CreatureGroupAdapter((CreatureGroupImplementation*) obj);

	DistributedObjectStub* stub = new CreatureGroup(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	CreatureGroupServant
 */

CreatureGroupServant::CreatureGroupServant() {
	_classHelper = CreatureGroupHelper::instance();
}

CreatureGroupServant::~CreatureGroupServant() {
}

void CreatureGroupServant::_setStub(DistributedObjectStub* stub) {
	_this = (CreatureGroup*) stub;
}

DistributedObjectStub* CreatureGroupServant::_getStub() {
	return _this;
}

