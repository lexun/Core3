/*
 *	server/zone/objects/tangible/crafting/CraftingStation.cpp generated by engine3 IDL compiler 0.55
 */

#include "../TangibleObject.h"

#include "../../../packets.h"

#include "../../player/Player.h"

#include "../../creature/CreatureObject.h"

#include "CraftingStation.h"

#include "CraftingStationImplementation.h"

/*
 *	CraftingStationStub
 */

CraftingStation::CraftingStation() : TangibleObject(NULL) {
}

CraftingStation::CraftingStation(DistributedObjectServant* obj) : TangibleObject(obj) {
}

CraftingStation::CraftingStation(CraftingStation& ref) : TangibleObject(ref) {
}

CraftingStation::~CraftingStation() {
}

CraftingStation* CraftingStation::clone() {
	return new CraftingStation(*this);
}


void CraftingStation::generateAttributes(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CraftingStationImplementation*) _impl)->generateAttributes(player);
}

int CraftingStation::useObject(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingStationImplementation*) _impl)->useObject(player);
}

void CraftingStation::setStationEffectiveness(float eff) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addFloatParameter(eff);

		method.executeWithVoidReturn();
	} else
		((CraftingStationImplementation*) _impl)->setStationEffectiveness(eff);
}

float CraftingStation::getStationEffectiveness() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return ((CraftingStationImplementation*) _impl)->getStationEffectiveness();
}

/*
 *	CraftingStationAdapter
 */

CraftingStationAdapter::CraftingStationAdapter(CraftingStationImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* CraftingStationAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		generateAttributes((Player*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 8:
		setStationEffectiveness(inv->getFloatParameter());
		break;
	case 9:
		resp->insertFloat(getStationEffectiveness());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CraftingStationAdapter::generateAttributes(Player* player) {
	return ((CraftingStationImplementation*) impl)->generateAttributes(player);
}

int CraftingStationAdapter::useObject(Player* player) {
	return ((CraftingStationImplementation*) impl)->useObject(player);
}

void CraftingStationAdapter::setStationEffectiveness(float eff) {
	return ((CraftingStationImplementation*) impl)->setStationEffectiveness(eff);
}

float CraftingStationAdapter::getStationEffectiveness() {
	return ((CraftingStationImplementation*) impl)->getStationEffectiveness();
}

/*
 *	CraftingStationHelper
 */

CraftingStationHelper::CraftingStationHelper() {
	className = "CraftingStation";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CraftingStationHelper::finalizeHelper() {
	CraftingStationHelper::finalize();
}

DistributedObject* CraftingStationHelper::instantiateObject() {
	return new CraftingStation();
}

DistributedObjectAdapter* CraftingStationHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new CraftingStationAdapter((CraftingStationImplementation*) obj);

	DistributedObjectStub* stub = new CraftingStation(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	CraftingStationServant
 */

CraftingStationServant::CraftingStationServant(unsigned long long oid, const unicode& n, const string& tempn, int tempCRC, int tp) : TangibleObjectImplementation(oid, n, tempn, tempCRC, tp) {
	_classHelper = CraftingStationHelper::instance();
}

CraftingStationServant::CraftingStationServant(CreatureObject* creature, const unicode& n, const string& tempn, int tempCRC, int tp) : TangibleObjectImplementation(creature, n, tempn, tempCRC, tp) {
	_classHelper = CraftingStationHelper::instance();
}

CraftingStationServant::~CraftingStationServant() {
}

void CraftingStationServant::_setStub(DistributedObjectStub* stub) {
	_this = (CraftingStation*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* CraftingStationServant::_getStub() {
	return _this;
}

