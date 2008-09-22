/*
 *	server/zone/objects/scene/SceneObject.h generated by engine3 IDL compiler 0.55
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/StandaloneBaseMessage.h"

#include "engine/util/QuadTreeEntry.h"

#include "../../ZoneProcessServerImplementation.h"

class ObjectMenuResponse;

class Zone;

class ZoneClientSession;

class Player;

class CreatureObject;

class BuildingObject;

#include "engine/core/ManagedObject.h"

class SceneObject : public ManagedObject {
public:
	bool destroy();

	void redeploy();

	void scheduleUndeploy();

	void removeUndeploymentEvent();

	void sendTo(Player* player, bool doClose = true);

	void sendDestroyTo(Player* player);

	void sendRadialResponseTo(Player* player, ObjectMenuResponse* omr);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	void close(ZoneClientSession* client);

	bool isInRange(SceneObject* obj, float range);

	bool isInRange(float x, float y, float range);

	int inRangeObjectCount();

	QuadTreeEntry* getInRangeObject(int idx);

	void addInRangeObject(QuadTreeEntry* obj, bool notifyUpdate = true);

	void removeInRangeObject(QuadTreeEntry* obj);

	bool isInQuadTree();

	QuadTreeEntry* getQuadTreeEntry();

	int compareTo(SceneObject* obj);

	BaseMessage* link(SceneObject* obj);

	void link(ZoneClientSession* client, SceneObject* obj);

	void randomizePosition(float radius);

	int useObject(Player* player);

	void initializePosition(float x, float z, float y);

	void setPosition(float x, float z, float y);

	void setDirection(float x, float z, float y, float w);

	void generateAttributes(Player* player);

	void info(const string& message, bool forcedLog = false);

	void error(const string& message);

	void setZoneProcessServer(ZoneProcessServerImplementation* processor);

	void setObjectID(unsigned long long oid);

	void setObjectCRC(unsigned int crc);

	void setMovementCounter(unsigned int cntr);

	void setZoneIndex(int id);

	void setAssociatedArea(unsigned long long uid);

	void setParent(SceneObject* par, unsigned int linktype = 04);

	void setZone(Zone* zne);

	void clearUndeploymentEvent();

	void insertToZone(Zone* zone);

	void insertToBuilding(BuildingObject* building);

	void removeFromZone(bool doLock = true);

	void removeFromBuilding(BuildingObject* building);

	void broadcastMessage(BaseMessage* msg, int range = 128, bool doLock = true);

	void broadcastMessage(StandaloneBaseMessage* msg, int range = 128, bool doLock = true);

	bool isUndeploymentScheduled();

	int getObjectType();

	unsigned long long getObjectID();

	unsigned int getObjectCRC();

	unsigned int getMovementCounter();

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	int getDirectionAngle();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	string& getLoggingName();

	unsigned long long getAssociatedArea();

	bool isPlayer();

	bool isNonPlayerCreature();

	bool isBuilding();

	bool isCell();

	bool isTangible();

	bool isIntangible();

	bool isStatic();

	bool isShip();

	bool isAttackableObject();

	bool isMission();

	bool isPlayerObject();

	bool isWaypoint();

	bool isManufactureSchematic();

	Zone* getZone();

	int getZoneID();

	SceneObject* getParent();

	unsigned long long getParentID();

	bool isMoving();

	void switchMovingState();

	bool doKeepObject();

	void setCombatState();

	void clearCombatState(bool removedefenders = true);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefenders();

	void removeDefender(SceneObject* defender);

	bool hasDefender(SceneObject* defender);

	SceneObject* getDefender(int idx);

	unsigned int getDefenderListSize();

	bool isPeaced();

	bool isAttackableBy(CreatureObject* creature);

	bool isInANoBuildArea();

protected:
	SceneObject(DummyConstructorParameter* param);

	virtual ~SceneObject();

	bool _destroy();

	string _return_getLoggingName;

	friend class SceneObjectHelper;
};

class SceneObjectImplementation;

class SceneObjectAdapter : public ManagedObjectAdapter {
public:
	SceneObjectAdapter(SceneObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	bool destroy();

	void redeploy();

	void scheduleUndeploy();

	void removeUndeploymentEvent();

	void sendTo(Player* player, bool doClose);

	void sendDestroyTo(Player* player);

	void sendRadialResponseTo(Player* player, ObjectMenuResponse* omr);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	void close(ZoneClientSession* client);

	bool isInRange(SceneObject* obj, float range);

	bool isInRange(float x, float y, float range);

	int inRangeObjectCount();

	QuadTreeEntry* getInRangeObject(int idx);

	void addInRangeObject(QuadTreeEntry* obj, bool notifyUpdate);

	void removeInRangeObject(QuadTreeEntry* obj);

	bool isInQuadTree();

	QuadTreeEntry* getQuadTreeEntry();

	int compareTo(SceneObject* obj);

	BaseMessage* link(SceneObject* obj);

	void link(ZoneClientSession* client, SceneObject* obj);

	void randomizePosition(float radius);

	int useObject(Player* player);

	void initializePosition(float x, float z, float y);

	void setPosition(float x, float z, float y);

	void setDirection(float x, float z, float y, float w);

	void generateAttributes(Player* player);

	void info(const string& message, bool forcedLog);

	void error(const string& message);

	void setObjectID(unsigned long long oid);

	void setObjectCRC(unsigned int crc);

	void setMovementCounter(unsigned int cntr);

	void setZoneIndex(int id);

	void setAssociatedArea(unsigned long long uid);

	void setParent(SceneObject* par, unsigned int linktype);

	void setZone(Zone* zne);

	void clearUndeploymentEvent();

	void insertToZone(Zone* zone);

	void insertToBuilding(BuildingObject* building);

	void removeFromZone(bool doLock);

	void removeFromBuilding(BuildingObject* building);

	void broadcastMessage(BaseMessage* msg, int range, bool doLock);

	void broadcastMessage(StandaloneBaseMessage* msg, int range, bool doLock);

	bool isUndeploymentScheduled();

	int getObjectType();

	unsigned long long getObjectID();

	unsigned int getObjectCRC();

	unsigned int getMovementCounter();

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	int getDirectionAngle();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	string& getLoggingName();

	unsigned long long getAssociatedArea();

	bool isPlayer();

	bool isNonPlayerCreature();

	bool isBuilding();

	bool isCell();

	bool isTangible();

	bool isIntangible();

	bool isStatic();

	bool isShip();

	bool isAttackableObject();

	bool isMission();

	bool isPlayerObject();

	bool isWaypoint();

	bool isManufactureSchematic();

	Zone* getZone();

	int getZoneID();

	SceneObject* getParent();

	unsigned long long getParentID();

	bool isMoving();

	void switchMovingState();

	bool doKeepObject();

	void setCombatState();

	void clearCombatState(bool removedefenders);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefenders();

	void removeDefender(SceneObject* defender);

	bool hasDefender(SceneObject* defender);

	SceneObject* getDefender(int idx);

	unsigned int getDefenderListSize();

	bool isPeaced();

	bool isAttackableBy(CreatureObject* creature);

	bool isInANoBuildArea();

protected:
	string _param0_info__string_bool_;
	string _param0_error__string_;
};

class SceneObjectHelper : public DistributedObjectClassHelper, public Singleton<SceneObjectHelper> {
	static SceneObjectHelper* staticInitializer;

public:
	SceneObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<SceneObjectHelper>;
};

#include "engine/core/ManagedObjectImplementation.h"

class SceneObjectServant : public ManagedObjectImplementation {
public:
	SceneObject* _this;

public:
	SceneObjectServant();
	virtual ~SceneObjectServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*SCENEOBJECT_H_*/
