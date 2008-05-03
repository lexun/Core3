/*
 *	server/zone/managers/item/ItemManager.cpp generated by engine3 IDL compiler 0.55
 */

#include "../../objects/creature/bluefrog/BFVector.h"

#include "../../objects/tangible/TangibleObject.h"

#include "../../objects/tangible/weapons/Weapon.h"

#include "../../objects/tangible/wearables/Armor.h"

#include "../../objects/player/Player.h"

#include "ItemManager.h"

#include "ItemManagerImplementation.h"

/*
 *	ItemManagerStub
 */

ItemManager::ItemManager() : DistributedObjectStub(NULL) {
}

ItemManager::ItemManager(DistributedObjectServant* obj) : DistributedObjectStub(obj) {
}

ItemManager::ItemManager(ItemManager& ref) : DistributedObjectStub(ref) {
}

ItemManager::~ItemManager() {
}

ItemManager* ItemManager::clone() {
	return new ItemManager(*this);
}


void ItemManager::loadStaticWorldObjects() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadStaticWorldObjects();
}

TangibleObject* ItemManager::getPlayerItem(Player* player, long long objectid) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addSignedLongParameter(objectid);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return ((ItemManagerImplementation*) _impl)->getPlayerItem(player, objectid);
}

void ItemManager::loadPlayerItems(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadPlayerItems(player);
}

void ItemManager::loadDefaultPlayerItems(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadDefaultPlayerItems(player);
}

void ItemManager::loadDefaultPlayerDatapadItems(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 10);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->loadDefaultPlayerDatapadItems(player);
}

void ItemManager::unloadPlayerItems(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 11);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->unloadPlayerItems(player);
}

void ItemManager::createPlayerItem(Player* player, TangibleObject* item) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 12);
		method.addObjectParameter(player);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->createPlayerItem(player, item);
}

void ItemManager::savePlayerItem(Player* player, TangibleObject* item) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 13);
		method.addObjectParameter(player);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->savePlayerItem(player, item);
}

void ItemManager::deletePlayerItem(Player* player, TangibleObject* item, bool notify) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 14);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addBooleanParameter(notify);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->deletePlayerItem(player, item, notify);
}

void ItemManager::showDbStats(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 15);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->showDbStats(player);
}

void ItemManager::showDbDeleted(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 16);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->showDbDeleted(player);
}

void ItemManager::purgeDbDeleted(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 17);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->purgeDbDeleted(player);
}

unsigned long long ItemManager::getNextStaticObjectID() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 18);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((ItemManagerImplementation*) _impl)->getNextStaticObjectID();
}

BFVector* ItemManager::getBFItemList() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 19);

		return (BFVector*) method.executeWithObjectReturn();
	} else
		return ((ItemManagerImplementation*) _impl)->getBFItemList();
}

BFVector* ItemManager::getBFProfList() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 20);

		return (BFVector*) method.executeWithObjectReturn();
	} else
		return ((ItemManagerImplementation*) _impl)->getBFProfList();
}

string& ItemManager::getBFProf(string& key) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 21);
		method.addAsciiParameter(key);

		method.executeWithAsciiReturn(_return_getBFProf);
		return _return_getBFProf;
	} else
		return ((ItemManagerImplementation*) _impl)->getBFProf(key);
}

void ItemManager::giveBFItemSet(Player* player, string& set) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 22);
		method.addObjectParameter(player);
		method.addAsciiParameter(set);

		method.executeWithVoidReturn();
	} else
		((ItemManagerImplementation*) _impl)->giveBFItemSet(player, set);
}

/*
 *	ItemManagerAdapter
 */

