/*
 *	server/zone/objects/tangible/attachment/Attachment.h generated by engine3 IDL compiler 0.60
 */

#ifndef ATTACHMENT_H_
#define ATTACHMENT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

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
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/tangible/wearables/WearableSkillModMap.h"

#include "server/zone/objects/tangible/wearables/WearableSkillMods.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace attachement {

class Attachment : public TangibleObject {
public:
	Attachment();

	void initializeTransientMembers();

	void initializeMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void setSkillModCount(int modCount);

	int getSkillModCount();

	String getSkillModName(int idx);

	int getSkillModValue(int idx);

	int getSkillModValue(String& name);

	void parseSkillModAttributeString(String& attr);

	void addSkillMod(const String& skillModType, int skillModValue);

	bool removeAttachment(PlayerCreature* player);

	void generateSkillMods();

	int getRandomModValue(int luck, int creatureLevel);

	bool isAttachment();

	bool isArmorAttachment();

	bool isClothingAttachment();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	Attachment(DummyConstructorParameter* param);

	virtual ~Attachment();

	String _return_getSkillModName;

	friend class AttachmentHelper;
};

} // namespace attachement
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::attachement;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace attachement {

class AttachmentImplementation : public TangibleObjectImplementation {
protected:
	int maxModifiers;

	int attachmentType;

	VectorMap<String, int> skillModMap;

	Reference<WearableSkillMods* > wearableSkillMods;

	static const int CLOTHINGTYPE = 1;

	static const int ARMORTYPE = 2;

public:
	AttachmentImplementation();

	AttachmentImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void initializeMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void setSkillModCount(int modCount);

	int getSkillModCount();

	String getSkillModName(int idx);

	int getSkillModValue(int idx);

	int getSkillModValue(String& name);

	void parseSkillModAttributeString(String& attr);

	void addSkillMod(const String& skillModType, int skillModValue);

	bool removeAttachment(PlayerCreature* player);

	void generateSkillMods();

	int getRandomModValue(int luck, int creatureLevel);

	bool isAttachment();

	bool isArmorAttachment();

	bool isClothingAttachment();

	Attachment* _this;

	operator const Attachment*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AttachmentImplementation();

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

	friend class Attachment;
};

class AttachmentAdapter : public TangibleObjectAdapter {
public:
	AttachmentAdapter(AttachmentImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void initializeMembers();

	void setSkillModCount(int modCount);

	int getSkillModCount();

	String getSkillModName(int idx);

	int getSkillModValue(int idx);

	int getSkillModValue(String& name);

	void parseSkillModAttributeString(String& attr);

	void addSkillMod(const String& skillModType, int skillModValue);

	bool removeAttachment(PlayerCreature* player);

	void generateSkillMods();

	int getRandomModValue(int luck, int creatureLevel);

	bool isAttachment();

	bool isArmorAttachment();

	bool isClothingAttachment();

protected:
	String _param0_getSkillModValue__String_;
	String _param0_parseSkillModAttributeString__String_;
	String _param0_addSkillMod__String_int_;
};

class AttachmentHelper : public DistributedObjectClassHelper, public Singleton<AttachmentHelper> {
	static AttachmentHelper* staticInitializer;

public:
	AttachmentHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AttachmentHelper>;
};

} // namespace attachement
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::attachement;

#endif /*ATTACHMENT_H_*/
