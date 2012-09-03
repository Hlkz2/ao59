
    SPELL_RAGING_SPIRIT                 = 69200,
    SPELL_RAGING_SPIRIT_VISUAL          = 69197,
    SPELL_RAGING_SPIRIT_VISUAL_CLONE    = 69198,
	
class npc_raging_spirit : public CreatureScript
{
    public:
        npc_raging_spirit() : CreatureScript("npc_raging_spirit") { }

        struct npc_raging_spiritAI : public ScriptedAI
        {
            npc_raging_spiritAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_SOUL_SHRIEK, urand(12000, 15000));
                DoCast(me, SPELL_PLAGUE_AVOIDANCE, true);
                DoCast(me, SPELL_RAGING_SPIRIT_VISUAL, true);
                if (TempSummon* summon = me->ToTempSummon())
                    if (Unit* summoner = summon->GetSummoner())
                        summoner->CastSpell(me, SPELL_RAGING_SPIRIT_VISUAL_CLONE, true);
                DoCast(me, SPELL_BOSS_HITTIN_YA, true);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                // player is the spellcaster so register summon manually
                if (Creature* lichKing = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING)))
                    lichKing->AI()->JustSummoned(me);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* lichKing = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING)))
                    lichKing->AI()->SummonedCreatureDespawn(me);
                if (TempSummon* summon = me->ToTempSummon())
                    summon->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SOUL_SHRIEK:
                            DoCastAOE(SPELL_SOUL_SHRIEK);
                            _events.ScheduleEvent(EVENT_SOUL_SHRIEK, urand(12000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_raging_spiritAI>(creature);
        }
};