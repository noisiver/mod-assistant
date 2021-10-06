SET
@Entry := 9000000,
@Model := 27822,
@Name  := "Gabriella",
@Title := "The Assistant",
@Icon  := "",
@GossipMenu := 0,
@MinLevel := 30,
@MaxLevel := 30,
@Faction  := 35,
@NPCFlag  := 1,
@Scale    := 1.0,
@Rank     := 0,
@Type     := 7,
@TypeFlags := 0,
@FlagsExtra := 2,
@AIName     := "SmartAI",
@Script     := "npc_assistant";

DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `InhabitType`, `RegenHealth`, `flags_extra`, `AiName`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 3, 1, @FlagsExtra, @AIName, @Script);

DELETE FROM `creature` WHERE `id`=@Entry;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry, @Entry, 0, -8825.05, 649.331, 94.5545, 4.6664); -- Stormwind City
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry+1, @Entry, 1, 1676.62, -4423.69, 18.9152, 2.64126); -- Orgrimmar
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES (@Entry+2, @Entry, 571, 5784.29, 623.186, 647.71, 5.75156); -- Dalaran
