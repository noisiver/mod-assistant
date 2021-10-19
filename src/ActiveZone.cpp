#include "Config.h"

class ActiveZone : public AllCreatureScript
{
    public:
        ActiveZone() : AllCreatureScript("ActiveZone") {}

        void OnAllCreatureUpdate(Creature* creature, uint32 diff) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.Creature.SetActive", 0))
            {
                if (sWorld->getBoolConfig(CONFIG_PRELOAD_ALL_NON_INSTANCED_MAP_GRIDS))
                {
                    if (creature->GetMapId() == 0 || creature->GetMapId() == 1 || creature->GetMapId() == 530 || creature->GetMapId() == 571)
                    {
                        if (sWorld->FindPlayerInZone(creature->GetZoneId()))
                        {
                            if (!creature->isActiveObject())
                                creature->setActive(true);
                        }
                        else
                        {
                            if (creature->isActiveObject())
                                creature->setActive(false);
                        }
                    }
                }
            }
        }
};

void AddActiveZoneScripts()
{
    new ActiveZone();
}
