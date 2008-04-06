/*
 *	server/zone/objects/tangible/terminal/travel/TravelTerminal.h generated by engine3 IDL compiler 0.55
 */

#ifndef TRAVELTERMINAL_H_
#define TRAVELTERMINAL_H_

#include "engine/orb/DistributedObjectBroker.h"

class Terminal;

class Player;

#include "engine/service/Message.h"

#include "../Terminal.h"

class TravelTerminal : public Terminal {
protected:
	TravelTerminal();
	TravelTerminal(DistributedObjectServant* obj);
	TravelTerminal(TravelTerminal& ref);

	virtual ~TravelTerminal();

public:
	TravelTerminal* clone();

	int useObject(Player* player);

protected:
	friend class TravelTerminalHelper;
};

class TravelTerminalImplementation;

class TravelTerminalAdapter : public TerminalAdapter {
public:
	TravelTerminalAdapter(TravelTerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

};

class TravelTerminalHelper : public DistributedObjectClassHelper, public Singleton<TravelTerminalHelper> {
public:
	TravelTerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<TravelTerminalHelper>;
};

#include "../TerminalImplementation.h"

class TravelTerminalServant : public TerminalImplementation {
public:
	TravelTerminal* _this;

public:
	TravelTerminalServant(unsigned int objCRC, unsigned long long objid, const unicode& n, const string& tempn, float x, float z, float y, int TerminalType);
	virtual ~TravelTerminalServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*TRAVELTERMINAL_H_*/
