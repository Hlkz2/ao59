#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"


enum Spells {
	SPELL_PC   = 39089,
    SPELL_MB   = 19659,
	SPELL_AE   = 35124,
	SPELL_AE2  = 37106 };

enum Events {
    EVENT_PC   = 1,
    EVENT_MB   = 2,
    EVENT_AE   = 3,
    EVENT_AE2  = 4 };

class lecteur : public CreatureScript {
    public: lecteur() : CreatureScript("lecteur") {}
        struct lecteurAI : public BossAI
        {
            lecteurAI(Creature* creature) : BossAI(creature, creature->GetGUID()) {}

void EnterCombat(Unit* victim)
{
    ScriptedAI::EnterCombat(victim);
    events.ScheduleEvent(EVENT_PC, 10000);
	events.ScheduleEvent(EVENT_MB, 15000);
	events.ScheduleEvent(EVENT_AE, 5000);
}

void UpdateAI(const uint32 diff)
{
	if (!UpdateVictim())
		return;
	events.Update(diff);

	if (!HealthAbovePct(20)) {
		events.ScheduleEvent(EVENT_AE2, 0);
		return; }

	if (me->HasUnitState(UNIT_STATE_CASTING))
		return;

    while (uint32 eventId = events.ExecuteEvent())
    {
        switch (eventId)
        {
            case EVENT_PC:
                DoCast(me, SPELL_PC);
                events.ScheduleEvent(EVENT_PC, 10000);
                break;
            case EVENT_MB:
				DoCast(me, SPELL_MB);
                events.ScheduleEvent(EVENT_MB, 15000);
                break;
            case EVENT_AE:
				DoCast(me, SPELL_AE);
                events.ScheduleEvent(EVENT_AE, 5000);
                break;
            case EVENT_AE2:
				me->InterruptNonMeleeSpells(true);
				DoCast(me, SPELL_AE2);
                break;
            default:
                break;
        }
    }

    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        { return new lecteurAI (creature); }
};

void AddSC_lecteur() { new lecteur(); }
