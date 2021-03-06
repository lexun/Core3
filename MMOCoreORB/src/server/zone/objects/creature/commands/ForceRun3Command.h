/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#ifndef FORCERUN3COMMAND_H_
#define FORCERUN3COMMAND_H_

#include "server/zone/objects/creature/buffs/PrivateSkillMultiplierBuff.h"
#include "JediQueueCommand.h"

class ForceRun3Command : public JediQueueCommand {
public:

	ForceRun3Command(const String& name, ZoneProcessServer* server)
	: JediQueueCommand(name, server) {
		// BuffCRC's, first one is used.
		buffCRCs.add(BuffCRC::JEDI_FORCE_RUN_3);
		buffCRCs.add(BuffCRC::JEDI_FORCE_RUN_2);
		buffCRCs.add(BuffCRC::JEDI_FORCE_RUN_1);

		skillMods.put("force_run", 3);
		skillMods.put("slope_move", 99);
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		int res = doJediSelfBuffCommand(creature);

		if (res != SUCCESS) {
			return res;
		}

		// need to apply the damage reduction in a separate buff so that the multiplication and division applies right
		Buff* buff = creature->getBuff(BuffCRC::JEDI_FORCE_RUN_3);
		if (buff == NULL)
			return GENERALERROR;

		ManagedReference<PrivateSkillMultiplierBuff*> multBuff = new PrivateSkillMultiplierBuff(creature, name.hashCode(), duration, BuffType::JEDI);
		multBuff->setSkillModifier("private_damage_multiplier", 19);
		multBuff->setSkillModifier("private_damage_divisor", 20);

		creature->addBuff(multBuff);
		buff->addSecondaryBuffCRC(multBuff->getBuffCRC());

		if (creature->hasBuff(String("burstrun").hashCode()) || creature->hasBuff(String("retreat").hashCode())) {
			creature->removeBuff(String("burstrun").hashCode());
			creature->removeBuff(String("retreat").hashCode());
		}

		return SUCCESS;
	}

};

#endif //FORCERUN3COMMAND_H_