ItemManagerAdapter::ItemManagerAdapter(ItemManagerImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* ItemManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		loadStaticWorldObjects();
		break;
	case 7:
		resp->insertLong(getPlayerItem((Player*) inv->getObjectParameter(), inv->getSignedLongParameter())->_getObjectID());
		break;
	case 8:
		loadPlayerItems((Player*) inv->getObjectParameter());
		break;
	case 9:
		loadDefaultPlayerItems((Player*) inv->getObjectParameter());
		break;
	case 10:
		loadDefaultPlayerDatapadItems((Player*) inv->getObjectParameter());
		break;
	case 11:
		unloadPlayerItems((Player*) inv->getObjectParameter());
		break;
	case 12:
		createPlayerItem((Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter());
		break;
	case 13:
		savePlayerItem((Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter());
		break;
	case 14:
		deletePlayerItem((Player*) inv->getObjectParameter(), (TangibleObject*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 15:
		showDbStats((Player*) inv->getObjectParameter());
		break;
	case 16:
		showDbDeleted((Player*) inv->getObjectParameter());
		break;
	case 17:
		purgeDbDeleted((Player*) inv->getObjectParameter());
		break;
	case 18:
		resp->insertLong(getNextStaticObjectID());
		break;
	case 19:
		resp->insertLong(getBFItemList()->_getObjectID());
		break;
	case 20:
		resp->insertLong(getBFProfList()->_getObjectID());
		break;
	case 21:
		resp->insertAscii(getBFProf(inv->getAsciiParameter(_param0_getBFProf__string_)));
		break;
	case 22:
		giveBFItemSet((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_giveBFItemSet__Player_string_));
		break;
	default:
		return NULL;
	}

	return resp;
}

void ItemManagerAdapter::loadStaticWorldObjects() {
	return ((ItemManagerImplementation*) impl)->loadStaticWorldObjects();
}

TangibleObject* ItemManagerAdapter::getPlayerItem(Player* player, long long objectid) {
	return ((ItemManagerImplementation*) impl)->getPlayerItem(player, objectid);
}

void ItemManagerAdapter::loadPlayerItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->loadPlayerItems(player);
}

void ItemManagerAdapter::loadDefaultPlayerItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->loadDefaultPlayerItems(player);
}

void ItemManagerAdapter::loadDefaultPlayerDatapadItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->loadDefaultPlayerDatapadItems(player);
}

void ItemManagerAdapter::unloadPlayerItems(Player* player) {
	return ((ItemManagerImplementation*) impl)->unloadPlayerItems(player);
}

void ItemManagerAdapter::createPlayerItem(Player* player, TangibleObject* item) {
	return ((ItemManagerImplementation*) impl)->createPlayerItem(player, item);
}

void ItemManagerAdapter::savePlayerItem(Player* player, TangibleObject* item) {
	return ((ItemManagerImplementation*) impl)->savePlayerItem(player, item);
}

void ItemManagerAdapter::deletePlayerItem(Player* player, TangibleObject* item, bool notify) {
	return ((ItemManagerImplementation*) impl)->deletePlayerItem(player, item, notify);
}

void ItemManagerAdapter::showDbStats(Player* player) {
	return ((ItemManagerImplementation*) impl)->showDbStats(player);
}

void ItemManagerAdapter::showDbDeleted(Player* player) {
	return ((ItemManagerImplementation*) impl)->showDbDeleted(player);
}

void ItemManagerAdapter::purgeDbDeleted(Player* player) {
	return ((ItemManagerImplementation*) impl)->purgeDbDeleted(player);
}

unsigned long long ItemManagerAdapter::getNextStaticObjectID() {
	return ((ItemManagerImplementation*) impl)->getNextStaticObjectID();
}

BFVector* ItemManagerAdapter::getBFItemList() {
	return ((ItemManagerImplementation*) impl)->getBFItemList();
}

BFVector* ItemManagerAdapter::getBFProfList() {
	return ((ItemManagerImplementation*) impl)->getBFProfList();
}

string& ItemManagerAdapter::getBFProf(string& key) {
	return ((ItemManagerImplementation*) impl)->getBFProf(key);
}

void ItemManagerAdapter::giveBFItemSet(Player* player, string& set) {
	return ((ItemManagerImplementation*) impl)->giveBFItemSet(player, set);
}

/*
 *	ItemManagerHelper
 */

ItemManagerHelper::ItemManagerHelper() {
	className = "ItemManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ItemManagerHelper::finalizeHelper() {
	ItemManagerHelper::finalize();
}

DistributedObject* ItemManagerHelper::instantiateObject() {
	return new ItemManager();
}

DistributedObjectAdapter* ItemManagerHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new ItemManagerAdapter((ItemManagerImplementation*) obj);

	DistributedObjectStub* stub = new ItemManager(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	ItemManagerServant
 */

ItemManagerServant::ItemManagerServant() {
	_classHelper = ItemManagerHelper::instance();
}

ItemManagerServant::~ItemManagerServant() {
}

void ItemManagerServant::_setStub(DistributedObjectStub* stub) {
	_this = (ItemManager*) stub;
}

DistributedObjectStub* ItemManagerServant::_getStub() {
	return _this;
}

