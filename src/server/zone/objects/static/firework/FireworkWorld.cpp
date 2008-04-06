/*
 *	server/zone/objects/static/firework/FireworkWorld.cpp generated by engine3 IDL compiler 0.55
 */

#include "../../static/StaticObject.h"

#include "../../player/Player.h"

#include "FireworkWorld.h"

#include "FireworkWorldImplementation.h"

/*
 *	FireworkWorldStub
 */

FireworkWorld::FireworkWorld() : StaticObject(NULL) {
}

FireworkWorld::FireworkWorld(DistributedObjectServant* obj) : StaticObject(obj) {
}

FireworkWorld::FireworkWorld(FireworkWorld& ref) : StaticObject(ref) {
}

FireworkWorld::~FireworkWorld() {
}

FireworkWorld* FireworkWorld::clone() {
	return new FireworkWorld(*this);
}


int FireworkWorld::getFireworkType() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return ((FireworkWorldImplementation*) _impl)->getFireworkType();
}

/*
 *	FireworkWorldAdapter
 */

FireworkWorldAdapter::FireworkWorldAdapter(FireworkWorldImplementation* obj) : StaticObjectAdapter(obj) {
}

Packet* FireworkWorldAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getFireworkType());
		break;
	default:
		return NULL;
	}

	return resp;
}

int FireworkWorldAdapter::getFireworkType() {
	return ((FireworkWorldImplementation*) impl)->getFireworkType();
}

/*
 *	FireworkWorldHelper
 */

FireworkWorldHelper::FireworkWorldHelper() {
	className = "FireworkWorld";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FireworkWorldHelper::finalizeHelper() {
	FireworkWorldHelper::finalize();
}

DistributedObject* FireworkWorldHelper::instantiateObject() {
	return new FireworkWorld();
}

DistributedObjectAdapter* FireworkWorldHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new FireworkWorldAdapter((FireworkWorldImplementation*) obj);

	DistributedObjectStub* stub = new FireworkWorld(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	FireworkWorldServant
 */

FireworkWorldServant::FireworkWorldServant(unsigned long long oid, int tp) : StaticObjectImplementation(oid, tp) {
	_classHelper = FireworkWorldHelper::instance();
}

FireworkWorldServant::~FireworkWorldServant() {
}

void FireworkWorldServant::_setStub(DistributedObjectStub* stub) {
	_this = (FireworkWorld*) stub;
	StaticObjectServant::_setStub(stub);
}

DistributedObjectStub* FireworkWorldServant::_getStub() {
	return _this;
}

