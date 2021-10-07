SET
@Entry := 9000000,
@Model := 27822,
@Name  := "Gabriella",
@Title := "The Assistant",
@Icon  := "Speak",
@GossipMenu := 0,
@MinLevel := 30,
@MaxLevel := 30,
@Faction  := 35,
@NPCFlag  := 129,
@Scale    := 1.0,
@Rank     := 0,
@Type     := 7,
@TypeFlags := 0,
@FlagsExtra := 2,
@AIName     := "SmartAI",
@Script     := "npc_assistant";

-- Creature template
DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `InhabitType`, `RegenHealth`, `flags_extra`, `AiName`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 3, 1, @FlagsExtra, @AIName, @Script);

-- Spawn points for Stormwind, Orgrimmar and Dalaran
DELETE FROM `creature` WHERE `id`=@Entry;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, @Entry, 0, -8825.05, 649.331, 94.5545, 4.6664); -- Stormwind City
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry+1, @Entry, 1, 1676.62, -4423.69, 18.9152, 2.64126); -- Orgrimmar
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry+2, @Entry, 571, 5784.29, 623.186, 647.71, 5.75156); -- Dalaran

-- Heirloom: Weapon
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42943);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42944);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42945);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42946);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42947);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 42948);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44091);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44092);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44093);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44094);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44095);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 44096);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 48716);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry, 48718);

-- Heirloom: Armor
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42949);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42950);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42951);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42952);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42984);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42985);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42991);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 42992);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44097);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44098);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44099);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44100);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44101);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44102);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44103);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44105);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 44107);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48677);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48683);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48685);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48687);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48689);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 48691);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+1, 50255);

-- Heirloom: Other
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+2, 49177);
