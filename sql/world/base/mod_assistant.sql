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

-- Class spells, talent ranks, proficiencies and mounts
DROP TABLE IF EXISTS `assistant_spells`;
CREATE TABLE `assistant_spells` (
    `id` INT(11) NOT NULL AUTO_INCREMENT,
    `type` INT NOT NULL,
    `race_id` INT NOT NULL,
    `class_id` INT NOT NULL,
    `team_id` INT NOT NULL DEFAULT -1,
    `spell_id` INT NOT NULL,
    `required_level` INT NOT NULL,
    `required_spell_id` INT NOT NULL DEFAULT -1,
    `requires_quest` INT NOT NULL DEFAULT 0,
    `comment` CHAR(50) NULL DEFAULT '',
    PRIMARY KEY (`race_id`, `class_id`, `spell_id`),
    INDEX `id` (`id`) USING BTREE
)
COMMENT='Class spells, talent ranks, proficiencies and mounts for Assistant'
COLLATE='utf8mb4_general_ci';

-- Talents: Warrior
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 21551, 48, 12294, 'Mortal Strike Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 21552, 54, 21551, 'Mortal Strike Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 21553, 60, 21552, 'Mortal Strike Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 25248, 66, 21553, 'Mortal Strike Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 30330, 70, 25248, 'Mortal Strike Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 47485, 75, 30330, 'Mortal Strike Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 47486, 80, 47485, 'Mortal Strike Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 30016, 60, 20243, 'Devastate Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 30022, 70, 30016, 'Devastate Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 47497, 75, 30022, 'Devastate Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 1, -1, 47498, 80, 47497, 'Devastate Rank 5');
-- Talents: Paladin
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 20929, 48, 20473, 'Holy Shock Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 20930, 56, 20929, 'Holy Shock Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 27174, 64, 20930, 'Holy Shock Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 33072, 70, 27174, 'Holy Shock Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 48824, 75, 33072, 'Holy Shock Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 48825, 80, 48824, 'Holy Shock Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 25899, 60, 20911, 'Greater Blessing of Sanctuary');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 20927, 50, 20925, 'Holy Shield Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 20928, 60, 20927, 'Holy Shield Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 27179, 70, 20928, 'Holy Shield Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 48951, 75, 27179, 'Holy Shield Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 48952, 80, 48951, 'Holy Shield Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 32699, 60, 31935, 'Avenger\'s Shield Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 32700, 70, 32699, 'Avenger\'s Shield Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 48826, 75, 32700, 'Avenger\'s Shield Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 2, -1, 48827, 80, 48826, 'Avenger\'s Shield Rank 5');
-- Talents: Hunter
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20900, 28, 19434, 'Aimed Shot Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20901, 36, 20900, 'Aimed Shot Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20902, 44, 20901, 'Aimed Shot Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20903, 52, 20902, 'Aimed Shot Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20904, 60, 20903, 'Aimed Shot Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 27065, 70, 20904, 'Aimed Shot Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 49049, 75, 27065, 'Aimed Shot Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 49050, 80, 49049, 'Aimed Shot Rank 9');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20909, 42, 19306, 'Counterattack Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 20910, 54, 20909, 'Counterattack Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 27067, 66, 20910, 'Counterattack Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 48998, 72, 27067, 'Counterattack Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 48999, 78, 48998, 'Counterattack Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 24132, 50, 19386, 'Wyvern Sting Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 24133, 60, 24132, 'Wyvern Sting Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 27068, 70, 24133, 'Wyvern Sting Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 49011, 75, 27068, 'Wyvern Sting Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 49012, 80, 49011, 'Wyvern Sting Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 63668, 57, 3674, 'Black Arrow Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 63669, 63, 63668, 'Black Arrow Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 63670, 69, 63669, 'Black Arrow Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 63671, 75, 63670, 'Black Arrow Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 63672, 80, 63671, 'Black Arrow Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 60051, 70, 53301, 'Explosive Shot Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 60052, 75, 60051, 'Explosive Shot Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 3, -1, 60053, 80, 60052, 'Explosive Shot Rank 4');
-- Talents: Rogue
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 34411, 50, 1329, 'Mutilate Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 34412, 60, 34411, 'Mutilate Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 34413, 70, 34412, 'Mutilate Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 48663, 75, 34413, 'Mutilate Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 48666, 80, 48663, 'Mutilate Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 17347, 46, 16511, 'Hemorrhage Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 17348, 58, 17347, 'Hemorrhage Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 26864, 70, 17348, 'Hemorrhage Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 4, -1, 48660, 80, 26864, 'Hemorrhage Rank 5');
-- Talents: Priest
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 53005, 70, 47540, 'Penance Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 53006, 75, 53005, 'Penance Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 53007, 80, 53006, 'Penance Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 19238, 26, 19236, 'Desperate Prayer Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 19240, 34, 19238, 'Desperate Prayer Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 19241, 42, 19240, 'Desperate Prayer Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 19242, 50, 19241, 'Desperate Prayer Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 19243, 58, 19242, 'Desperate Prayer Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 25437, 66, 19243, 'Desperate Prayer Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48172, 73, 25437, 'Desperate Prayer Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48173, 80, 48172, 'Desperate Prayer Rank 9');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 27870, 50, 724, 'Lightwell Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 27871, 60, 27870, 'Lightwell Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 28275, 70, 27871, 'Lightwell Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48086, 75, 28275, 'Lightwell Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48087, 80, 48086, 'Lightwell Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 34863, 56, 34861, 'Circle of Healing Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 34864, 60, 34863, 'Circle of Healing Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 34865, 65, 34864, 'Circle of Healing Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 34866, 70, 34865, 'Circle of Healing Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48088, 75, 34866, 'Circle of Healing Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48089, 80, 48088, 'Circle of Healing Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 17311, 28, 15407, 'Mind Flay Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 17312, 36, 17311, 'Mind Flay Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 17313, 44, 17312, 'Mind Flay Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 17314, 52, 17313, 'Mind Flay Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 18807, 60, 17314, 'Mind Flay Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 25387, 68, 18807, 'Mind Flay Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48155, 74, 25387, 'Mind Flay Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48156, 80, 48155, 'Mind Flay Rank 9');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 34916, 60, 34914, 'Vampiric Touch Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 34917, 70, 34916, 'Vampiric Touch Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48159, 75, 34917, 'Vampiric Touch Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 5, -1, 48160, 80, 48159, 'Vampiric Touch Rank 5');
-- Talents: Death Knight
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55258, 59, 55050, 'Heart Strike Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55259, 64, 55258, 'Heart Strike Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55260, 69, 55259, 'Heart Strike Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55261, 74, 55260, 'Heart Strike Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55262, 80, 55261, 'Heart Strike Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51416, 60, 49143, 'Frost Strike Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51417, 65, 51416, 'Frost Strike Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51418, 70, 51417, 'Frost Strike Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51419, 75, 51418, 'Frost Strike Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55268, 80, 51419, 'Frost Strike Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51409, 70, 49184, 'Howling Blast Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51410, 75, 51409, 'Howling Blast Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51411, 80, 51410, 'Howling Blast Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51325, 60, 49158, 'Corpse Explosion Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51326, 70, 51325, 'Corpse Explosion Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51327, 75, 51326, 'Corpse Explosion Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 51328, 80, 51327, 'Corpse Explosion Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55265, 67, 55090, 'Scourge Strike Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55270, 73, 55265, 'Scourge Strike Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 6, -1, 55271, 79, 55270, 'Scourge Strike Rank 4');
-- Talents: Shaman
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 57720, 60, 30706, 'Totem of Wrath Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 57721, 70, 57720, 'Totem of Wrath Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 57722, 80, 57721, 'Totem of Wrath Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 59156, 70, 51490, 'Thunderstorm Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 59158, 75, 59156, 'Thunderstorm Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 59159, 80, 59158, 'Thunderstorm Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 32593, 60, 974, 'Earth Shield Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 32594, 70, 32593, 'Earth Shield Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 49283, 75, 32594, 'Earth Shield Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 49284, 80, 49283, 'Earth Shield Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 61299, 70, 61295, 'Riptide Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 61300, 75, 61299, 'Riptide Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 7, -1, 61301, 80, 61300, 'Riptide Rank 4');
-- Talents: Mage
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 44780, 70, 44425, 'Arcane Barrage Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 44781, 80, 44780, 'Arcane Barrage Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 12505, 24, 11366, 'Pyroblast Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 12522, 30, 12505, 'Pyroblast Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 12523, 36, 12522, 'Pyroblast Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 12524, 42, 12523, 'Pyroblast Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 12525, 48, 12524, 'Pyroblast Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 12526, 54, 12525, 'Pyroblast Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 18809, 60, 12526, 'Pyroblast Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 27132, 66, 18809, 'Pyroblast Rank 9');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 33938, 70, 27132, 'Pyroblast Rank 10');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 42890, 73, 33938, 'Pyroblast Rank 11');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 42891, 77, 42890, 'Pyroblast Rank 12');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13018, 36, 11113, 'Blast Wave Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13019, 44, 13018, 'Blast Wave Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13020, 52, 13019, 'Blast Wave Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13021, 60, 13020, 'Blast Wave Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 27133, 65, 13021, 'Blast Wave Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 33933, 70, 27133, 'Blast Wave Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 42944, 75, 33933, 'Blast Wave Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 42945, 80, 42944, 'Blast Wave Rank 9');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 33041, 56, 31661, 'Dragon\'s Breath Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 33042, 64, 33041, 'Dragon\'s Breath Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 33043, 70, 33042, 'Dragon\'s Breath Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 42949, 75, 33043, 'Dragon\'s Breath Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 42950, 80, 42949, 'Dragon\'s Breath Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 55359, 70, 44457, 'Living Bomb Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 55360, 80, 55359, 'Living Bomb Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13031, 46, 11426, 'Ice Barrier Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13032, 52, 13031, 'Ice Barrier Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 13033, 58, 13032, 'Ice Barrier Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 27134, 64, 13033, 'Ice Barrier Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 33405, 70, 27134, 'Ice Barrier Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 43038, 75, 33405, 'Ice Barrier Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 8, -1, 43039, 80, 43038, 'Ice Barrier Rank 8');
-- Talents: Warlock
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18937, 50, 18220, 'Dark Pact Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18938, 60, 18937, 'Dark Pact Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 27265, 70, 18938, 'Dark Pact Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59092, 80, 27265, 'Dark Pact Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 30404, 60, 30108, 'Unstable Affliction Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 30405, 70, 30404, 'Unstable Affliction Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 47841, 75, 30405, 'Unstable Affliction Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 47843, 80, 47841, 'Unstable Affliction Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59161, 70, 48181, 'Haunt Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59163, 75, 59161, 'Haunt Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59164, 80, 59163, 'Haunt Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18867, 24, 17877, 'Shadowburn Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18868, 32, 18867, 'Shadowburn Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18869, 40, 18868, 'Shadowburn Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18870, 48, 18869, 'Shadowburn Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 18871, 56, 18870, 'Shadowburn Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 27263, 63, 18871, 'Shadowburn Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 30546, 70, 27263, 'Shadowburn Rank 8');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 47826, 75, 30546, 'Shadowburn Rank 9');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 47827, 80, 47826, 'Shadowburn Rank 10');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 30413, 60, 30283, 'Shadowfury Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 30414, 70, 30413, 'Shadowfury Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 47846, 75, 30414, 'Shadowfury Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 47847, 80, 47846, 'Shadowfury Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59170, 70, 50796, 'Chaos Bolt Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59171, 75, 59170, 'Chaos Bolt Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 9, -1, 59172, 80, 59171, 'Chaos Bolt Rank 4');
-- Talents: Druid
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 24974, 30, 5570, 'Insect Swarm Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 24975, 40, 24974, 'Insect Swarm Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 24976, 50, 24975, 'Insect Swarm Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 24977, 60, 24976, 'Insect Swarm Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 27013, 70, 24977, 'Insect Swarm Rank 6');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 48468, 80, 27013, 'Insect Swarm Rank 7');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53223, 60, 50516, 'Typhoon Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53225, 70, 53223, 'Typhoon Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53226, 75, 53225, 'Typhoon Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 61384, 80, 53226, 'Typhoon Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53199, 70, 48505, 'Starfall Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53200, 75, 53199, 'Starfall Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53201, 80, 53200, 'Starfall Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 33986, 58, 33878, 'Mangle (Bear) Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 33987, 68, 33986, 'Mangle (Bear) Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 48563, 75, 33987, 'Mangle (Bear) Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 48564, 80, 48563, 'Mangle (Bear) Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 33982, 58, 33876, 'Mangle (Cat) Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 33983, 68, 33982, 'Mangle (Cat) Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 48565, 75, 33983, 'Mangle (Cat) Rank 4');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 48566, 80, 48565, 'Mangle (Cat) Rank 5');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53248, 70, 48438, 'Wild Growth Rank 2');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53249, 75, 53248, 'Wild Growth Rank 3');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (1, -1, 11, -1, 53251, 80, 53249, 'Wild Growth Rank 4');
-- Proficiencies: Warrior
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 196, 0, -1, 'One-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 197, 0, -1, 'Two-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 199, 0, -1, 'Two-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 200, 0, -1, 'Polearms');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 202, 0, -1, 'Two-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 264, 0, -1, 'Bows');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 266, 0, -1, 'Guns');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 5011, 0, -1, 'Crossbows');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 15590, 0, -1, 'Fist Weapons');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 3127, 6, -1, 'Parry');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 674, 20, -1, 'Dual Wield');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 1, -1, 750, 40, -1, 'Plate Mail');
-- Proficiencies: Paladin
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 196, 0, -1, 'One-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 197, 0, -1, 'Two-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 199, 0, -1, 'Two-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 200, 0, -1, 'Polearms');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 202, 0, -1, 'Two-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 3127, 8, -1, 'Parry');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 2, -1, 750, 40, -1, 'Plate Mail');
-- Proficiencies: Hunter
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 196, 0, -1, 'One-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 197, 0, -1, 'Two-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 200, 0, -1, 'Polearms');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 202, 0, -1, 'Two-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 264, 0, -1, 'Bows');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 266, 0, -1, 'Guns');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 5011, 0, -1, 'Crossbows');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 15590, 0, -1, 'Fist Weapons');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 3127, 8, -1, 'Parry');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 674, 20, -1, 'Dual Wield');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 3, -1, 8737, 40, -1, 'Mail');
-- Proficiencies: Rogue
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 196, 0, -1, 'One-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 264, 0, -1, 'Bows');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 266, 0, -1, 'Guns');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 5011, 0, -1, 'Crossbows');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 15590, 0, -1, 'Fist Weapons');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 674, 10, -1, 'Dual Wield');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 4, -1, 3127, 12, -1, 'Parry');
-- Proficiencies: Priest
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 5, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 5, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 5, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 5, -1, 5009, 0, -1, 'Wands');
-- Proficiencies: Death Knight
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 196, 0, -1, 'One-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 197, 0, -1, 'Two-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 199, 0, -1, 'Two-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 200, 0, -1, 'Polearms');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 202, 0, -1, 'Two-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 3127, 12, -1, 'Parry');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 674, 20, -1, 'Dual Wield');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 6, -1, 750, 40, -1, 'Plate Mail');
-- Proficiencies: Shaman
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 196, 0, -1, 'One-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 197, 0, -1, 'Two-Handed Axes');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 199, 0, -1, 'Two-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 674, 0, -1, 'Dual Wield');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 15590, 0, -1, 'Fist Weapons');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 7, -1, 8737, 40, -1, 'Mail');
-- Proficiencies: Mage
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 8, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 8, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 8, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 8, -1, 5009, 0, -1, 'Wands');
-- Proficiencies: Warlock
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 9, -1, 201, 0, -1, 'One-Handed Swords');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 9, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 9, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 9, -1, 5009, 0, -1, 'Wands');
-- Proficiencies: Druid
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 11, -1, 198, 0, -1, 'One-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 11, -1, 199, 0, -1, 'Two-Handed Maces');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 11, -1, 200, 0, -1, 'Polearms');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 11, -1, 227, 0, -1, 'Staves');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 11, -1, 1180, 0, -1, 'Daggers');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_Spell_id`, `comment`) VALUES (2, -1, 11, -1, 15590, 0, -1, 'Fist Weapons');
-- Mounts: Riding
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, -1, 33388, 20, -1, 'Apprentice Riding');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, -1, 33391, 40, 33388, 'Journeyman Riding');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, -1, 34090, 60, 33391, 'Expert Riding');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, -1, 34091, 70, 34090, 'Artisan Riding');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, -1, 54197, 77, 34090, 'Cold Weather Flying');
-- Mounts: Human
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, -1, 0, 458, 20, 33388, 'Brown Horse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, -1, 0, 472, 20, 33388, 'Pinto');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, -1, 0, 6648, 20, 33388, 'Chestnut Mare');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, -1, 0, 23227, 40, 33391, 'Swift Palomino');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, -1, 0, 23228, 40, 33391, 'Swift White Steed');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, -1, 0, 23229, 40, 33391, 'Swift Brown Steed');
-- Mounts: Orc
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 580, 20, 33388, 'Timber Wolf');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 6653, 20, 33388, 'Dire Wolf');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 6654, 20, 33388, 'Brown Wolf');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 64658, 20, 33388, 'Black Wolf');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 23250, 40, 33391, 'Swift Brown Wolf');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 23251, 40, 33391, 'Swift Timber Wolf');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 2, -1, 1, 23252, 40, 33391, 'Swift Gray Wolf');
-- Mounts: Dwarf
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, -1, 0, 6777, 20, 33388, 'Gray Ram');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, -1, 0, 6898, 20, 33388, 'White Ram');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, -1, 0, 6899, 20, 33388, 'Brown Ram');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, -1, 0, 23238, 40, 33391, 'Swift Brown Ram');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, -1, 0, 23239, 40, 33391, 'Swift Gray Ram');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, -1, 0, 23240, 40, 33391, 'Swift White Ram');
-- Mounts: Night Elf
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 8394, 20, 33388, 'Striped Frostsaber');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 10789, 20, 33388, 'Spotted Frostsaber');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 10793, 20, 33388, 'Striped Nightsaber');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 66847, 20, 33388, 'Striped Dawnsaber');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 23219, 40, 33391, 'Swift Mistsaber');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 23221, 40, 33391, 'Swift Frostsaber');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 4, -1, 0, 23338, 40, 33391, 'Swift Stormsaber');
-- Mounts: Undead
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 17462, 20, 33388, 'Red Skeletal Horse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 17463, 20, 33388, 'Blue Skeletal Horse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 17464, 20, 33388, 'Brown Skeletal Horse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 64977, 20, 33388, 'Black Skeletal Horse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 17465, 40, 33391, 'Green Skeletal Warhorse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 23246, 40, 33391, 'Purple Skeletal Warhorse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 5, -1, 1, 66846, 40, 33391, 'Ochre Skeletal Warhorse');
-- Mounts: Tauren
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 6, -1, 1, 18989, 20, 33388, 'Gray Kodo');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 6, -1, 1, 18990, 20, 33388, 'Brown Kodo');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 6, -1, 1, 64657, 20, 33388, 'White Kodo');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 6, -1, 1, 23247, 40, 33391, 'Great White Kodo');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 6, -1, 1, 23248, 40, 33391, 'Great Gray Kodo');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 6, -1, 1, 23249, 40, 33391, 'Great Brown Kodo');
-- Mounts: Gnome
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 10873, 20, 33388, 'Red Mechanostrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 10969, 20, 33388, 'Blue Mechanostrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 17453, 20, 33388, 'Green Mechanostrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 17454, 20, 33388, 'Unpainted Mechanostrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 23222, 40, 33391, 'Swift Yellow Mechanostrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 23223, 40, 33391, 'Swift White Mechanostrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 7, -1, 0, 23225, 40, 33391, 'Swift Green Mechanostrider');
-- Mounts: Troll
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 8, -1, 1, 8395, 20, 33388, 'Emerald Raptor');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 8, -1, 1, 10796, 20, 33388, 'Turquoise Raptor');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 8, -1, 1, 10799, 20, 33388, 'Violet Raptor');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 8, -1, 1, 23241, 40, 33391, 'Swift Blue Raptor');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 8, -1, 1, 23242, 40, 33391, 'Swift Olive Raptor');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 8, -1, 1, 23243, 40, 33391, 'Swift Orange Raptor');
-- Mounts: Blood Elf
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 34795, 20, 33388, 'Red Hawkstrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 35018, 20, 33388, 'Purple Hawkstrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 35020, 20, 33388, 'Blue Hawkstrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 35022, 20, 33388, 'Black Hawkstrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 33660, 40, 33391, 'Swift Pink Hawkstrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 35025, 40, 33391, 'Swift Green Hawkstrider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, -1, 1, 35027, 40, 33391, 'Swift Purple Hawkstrider');
-- Mounts: Draenei
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, -1, 0, 34406, 20, 33388, 'Brown Elekk');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, -1, 0, 35710, 20, 33388, 'Gray Elekk');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, -1, 0, 35711, 20, 33388, 'Purple Elekk');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, -1, 0, 35712, 40, 33391, 'Great Green Elekk');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, -1, 0, 35713, 40, 33391, 'Great Blue Elekk');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, -1, 0, 35714, 40, 33391, 'Great Purple Elekk');
-- Mounts: Alliance
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32239, 60, 34090, 'Ebon Gryphon');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32240, 60, 34090, 'Snowy Gryphon');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32235, 60, 34090, 'Golden Gryphon');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32289, 70, 34091, 'Swift Red Gryphon');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32290, 70, 34091, 'Swift Green Gryphon');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32242, 70, 34091, 'Swift Blue Gryphon');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 0, 32292, 70, 34091, 'Swift Purple Gryphon');
-- Mounts: Horde
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32243, 60, 34090, 'Tawny Wind Rider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32244, 60, 34090, 'Blue Wind Rider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32245, 60, 34090, 'Green Wind Rider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32246, 70, 34091, 'Swift Red Wind Rider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32295, 70, 34091, 'Swift Green Wind Rider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32296, 70, 34091, 'Swift Yellow Wind Rider');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, -1, 1, 32297, 70, 34091, 'Swift Purple Wind Rider');
-- Mounts: Paladin
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 10, 2, 1, 13819, 20, 33388, 'Warhorse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `requires_quest`, `comment`) VALUES (3, 10, 2, 1, 34767, 40, 33391, 1, 'Charger');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 1, 2, 0, 34769, 20, 33388, 'Summon Warhorse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 3, 2, 0, 34769, 20, 33388, 'Summon Warhorse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, 11, 2, 0, 34769, 20, 33388, 'Summon Warhorse');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `requires_quest`, `comment`) VALUES (3, 1, 2, 0, 23214, 40, 33391, 1, 'Summon Charger');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `requires_quest`, `comment`) VALUES (3, 3, 2, 0, 23214, 40, 33391, 1, 'Summon Charger');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `requires_quest`, `comment`) VALUES (3, 11, 2, 0, 23214, 40, 33391, 1, 'Summon Charger');
-- Mounts: Death Knight
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, 6, -1, 48778, 60, 33391, 'Acherus Deathcharger');
-- Mounts: Warlock
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `comment`) VALUES (3, -1, 9, -1, 5784, 20, 33388, 'Felsteed');
INSERT INTO `assistant_spells` (`type`, `race_id`, `class_id`, `team_id`, `spell_id`, `required_level`, `required_spell_id`, `requires_quest`, `comment`) VALUES (3, -1, 9, -1, 23161, 40, 33391, 1, 'Dreadsteed');

