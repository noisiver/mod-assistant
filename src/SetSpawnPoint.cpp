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

                QueryResult result = WorldDatabase.PQuery("SELECT `map_id`, `pos_x`, `pos_y`, `pos_z`, `orientation` FROM `assistant_spawn_point` WHERE `team_id`=%u", player->GetTeamId());

                if (!result || result->GetRowCount() == 0)
                    return;

                Field* fields = result->Fetch();
                player->TeleportTo(fields[0].GetUInt32(), fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat());
            }
        }
};

void AddSetSpawnPointScripts()
{
    new SetSpawnPoint();
}
