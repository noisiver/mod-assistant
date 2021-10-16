#ifndef ASSISTANTDATA_H
#define ASSISTANTDATA_H

struct SpawnPoints
{
    uint32 MapId;
    float X;
    float Y;
    float Z;
    float O;
};

struct TalentRanks
{
    int32 ClassId;
    uint32 SpellId;
    uint32 RequiredLevel;
    uint32 RequiredSpellId;
};

struct Proficiencies
{
    int32 ClassId;
    uint32 SpellId;
    uint32 RequiredLevel;
};

struct Mounts
{
    int32 RaceId;
    int32 ClassId;
    int32 TeamId;
    uint32 SpellId;
    uint32 RequiredLevel;
    uint32 RequiredSpellId;
    uint32 RequiresQuest;
};

class AssistantData
{
    public:
        std::vector<SpawnPoints> GetSpawnPoints();
        std::vector<TalentRanks> GetTalentRanks();
        int GetTalentRankCount();
        std::vector<Proficiencies> GetProficiencies();
        int GetProficiencyCount();
        std::vector<Mounts> GetMounts();
        int GetMountsCount();
};

#endif