-- Spawn points
DROP TABLE IF EXISTS `assistant_spawn_points`;
CREATE TABLE `assistant_spawn_points` (
    `team_id` INT NOT NULL,
    `map_id` INT NOT NULL,
    `pos_x` FLOAT NOT NULL,
    `pos_y` FLOAT NOT NULL,
    `pos_z` FLOAT NOT NULL,
    `orientation` FLOAT NOT NULL,
    `comment` CHAR(50) NULL DEFAULT '',
    PRIMARY KEY (`team_id`)
)
COMMENT='Spawn points for Assistant'
COLLATE='utf8mb4_general_ci';

INSERT INTO `assistant_spawn_points` (`team_id`, `map_id`, `pos_x`, `pos_y`, `pos_z`, `orientation`, `comment`) VALUES (0, 0, -8830.44, 626.666, 93.9829, 0.682076, 'Alliance - Stormwind City');
INSERT INTO `assistant_spawn_points` (`team_id`, `map_id`, `pos_x`, `pos_y`, `pos_z`, `orientation`, `comment`) VALUES (1, 1, 1630.78, -4412.99, 16.5677, 0.080535, 'Horde - Orgrimmar');

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

-- Glyph: Warrior (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43412, 43413, 43414, 43415, 43416, 43417, 43418, 43419, 43420, 43421, 43422, 43423, 43424, 43425, 43426, 43427, 43428, 43429, 43430, 43431, 43432, 45790, 45792, 45793, 45794, 45795, 45797);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43412);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43413);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43416);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43417);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43418);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43419);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43420);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43421);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43422);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43423);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43424);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43425);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43426);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43427);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43428);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43429);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43430);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43431);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 43432);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45790);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45792);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45793);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45794);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45795);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+3, 45797);
-- Glyph: Paladin (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41092, 41094, 41095, 41096, 41097, 41098, 41099, 41100, 41101, 41102, 41103, 41104, 41105, 41106, 41107, 41108, 41109, 41110, 43867, 43868, 43869, 45741, 45742, 45743, 45744, 45745, 45746, 45747);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41092);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41094);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41095);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41096);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41097);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41098);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41099);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41100);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41101);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41102);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41103);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41104);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41105);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41106);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41107);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41108);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41109);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 41110);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43867);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43868);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 43869);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45743);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45744);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45745);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45746);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+4, 45747);
-- Glyph: Hunter (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42897, 42898, 42899, 42900, 42901, 42902, 42903, 42904, 42905, 42906, 42907, 42908, 42909, 42910, 42911, 42912, 42913, 42914, 42915, 42916, 42917, 45625, 45731, 45732, 45733, 45734, 45735);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42898);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42900);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42902);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42904);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42905);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42907);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42910);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42911);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42916);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 42917);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45625);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45731);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45732);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45733);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45734);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+5, 45735);
-- Glyph: Rogue (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42954, 42955, 42956, 42957, 42958, 42959, 42960, 42961, 42962, 42963, 42964, 42965, 42966, 42967, 42968, 42969, 42970, 42971, 42972, 42973, 42974, 45761, 45762, 45764, 45766, 45767, 45768, 45769);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42954);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42956);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42957);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42958);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42959);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42960);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42961);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42962);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42963);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42964);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42965);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42966);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42967);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42968);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42969);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42970);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42971);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42972);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42973);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 42974);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45761);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45762);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45764);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45766);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45767);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45768);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+6, 45769);
-- Glyph: Priest (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42396, 42397, 42398, 42399, 42400, 42401, 42402, 42403, 42404, 42405, 42406, 42407, 42408, 42409, 42410, 42411, 42412, 42414, 42415, 42416, 42417, 45753, 45755, 45756, 45757, 45758, 45760);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42402);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42403);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42404);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42405);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42406);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42407);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42408);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42409);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42410);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42411);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42412);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42414);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42415);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42416);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 42417);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45753);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45755);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45756);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45757);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45758);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+7, 45760);
-- Glyph: Death Knight (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43533, 43534, 43536, 43537, 43538, 43541, 43542, 43543, 43545, 43546, 43547, 43548, 43549, 43550, 43551, 43552, 43553, 43554, 43825, 43826, 43827, 45799, 45800, 45803, 45804, 45805, 45806);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43536);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43537);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43538);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43543);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43545);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43546);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43547);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43548);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43549);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43550);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43551);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43552);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43553);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43554);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43825);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43826);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 43827);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45799);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45800);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45803);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45804);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45805);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+8, 45806);
-- Glyph: Shaman (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41517, 41518, 41524, 41526, 41527, 41529, 41530, 41531, 41532, 41533, 41534, 41535, 41536, 41537, 41538, 41539, 41540, 41541, 41542, 41547, 41552, 45770, 45771, 45772, 45775, 45776, 45777, 45778);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41517);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41518);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41524);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41526);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41527);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41529);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41530);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41531);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41532);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41533);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41534);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41536);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41537);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41538);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41540);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41541);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41542);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41547);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 41552);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45770);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45771);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45772);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45775);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45776);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45777);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+9, 45778);
-- Glyph: Mage (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42734, 42735, 42736, 42737, 42738, 42739, 42740, 42741, 42742, 42743, 42744, 42745, 42746, 42747, 42748, 42749, 42750, 42751, 42752, 42753, 42754, 44684, 44955, 45736, 45737, 45738, 45739, 45740, 50045);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42734);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42735);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42738);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42740);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42741);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42743);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42744);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42745);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42746);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42747);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42748);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42749);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42750);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42751);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42752);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42753);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 42754);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 44684);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 44955);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45736);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45737);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45738);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45739);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 45740);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+10, 50045);
-- Glyph: Warlock (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42453, 42454, 42455, 42456, 42457, 42458, 42459, 42460, 42461, 42462, 42463, 42464, 42465, 42466, 42467, 42468, 42469, 42470, 42471, 42473, 42742, 45779, 45780, 45781, 45782, 45783, 45785, 45789, 50077);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42453);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42454);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42455);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42456);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42457);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42458);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42459);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42460);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42461);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42462);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42463);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42464);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42465);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42466);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42467);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42468);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42469);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42470);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42471);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42473);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 42742);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45779);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45780);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45781);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45782);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45783);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45785);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 45789);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+11, 50077);
-- Glyph: Druid (Major)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40896, 40897, 40899, 40900, 40901, 40902, 40903, 40906, 40908, 40909, 40912, 40913, 40914, 40915, 40916, 40919, 40920, 40921, 40922, 40923, 40924, 44928, 45601, 45602, 45603, 45604, 45622, 45623, 46372, 48720, 50125);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40896);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40897);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40899);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40900);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40901);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40902);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40903);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40906);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40908);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40909);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40912);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40913);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40914);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40915);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40916);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40919);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40920);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40921);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40922);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40923);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 40924);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 44928);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45601);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45602);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45603);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45604);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45622);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 45623);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 46372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 48720);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+12, 50125);
-- Glyph: Warrior (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43395, 43396, 43397, 43398, 43399, 43400, 49084);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43399);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 43400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+13, 49084);
-- Glyph: Paladin (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43340, 43365, 43366, 43367, 43368, 43369);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43340);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43365);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43366);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43367);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43368);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+14, 43369);
-- Glyph: Hunter (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43338, 43350, 43351, 43354, 43355, 43356);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43338);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43350);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43351);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43354);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43355);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+15, 43356);
-- Glyph: Rogue (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43343, 43376, 43377, 43378, 43379, 43380);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43343);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+16, 43380);
-- Glyph: Priest (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43342, 43370, 43371, 43372, 43373, 43374);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43342);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43370);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43371);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43372);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43373);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+17, 43374);
-- Glyph: Death Knight (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43535, 43539, 43544, 43671, 43672, 43673);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43535);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43539);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43544);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43671);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43672);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+18, 43673);
-- Glyph: Shaman (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43344, 43381, 43385, 43386, 43388, 43725, 44923);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43344);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43386);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43388);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 43725);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+19, 44923);
-- Glyph: Mage (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43339, 43357, 43359, 43360, 43361, 43362, 43364, 44920);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43357);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43359);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43360);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43361);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43362);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 43364);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+20, 44920);
-- Glyph: Warlock (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43389, 43390, 43391, 43392, 43393, 43394);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43390);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43391);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43392);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43393);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+21, 43394);
-- Glyph: Druid (Minor)
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43316, 43331, 43332, 43334, 43335, 43674, 44922);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43316);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43331);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43332);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43334);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 43674);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+22, 44922);

