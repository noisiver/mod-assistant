#include "Player.h"
#include "Config.h"

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

                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    player->TeleportTo(0, -8830.438477, 626.666199, 93.982887, 0.682076);
                }
                else if (player->GetTeamId() == TEAM_HORDE)
                {
                    player->TeleportTo(1, 1630.776001,  -4412.993652, 16.567701, 0.080535);
                }
            }
        }
};

void AddSetSpawnPointScripts()
{
    new SetSpawnPoint();
}
