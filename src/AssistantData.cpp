#include "AssistantData.h"

std::vector<SpawnPoints> spawnPoints;
std::vector<TalentRanks> talentRanks;
std::vector<Proficiencies> proficiencies;
std::vector<Mounts> mounts;

enum SpellTypes
{
    TYPE_CLASS_SPELLS  = 0,
    TYPE_TALENT_RANKS  = 1,
    TYPE_PROFICIENCIES = 2,
    TYPE_MOUNTS        = 3
};

void LoadSpawnPoints()
{
    QueryResult result = WorldDatabase.Query("SELECT `team_id`, `map_id`, `pos_x`, `pos_y`, `pos_z`, `orientation` FROM `assistant_spawn_points`");

    if (!result)
        return;

    int i = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 TeamId = fields[0].GetUInt32();

        spawnPoints.push_back(SpawnPoints());
        spawnPoints[TeamId].MapId = fields[1].GetUInt32();
        spawnPoints[TeamId].X = fields[2].GetFloat();
        spawnPoints[TeamId].Y = fields[3].GetFloat();
        spawnPoints[TeamId].Z = fields[4].GetFloat();
        spawnPoints[TeamId].O = fields[5].GetFloat();

        i++;
    } while (result->NextRow());

    LOG_INFO("server.loading", ">> Loaded %u spawn points", i);
}

std::vector<SpawnPoints> AssistantData::GetSpawnPoints()
{
    return spawnPoints;
}

void LoadTalentRanks()
{
    QueryResult result = WorldDatabase.PQuery("SELECT `class_id`, `spell_id`, `required_level`, `required_spell_id` FROM `assistant_spells` WHERE `type`=%u ORDER BY `id` ASC", TYPE_TALENT_RANKS);

    if (!result)
        return;

    int i = 0;

    do
    {
        Field* fields = result->Fetch();

        talentRanks.push_back(TalentRanks());
        talentRanks[i].ClassId = fields[0].GetInt32();
        talentRanks[i].SpellId = fields[1].GetUInt32();
        talentRanks[i].RequiredLevel = fields[2].GetUInt32();
        talentRanks[i].RequiredSpellId = fields[3].GetUInt32();

        i++;
    } while (result->NextRow());

    LOG_INFO("server.loading", ">> Loaded %u talent ranks", i);
}

std::vector<TalentRanks> AssistantData::GetTalentRanks()
{
    return talentRanks;
}

int AssistantData::GetTalentRankCount()
{
    return talentRanks.size();
}

void LoadProficiencies()
{
    QueryResult result = WorldDatabase.PQuery("SELECT `class_id`, `spell_id`, `required_level` FROM `assistant_spells` WHERE `type`=%u ORDER BY `id` ASC", TYPE_PROFICIENCIES);

    if (!result)
        return;

    int i = 0;

    do
    {
        Field* fields = result->Fetch();

        proficiencies.push_back(Proficiencies());
        proficiencies[i].ClassId = fields[0].GetInt32();
        proficiencies[i].SpellId = fields[1].GetUInt32();
        proficiencies[i].RequiredLevel = fields[2].GetUInt32();

        i++;
    } while (result->NextRow());

    LOG_INFO("server.loading", ">> Loaded %u proficiency spells", i);
}

std::vector<Proficiencies> AssistantData::GetProficiencies()
{
    return proficiencies;
}

int AssistantData::GetProficiencyCount()
{
    return proficiencies.size();
}

void LoadMounts()
{
    QueryResult result = WorldDatabase.PQuery("SELECT `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `requires_quest` FROM `assistant_spells` WHERE `type`=%u ORDER BY `id` ASC", TYPE_MOUNTS);

    if (!result)
        return;

    int i = 0;

    do
    {
        Field* fields = result->Fetch();

        mounts.push_back(Mounts());
        mounts[i].RaceId = fields[0].GetInt32();
        mounts[i].ClassId = fields[1].GetInt32();
        mounts[i].TeamId = fields[2].GetInt32();
        mounts[i].SpellId = fields[3].GetUInt32();
        mounts[i].RequiredLevel = fields[4].GetUInt32();
        mounts[i].RequiredSpellId = fields[5].GetUInt32();
        mounts[i].RequiresQuest = fields[6].GetUInt32();

        i++;
    } while (result->NextRow());

    LOG_INFO("server.loading", ">> Loaded %u mount spells", i);
}

std::vector<Mounts> AssistantData::GetMounts()
{
    return mounts;
}

int AssistantData::GetMountsCount()
{
    return mounts.size();
}

class AssistantWorldData : public WorldScript
{
    public:
        AssistantWorldData() : WorldScript("AssistantWorldData") { }

        void OnStartup() override
        {
            LOG_INFO("server.loading", "Loading assistant data");
            LoadSpawnPoints();
            LoadTalentRanks();
            LoadProficiencies();
            LoadMounts();
        }
};

void AddAssistantDataScripts()
{
    new AssistantWorldData();
}
