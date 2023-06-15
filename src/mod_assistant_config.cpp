#include "mod_assistant.h"

void Assistant::OnAfterConfigLoad(bool /*reload*/)
{
    // Vendors
    EnableHeirlooms = sConfigMgr->GetOption<bool>("Assistant.Heirlooms", 1);
    EnableGlyphs = sConfigMgr->GetOption<bool>("Assistant.Glyphs", 1);
    EnableGems = sConfigMgr->GetOption<bool>("Assistant.Gems", 1);
    EnableContainers = sConfigMgr->GetOption<bool>("Assistant.Containers", 1);

    // Utilities
    EnableUtilities = sConfigMgr->GetOption<bool>("Assistant.Utilities", 1);
    CostNameChange = sConfigMgr->GetOption<uint32>("Assistant.Utilities.NameChange", 10) * 10000;
    CostCustomization = sConfigMgr->GetOption<uint32>("Assistant.Utilities.Customization", 50) * 10000;
    CostRaceChange = sConfigMgr->GetOption<uint32>("Assistant.Utilities.RaceChange", 500) * 10000;
    CostFactionChange = sConfigMgr->GetOption<uint32>("Assistant.Utilities.FactionChange", 1000) * 10000;

    // Professions
    EnableApprenticeProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Apprentice.Enabled", 1);
    EnableJourneymanProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Journeyman.Enabled", 1);
    EnableExpertProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Expert.Enabled", 1);
    EnableArtisanProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Artisan.Enabled", 1);
    EnableMasterProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.Master.Enabled", 0);
    EnableGrandMasterProfession = sConfigMgr->GetOption<bool>("Assistant.Professions.GrandMaster.Enabled", 0);
    CostApprenticeProfession = sConfigMgr->GetOption<uint32>("Assistant.Professions.Apprentice.Cost", 100);
    CostJourneymanProfession = sConfigMgr->GetOption<uint32>("Assistant.Professions.Journeyman.Cost", 250);
    CostExpertProfession = sConfigMgr->GetOption<uint32>("Assistant.Professions.Expert.Cost", 500);
    CostArtisanProfession = sConfigMgr->GetOption<uint32>("Assistant.Professions.Artisan.Cost", 750);
    CostMasterProfession = sConfigMgr->GetOption<uint32>("Assistant.Professions.Master.Cost", 1250);
    CostGrandMasterProfession = sConfigMgr->GetOption<uint32>("Assistant.Professions.GrandMaster.Cost", 2500);

    // Flight Paths
    EnableFlightPaths[0] = sConfigMgr->GetOption<bool>("Assistant.FlightPaths.Vanilla.Enabled", 1);
    EnableFlightPaths[1] = sConfigMgr->GetOption<bool>("Assistant.FlightPaths.BurningCrusade.Enabled", 1);
    EnableFlightPaths[2] = sConfigMgr->GetOption<bool>("Assistant.FlightPaths.WrathOfTheLichKing.Enabled", 0);
    RequiredLevelForFlightPaths[0] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.Vanilla.RequiredLevel", 60);
    RequiredLevelForFlightPaths[1] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.BurningCrusade.RequiredLevel", 70);
    RequiredLevelForFlightPaths[2] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.WrathOfTheLichKing.RequiredLevel", 80);
    CostFlightPaths[0] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.Vanilla.Cost", 10);
    CostFlightPaths[1] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.BurningCrusade.Cost", 25);
    CostFlightPaths[2] = sConfigMgr->GetOption<uint32>("Assistant.FlightPaths.WrathOfTheLichKing.Cost", 75);
}
