/*
 *	server/zone/objects/auction/AuctionItem.cpp generated by engine3 IDL compiler 0.55
 */

#include "AuctionItem.h"

#include "AuctionItemImplementation.h"

/*
 *	AuctionItemStub
 */

AuctionItem::AuctionItem() : ManagedObject(NULL) {
}

AuctionItem::AuctionItem(DistributedObjectServant* obj) : ManagedObject(obj) {
}

AuctionItem::AuctionItem(AuctionItem& ref) : ManagedObject(ref) {
}

AuctionItem::~AuctionItem() {
}

AuctionItem* AuctionItem::clone() {
	return new AuctionItem(*this);
}


unsigned long long AuctionItem::getId() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getId();
}

unsigned long long AuctionItem::getOwnerId() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getOwnerId();
}

void AuctionItem::setOwnerId(unsigned long long ownerid) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addUnsignedLongParameter(ownerid);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setOwnerId(ownerid);
}

void AuctionItem::setOwnerName(string& name) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 9);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setOwnerName(name);
}

unsigned long long AuctionItem::getBuyerId() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 10);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getBuyerId();
}

void AuctionItem::setBuyerId(unsigned long long buyerid) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 11);
		method.addUnsignedLongParameter(buyerid);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setBuyerId(buyerid);
}

string& AuctionItem::getBidderName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 12);

		method.executeWithAsciiReturn(_return_getBidderName);
		return _return_getBidderName;
	} else
		return ((AuctionItemImplementation*) _impl)->getBidderName();
}

void AuctionItem::setBidderName(string& name) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 13);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setBidderName(name);
}

unsigned int AuctionItem::getItemType() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 14);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getItemType();
}

bool AuctionItem::isSold() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->isSold();
}

void AuctionItem::setSold(bool sld) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 16);
		method.addBooleanParameter(sld);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setSold(sld);
}

string& AuctionItem::getTerminalTitle() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 17);

		method.executeWithAsciiReturn(_return_getTerminalTitle);
		return _return_getTerminalTitle;
	} else
		return ((AuctionItemImplementation*) _impl)->getTerminalTitle();
}

string& AuctionItem::getOwnerName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 18);

		method.executeWithAsciiReturn(_return_getOwnerName);
		return _return_getOwnerName;
	} else
		return ((AuctionItemImplementation*) _impl)->getOwnerName();
}

void AuctionItem::setLocationPointer(int locpt) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 19);
		method.addSignedIntParameter(locpt);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setLocationPointer(locpt);
}

int AuctionItem::getLocationPointer() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 20);

		return method.executeWithSignedIntReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getLocationPointer();
}

void AuctionItem::setOwnerPointer(int ownpt) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 21);
		method.addSignedIntParameter(ownpt);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setOwnerPointer(ownpt);
}

int AuctionItem::getOwnerPointer() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 22);

		return method.executeWithSignedIntReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getOwnerPointer();
}

string& AuctionItem::getItemName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 23);

		method.executeWithAsciiReturn(_return_getItemName);
		return _return_getItemName;
	} else
		return ((AuctionItemImplementation*) _impl)->getItemName();
}

void AuctionItem::setItemDescription(string& description) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 24);
		method.addAsciiParameter(description);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setItemDescription(description);
}

string& AuctionItem::getItemDescription() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 25);

		method.executeWithAsciiReturn(_return_getItemDescription);
		return _return_getItemDescription;
	} else
		return ((AuctionItemImplementation*) _impl)->getItemDescription();
}

int AuctionItem::getPrice() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 26);

		return method.executeWithSignedIntReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getPrice();
}

void AuctionItem::setPrice(int prc) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 27);
		method.addSignedIntParameter(prc);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setPrice(prc);
}

unsigned int AuctionItem::getExpireTime() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 28);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getExpireTime();
}

void AuctionItem::setExpireTime(unsigned int expiretime) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 29);
		method.addUnsignedIntParameter(expiretime);

		method.executeWithVoidReturn();
	} else
		((AuctionItemImplementation*) _impl)->setExpireTime(expiretime);
}

bool AuctionItem::getAuction() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 30);

		return method.executeWithBooleanReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getAuction();
}

int AuctionItem::getPlanet() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 31);

		return method.executeWithSignedIntReturn();
	} else
		return ((AuctionItemImplementation*) _impl)->getPlanet();
}

string& AuctionItem::getLocation() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 32);

		method.executeWithAsciiReturn(_return_getLocation);
		return _return_getLocation;
	} else
		return ((AuctionItemImplementation*) _impl)->getLocation();
}

/*
 *	AuctionItemAdapter
 */

AuctionItemAdapter::AuctionItemAdapter(AuctionItemImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* AuctionItemAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(getId());
		break;
	case 7:
		resp->insertLong(getOwnerId());
		break;
	case 8:
		setOwnerId(inv->getUnsignedLongParameter());
		break;
	case 9:
		setOwnerName(inv->getAsciiParameter(_param0_setOwnerName__string_));
		break;
	case 10:
		resp->insertLong(getBuyerId());
		break;
	case 11:
		setBuyerId(inv->getUnsignedLongParameter());
		break;
	case 12:
		resp->insertAscii(getBidderName());
		break;
	case 13:
		setBidderName(inv->getAsciiParameter(_param0_setBidderName__string_));
		break;
	case 14:
		resp->insertInt(getItemType());
		break;
	case 15:
		resp->insertBoolean(isSold());
		break;
	case 16:
		setSold(inv->getBooleanParameter());
		break;
	case 17:
		resp->insertAscii(getTerminalTitle());
		break;
	case 18:
		resp->insertAscii(getOwnerName());
		break;
	case 19:
		setLocationPointer(inv->getSignedIntParameter());
		break;
	case 20:
		resp->insertSignedInt(getLocationPointer());
		break;
	case 21:
		setOwnerPointer(inv->getSignedIntParameter());
		break;
	case 22:
		resp->insertSignedInt(getOwnerPointer());
		break;
	case 23:
		resp->insertAscii(getItemName());
		break;
	case 24:
		setItemDescription(inv->getAsciiParameter(_param0_setItemDescription__string_));
		break;
	case 25:
		resp->insertAscii(getItemDescription());
		break;
	case 26:
		resp->insertSignedInt(getPrice());
		break;
	case 27:
		setPrice(inv->getSignedIntParameter());
		break;
	case 28:
		resp->insertInt(getExpireTime());
		break;
	case 29:
		setExpireTime(inv->getUnsignedIntParameter());
		break;
	case 30:
		resp->insertBoolean(getAuction());
		break;
	case 31:
		resp->insertSignedInt(getPlanet());
		break;
	case 32:
		resp->insertAscii(getLocation());
		break;
	default:
		return NULL;
	}

	return resp;
}

