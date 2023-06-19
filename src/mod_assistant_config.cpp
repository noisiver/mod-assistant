#include "mod_assistant.h"

void Assistant::OnAfterConfigLoad(bool /*reload*/)
{
    // Vendors
    HeirloomsEnabled = sConfigMgr->GetOption<bool>("Assistant.Heirlooms.Enabled", 1);
    GlyphsEnabled = sConfigMgr->GetOption<bool>("Assistant.Glyphs.Enabled", 1);
    GemsEnabled = sConfigMgr->GetOption<bool>("Assistant.Gems.Enabled", 1);
    ContainersEnabled = sConfigMgr->GetOption<bool>("Assistant.Containers.Enabled", 1);

    // Utilities
    UtilitiesEnabled = sConfigMgr->GetOption<bool>("Assistant.Utilities.Enabled", 1);
    NameChangeCost = sConfigMgr->GetOption<uint32>("Assistant.Utilities.NameChange.Cost", 100000);
    CustomizeCost = sConfigMgr->GetOption<uint32>("Assistant.Utilities.Customize.Cost", 500000);
    RaceChangeCost = sConfigMgr->GetOption<uint32>("Assistant.Utilities.RaceChange.Cost", 5000000);
    FactionChangeCost = sConfigMgr->GetOption<uint32>("Assistant.Utilities.FactionChange.Cost", 10000000);

    // Flight Paths
    FlightPathsEnabled[EXPANSION_CLASSIC] = sConfigMgr->GetOption<bool>("Assistant.FlightPaths.Vanilla.Enabled", 1);
    FlightPathsRequiredLevel[EXPANSION_CLASSIC] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.Vanilla.RequiredLevel", 60);
    FlightPathsCost[EXPANSION_CLASSIC] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.Vanilla.Cost", 250000);
    FlightPathsEnabled[EXPANSION_THE_BURNING_CRUSADE] = sConfigMgr->GetOption<bool>("Assistant.FlightPaths.BurningCrusade.Enabled", 1);
    FlightPathsRequiredLevel[EXPANSION_THE_BURNING_CRUSADE] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.BurningCrusade.RequiredLevel", 70);
    FlightPathsCost[EXPANSION_THE_BURNING_CRUSADE] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.BurningCrusade.Cost", 1000000);
    FlightPathsEnabled[EXPANSION_WRATH_OF_THE_LICH_KING] = sConfigMgr->GetOption<bool>("Assistant.FlightPaths.WrathOfTheLichKing.Enabled", 0);
    FlightPathsRequiredLevel[EXPANSION_WRATH_OF_THE_LICH_KING] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.WrathOfTheLichKing.RequiredLevel", 80);
    FlightPathsCost[EXPANSION_WRATH_OF_THE_LICH_KING] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.WrathOfTheLichKing.Cost", 2500000);

    // Professions
    ApprenticeProfessionEnabled = sConfigMgr->GetOption<bool>("Assistant.Professions.Apprentice.Enabled", 1);
    ApprenticeProfessionCost = sConfigMgr->GetOption<uint32>("Assistant.Professions.Apprentice.Cost", 1000000);
    JourneymanProfessionEnabled = sConfigMgr->GetOption<bool>("Assistant.Professions.Journeyman.Enabled", 1);
    JourneymanProfessionCost = sConfigMgr->GetOption<uint32>("Assistant.Professions.Journeyman.Cost", 2500000);
    ExpertProfessionEnabled = sConfigMgr->GetOption<bool>("Assistant.Professions.Expert.Enabled", 1);
    ExpertProfessionCost = sConfigMgr->GetOption<uint32>("Assistant.Professions.Expert.Cost", 5000000);
    ArtisanProfessionEnabled = sConfigMgr->GetOption<bool>("Assistant.Professions.Artisan.Enabled", 1);
    ArtisanProfessionCost = sConfigMgr->GetOption<uint32>("Assistant.Professions.Artisan.Cost", 7500000);
    MasterProfessionEnabled = sConfigMgr->GetOption<bool>("Assistant.Professions.Master.Enabled", 0);
    MasterProfessionCost = sConfigMgr->GetOption<uint32>("Assistant.Professions.Master.Cost", 12500000);
    GrandMasterProfessionEnabled = sConfigMgr->GetOption<bool>("Assistant.Professions.GrandMaster.Enabled", 0);
    GrandMasterProfessionCost = sConfigMgr->GetOption<uint32>("Assistant.Professions.GrandMaster.Cost", 25000000);
}
