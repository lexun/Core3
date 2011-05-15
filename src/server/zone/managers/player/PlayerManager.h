/*
 *	server/zone/managers/player/PlayerManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYERMANAGER_H_
#define PLAYERMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {
namespace objects {
namespace group {

class GroupObject;

} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group;

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
namespace packets {

class MessageCallback;

} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace wearables {

class ArmorObject;

} // namespace wearables
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::wearables;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObject;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/player/PlayerMap.h"

#include "server/zone/managers/player/CharacterNameMap.h"

#include "server/zone/managers/player/StartingItemList.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/managers/player/StartingLocationList.h"

#include "server/zone/managers/player/StartingLocation.h"

#include "engine/log/Logger.h"

#include "engine/lua/Lua.h"

#include "system/util/VectorMap.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Vector3.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerManager : public Observer {
public:
	PlayerManager(ZoneServer* zoneServer, ZoneProcessServer* impl);

	void loadNameMap();

	void sendStartingLocationsTo(PlayerCreature* player);

	StartingLocation* getStartingLocation(const String& city);

	bool kickUser(const String& name, const String& admin);

	bool createPlayer(MessageCallback* callback);

	bool checkPlayerName(MessageCallback* callback);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	int notifyDestruction(TangibleObject* destructor, TangibleObject* destructedObject, int condition);

	int notifyDefendersOfIncapacitation(TangibleObject* destructor, TangibleObject* destructedObject);

	void killPlayer(TangibleObject* attacker, PlayerCreature* player);

	byte calculateIncapacitationTimer(PlayerCreature* player, int condition);

	bool checkEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void applyEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void removeEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void awardBadge(PlayerCreature* player, unsigned int badge);

	void setExperienceMultiplier(float globalMultiplier);

	void awardExperience(PlayerCreature* player, const String& xpType, int amount, bool sendSystemMessage = true, float localMultiplier = 1.0f);

	void handleAbortTradeMessage(PlayerCreature* player, bool doLock = true);

	void handleAddItemToTradeWindow(PlayerCreature* player, unsigned long long itemID);

	void handleGiveMoneyMessage(PlayerCreature* player, unsigned int value);

	void handleAcceptTransactionMessage(PlayerCreature* player);

	void handleUnAcceptTransactionMessage(PlayerCreature* player);

	void handleVerifyTradeMessage(PlayerCreature* player);

	bool checkTradeItems(PlayerCreature* player, PlayerCreature* receiver);

	SceneObject* getInRangeStructureWithAdminRights(CreatureObject* creature, unsigned long long targetID = 0);

	void sendBattleFatigueMessage(PlayerCreature* player, PlayerCreature* target);

	int getMedicalFacilityRating(CreatureObject* creature);

	void stopWatch(CreatureObject* creature, unsigned long long entid, bool doSendPackets = true, bool forced = false, bool doLock = true, bool outOfRange = false);

	void stopListen(CreatureObject* creature, unsigned long long entid, bool doSendPackets = true, bool forced = false, bool doLock = true, bool outOfRange = false);

	void startWatch(CreatureObject* creature, unsigned long long entid);

	void startListen(CreatureObject* creature, unsigned long long entid);

	int healEnhance(CreatureObject* enhancer, CreatureObject* patient, byte attribute, int buffvalue, float duration);

	void disseminateExperience(TangibleObject* destructedObject, DamageMap* damageMap);

	bool squadLeaderCheck(PlayerCreature* player, GroupObject* group);

	void awardSquadLeaderExperience(GroupObject* group, int amount, TangibleObject* source);

	void sendMessageOfTheDay(PlayerCreature* player);

	void sendActivateCloneRequest(PlayerCreature* player);

	void sendPlayerToCloner(PlayerCreature* player, unsigned long long clonerID);

	bool checkExistentNameInDatabase(const String& firstName);

	TangibleObject* createHairObject(const String& hairObjectFile, const String& hairCustomization);

	bool createAllPlayerObjects(PlayerCreature* player);

	void createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile);

	void createTutorialBuilding(PlayerCreature* player);

	void createSkippedTutorialBuilding(PlayerCreature* player);

	int checkSpeedHackFirstTest(PlayerCreature* player, float parsedSpeed, ValidatedPosition& teleportPosition, float errorMultiplier = 1);

	int checkSpeedHackSecondTest(PlayerCreature* player, float newX, float newZ, float newY, unsigned int newStamp, SceneObject* newParent = NULL);

	bool existsName(const String& name);

	unsigned long long getObjectID(const String& name);

	PlayerCreature* getPlayer(const String& name);

	void updateAdminLevel(PlayerCreature* player, const String& targetName, int adminLevel = 1);

	void generateHologrindProfessions(PlayerCreature* player);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PlayerManager(DummyConstructorParameter* param);

	virtual ~PlayerManager();

	friend class PlayerManagerHelper;
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerManagerImplementation : public ObserverImplementation, public Logger {
	ManagedReference<ZoneProcessServer* > processor;

	ManagedWeakReference<ZoneServer* > server;

	Reference<PlayerMap* > playerMap;

	Reference<CharacterNameMap* > nameMap;

	float globalExpMultiplier;

public:
	Reference<StartingItemList* > startingItemList;

private:
	StartingLocationList startingLocationList;

public:
	PlayerManagerImplementation(ZoneServer* zoneServer, ZoneProcessServer* impl);

	PlayerManagerImplementation(DummyConstructorParameter* param);

	void loadNameMap();

private:
	void loadStartingItems();

	void loadStartingLocations();

public:
	void finalize();

	void sendStartingLocationsTo(PlayerCreature* player);

	StartingLocation* getStartingLocation(const String& city);

	bool kickUser(const String& name, const String& admin);

	bool createPlayer(MessageCallback* callback);

	bool checkPlayerName(MessageCallback* callback);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	int notifyDestruction(TangibleObject* destructor, TangibleObject* destructedObject, int condition);

	int notifyDefendersOfIncapacitation(TangibleObject* destructor, TangibleObject* destructedObject);

	void killPlayer(TangibleObject* attacker, PlayerCreature* player);

	byte calculateIncapacitationTimer(PlayerCreature* player, int condition);

	bool checkEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void applyEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void removeEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void awardBadge(PlayerCreature* player, unsigned int badge);

	void setExperienceMultiplier(float globalMultiplier);

	void awardExperience(PlayerCreature* player, const String& xpType, int amount, bool sendSystemMessage = true, float localMultiplier = 1.0f);

	void handleAbortTradeMessage(PlayerCreature* player, bool doLock = true);

	void handleAddItemToTradeWindow(PlayerCreature* player, unsigned long long itemID);

	void handleGiveMoneyMessage(PlayerCreature* player, unsigned int value);

	void handleAcceptTransactionMessage(PlayerCreature* player);

	void handleUnAcceptTransactionMessage(PlayerCreature* player);

	void handleVerifyTradeMessage(PlayerCreature* player);

	bool checkTradeItems(PlayerCreature* player, PlayerCreature* receiver);

	SceneObject* getInRangeStructureWithAdminRights(CreatureObject* creature, unsigned long long targetID = 0);

	void sendBattleFatigueMessage(PlayerCreature* player, PlayerCreature* target);

	int getMedicalFacilityRating(CreatureObject* creature);

	void stopWatch(CreatureObject* creature, unsigned long long entid, bool doSendPackets = true, bool forced = false, bool doLock = true, bool outOfRange = false);

	void stopListen(CreatureObject* creature, unsigned long long entid, bool doSendPackets = true, bool forced = false, bool doLock = true, bool outOfRange = false);

	void startWatch(CreatureObject* creature, unsigned long long entid);

	void startListen(CreatureObject* creature, unsigned long long entid);

	int healEnhance(CreatureObject* enhancer, CreatureObject* patient, byte attribute, int buffvalue, float duration);

	void disseminateExperience(TangibleObject* destructedObject, DamageMap* damageMap);

	bool squadLeaderCheck(PlayerCreature* player, GroupObject* group);

	void awardSquadLeaderExperience(GroupObject* group, int amount, TangibleObject* source);

	void sendMessageOfTheDay(PlayerCreature* player);

	void sendActivateCloneRequest(PlayerCreature* player);

	void sendPlayerToCloner(PlayerCreature* player, unsigned long long clonerID);

	bool checkExistentNameInDatabase(const String& firstName);

	TangibleObject* createHairObject(const String& hairObjectFile, const String& hairCustomization);

	bool createAllPlayerObjects(PlayerCreature* player);

	void createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile);

	void createTutorialBuilding(PlayerCreature* player);

	void createSkippedTutorialBuilding(PlayerCreature* player);

	int checkSpeedHackFirstTest(PlayerCreature* player, float parsedSpeed, ValidatedPosition& teleportPosition, float errorMultiplier = 1);

	int checkSpeedHackSecondTest(PlayerCreature* player, float newX, float newZ, float newY, unsigned int newStamp, SceneObject* newParent = NULL);

	bool existsName(const String& name);

	unsigned long long getObjectID(const String& name);

	PlayerCreature* getPlayer(const String& name);

	void updateAdminLevel(PlayerCreature* player, const String& targetName, int adminLevel = 1);

	void generateHologrindProfessions(PlayerCreature* player);

	PlayerManager* _this;

	operator const PlayerManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PlayerManagerImplementation();

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

	friend class PlayerManager;
};

class PlayerManagerAdapter : public ObserverAdapter {
public:
	PlayerManagerAdapter(PlayerManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadNameMap();

	void finalize();

	bool kickUser(const String& name, const String& admin);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	int notifyDestruction(TangibleObject* destructor, TangibleObject* destructedObject, int condition);

	int notifyDefendersOfIncapacitation(TangibleObject* destructor, TangibleObject* destructedObject);

	void killPlayer(TangibleObject* attacker, PlayerCreature* player);

	byte calculateIncapacitationTimer(PlayerCreature* player, int condition);

	bool checkEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void applyEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void removeEncumbrancies(PlayerCreature* player, ArmorObject* armor);

	void awardBadge(PlayerCreature* player, unsigned int badge);

	void setExperienceMultiplier(float globalMultiplier);

	void awardExperience(PlayerCreature* player, const String& xpType, int amount, bool sendSystemMessage, float localMultiplier);

	void handleAbortTradeMessage(PlayerCreature* player, bool doLock);

	void handleAddItemToTradeWindow(PlayerCreature* player, unsigned long long itemID);

	void handleGiveMoneyMessage(PlayerCreature* player, unsigned int value);

	void handleAcceptTransactionMessage(PlayerCreature* player);

	void handleUnAcceptTransactionMessage(PlayerCreature* player);

	void handleVerifyTradeMessage(PlayerCreature* player);

	bool checkTradeItems(PlayerCreature* player, PlayerCreature* receiver);

	SceneObject* getInRangeStructureWithAdminRights(CreatureObject* creature, unsigned long long targetID);

	void sendBattleFatigueMessage(PlayerCreature* player, PlayerCreature* target);

	int getMedicalFacilityRating(CreatureObject* creature);

	void stopWatch(CreatureObject* creature, unsigned long long entid, bool doSendPackets, bool forced, bool doLock, bool outOfRange);

	void stopListen(CreatureObject* creature, unsigned long long entid, bool doSendPackets, bool forced, bool doLock, bool outOfRange);

	void startWatch(CreatureObject* creature, unsigned long long entid);

	void startListen(CreatureObject* creature, unsigned long long entid);

	int healEnhance(CreatureObject* enhancer, CreatureObject* patient, byte attribute, int buffvalue, float duration);

	bool squadLeaderCheck(PlayerCreature* player, GroupObject* group);

	void awardSquadLeaderExperience(GroupObject* group, int amount, TangibleObject* source);

	void sendMessageOfTheDay(PlayerCreature* player);

	void sendActivateCloneRequest(PlayerCreature* player);

	void sendPlayerToCloner(PlayerCreature* player, unsigned long long clonerID);

	bool checkExistentNameInDatabase(const String& firstName);

	TangibleObject* createHairObject(const String& hairObjectFile, const String& hairCustomization);

	bool createAllPlayerObjects(PlayerCreature* player);

	void createDefaultPlayerItems(PlayerCreature* player, const String& profession, const String& templateFile);

	void createTutorialBuilding(PlayerCreature* player);

	void createSkippedTutorialBuilding(PlayerCreature* player);

	int checkSpeedHackSecondTest(PlayerCreature* player, float newX, float newZ, float newY, unsigned int newStamp, SceneObject* newParent);

	bool existsName(const String& name);

	unsigned long long getObjectID(const String& name);

	PlayerCreature* getPlayer(const String& name);

	void updateAdminLevel(PlayerCreature* player, const String& targetName, int adminLevel);

	void generateHologrindProfessions(PlayerCreature* player);

protected:
	String _param0_kickUser__String_String_;
	String _param1_kickUser__String_String_;
	String _param1_awardExperience__PlayerCreature_String_int_bool_float_;
	String _param0_checkExistentNameInDatabase__String_;
	String _param0_createHairObject__String_String_;
	String _param1_createHairObject__String_String_;
	String _param1_createDefaultPlayerItems__PlayerCreature_String_String_;
	String _param2_createDefaultPlayerItems__PlayerCreature_String_String_;
	String _param0_existsName__String_;
	String _param0_getObjectID__String_;
	String _param0_getPlayer__String_;
	String _param1_updateAdminLevel__PlayerCreature_String_int_;
};

class PlayerManagerHelper : public DistributedObjectClassHelper, public Singleton<PlayerManagerHelper> {
	static PlayerManagerHelper* staticInitializer;

public:
	PlayerManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerManagerHelper>;
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

#endif /*PLAYERMANAGER_H_*/
