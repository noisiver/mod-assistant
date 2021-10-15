#include "Player.h"
#include "Config.h"

#include "AssistantData.h"

class SetSpawnPoint : public PlayerScript
{
    public:
        SetSpawnPoint() : PlayerScript("SetSpawnPoint") { }

        void OnFirstLogin(Player* player) override
        {
            if (sConfigMgr->GetBoolDefault("Assistant.SpawnPoint.Enabled", 0))
            {
                if (player->getClass() == CLASS_DEATH_KNIGHT && !sConfigMgr->GetBoolDefault("Assistant.SpawnPoint.DeathKnight", 0))
                    return;

                uint32 mapId = assistantData->GetSpawnPoints()[player->GetTeamId()].MapId;
                float x = assistantData->GetSpawnPoints()[player->GetTeamId()].X;
                float y = assistantData->GetSpawnPoints()[player->GetTeamId()].Y;
                float z = assistantData->GetSpawnPoints()[player->GetTeamId()].Z;
                float orientation = assistantData->GetSpawnPoints()[player->GetTeamId()].O;

                player->TeleportTo(mapId, x, y, z, orientation);
            }
        }

    private:
        AssistantData* assistantData = new AssistantData();
};

void AddSetSpawnPointScripts()
{
    new SetSpawnPoint();
}