-- Gem: Meta
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41285, 41307, 41333, 41335, 41339, 41375, 41376, 41377, 41378, 41379, 41380, 41381, 41382, 41385, 41389, 41395, 41396, 41397, 41398, 41400, 41401);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41285);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41307);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41333);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41335);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41339);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41375);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41376);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41377);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41378);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41379);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41380);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41381);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41382);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41385);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41389);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41395);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41396);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41397);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41398);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41400);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 41401);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44076);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44078);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44081);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44082);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44084);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44087);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44088);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+23, 44089);
-- Gem: Red
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40111, 40112, 40113, 40114, 40115, 40116, 40117, 40118, 45862, 45879, 45883);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40111);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40112);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40113);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40114);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40115);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40116);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40117);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 40118);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 45862);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 45879);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+24, 45883);
-- Gem: Blue
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40119, 40120, 40121, 40122, 45880, 45881);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+25;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40119);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40120);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40121);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 40122);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 45880);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+25, 45881);
-- Gem: Yellow
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40123, 40124, 40125, 40126, 40127, 40128, 45882, 45987);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+26;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40123);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40124);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40125);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40126);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40127);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 40128);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 45882);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+26, 45987);
-- Gem: Purple
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40129, 40130, 40131, 40132, 40133, 40134, 40135, 40136, 40137, 40138, 40139, 40140, 40141);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+27;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40129);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40130);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40131);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40132);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40133);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40134);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40135);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40136);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40137);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40138);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40139);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40140);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+27, 40141);
-- Gem: Green
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40164, 40165, 40166, 40167, 40168, 40169, 40170, 40171, 40172, 40173, 40174, 40175, 40176, 40177, 40178, 40179, 40180, 40181, 40182);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+28;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40164);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40165);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40166);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40167);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40168);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40169);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40170);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40171);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40172);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40173);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40174);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40175);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40176);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40177);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40178);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40179);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40180);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40181);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+28, 40182);
-- Gem: Orange
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40156, 40157, 40158, 40159, 40160, 40161, 40162, 40163);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+29;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40142);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40143);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40144);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40145);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40146);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40147);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40148);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40149);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40150);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40151);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40152);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40153);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40154);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40155);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40156);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40157);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40158);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40159);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40160);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40161);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40162);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+29, 40163);

-- Container
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41597, 44447, 44448);
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+30;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 23162);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 41597);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 44447);
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES (@Entry+30, 44448);
