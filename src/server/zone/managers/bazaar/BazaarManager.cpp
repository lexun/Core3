/*
 *	server/zone/managers/bazaar/BazaarManager.cpp generated by engine3 IDL compiler 0.55
 */

#include "../../objects/auction/AuctionItem.h"

#include "../../objects/player/Player.h"

#include "../../objects/tangible/terminal/bazaar/RegionBazaar.h"

#include "BazaarPlanetManager.h"

#include "BazaarManager.h"

#include "BazaarManagerImplementation.h"

/*
 *	BazaarManagerStub
 */

BazaarManager::BazaarManager() : DistributedObjectStub(NULL) {
}

BazaarManager::BazaarManager(DistributedObjectServant* obj) : DistributedObjectStub(obj) {
}

BazaarManager::BazaarManager(BazaarManager& ref) : DistributedObjectStub(ref) {
}

BazaarManager::~BazaarManager() {
}

BazaarManager* BazaarManager::clone() {
	return new BazaarManager(*this);
}


void BazaarManager::newBazaarRequest(unsigned long long bazaarID, Player* player, int planet) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addUnsignedLongParameter(bazaarID);
		method.addObjectParameter(player);
		method.addSignedIntParameter(planet);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->newBazaarRequest(bazaarID, player, planet);
}

bool BazaarManager::isBazaarTerminal(unsigned long long objectID) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithBooleanReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->isBazaarTerminal(objectID);
}

void BazaarManager::addSaleItem(Player* player, unsigned long long objectid, unsigned long long bazaarid, unicode& description, int price, int duration, bool auction) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addUnsignedLongParameter(bazaarid);
		method.addUnicodeParameter(description);
		method.addSignedIntParameter(price);
		method.addSignedIntParameter(duration);
		method.addBooleanParameter(auction);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->addSaleItem(player, objectid, bazaarid, description, price, duration, auction);
}

void BazaarManager::getBazaarData(Player* player, unsigned long long objectid, int screen, int extent, unsigned int category, int count, int offset) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 9);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addSignedIntParameter(screen);
		method.addSignedIntParameter(extent);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getBazaarData(player, objectid, screen, extent, category, count, offset);
}

RegionBazaar* BazaarManager::getBazaar(unsigned long long bazaarid) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 10);
		method.addUnsignedLongParameter(bazaarid);

		return (RegionBazaar*) method.executeWithObjectReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->getBazaar(bazaarid);
}

BazaarPlanetManager* BazaarManager::getPlanet(unsigned long long bazaarid) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 11);
		method.addUnsignedLongParameter(bazaarid);

		return (BazaarPlanetManager*) method.executeWithObjectReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->getPlanet(bazaarid);
}

void BazaarManager::buyItem(Player* player, unsigned long long objectid, int price1, int price2) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 12);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->buyItem(player, objectid, price1, price2);
}

void BazaarManager::retrieveItem(Player* player, unsigned long long objectid, long long bazaarid) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 13);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addSignedLongParameter(bazaarid);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->retrieveItem(player, objectid, bazaarid);
}

void BazaarManager::getItemAttributes(Player* player, unsigned long long objectId) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 14);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectId);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getItemAttributes(player, objectId);
}

/*
 *	BazaarManagerAdapter
 */

BazaarManagerAdapter::BazaarManagerAdapter(BazaarManagerImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* BazaarManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		newBazaarRequest(inv->getUnsignedLongParameter(), (Player*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 7:
		resp->insertBoolean(isBazaarTerminal(inv->getUnsignedLongParameter()));
		break;
	case 8:
		addSaleItem((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getUnsignedLongParameter(), inv->getUnicodeParameter(_param3_addSaleItem__Player_long_long_unicode_int_int_bool_), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 9:
		getBazaarData((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 10:
		resp->insertLong(getBazaar(inv->getUnsignedLongParameter())->_getObjectID());
		break;
	case 11:
		resp->insertLong(getPlanet(inv->getUnsignedLongParameter())->_getObjectID());
		break;
	case 12:
		buyItem((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 13:
		retrieveItem((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getSignedLongParameter());
		break;
	case 14:
		getItemAttributes((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void BazaarManagerAdapter::newBazaarRequest(unsigned long long bazaarID, Player* player, int planet) {
	return ((BazaarManagerImplementation*) impl)->newBazaarRequest(bazaarID, player, planet);
}

bool BazaarManagerAdapter::isBazaarTerminal(unsigned long long objectID) {
	return ((BazaarManagerImplementation*) impl)->isBazaarTerminal(objectID);
}

void BazaarManagerAdapter::addSaleItem(Player* player, unsigned long long objectid, unsigned long long bazaarid, unicode& description, int price, int duration, bool auction) {
	return ((BazaarManagerImplementation*) impl)->addSaleItem(player, objectid, bazaarid, description, price, duration, auction);
}

void BazaarManagerAdapter::getBazaarData(Player* player, unsigned long long objectid, int screen, int extent, unsigned int category, int count, int offset) {
	return ((BazaarManagerImplementation*) impl)->getBazaarData(player, objectid, screen, extent, category, count, offset);
}

RegionBazaar* BazaarManagerAdapter::getBazaar(unsigned long long bazaarid) {
	return ((BazaarManagerImplementation*) impl)->getBazaar(bazaarid);
}

BazaarPlanetManager* BazaarManagerAdapter::getPlanet(unsigned long long bazaarid) {
	return ((BazaarManagerImplementation*) impl)->getPlanet(bazaarid);
}

void BazaarManagerAdapter::buyItem(Player* player, unsigned long long objectid, int price1, int price2) {
	return ((BazaarManagerImplementation*) impl)->buyItem(player, objectid, price1, price2);
}

void BazaarManagerAdapter::retrieveItem(Player* player, unsigned long long objectid, long long bazaarid) {
	return ((BazaarManagerImplementation*) impl)->retrieveItem(player, objectid, bazaarid);
}

void BazaarManagerAdapter::getItemAttributes(Player* player, unsigned long long objectId) {
	return ((BazaarManagerImplementation*) impl)->getItemAttributes(player, objectId);
}

/*
 *	BazaarManagerHelper
 */

BazaarManagerHelper::BazaarManagerHelper() {
	className = "BazaarManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BazaarManagerHelper::finalizeHelper() {
	BazaarManagerHelper::finalize();
}

DistributedObject* BazaarManagerHelper::instantiateObject() {
	return new BazaarManager();
}

DistributedObjectAdapter* BazaarManagerHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new BazaarManagerAdapter((BazaarManagerImplementation*) obj);

	DistributedObjectStub* stub = new BazaarManager(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	BazaarManagerServant
 */

BazaarManagerServant::BazaarManagerServant() {
	_classHelper = BazaarManagerHelper::instance();
}

BazaarManagerServant::~BazaarManagerServant() {
}

void BazaarManagerServant::_setStub(DistributedObjectStub* stub) {
	_this = (BazaarManager*) stub;
}

DistributedObjectStub* BazaarManagerServant::_getStub() {
	return _this;
}