unsigned long long AuctionItemAdapter::getId() {
	return ((AuctionItemImplementation*) impl)->getId();
}

unsigned long long AuctionItemAdapter::getOwnerId() {
	return ((AuctionItemImplementation*) impl)->getOwnerId();
}

void AuctionItemAdapter::setOwnerId(unsigned long long ownerid) {
	return ((AuctionItemImplementation*) impl)->setOwnerId(ownerid);
}

void AuctionItemAdapter::setOwnerName(string& name) {
	return ((AuctionItemImplementation*) impl)->setOwnerName(name);
}

unsigned long long AuctionItemAdapter::getBuyerId() {
	return ((AuctionItemImplementation*) impl)->getBuyerId();
}

void AuctionItemAdapter::setBuyerId(unsigned long long buyerid) {
	return ((AuctionItemImplementation*) impl)->setBuyerId(buyerid);
}

string& AuctionItemAdapter::getBidderName() {
	return ((AuctionItemImplementation*) impl)->getBidderName();
}

void AuctionItemAdapter::setBidderName(string& name) {
	return ((AuctionItemImplementation*) impl)->setBidderName(name);
}

unsigned int AuctionItemAdapter::getItemType() {
	return ((AuctionItemImplementation*) impl)->getItemType();
}

bool AuctionItemAdapter::isSold() {
	return ((AuctionItemImplementation*) impl)->isSold();
}

void AuctionItemAdapter::setSold(bool sld) {
	return ((AuctionItemImplementation*) impl)->setSold(sld);
}

string& AuctionItemAdapter::getTerminalTitle() {
	return ((AuctionItemImplementation*) impl)->getTerminalTitle();
}

string& AuctionItemAdapter::getOwnerName() {
	return ((AuctionItemImplementation*) impl)->getOwnerName();
}

void AuctionItemAdapter::setLocationPointer(int locpt) {
	return ((AuctionItemImplementation*) impl)->setLocationPointer(locpt);
}

int AuctionItemAdapter::getLocationPointer() {
	return ((AuctionItemImplementation*) impl)->getLocationPointer();
}

void AuctionItemAdapter::setOwnerPointer(int ownpt) {
	return ((AuctionItemImplementation*) impl)->setOwnerPointer(ownpt);
}

int AuctionItemAdapter::getOwnerPointer() {
	return ((AuctionItemImplementation*) impl)->getOwnerPointer();
}

string& AuctionItemAdapter::getItemName() {
	return ((AuctionItemImplementation*) impl)->getItemName();
}

void AuctionItemAdapter::setItemDescription(string& description) {
	return ((AuctionItemImplementation*) impl)->setItemDescription(description);
}

string& AuctionItemAdapter::getItemDescription() {
	return ((AuctionItemImplementation*) impl)->getItemDescription();
}

int AuctionItemAdapter::getPrice() {
	return ((AuctionItemImplementation*) impl)->getPrice();
}

void AuctionItemAdapter::setPrice(int prc) {
	return ((AuctionItemImplementation*) impl)->setPrice(prc);
}

unsigned int AuctionItemAdapter::getExpireTime() {
	return ((AuctionItemImplementation*) impl)->getExpireTime();
}

void AuctionItemAdapter::setExpireTime(unsigned int expiretime) {
	return ((AuctionItemImplementation*) impl)->setExpireTime(expiretime);
}

bool AuctionItemAdapter::getAuction() {
	return ((AuctionItemImplementation*) impl)->getAuction();
}

int AuctionItemAdapter::getPlanet() {
	return ((AuctionItemImplementation*) impl)->getPlanet();
}

string& AuctionItemAdapter::getLocation() {
	return ((AuctionItemImplementation*) impl)->getLocation();
}

/*
 *	AuctionItemHelper
 */

AuctionItemHelper::AuctionItemHelper() {
	className = "AuctionItem";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void AuctionItemHelper::finalizeHelper() {
	AuctionItemHelper::finalize();
}

DistributedObject* AuctionItemHelper::instantiateObject() {
	return new AuctionItem();
}

DistributedObjectAdapter* AuctionItemHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new AuctionItemAdapter((AuctionItemImplementation*) obj);

	DistributedObjectStub* stub = new AuctionItem(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	AuctionItemServant
 */

AuctionItemServant::AuctionItemServant() : ManagedObjectImplementation() {
	_classHelper = AuctionItemHelper::instance();
}

AuctionItemServant::~AuctionItemServant() {
}

void AuctionItemServant::_setStub(DistributedObjectStub* stub) {
	_this = (AuctionItem*) stub;
	ManagedObjectServant::_setStub(stub);
}

DistributedObjectStub* AuctionItemServant::_getStub() {
	return _this;
}

