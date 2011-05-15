/*
 *	server/zone/managers/resource/ResourceManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneProcessServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace managers {
namespace object {

class ObjectManager;

} // namespace object
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::object;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace resource {

class ResourceContainer;

} // namespace resource
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::resource;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {
namespace resourcedeedlistbox {

class ResourceDeedListBox;

} // namespace resourcedeedlistbox
} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox::resourcedeedlistbox;

#include "server/zone/managers/resource/resourcespawner/ResourceSpawner.h"

#include "server/zone/packets/resource/ResourceListForSurveyMessage.h"

#include "server/zone/objects/resource/ResourceSpawn.h"

#include "engine/core/ManagedObject.h"

#include "engine/lua/Lua.h"

#include "engine/log/Logger.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {

class ResourceManager : public Observer {
public:
	static const int RESOURCE_DEED_QUANTITY = 100000;

	ResourceManager(ZoneServer* server, ZoneProcessServer* impl, ObjectManager* objectMan);

	void stop();

	void initialize();

	void shiftResources();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void sendResourceListForSurvey(PlayerCreature* playerCreature, const int toolType, const String& surveyType);

	void sendSurvey(PlayerCreature* playerCreature, const String& resname);

	void sendSample(PlayerCreature* playerCreature, const String& resname, const String& sampleAnimation);

	ResourceContainer* harvestResource(PlayerCreature* player, const String& type, const int quantity);

	void harvestResourceToPlayer(PlayerCreature* player, ResourceSpawn* resourceSpawn, const int quantity);

	unsigned int getAvailablePowerFromPlayer(PlayerCreature* player);

	void removePowerFromPlayer(PlayerCreature* player, unsigned int power);

	void getResourceListByType(Vector<ManagedReference<ResourceSpawn* > >& list, int type, int zoneid);

	void createResourceSpawn(PlayerCreature* playerCreature, const String& restype);

	void givePlayerResource(PlayerCreature* playerCreature, const String& restype, const int quantity);

	ResourceSpawn* getCurrentSpawn(const String& restype, int zoneid);

	ResourceSpawn* getResourceSpawn(const String& spawnName);

	void addChildrenToDeedListBox(const String& name, ResourceDeedListBox* suil, bool parent = false);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ResourceManager(DummyConstructorParameter* param);

	virtual ~ResourceManager();

	friend class ResourceManagerHelper;
};

} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource;

namespace server {
namespace zone {
namespace managers {
namespace resource {

class ResourceManagerImplementation : public ObserverImplementation, public Lua {
	ManagedReference<ZoneProcessServer* > processor;

	ManagedWeakReference<ZoneServer* > zoneServer;

	Reference<ResourceSpawner* > resourceSpawner;

	Reference<ObjectManager* > objectManager;

	int shiftInterval;

public:
	static const int RESOURCE_DEED_QUANTITY = 100000;

	ResourceManagerImplementation(ZoneServer* server, ZoneProcessServer* impl, ObjectManager* objectMan);

	ResourceManagerImplementation(DummyConstructorParameter* param);

	void stop();

	void initialize();

	void shiftResources();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void sendResourceListForSurvey(PlayerCreature* playerCreature, const int toolType, const String& surveyType);

	void sendSurvey(PlayerCreature* playerCreature, const String& resname);

	void sendSample(PlayerCreature* playerCreature, const String& resname, const String& sampleAnimation);

	ResourceContainer* harvestResource(PlayerCreature* player, const String& type, const int quantity);

	void harvestResourceToPlayer(PlayerCreature* player, ResourceSpawn* resourceSpawn, const int quantity);

	unsigned int getAvailablePowerFromPlayer(PlayerCreature* player);

	void removePowerFromPlayer(PlayerCreature* player, unsigned int power);

	void getResourceListByType(Vector<ManagedReference<ResourceSpawn* > >& list, int type, int zoneid);

	void createResourceSpawn(PlayerCreature* playerCreature, const String& restype);

	void givePlayerResource(PlayerCreature* playerCreature, const String& restype, const int quantity);

	ResourceSpawn* getCurrentSpawn(const String& restype, int zoneid);

	ResourceSpawn* getResourceSpawn(const String& spawnName);

private:
	bool loadConfigFile();

	bool loadConfigData();

	void loadDefaultConfig();

	void startResourceSpawner();

public:
	void addChildrenToDeedListBox(const String& name, ResourceDeedListBox* suil, bool parent = false);

	ResourceManager* _this;

	operator const ResourceManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ResourceManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class ResourceManager;
};

class ResourceManagerAdapter : public ObserverAdapter {
public:
	ResourceManagerAdapter(ResourceManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void stop();

	void initialize();

	void shiftResources();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void sendResourceListForSurvey(PlayerCreature* playerCreature, const int toolType, const String& surveyType);

	void sendSurvey(PlayerCreature* playerCreature, const String& resname);

	void sendSample(PlayerCreature* playerCreature, const String& resname, const String& sampleAnimation);

	ResourceContainer* harvestResource(PlayerCreature* player, const String& type, const int quantity);

	void harvestResourceToPlayer(PlayerCreature* player, ResourceSpawn* resourceSpawn, const int quantity);

	unsigned int getAvailablePowerFromPlayer(PlayerCreature* player);

	void removePowerFromPlayer(PlayerCreature* player, unsigned int power);

	void createResourceSpawn(PlayerCreature* playerCreature, const String& restype);

	void givePlayerResource(PlayerCreature* playerCreature, const String& restype, const int quantity);

	ResourceSpawn* getCurrentSpawn(const String& restype, int zoneid);

	ResourceSpawn* getResourceSpawn(const String& spawnName);

	void addChildrenToDeedListBox(const String& name, ResourceDeedListBox* suil, bool parent);

protected:
	String _param2_sendResourceListForSurvey__PlayerCreature_int_String_;
	String _param1_sendSurvey__PlayerCreature_String_;
	String _param1_sendSample__PlayerCreature_String_String_;
	String _param2_sendSample__PlayerCreature_String_String_;
	String _param1_harvestResource__PlayerCreature_String_int_;
	String _param1_createResourceSpawn__PlayerCreature_String_;
	String _param1_givePlayerResource__PlayerCreature_String_int_;
	String _param0_getCurrentSpawn__String_int_;
	String _param0_getResourceSpawn__String_;
	String _param0_addChildrenToDeedListBox__String_ResourceDeedListBox_bool_;
};

class ResourceManagerHelper : public DistributedObjectClassHelper, public Singleton<ResourceManagerHelper> {
	static ResourceManagerHelper* staticInitializer;

public:
	ResourceManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ResourceManagerHelper>;
};

} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource;

#endif /*RESOURCEMANAGER_H_*/
