SET
@Entry      := 9000000,
@Model      := 27822,
@Name       := "Gabriella",
@Title      := "The Assistant",
@Icon       := "Speak",
@MinLevel   := 30,
@MaxLevel   := 30,
@Faction    := 35,
@NPCFlag    := 129,
@Type       := 7,
@FlagsExtra := 16777218,
@Script     := "npc_assistant";

DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `unit_class`, `unit_flags`, `type`, `flags_extra`, `ScriptName`) VALUES
(@Entry, @Name, @Title, @Icon, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 2, @Type, @FlagsExtra, @Script);

DELETE FROM `creature_template_model` WHERE `CreatureID`=@Entry;
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`) VALUES
(@Entry, 0, @Model, 1, 1);

DELETE FROM `creature` WHERE `id1`=@Entry;
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(@Entry, 0, -8824.65, 649.467, 94.5585, 4.47955), -- Stormwind City
(@Entry, 0, -4956.91, -932.369, 501.66, 4.77523), -- City of Ironforge
(@Entry, 0, 1590.66, 272.521, -55.3428, 0.361283), -- Undercity
(@Entry, 1, 9929.71, 2507.59, 1318.17, 4.78701), -- Darnassus
(@Entry, 1, 1619.08, -4443.65, 10.869, 1.73804), -- Orgrimmar
(@Entry, 1, -1292.12, 116.913, 131.175, 5.78446), -- Thunder Bluff
(@Entry, 530, -3955.07, -11670, -138.757, 3.29082), -- The Exodar
(@Entry, 530, 9469.83, -7294.44, 14.3078, 0.105431), -- Silvermoon City
(@Entry, 530, -1814.49, 5425.97, -12.4281, 2.87456), -- Shattrath City
(@Entry, 571, 5791.71, 560.464, 650.657, 1.79314); -- Dalaran

-- Major Glyphs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43412, 43413, 43414, 43415, 43416, 43417, 43418, 43419, 43420, 43421, 43422, 43423, 43424, 43425, 43426, 43427, 43428, 43429, 43430, 43431, 43432, 45790, 45792, 45793, 45794, 45795, 45797);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41092, 41094, 41095, 41096, 41097, 41098, 41099, 41100, 41101, 41102, 41103, 41104, 41105, 41106, 41107, 41108, 41109, 41110, 43867, 43868, 43869, 45741, 45742, 45743, 45744, 45745, 45746, 45747);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42897, 42898, 42899, 42900, 42901, 42902, 42903, 42904, 42905, 42906, 42907, 42908, 42909, 42910, 42911, 42912, 42913, 42914, 42915, 42916, 42917, 45625, 45731, 45732, 45733, 45734, 45735);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42954, 42955, 42956, 42957, 42958, 42959, 42960, 42961, 42962, 42963, 42964, 42965, 42966, 42967, 42968, 42969, 42970, 42971, 42972, 42973, 42974, 45761, 45762, 45764, 45766, 45767, 45768, 45769);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42396, 42397, 42398, 42399, 42400, 42401, 42402, 42403, 42404, 42405, 42406, 42407, 42408, 42409, 42410, 42411, 42412, 42414, 42415, 42416, 42417, 45753, 45755, 45756, 45757, 45758, 45760);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43533, 43534, 43536, 43537, 43538, 43541, 43542, 43543, 43545, 43546, 43547, 43548, 43549, 43550, 43551, 43552, 43553, 43554, 43825, 43826, 43827, 45799, 45800, 45803, 45804, 45805, 45806);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41517, 41518, 41524, 41526, 41527, 41529, 41530, 41531, 41532, 41533, 41534, 41535, 41536, 41537, 41538, 41539, 41540, 41541, 41542, 41547, 41552, 45770, 45771, 45772, 45775, 45776, 45777, 45778);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42734, 42735, 42736, 42737, 42738, 42739, 42740, 42741, 42742, 42743, 42744, 42745, 42746, 42747, 42748, 42749, 42750, 42751, 42752, 42753, 42754, 44684, 44955, 45736, 45737, 45738, 45739, 45740, 50045);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (42453, 42454, 42455, 42456, 42457, 42458, 42459, 42460, 42461, 42462, 42463, 42464, 42465, 42466, 42467, 42468, 42469, 42470, 42471, 42473, 45779, 45780, 45781, 45782, 45783, 45785, 45789, 50077);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40896, 40897, 40899, 40900, 40901, 40902, 40903, 40906, 40908, 40909, 40912, 40913, 40914, 40915, 40916, 40919, 40920, 40921, 40922, 40923, 40924, 44928, 45601, 45602, 45603, 45604, 45622, 45623, 46372, 48720, 50125);
-- Minor Glyphs
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43395, 43396, 43397, 43398, 43399, 43400, 49084);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43340, 43365, 43366, 43367, 43368, 43369);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43338, 43350, 43351, 43354, 43355, 43356);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43343, 43376, 43377, 43378, 43379, 43380);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43342, 43370, 43371, 43372, 43373, 43374);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43535, 43539, 43544, 43671, 43672, 43673);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43344, 43381, 43385, 43386, 43388, 43725, 44923);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43339, 43357, 43359, 43360, 43361, 43362, 43364, 44920);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43389, 43390, 43391, 43392, 43393, 43394);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (43316, 43331, 43332, 43334, 43335, 43674, 44922);
-- Gems
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (41285, 41307, 41333, 41335, 41339, 41375, 41376, 41377, 41378, 41379, 41380, 41381, 41382, 41385, 41389, 41395, 41396, 41397, 41398, 41400, 41401);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40111, 40112, 40113, 40114, 40115, 40116, 40117, 40118, 45862, 45879, 45883);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40119, 40120, 40121, 40122, 45880, 45881);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40123, 40124, 40125, 40126, 40127, 40128, 45882, 45987);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40129, 40130, 40131, 40132, 40133, 40134, 40135, 40136, 40137, 40138, 40139, 40140, 40141);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40164, 40165, 40166, 40167, 40168, 40169, 40170, 40171, 40172, 40173, 40174, 40175, 40176, 40177, 40178, 40179, 40180, 40181, 40182);
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40156, 40157, 40158, 40159, 40160, 40161, 40162, 40163);
-- Containers
UPDATE `item_template` SET `BuyPrice`=0, `SellPrice`=0 WHERE `entry` IN (1729, 3604, 3605, 22243, 23162);
UPDATE `item_template` SET `maxcount`=0 WHERE `entry`=1729;
-- Gem: Meta 70
UPDATE `item_template` SET `BuyPrice`=300000, `SellPrice`=100000 WHERE `entry` IN (25896, 34220, 25893, 25901, 32640, 25894, 25895, 32409, 28557, 25897, 28556, 25898, 35501, 25890, 32641, 25899, 35503, 32410, 33633);
-- Gem: Red 70
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=100000 WHERE `entry` IN (24027, 24029, 24028, 24030, 24031, 24032, 24036);
UPDATE `item_template` SET `BuyPrice`=200000, `SellPrice`=100000 WHERE `entry` IN (32195, 32194, 35489, 32193, 32198, 35487, 32196, 32197, 32199, 35488);
-- Gem: Blue 70
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=100000 WHERE `entry` IN (24033, 24039, 24035, 24037);
UPDATE `item_template` SET `BuyPrice`=200000, `SellPrice`=100000 WHERE `entry` IN (32200, 32201, 32202, 32203);
-- Gem: Yellow 70
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=100000 WHERE `entry` IN (24047, 24051, 24052, 24050, 24053, 35315, 24048, 31861);
UPDATE `item_template` SET `BuyPrice`=200000, `SellPrice`=100000 WHERE `entry` IN (32205, 32204, 32208, 35761, 32207, 32209, 32206, 32210);
-- Gem: Purple 70
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=100000 WHERE `entry` IN (24057, 24055, 24056, 31865, 35707, 24054, 31863);
UPDATE `item_template` SET `BuyPrice`=200000, `SellPrice`=100000 WHERE `entry` IN (32216, 32213, 37503, 32214, 32212, 32215, 32211);
-- Gem: Green 70
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=100000 WHERE `entry` IN (33782, 24065, 24062, 24066, 24067, 35318);
UPDATE `item_template` SET `BuyPrice`=200000, `SellPrice`=100000 WHERE `entry` IN (32225, 32223, 32224, 32226, 35759, 35758);
-- Gem: Orange 70
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=100000 WHERE `entry` IN (31867, 32637, 31868, 24061, 24058, 24060, 35316);
UPDATE `item_template` SET `BuyPrice`=200000, `SellPrice`=100000 WHERE `entry` IN (32220, 32219, 32222, 35760, 32217, 32221, 32218);
-- Flasks
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=0 WHERE `entry` IN (13512, 13510, 13513);
UPDATE `item_template` SET `BuyPrice`=150000, `SellPrice`=0 WHERE `entry` IN (22866, 22854, 22861, 33208, 22853, 22851);
UPDATE `item_template` SET `BuyPrice`=250000, `SellPrice`=0 WHERE `entry` IN (46376, 46377, 46379, 46378);
-- Enchantments lvl 40-50
UPDATE `item_template` SET `BuyPrice`=5000, `SellPrice`=0 WHERE `entry` IN (7967, 15564, 38837, 10548, 38833, 38847, 38848, 8173, 38825, 38846, 38822, 38829, 38845, 38851, 38832, 38827, 38839, 38841, 38844, 38835, 38849, 38824, 38826, 38828, 38830, 38836, 45628, 38840, 38842);
-- Enchantments lvl 51-60 white/green
UPDATE `item_template` SET `BuyPrice`=30000, `SellPrice`=0 WHERE `entry` IN (11642, 12645, 38854, 38938, 11644, 25650, 11647, 18173, 38857, 11645, 38863, 18172, 18182, 18330, 38860, 11622, 18331, 11646, 11648, 18170, 18329, 38852, 38853, 38859, 18169, 38856, 38861, 38867, 11643, 11649, 18171, 38858, 38862, 38864, 38866, 38881, 38929, 38855);
-- Enchantments lvl 51-60 rare
UPDATE `item_template` SET `BuyPrice`=100000, `SellPrice`=0 WHERE `entry` IN (38880, 38838, 18283, 20077, 19782, 38879, 19783, 38896, 20078, 22638, 38875, 19784, 20076, 19787, 19788, 38872, 22636, 38870, 19785, 38878, 19786, 19789, 19790, 22635, 38869, 18251, 38868, 38871);
UPDATE `item_template` SET `BuyPrice`=300000, `SellPrice`=0 WHERE `entry` IN (38873, 38877);
-- Enchantments lvl 65-70 BC white/green
UPDATE `item_template` SET `BuyPrice`=120000, `SellPrice`=0 WHERE `entry` IN (29534, 29533, 24273, 23764, 38918, 38917, 28888, 34207, 23530, 29192, 29193, 28887, 29191, 29186, 28910, 28912, 38884, 28886, 30846, 29187, 29189, 28909, 38920, 38919, 38946, 28889, 35728, 38947, 28911, 35729, 35730, 35731, 38913, 38933, 38902, 38889, 38895, 38945, 38939, 38882, 38899, 38910, 38944);
-- Enchantments lvl 70 BC rare
UPDATE `item_template` SET `BuyPrice`=400000, `SellPrice`=0 WHERE `entry` IN (38925, 41146, 24274, 23766, 29536, 44497, 24276, 29535, 44453, 23765, 38957, 38948, 38926, 38927, 38922, 38924, 38923, 38998);
-- Enchantments lvl 80 WOTLK white/green
UPDATE `item_template` SET `BuyPrice`=400000, `SellPrice`=0 WHERE `entry` IN (38979, 39006, 39003, 38989, 38975, 44458, 38967, 38986, 39005, 38997, 38984, 38993, 39004, 38978, 38976, 38990, 38964, 38985);
-- Enchantments lvl 80 WOTLK rares
UPDATE `item_template` SET `BuyPrice`=750000, `SellPrice`=0 WHERE `entry` IN (38371, 38372, 44493, 44463, 44466, 44957, 41611, 44137, 44936, 44069, 44879, 44075, 41167, 44067, 44878, 44068,44877, 44131, 44139, 41601, 44138, 44875, 44130, 41603, 44129, 44140, 46026, 44876, 44141, 44132, 46098, 45060, 44884, 44872, 44124, 44880, 38963, 44125, 44881, 44883, 44882, 38992, 38995, 38965, 44467, 45056, 38972, 43987);
-- Enchantments lvl 80 WOTLK epics
UPDATE `item_template` SET `BuyPrice`=1000000, `SellPrice`=0 WHERE `entry` IN (41602, 38374, 41604, 41604, 38373, 44871, 44963, 44874, 44126, 44873);
-- Potions lvl 1-60 Vanilla
UPDATE `item_template` SET `BuyPrice`=5000, `SellPrice`=0 WHERE `entry` IN (9036, 13442, 13457, 13456, 13458, 13446, 13444, 20008);
UPDATE `item_template` SET `BuyPrice`=500, `SellPrice`=0 WHERE `entry` IN (5631);
UPDATE `item_template` SET `BuyPrice`=1000, `SellPrice`=0 WHERE `entry` IN (5633, 2459 ,5634);
-- Potions lvl 60-70 Burning Crusade
UPDATE `item_template` SET `BuyPrice`=20000, `SellPrice`=0 WHERE `entry` IN (22829, 22832, 22838, 22839, 22837, 22849, 22842, 22844, 22845, 22841, 22846);
-- Potions lvl 70-80 WotLK
UPDATE `item_template` SET `BuyPrice`=30000, `SellPrice`=0 WHERE `entry` IN (33447, 33448, 40211, 40212, 40093, 40215, 40217, 40214, 40216, 40213);

-- Heirloom: Weapon
DELETE FROM `npc_vendor` WHERE `entry` BETWEEN @Entry AND @Entry+49;
INSERT INTO `npc_vendor` (`entry`, `item`) VALUES
(@Entry, 42943), -- Bloodied Arcanite Reaper
(@Entry, 42944), -- Balanced Heartseeker
(@Entry, 42945), -- Venerable Dal'Rend's Sacred Charge
(@Entry, 42946), -- Charmed Ancient Bone Bow
(@Entry, 42947), -- Dignified Headmaster's Charge
(@Entry, 42948), -- Devout Aurastone Hammer
(@Entry, 44091), -- Sharpened Scarlet Kris
(@Entry, 44092), -- Reforged Truesilver Champion
(@Entry, 44093), -- Upgraded Dwarven Hand Cannon
(@Entry, 44094), -- The Blessed Hammer of Grace
(@Entry, 44095), -- Grand Staff of Jordan
(@Entry, 44096), -- Battleworn Thrash Blade
(@Entry, 48716), -- Venerable Mass of McGowan
(@Entry, 48718), -- Repurposed Lava Dredger
-- Heirloom: Armor
(@Entry+1, 42949), -- Polished Spaulders of Valor
(@Entry+1, 42950), -- Champion Herod's Shoulder
(@Entry+1, 42951), -- Mystical Pauldrons of Elements
(@Entry+1, 42952), -- Stained Shadowcraft Spaulders
(@Entry+1, 42984), -- Preened Ironfeather Shoulders
(@Entry+1, 42985), -- Tattered Dreadmist Mantle
(@Entry+1, 42991), -- Swift Hand of Justice
(@Entry+1, 42992), -- Discerning Eye of the Beast
(@Entry+1, 44097), -- Inherited Insignia of the Horde
(@Entry+1, 44098), -- Inherited Insignia of the Alliance
(@Entry+1, 44099), -- Strengthened Stockade Pauldrons
(@Entry+1, 44100), -- Pristine Lightforge Spaulders
(@Entry+1, 44101), -- Prized Beastmaster's Mantle
(@Entry+1, 44102), -- Aged Pauldrons of The Five Thunders
(@Entry+1, 44103), -- Exceptional Stormshroud Shoulders
(@Entry+1, 44105), -- Lasting Feralheart Spaulders
(@Entry+1, 44107), -- Exquisite Sunderseer Mantle
(@Entry+1, 48677), -- Champion's Deathdealer Breastplate
(@Entry+1, 48683), -- Mystical Vest of Elements
(@Entry+1, 48685), -- Polished Breastplate of Valor
(@Entry+1, 48687), -- Preened Ironfeather Breastplate
(@Entry+1, 48689), -- Stained Shadowcraft Tunic
(@Entry+1, 48691), -- Tattered Dreadmist Robe
(@Entry+1, 50255), -- Dread Pirate Ring
-- Heirloom: Armor (Custom, requires manual work to create)
(@Entry+1, 100000), -- Signet of the Third Fleet (Secondary Ring)
(@Entry+1, 100001), -- Worn Stoneskin Gargoyle Cloak (Secondary Cloak)
(@Entry+1, 100002), -- Eternal Horizon Choker (Secondary Neckpiece)
(@Entry+1, 100003), -- Stained Shadowcraft Mask (Agility Helm)
(@Entry+1, 100004), -- Stained Shadowcraft Pants (Agility Pants)
(@Entry+1, 100005), -- Helm of Valor (Plate Helm)
(@Entry+1, 100006), -- Legplates of Valor (Plate Pants)
(@Entry+1, 100007), -- Coif of Elements (Mail Helm)
(@Entry+1, 100008), -- Kilt of Elements (Mail Pants)
(@Entry+1, 100009), -- Dreadmist Mask (Cloth Helm)
(@Entry+1, 100010), -- Dreadmist Leggings (Cloth Pants)
(@Entry+1, 100011), -- Wildheart Cowl (Druid Helm)
(@Entry+1, 100012), -- Wildheart Kilt (Druid Pants)
-- Heirloom: Other
(@Entry+2, 49177), -- Tome of Cold Weather Flight
-- Heirloom: Other (Custom, requires manual work to create)
(@Entry+2, 701000), -- Classic Flying Mount
-- Glyph: Warrior (Major)
(@Entry+3, 43412), -- Glyph of Bloodthirst
(@Entry+3, 43413), -- Glyph of Rapid Charge
(@Entry+3, 43414), -- Glyph of Cleaving
(@Entry+3, 43415), -- Glyph of Devastate
(@Entry+3, 43416), -- Glyph of Execution
(@Entry+3, 43417), -- Glyph of Hamstring
(@Entry+3, 43418), -- Glyph of Heroic Strike
(@Entry+3, 43419), -- Glyph of Intervene
(@Entry+3, 43420), -- Glyph of Barbaric Insults
(@Entry+3, 43421), -- Glyph of Mortal Strike
(@Entry+3, 43422), -- Glyph of Overpower
(@Entry+3, 43423), -- Glyph of Rending
(@Entry+3, 43424), -- Glyph of Revenge
(@Entry+3, 43425), -- Glyph of Blocking
(@Entry+3, 43426), -- Glyph of Last Stand
(@Entry+3, 43427), -- Glyph of Sunder Armor
(@Entry+3, 43428), -- Glyph of Sweeping Strikes
(@Entry+3, 43429), -- Glyph of Taunt
(@Entry+3, 43430), -- Glyph of Resonating Power
(@Entry+3, 43431), -- Glyph of Victory Rush
(@Entry+3, 43432), -- Glyph of Whirlwind
(@Entry+3, 45790), -- Glyph of Bladestorm
(@Entry+3, 45792), -- Glyph of Shockwave
(@Entry+3, 45793), -- Glyph of Vigilance
(@Entry+3, 45794), -- Glyph of Enraged Regeneration
(@Entry+3, 45795), -- Glyph of Spell Reflection
(@Entry+3, 45797), -- Glyph of Shield Wall
-- Glyph: Paladin (Major)
(@Entry+4, 41092), -- Glyph of Judgement
(@Entry+4, 41094), -- Glyph of Seal of Command
(@Entry+4, 41095), -- Glyph of Hammer of Justice
(@Entry+4, 41096), -- Glyph of Spiritual Attunement
(@Entry+4, 41097), -- Glyph of Hammer of Wrath
(@Entry+4, 41098), -- Glyph of Crusader Strike
(@Entry+4, 41099), -- Glyph of Consecration
(@Entry+4, 41100), -- Glyph of Righteous Defense
(@Entry+4, 41101), -- Glyph of Avenger's Shield
(@Entry+4, 41102), -- Glyph of Turn Evil
(@Entry+4, 41103), -- Glyph of Exorcism
(@Entry+4, 41104), -- Glyph of Cleansing
(@Entry+4, 41105), -- Glyph of Flash of Light
(@Entry+4, 41106), -- Glyph of Holy Light
(@Entry+4, 41107), -- Glyph of Avenging Wrath
(@Entry+4, 41108), -- Glyph of Divinity
(@Entry+4, 41109), -- Glyph of Seal of Wisdom
(@Entry+4, 41110), -- Glyph of Seal of Light
(@Entry+4, 43867), -- Glyph of Holy Wrath
(@Entry+4, 43868), -- Glyph of Seal of Righteousness
(@Entry+4, 43869), -- Glyph of Seal of Vengeance
(@Entry+4, 45741), -- Glyph of Beacon of Light
(@Entry+4, 45742), -- Glyph of Hammer of the Righteous
(@Entry+4, 45743), -- Glyph of Divine Storm
(@Entry+4, 45744), -- Glyph of Shield of Righteousness
(@Entry+4, 45745), -- Glyph of Divine Plea
(@Entry+4, 45746), -- Glyph of Holy Shock
(@Entry+4, 45747), -- Glyph of Salvation
-- Glyph: Hunter (Major)
(@Entry+5, 42897), -- Glyph of Aimed Shot
(@Entry+5, 42898), -- Glyph of Arcane Shot
(@Entry+5, 42899), -- Glyph of the Beast
(@Entry+5, 42900), -- Glyph of Mending
(@Entry+5, 42901), -- Glyph of Aspect of the Viper
(@Entry+5, 42902), -- Glyph of Bestial Wrath
(@Entry+5, 42903), -- Glyph of Deterrence
(@Entry+5, 42904), -- Glyph of Disengage
(@Entry+5, 42905), -- Glyph of Freezing Trap
(@Entry+5, 42906), -- Glyph of Frost Trap
(@Entry+5, 42907), -- Glyph of Hunter's Mark
(@Entry+5, 42908), -- Glyph of Immolation Trap
(@Entry+5, 42909), -- Glyph of the Hawk
(@Entry+5, 42910), -- Glyph of Multi-Shot
(@Entry+5, 42911), -- Glyph of Rapid Fire
(@Entry+5, 42912), -- Glyph of Serpent Sting
(@Entry+5, 42913), -- Glyph of Snake Trap
(@Entry+5, 42914), -- Glyph of Steady Shot
(@Entry+5, 42915), -- Glyph of Trueshot Aura
(@Entry+5, 42916), -- Glyph of Volley
(@Entry+5, 42917), -- Glyph of Wyvern Sting
(@Entry+5, 45625), -- Glyph of Chimera Shot
(@Entry+5, 45731), -- Glyph of Explosive Shot
(@Entry+5, 45732), -- Glyph of Kill Shot
(@Entry+5, 45733), -- Glyph of Explosive Trap
(@Entry+5, 45734), -- Glyph of Scatter Shot
(@Entry+5, 45735), -- Glyph of Raptor Strike
-- Glyph: Rogue (Major)
(@Entry+6, 42954), -- Glyph of Adrenaline Rush
(@Entry+6, 42955), -- Glyph of Ambush
(@Entry+6, 42956), -- Glyph of Backstab
(@Entry+6, 42957), -- Glyph of Blade Flurry
(@Entry+6, 42958), -- Glyph of Crippling Poison
(@Entry+6, 42959), -- Glyph of Deadly Throw
(@Entry+6, 42960), -- Glyph of Evasion
(@Entry+6, 42961), -- Glyph of Eviscerate
(@Entry+6, 42962), -- Glyph of Expose Armor
(@Entry+6, 42963), -- Glyph of Feint
(@Entry+6, 42964), -- Glyph of Garrote
(@Entry+6, 42965), -- Glyph of Ghostly Strike
(@Entry+6, 42966), -- Glyph of Gouge
(@Entry+6, 42967), -- Glyph of Hemorrhage
(@Entry+6, 42968), -- Glyph of Preparation
(@Entry+6, 42969), -- Glyph of Rupture
(@Entry+6, 42970), -- Glyph of Sap
(@Entry+6, 42971), -- Glyph of Vigor
(@Entry+6, 42972), -- Glyph of Sinister Strike
(@Entry+6, 42973), -- Glyph of Slice and Dice
(@Entry+6, 42974), -- Glyph of Sprint
(@Entry+6, 45761), -- Glyph of Hunger for Blood
(@Entry+6, 45762), -- Glyph of Killing Spree
(@Entry+6, 45764), -- Glyph of Shadow Dance
(@Entry+6, 45766), -- Glyph of Fan of Knives
(@Entry+6, 45767), -- Glyph of Tricks of the Trade
(@Entry+6, 45768), -- Glyph of Mutilate
(@Entry+6, 45769), -- Glyph of Cloak of Shadows
-- Glyph: Priest (Major)
(@Entry+7, 42396), -- Glyph of Circle of Healing
(@Entry+7, 42397), -- Glyph of Dispel Magic
(@Entry+7, 42398), -- Glyph of Fade
(@Entry+7, 42399), -- Glyph of Fear Ward
(@Entry+7, 42400), -- Glyph of Flash Heal
(@Entry+7, 42401), -- Glyph of Holy Nova
(@Entry+7, 42402), -- Glyph of Inner Fire
(@Entry+7, 42403), -- Glyph of Lightwell
(@Entry+7, 42404), -- Glyph of Mass Dispel
(@Entry+7, 42405), -- Glyph of Mind Control
(@Entry+7, 42406), -- Glyph of Shadow Word: Pain
(@Entry+7, 42407), -- Glyph of Shadow
(@Entry+7, 42408), -- Glyph of Power Word: Shield
(@Entry+7, 42409), -- Glyph of Prayer of Healing
(@Entry+7, 42410), -- Glyph of Psychic Scream
(@Entry+7, 42411), -- Glyph of Renew
(@Entry+7, 42412), -- Glyph of Scourge Imprisonment
(@Entry+7, 42414), -- Glyph of Shadow Word: Death
(@Entry+7, 42415), -- Glyph of Mind Flay
(@Entry+7, 42416), -- Glyph of Smite
(@Entry+7, 42417), -- Glyph of Spirit of Redemption
(@Entry+7, 45753), -- Glyph of Dispersion
(@Entry+7, 45755), -- Glyph of Guardian Spirit
(@Entry+7, 45756), -- Glyph of Penance
(@Entry+7, 45757), -- Glyph of Mind Sear
(@Entry+7, 45758), -- Glyph of Hymn of Hope
(@Entry+7, 45760), -- Glyph of Pain Suppression
-- Glyph: Death Knight (Major)
(@Entry+8, 43533), -- Glyph of Anti-Magic Shell
(@Entry+8, 43534), -- Glyph of Heart Strike
(@Entry+8, 43536), -- Glyph of Bone Shield
(@Entry+8, 43537), -- Glyph of Chains of Ice
(@Entry+8, 43538), -- Glyph of Dark Command
(@Entry+8, 43541), -- Glyph of Death Grip
(@Entry+8, 43542), -- Glyph of Death and Decay
(@Entry+8, 43543), -- Glyph of Frost Strike
(@Entry+8, 43545), -- Glyph of Icebound Fortitude
(@Entry+8, 43546), -- Glyph of Icy Touch
(@Entry+8, 43547), -- Glyph of Obliterate
(@Entry+8, 43548), -- Glyph of Plague Strike
(@Entry+8, 43549), -- Glyph of the Ghoul
(@Entry+8, 43550), -- Glyph of Rune Strike
(@Entry+8, 43551), -- Glyph of Scourge Strike
(@Entry+8, 43552), -- Glyph of Strangulate
(@Entry+8, 43553), -- Glyph of Unbreakable Armor
(@Entry+8, 43554), -- Glyph of Vampiric Blood
(@Entry+8, 43825), -- Glyph of Rune Tap
(@Entry+8, 43826), -- Glyph of Blood Strike
(@Entry+8, 43827), -- Glyph of Death Strike
(@Entry+8, 45799), -- Glyph of Dancing Rune Weapon
(@Entry+8, 45800), -- Glyph of Hungering Cold
(@Entry+8, 45803), -- Glyph of Unholy Blight
(@Entry+8, 45804), -- Glyph of Dark Death
(@Entry+8, 45805), -- Glyph of Disease
(@Entry+8, 45806), -- Glyph of Howling Blast
-- Glyph: Shaman (Major)
(@Entry+9, 41517), -- Glyph of Chain Heal
(@Entry+9, 41518), -- Glyph of Chain Lightning
(@Entry+9, 41524), -- Glyph of Lava
(@Entry+9, 41526), -- Glyph of Shocking
(@Entry+9, 41527), -- Glyph of Earthliving Weapon
(@Entry+9, 41529), -- Glyph of Fire Elemental Totem
(@Entry+9, 41530), -- Glyph of Fire Nova
(@Entry+9, 41531), -- Glyph of Flame Shock
(@Entry+9, 41532), -- Glyph of Flametongue Weapon
(@Entry+9, 41533), -- Glyph of Healing Stream Totem
(@Entry+9, 41534), -- Glyph of Healing Wave
(@Entry+9, 41535), -- Glyph of Lesser Healing Wave
(@Entry+9, 41536), -- Glyph of Lightning Bolt
(@Entry+9, 41537), -- Glyph of Lightning Shield
(@Entry+9, 41538), -- Glyph of Mana Tide Totem
(@Entry+9, 41539), -- Glyph of Stormstrike
(@Entry+9, 41540), -- Glyph of Lava Lash
(@Entry+9, 41541), -- Glyph of Water Mastery
(@Entry+9, 41542), -- Glyph of Windfury Weapon
(@Entry+9, 41547), -- Glyph of Frost Shock
(@Entry+9, 41552), -- Glyph of Elemental Mastery
(@Entry+9, 45770), -- Glyph of Thunder
(@Entry+9, 45771), -- Glyph of Feral Spirit
(@Entry+9, 45772), -- Glyph of Riptide
(@Entry+9, 45775), -- Glyph of Earth Shield
(@Entry+9, 45776), -- Glyph of Totem of Wrath
(@Entry+9, 45777), -- Glyph of Hex
(@Entry+9, 45778), -- Glyph of Stoneclaw Totem
-- Glyph: Mage (Major)
(@Entry+10, 42734), -- Glyph of Arcane Explosion
(@Entry+10, 42735), -- Glyph of Arcane Missiles
(@Entry+10, 42736), -- Glyph of Arcane Power
(@Entry+10, 42737), -- Glyph of Blink
(@Entry+10, 42738), -- Glyph of Evocation
(@Entry+10, 42739), -- Glyph of Fireball
(@Entry+10, 42740), -- Glyph of Fire Blast
(@Entry+10, 42741), -- Glyph of Frost Nova
(@Entry+10, 42742), -- Glyph of Frostbolt
(@Entry+10, 42743), -- Glyph of Ice Armor
(@Entry+10, 42744), -- Glyph of Ice Block
(@Entry+10, 42745), -- Glyph of Ice Lance
(@Entry+10, 42746), -- Glyph of Icy Veins
(@Entry+10, 42747), -- Glyph of Scorch
(@Entry+10, 42748), -- Glyph of Invisibility
(@Entry+10, 42749), -- Glyph of Mage Armor
(@Entry+10, 42750), -- Glyph of Mana Gem
(@Entry+10, 42751), -- Glyph of Molten Armor
(@Entry+10, 42752), -- Glyph of Polymorph
(@Entry+10, 42753), -- Glyph of Remove Curse
(@Entry+10, 42754), -- Glyph of Water Elemental
(@Entry+10, 44684), -- Glyph of Frostfire
(@Entry+10, 44955), -- Glyph of Arcane Blast
(@Entry+10, 45736), -- Glyph of Deep Freeze
(@Entry+10, 45737), -- Glyph of Living Bomb
(@Entry+10, 45738), -- Glyph of Arcane Barrage
(@Entry+10, 45739), -- Glyph of Mirror Image
(@Entry+10, 45740), -- Glyph of Ice Barrier
(@Entry+10, 50045), -- Glyph of Eternal Water
-- Glyph: Warlock (Major)
(@Entry+11, 42453), -- Glyph of Incinerate
(@Entry+11, 42454), -- Glyph of Conflagrate
(@Entry+11, 42455), -- Glyph of Corruption
(@Entry+11, 42456), -- Glyph of Curse of Agony
(@Entry+11, 42457), -- Glyph of Death Coil
(@Entry+11, 42458), -- Glyph of Fear
(@Entry+11, 42459), -- Glyph of Felguard
(@Entry+11, 42460), -- Glyph of Felhunter
(@Entry+11, 42461), -- Glyph of Health Funnel
(@Entry+11, 42462), -- Glyph of Healthstone
(@Entry+11, 42463), -- Glyph of Howl of Terror
(@Entry+11, 42464), -- Glyph of Immolate
(@Entry+11, 42465), -- Glyph of Imp
(@Entry+11, 42466), -- Glyph of Searing Pain
(@Entry+11, 42467), -- Glyph of Shadow Bolt
(@Entry+11, 42468), -- Glyph of Shadowburn
(@Entry+11, 42469), -- Glyph of Siphon Life
(@Entry+11, 42470), -- Glyph of Soulstone
(@Entry+11, 42471), -- Glyph of Succubus
(@Entry+11, 42473), -- Glyph of Voidwalker
(@Entry+11, 45779), -- Glyph of Haunt
(@Entry+11, 45780), -- Glyph of Metamorphosis
(@Entry+11, 45781), -- Glyph of Chaos Bolt
(@Entry+11, 45782), -- Glyph of Demonic Circle
(@Entry+11, 45783), -- Glyph of Shadowflame
(@Entry+11, 45785), -- Glyph of Life Tap
(@Entry+11, 45789), -- Glyph of Soul Link
(@Entry+11, 50077), -- Glyph of Quick Decay
-- Glyph: Druid (Major)
(@Entry+12, 40896), -- Glyph of Frenzied Regeneration
(@Entry+12, 40897), -- Glyph of Maul
(@Entry+12, 40899), -- Glyph of Growl
(@Entry+12, 40900), -- Glyph of Mangle
(@Entry+12, 40901), -- Glyph of Shred
(@Entry+12, 40902), -- Glyph of Rip
(@Entry+12, 40903), -- Glyph of Rake
(@Entry+12, 40906), -- Glyph of Swiftmend
(@Entry+12, 40908), -- Glyph of Innervate
(@Entry+12, 40909), -- Glyph of Rebirth
(@Entry+12, 40912), -- Glyph of Regrowth
(@Entry+12, 40913), -- Glyph of Rejuvenation
(@Entry+12, 40914), -- Glyph of Healing Touch
(@Entry+12, 40915), -- Glyph of Lifebloom
(@Entry+12, 40916), -- Glyph of Starfire
(@Entry+12, 40919), -- Glyph of Insect Swarm
(@Entry+12, 40920), -- Glyph of Hurricane
(@Entry+12, 40921), -- Glyph of Starfall
(@Entry+12, 40922), -- Glyph of Wrath
(@Entry+12, 40923), -- Glyph of Moonfire
(@Entry+12, 40924), -- Glyph of Entangling Roots
(@Entry+12, 44928), -- Glyph of Focus
(@Entry+12, 45601), -- Glyph of Berserk
(@Entry+12, 45602), -- Glyph of Wild Growth
(@Entry+12, 45603), -- Glyph of Nourish
(@Entry+12, 45604), -- Glyph of Savage Roar
(@Entry+12, 45622), -- Glyph of Monsoon
(@Entry+12, 45623), -- Glyph of Barkskin
(@Entry+12, 46372), -- Glyph of Survival Instincts
(@Entry+12, 48720), -- Glyph of Claw
(@Entry+12, 50125), -- Glyph of Rapid Rejuvenation
-- Glyph: Warrior (Minor)
(@Entry+13, 43395), -- Glyph of Battle
(@Entry+13, 43396), -- Glyph of Bloodrage
(@Entry+13, 43397), -- Glyph of Charge
(@Entry+13, 43398), -- Glyph of Mocking Blow
(@Entry+13, 43399), -- Glyph of Thunder Clap
(@Entry+13, 43400), -- Glyph of Enduring Victory
(@Entry+13, 49084), -- Glyph of Command
-- Glyph: Paladin (Minor)
(@Entry+14, 43340), -- Glyph of Blessing of Might
(@Entry+14, 43365), -- Glyph of Blessing of Kings
(@Entry+14, 43366), -- Glyph of Blessing of Wisdom
(@Entry+14, 43367), -- Glyph of Lay on Hands
(@Entry+14, 43368), -- Glyph of Sense Undead
(@Entry+14, 43369), -- Glyph of the Wise
-- Glyph: Hunter (Minor)
(@Entry+15, 43338), -- Glyph of Revive Pet
(@Entry+15, 43350), -- Glyph of Mend Pet
(@Entry+15, 43351), -- Glyph of Feign Death
(@Entry+15, 43354), -- Glyph of Possessed Strength
(@Entry+15, 43355), -- Glyph of the Pack
(@Entry+15, 43356), -- Glyph of Scare Beast
-- Glyph: Rogue (Minor)
(@Entry+16, 43343), -- Glyph of Pick Pocket
(@Entry+16, 43376), -- Glyph of Distract
(@Entry+16, 43377), -- Glyph of Pick Lock
(@Entry+16, 43378), -- Glyph of Safe Fall
(@Entry+16, 43379), -- Glyph of Blurred Speed
(@Entry+16, 43380), -- Glyph of Vanish
-- Glyph: Priest (Minor)
(@Entry+17, 43342), -- Glyph of Fading
(@Entry+17, 43370), -- Glyph of Levitate
(@Entry+17, 43371), -- Glyph of Fortitude
(@Entry+17, 43372), -- Glyph of Shadow Protection
(@Entry+17, 43373), -- Glyph of Shackle Undead
(@Entry+17, 43374), -- Glyph of Shadowfiend
-- Glyph: Death Knight (Minor)
(@Entry+18, 43535), -- Glyph of Blood Tap
(@Entry+18, 43539), -- Glyph of Death's Embrace
(@Entry+18, 43544), -- Glyph of Horn of Winter
(@Entry+18, 43671), -- Glyph of Corpse Explosion
(@Entry+18, 43672), -- Glyph of Pestilence
(@Entry+18, 43673), -- Glyph of Raise Dead
-- Glyph: Shaman (Minor)
(@Entry+19, 43344), -- Glyph of Water Breathing
(@Entry+19, 43381), -- Glyph of Astral Recall
(@Entry+19, 43385), -- Glyph of Renewed Life
(@Entry+19, 43386), -- Glyph of Water Shield
(@Entry+19, 43388), -- Glyph of Water Walking
(@Entry+19, 43725), -- Glyph of Ghost Wolf
(@Entry+19, 44923), -- Glyph of Thunderstorm
-- Glyph: Mage (Minor)
(@Entry+20, 43339), -- Glyph of Arcane Intellect
(@Entry+20, 43357), -- Glyph of Fire Ward
(@Entry+20, 43359), -- Glyph of Frost Armor
(@Entry+20, 43360), -- Glyph of Frost Ward
(@Entry+20, 43361), -- Glyph of the Penguin
(@Entry+20, 43362), -- Glyph of the Bear Cub
(@Entry+20, 43364), -- Glyph of Slow Fall
(@Entry+20, 44920), -- Glyph of Blast Wave
-- Glyph: Warlock (Minor)
(@Entry+21, 43389), -- Glyph of Unending Breath
(@Entry+21, 43390), -- Glyph of Drain Soul
(@Entry+21, 43391), -- Glyph of Kilrogg
(@Entry+21, 43392), -- Glyph of Curse of Exhaustion
(@Entry+21, 43393), -- Glyph of Enslave Demon
(@Entry+21, 43394), -- Glyph of Souls
-- Glyph: Druid (Minor)
(@Entry+22, 43316), -- Glyph of Aquatic Form
(@Entry+22, 43331), -- Glyph of Unburdened Rebirth
(@Entry+22, 43332), -- Glyph of Thorns
(@Entry+22, 43334), -- Glyph of Challenging Roar
(@Entry+22, 43335), -- Glyph of the Wild
(@Entry+22, 43674), -- Glyph of Dash
(@Entry+22, 44922), -- Glyph of Typhoon
-- Gem: Meta
(@Entry+23, 41285), -- Chaotic Skyflare Diamond
(@Entry+23, 41307), -- Destructive Skyflare Diamond
(@Entry+23, 41333), -- Ember Skyflare Diamond
(@Entry+23, 41335), -- Enigmatic Skyflare Diamond
(@Entry+23, 41339), -- Swift Skyflare Diamond
(@Entry+23, 41375), -- Tireless Skyflare Diamond
(@Entry+23, 41376), -- Revitalizing Skyflare Diamond
(@Entry+23, 41377), -- Effulgent Skyflare Diamond
(@Entry+23, 41378), -- Forlorn Skyflare Diamond
(@Entry+23, 41379), -- Impassive Skyflare Diamond
(@Entry+23, 41380), -- Austere Earthsiege Diamond
(@Entry+23, 41381), -- Persistent Earthsiege Diamond
(@Entry+23, 41382), -- Trenchant Earthsiege Diamond
(@Entry+23, 41385), -- Invigorating Earthsiege Diamond
(@Entry+23, 41389), -- Beaming Earthsiege Diamond
(@Entry+23, 41395), -- Bracing Earthsiege Diamond
(@Entry+23, 41396), -- Eternal Earthsiege Diamond
(@Entry+23, 41397), -- Powerful Earthsiege Diamond
(@Entry+23, 41398), -- Relentless Earthsiege Diamond
(@Entry+23, 41400), -- Thundering Skyflare Diamond
(@Entry+23, 41401), -- Insightful Earthsiege Diamond
(@Entry+23, 44076), -- Swift Starflare Diamond
(@Entry+23, 44078), -- Tireless Starflare Diamond
(@Entry+23, 44081), -- Enigmatic Starflare Diamond
(@Entry+23, 44082), -- Impassive Starflare Diamond
(@Entry+23, 44084), -- Forlorn Starflare Diamond
(@Entry+23, 44087), -- Persistent Earthshatter Diamond
(@Entry+23, 44088), -- Powerful Earthshatter Diamond
(@Entry+23, 44089), -- Trenchant Earthshatter Diamond
-- Gem: Red
(@Entry+24, 40111), -- Bold Cardinal Ruby
(@Entry+24, 40112), -- Delicate Cardinal Ruby
(@Entry+24, 40113), -- Runed Cardinal Ruby
(@Entry+24, 40114), -- Bright Cardinal Ruby
(@Entry+24, 40115), -- Subtle Cardinal Ruby
(@Entry+24, 40116), -- Flashing Cardinal Ruby
(@Entry+24, 40117), -- Fractured Cardinal Ruby
(@Entry+24, 40118), -- Precise Cardinal Ruby
(@Entry+24, 45862), -- Bold Stormjewel
(@Entry+24, 45879), -- Delicate Stormjewel
(@Entry+24, 45883), -- Runed Stormjewel
-- Gem: Blue
(@Entry+25, 40119), -- Solid Majestic Zircon
(@Entry+25, 40120), -- Sparkling Majestic Zircon
(@Entry+25, 40121), -- Lustrous Majestic Zircon
(@Entry+25, 40122), -- Stormy Majestic Zircon
(@Entry+25, 45880), -- Solid Stormjewel
(@Entry+25, 45881), -- Sparkling Stormjewel
-- Gem: Yellow
(@Entry+26, 40123), -- Brilliant King's Amber
(@Entry+26, 40124), -- Smooth King's Amber
(@Entry+26, 40125), -- Rigid King's Amber
(@Entry+26, 40126), -- Thick King's Amber
(@Entry+26, 40127), -- Mystic King's Amber
(@Entry+26, 40128), -- Quick King's Amber
(@Entry+26, 45882), -- Brilliant Stormjewel
(@Entry+26, 45987), -- Rigid Stormjewel
-- Gem: Purple
(@Entry+27, 40129), -- Sovereign Dreadstone
(@Entry+27, 40130), -- Shifting Dreadstone
(@Entry+27, 40131), -- Tenuous Dreadstone
(@Entry+27, 40132), -- Glowing Dreadstone
(@Entry+27, 40133), -- Purified Dreadstone
(@Entry+27, 40134), -- Royal Dreadstone
(@Entry+27, 40135), -- Mysterious Dreadstone
(@Entry+27, 40136), -- Balanced Dreadstone
(@Entry+27, 40137), -- Infused Dreadstone
(@Entry+27, 40138), -- Regal Dreadstone
(@Entry+27, 40139), -- Defender's Dreadstone
(@Entry+27, 40140), -- Puissant Dreadstone
(@Entry+27, 40141), -- Guardian's Dreadstone
-- Gem: Green
(@Entry+28, 40164), -- Timeless Eye of Zul
(@Entry+28, 40165), -- Jagged Eye of Zul
(@Entry+28, 40166), -- Vivid Eye of Zul
(@Entry+28, 40167), -- Enduring Eye of Zul
(@Entry+28, 40168), -- Steady Eye of Zul
(@Entry+28, 40169), -- Forceful Eye of Zul
(@Entry+28, 40170), -- Seer's Eye of Zul
(@Entry+28, 40171), -- Misty Eye of Zul
(@Entry+28, 40172), -- Shining Eye of Zul
(@Entry+28, 40173), -- Turbid Eye of Zul
(@Entry+28, 40174), -- Intricate Eye of Zul
(@Entry+28, 40175), -- Dazzling Eye of Zul
(@Entry+28, 40176), -- Sundered Eye of Zul
(@Entry+28, 40177), -- Lambent Eye of Zul
(@Entry+28, 40178), -- Opaque Eye of Zul
(@Entry+28, 40179), -- Energized Eye of Zul
(@Entry+28, 40180), -- Radiant Eye of Zul
(@Entry+28, 40181), -- Tense Eye of Zul
(@Entry+28, 40182), -- Shattered Eye of Zul
-- Gem: Orange
(@Entry+29, 40142), -- Inscribed Ametrine
(@Entry+29, 40143), -- Etched Ametrine
(@Entry+29, 40144), -- Champion's Ametrine
(@Entry+29, 40145), -- Resplendent Ametrine
(@Entry+29, 40146), -- Fierce Ametrine
(@Entry+29, 40147), -- Deadly Ametrine
(@Entry+29, 40148), -- Glinting Ametrine
(@Entry+29, 40149), -- Lucent Ametrine
(@Entry+29, 40150), -- Deft Ametrine
(@Entry+29, 40151), -- Luminous Ametrine
(@Entry+29, 40152), -- Potent Ametrine
(@Entry+29, 40153), -- Veiled Ametrine
(@Entry+29, 40154), -- Durable Ametrine
(@Entry+29, 40155), -- Reckless Ametrine
(@Entry+29, 40156), -- Wicked Ametrine
(@Entry+29, 40157), -- Pristine Ametrine
(@Entry+29, 40158), -- Empowered Ametrine
(@Entry+29, 40159), -- Stark Ametrine
(@Entry+29, 40160), -- Stalwart Ametrine
(@Entry+29, 40161), -- Glimmering Ametrine
(@Entry+29, 40162), -- Accurate Ametrine
(@Entry+29, 40163), -- Resolute Ametrine
-- Container
(@Entry+30, 1729),  -- Gunnysack of the Night Watch
(@Entry+30, 3604),  -- Bandolier of the Night Watch
(@Entry+30, 3605),  -- Quiver of the Night Watch
(@Entry+30, 22243), -- Small Soul Pouch
(@Entry+30, 23162), -- Foror's Crate of Endless Resist Gear Storage (36 Slot)
-- Gem: Meta 70
(@Entry+31, 25896), -- Powerful Earthstorm Diamond
(@Entry+31, 34220), -- Chaotic Skyfire Diamond
(@Entry+31, 25893), -- Mystical Skyfire Diamond
(@Entry+31, 25901), -- Insightful Earthstorm Diamond
(@Entry+31, 32640), -- Potent Unstable Diamond
(@Entry+31, 25894), -- Swift Skyfire Diamond
(@Entry+31, 25895), -- Enigmatic Skyfire Diamond
(@Entry+31, 32409), -- Relentless Earthstorm Diamond
(@Entry+31, 28557), -- Swift Starfire Diamond
(@Entry+31, 25897), -- Bracing Earthstorm Diamond
(@Entry+31, 28556), -- Swift Windfire Diamond
(@Entry+31, 25898), -- Tenacious Earthstorm Diamond
(@Entry+31, 35501), -- Eternal Earthstorm Diamond
(@Entry+31, 25890), -- Destructive Skyfire Diamond
(@Entry+31, 32641), -- Imbued Unstable Diamond
(@Entry+31, 25899), -- Brutal Earthstorm Diamond
(@Entry+31, 35503), -- Ember Skyfire Diamond
(@Entry+31, 32410), -- Thundering Skyfire Diamond
-- Gem: Red 70
(@Entry+32, 24027), -- Bold Living Ruby
(@Entry+32, 24029), -- Teardrop Living Ruby
(@Entry+32, 24028), -- Delicate Living Ruby
(@Entry+32, 24030), -- Runed Living Ruby
(@Entry+32, 24031), -- Bright Living Ruby
(@Entry+32, 24032), -- Subtle Living Ruby
(@Entry+32, 24036), -- Flashing Living Ruby
(@Entry+32, 32195), -- Teardrop Crimson Spinel
(@Entry+32, 32194), -- Delicate Crimson Spinel
(@Entry+32, 35489), -- Teardrop Crimson Spinel
(@Entry+32, 32193), -- Bold Crimson Spinel
(@Entry+32, 32198), -- Subtle Crimson Spinel
(@Entry+32, 35487), -- Bright Crimson Spinel
(@Entry+32, 32196), -- Runed Crimson Spinel
(@Entry+32, 32197), -- Bright Crimson Spinel
(@Entry+32, 32199), -- Flashing Crimson Spinel
(@Entry+32, 35488), -- Runed Crimson Spinel
-- Gem: Blue 70
(@Entry+33, 24033), -- Solid Star of Elune
(@Entry+33, 24039), -- Stormy Star of Elune
(@Entry+33, 24035), -- Sparkling Star of Elune
(@Entry+33, 24037), -- Lustrous Star of Elune
(@Entry+33, 32200), -- Solid Empyrean Sapphire
(@Entry+33, 32201), -- Sparkling Empyrean Sapphire
(@Entry+33, 32202), -- Lustrous Empyrean Sapphire
(@Entry+33, 32203), -- Stormy Empyrean Sapphire
-- Gem: Yellow 70
(@Entry+34, 24047), -- Brilliant Dawnstone
(@Entry+34, 24051), -- Rigid Dawnstone
(@Entry+34, 24052), -- Thick Dawnstone
(@Entry+34, 24050), -- Gleaming Dawnstone
(@Entry+34, 24053), -- Mystic Dawnstone
(@Entry+34, 35315), -- Quick Dawnstone
(@Entry+34, 24048), -- Smooth Dawnstone
(@Entry+34, 31861), -- Great Dawnstone
(@Entry+34, 32205), -- Smooth Lionseye
(@Entry+34, 32204), -- Brilliant Lionseye
(@Entry+34, 32208), -- Thick Lionseye
(@Entry+34, 35761), -- Quick Lionseye
(@Entry+34, 32207), -- Gleaming Lionseye
(@Entry+34, 32209), -- Mystic Lionseye
(@Entry+34, 32206), -- Rigid Lionseye
(@Entry+34, 32210), -- Great Lionseye
-- Gem: Purple 70
(@Entry+35, 24057), -- Royal Nightseye
(@Entry+35, 24055), -- Shifting Nightseye
(@Entry+35, 24056), -- Glowing Nightseye
(@Entry+35, 31865), -- Infused Nightseye
(@Entry+35, 35707), -- Regal Nightseye
(@Entry+35, 24054), -- Sovereign Nightseye
(@Entry+35, 31863), -- Balanced Nightseye
(@Entry+35, 32216), -- Royal Shadowsong Amethyst
(@Entry+35, 32213), -- Balanced Shadowsong Amethyst
(@Entry+35, 37503), -- Purified Shadowsong Amethyst
(@Entry+35, 32214), -- Infused Shadowsong Amethyst
(@Entry+35, 32212), -- Shifting Shadowsong Amethyst
(@Entry+35, 32215), -- Glowing Shadowsong Amethyst
(@Entry+35, 32211), -- Sovereign Shadowsong Amethyst
-- Gem: Green 70
(@Entry+36, 33782), -- Steady Talasite
(@Entry+36, 24065), -- Dazzling Talasite
(@Entry+36, 24062), -- Enduring Talasite
(@Entry+36, 24066), -- Radiant Talasite
(@Entry+36, 24067), -- Jagged Talasite
(@Entry+36, 35318), -- Forceful Talasite
(@Entry+36, 32225), -- Dazzling Seaspray Emerald
(@Entry+36, 32223), -- Enduring Seaspray Emerald
(@Entry+36, 32224), -- Radiant Seaspray Emerald
(@Entry+36, 32226), -- Jagged Seaspray Emerald
(@Entry+36, 35759), -- Forceful Seaspray Emerald
(@Entry+36, 35758), -- Steady Seaspray Emerald
-- Gem: Orange 70
(@Entry+37, 31867), -- Veiled Noble Topaz
(@Entry+37, 32637), -- Unstable Citrine
(@Entry+37, 31868), -- Wicked Noble Topaz
(@Entry+37, 24061), -- Glinting Noble Topaz
(@Entry+37, 24058), -- Inscribed Noble Topaz
(@Entry+37, 24060), -- Luminous Noble Topaz
(@Entry+37, 35316), -- Reckless Noble Topaz
(@Entry+37, 32220), -- Glinting Pyrestone
(@Entry+37, 32219), -- Luminous Pyrestone
(@Entry+37, 32222), -- Wicked Pyrestone
(@Entry+37, 35760), -- Reckless Pyrestone
(@Entry+37, 32217), -- Inscribed Pyrestone
(@Entry+37, 32221), -- Veiled Pyrestone
(@Entry+37, 32218), -- Potent Pyrestone
-- Flasks
(@Entry+38, 13512), -- Flask of Supreme Power
(@Entry+38, 13510), -- Flask of the Titans
(@Entry+38, 13513), -- Flask of Chromatic Resistance
(@Entry+38, 22866), -- Flask of Pure Death
(@Entry+38, 22854), -- Flask of Relentless Assault
(@Entry+38, 22861), -- Flask of Blinding Light
(@Entry+38, 33208), -- Flask of Chromatic Wonder
(@Entry+38, 22853), -- Flask of Mighty Restoration
(@Entry+38, 22851), -- Flask of Fortification
(@Entry+38, 46376), -- Flask of the Frost Wyrm
(@Entry+38, 46377), -- Flask of Endless Rage
(@Entry+38, 46379), -- Flask of Stoneblood
(@Entry+38, 46378), -- Flask of Pure Mojo
-- Enchantments lvl 40-50
(@Entry+39, 7967),  -- Mithril Shield Spike
(@Entry+39, 15564), -- Rugged Armor Kit
(@Entry+39, 38837), -- Scroll of Enchant Boots - Minor Speed
(@Entry+39, 10548), -- Sniper Scope
(@Entry+39, 38833), -- Scroll of Enchant Chest - Superior Health
(@Entry+39, 38847), -- Scroll of Enchant Chest - Stats
(@Entry+39, 38848), -- Scroll of Enchant Weapon - Greater Striking
(@Entry+39, 8173),  -- Thick Armor Kit
(@Entry+39, 38825), -- Scroll of Enchant Cloak - Greater Defense
(@Entry+39, 38846), -- Scroll of Enchant Bracer - Greater Strength
(@Entry+39, 38822), -- Scroll of Enchant 2H Weapon - Impact
(@Entry+39, 38829), -- Scroll of Enchant Bracer - Intellect
(@Entry+39, 38845), -- Scroll of Enchant 2H Weapon - Greater Impact
(@Entry+39, 38851), -- Scroll of Enchant Gloves - Minor Haste
(@Entry+39, 38832), -- Scroll of Enchant Bracer - Greater Spirit
(@Entry+39, 38827), -- Scroll of Enchant Gloves - Agility
(@Entry+39, 38839), -- Scroll of Enchant Shield - Greater Spirit
(@Entry+39, 38841), -- Scroll of Enchant Chest - Superior Mana
(@Entry+39, 38844), -- Scroll of Enchant Boots - Agility
(@Entry+39, 38835), -- Scroll of Enchant Cloak - Lesser Agility
(@Entry+39, 38849), -- Scroll of Enchant Bracer - Greater Stamina
(@Entry+39, 38824), -- Scroll of Enchant Chest - Lesser Stats
(@Entry+39, 38826), -- Scroll of Enchant Cloak - Resistance
(@Entry+39, 38828), -- Scroll of Enchant Shield - Stamina
(@Entry+39, 38830), -- Scroll of Enchant Boots - Stamina
(@Entry+39, 38836), -- Scroll of Enchant Gloves - Strength
(@Entry+39, 45628), -- Scroll of Enchant Boots - Lesser Accuracy
(@Entry+39, 38840), -- Scroll of Enchant Weapon - Demonslaying
(@Entry+39, 38842), -- Scroll of Enchant Bracer - Deflection
-- Enchantments lvl 51-60 white/green
(@Entry+40, 11642), -- Lesser Arcanum of Constitution
(@Entry+40, 12645), -- Thorium Shield Spike
(@Entry+40, 38854), -- Scroll of Enchant Bracer - Superior Strength
(@Entry+40, 38938), -- Scroll of Enchant Bracer - Assault
(@Entry+40, 11644), -- Lesser Arcanum of Resilience
(@Entry+40, 25650), -- Knothide Armor Kit
(@Entry+40, 11647), -- Lesser Arcanum of Voracity
(@Entry+40, 18173), -- Shadow Mantle of the Dawn
(@Entry+40, 38857), -- Scroll of Enchant Gloves - Greater Strength
(@Entry+40, 11645), -- Lesser Arcanum of Voracity
(@Entry+40, 38863), -- Scroll of Enchant Boots - Greater Agility
(@Entry+40, 18172), -- Nature Mantle of the Dawn
(@Entry+40, 18182), -- Chromatic Mantle of the Dawn
(@Entry+40, 18330), -- Arcanum of Focus
(@Entry+40, 38860), -- Scroll of Enchant Shield - Vitality
(@Entry+40, 11622), -- Lesser Arcanum of Rumination
(@Entry+40, 18331), -- Arcanum of Protection
(@Entry+40, 11646), -- Lesser Arcanum of Voracity
(@Entry+40, 11648), -- Lesser Arcanum of Voracity
(@Entry+40, 18170), -- Frost Mantle of the Dawn
(@Entry+40, 18329), -- Arcanum of Rapidity
(@Entry+40, 38852), -- Scroll of Enchant Bracer - Greater Intellect
(@Entry+40, 38853), -- Scroll of Enchant Bracer - Superior Spirit
(@Entry+40, 38859), -- Scroll of Enchant Cloak - Superior Defense
(@Entry+40, 18169), -- Flame Mantle of the Dawn
(@Entry+40, 38856), -- Scroll of Enchant Gloves - Greater Agility
(@Entry+40, 38861), -- Scroll of Enchant Shield - Greater Stamina
(@Entry+40, 38867), -- Scroll of Enchant Chest - Major Mana
(@Entry+40, 11643), -- Lesser Arcanum of Tenacity
(@Entry+40, 11649), -- Lesser Arcanum of Voracity
(@Entry+40, 18171), -- Arcane Mantle of the Dawn
(@Entry+40, 38858), -- Scroll of Enchant Cloak - Greater Resistance
(@Entry+40, 38862), -- Scroll of Enchant Boots - Greater Stamina
(@Entry+40, 38864), -- Scroll of Enchant Boots - Spirit
(@Entry+40, 38866), -- Scroll of Enchant Chest - Major Health
(@Entry+40, 38881), -- Scroll of Enchant Bracer - Mana Regeneration
(@Entry+40, 38929), -- Scroll of Enchant Chest - Restore Mana Prime
(@Entry+40, 38855), -- Scroll of Enchant Bracer - Superior Stamina
-- Enchantments lvl 51-60 rare
(@Entry+41, 38880), -- Scroll of Enchant Weapon - Agility
(@Entry+41, 38838), -- Scroll of Enchant Weapon - Fiery Weapon
(@Entry+41, 18283), -- Biznicks 247x128 Accurascope
(@Entry+41, 20077), -- Zandalar Signet of Might
(@Entry+41, 19782), -- Presence of Might
(@Entry+41, 38879), -- Scroll of Enchant Weapon - Strength
(@Entry+41, 19783), -- Syncretist's Sigil
(@Entry+41, 38896), -- Scroll of Enchant 2H Weapon - Agility
(@Entry+41, 20078), -- Zandalar Signet of Serenity
(@Entry+41, 22638), -- Shadow Guard
(@Entry+41, 38875), -- Scroll of Enchant 2H Weapon - Major Intellect
(@Entry+41, 19784), -- Death's Embrace
(@Entry+41, 20076), -- Zandalar Signet of Mojo
(@Entry+41, 19787), -- Presence of Sight
(@Entry+41, 19788), -- Hoodoo Hex
(@Entry+41, 38872), -- Scroll of Enchant Weapon - Unholy Weapon
(@Entry+41, 22636), -- Ice Guard
(@Entry+41, 38870), -- Scroll of Enchant Weapon - Superior Striking
(@Entry+41, 19785), -- Falcon's Call
(@Entry+41, 38878), -- Scroll of Enchant Weapon - Healing Power
(@Entry+41, 19786), -- Vodouisant's Vigilant Embrace
(@Entry+41, 19789), -- Prophetic Aura
(@Entry+41, 19790), -- Animist's Caress
(@Entry+41, 22635), -- Savage Guard
(@Entry+41, 38869), -- Scroll of Enchant 2H Weapon - Superior Impact
(@Entry+41, 18251), -- Core Armor Kit
(@Entry+41, 38868), -- Scroll of Enchant Weapon - Icy Chill
(@Entry+41, 38871), -- Scroll of Enchant Weapon - Lifestealing
(@Entry+41, 38873), -- Scroll of Enchant Weapon - Crusader
(@Entry+41, 38877), -- Scroll of Enchant Weapon - Spellpower
-- Enchantments lvl 65-70 BC white/green
(@Entry+42, 29534), -- Clefthide Leg Armor
(@Entry+42, 29533), -- Cobrahide Leg Armor
(@Entry+42, 24273), -- Mystic Spellthread
(@Entry+42, 23764), -- Adamantite Scope
(@Entry+42, 38918), -- Scroll of Enchant Weapon - Major Intellect
(@Entry+42, 38917), -- Scroll of Enchant Weapon - Major Striking
(@Entry+42, 28888), -- Greater Inscription of Vengeance
(@Entry+42, 34207), -- Glove Reinforcements
(@Entry+42, 23530), -- Felsteel Shield Spike
(@Entry+42, 29192), -- Arcanum of Ferocity
(@Entry+42, 29193), -- Arcanum of the Gladiator
(@Entry+42, 28887), -- Greater Inscription of Faith
(@Entry+42, 29191), -- Arcanum of Power
(@Entry+42, 29186), -- Arcanum of the Defender
(@Entry+42, 28910), -- Greater Inscription of the Blade
(@Entry+42, 28912), -- Greater Inscription of the Oracle
(@Entry+42, 38884), -- Scroll of Enchant Weapon - Mighty Intellect
(@Entry+42, 28886), -- Greater Inscription of Discipline
(@Entry+42, 30846), -- Arcanum of the Outcast
(@Entry+42, 29187), -- Inscription of Endurance
(@Entry+42, 29189), -- Arcanum of Renewal
(@Entry+42, 28909), -- Greater Inscription of the Orb
(@Entry+42, 38920), -- Scroll of Enchant Weapon - Potency
(@Entry+42, 38919), -- Scroll of Enchant 2H Weapon - Savagery
(@Entry+42, 38946), -- Scroll of Enchant Weapon - Major Healing
(@Entry+42, 28889), -- Greater Inscription of Warding
(@Entry+42, 35728), -- Greater Inscription of the Blade
(@Entry+42, 38947), -- Scroll of Enchant Weapon - Greater Agility
(@Entry+42, 28911), -- Greater Inscription of the Knight
(@Entry+42, 35729), -- Greater Inscription of the Knight
(@Entry+42, 35730), -- Greater Inscription of the Oracle
(@Entry+42, 35731), -- Greater Inscription of the Orb
(@Entry+42, 38913), -- Scroll of Enchant Chest - Exceptional Stats
(@Entry+42, 38933), -- Scroll of Enchant Gloves - Major Strength
(@Entry+42, 38902), -- Scroll of Enchant Bracer - Fortitude
(@Entry+42, 38889), -- Scroll of Enchant Gloves - Healing Power
(@Entry+42, 38895), -- Scroll of Enchant Cloak - Dodge
(@Entry+42, 38945), -- Scroll of Enchant Shield - Major Stamina
(@Entry+42, 38939), -- Scroll of Enchant Cloak - Spell Penetration
(@Entry+42, 38882), -- Scroll of Enchant Bracer - Healing Power
(@Entry+42, 38899), -- Scroll of Enchant Bracer - Major Defense
(@Entry+42, 38910), -- Scroll of Enchant Boots - Surefooted
(@Entry+42, 38944), -- Scroll of Enchant Boots - Boar's Speed
-- Enchantments lvl 70 BC rare
(@Entry+43, 38925), -- Scroll of Enchant Weapon - Mongoose
(@Entry+43, 41146), -- Sun Scope
(@Entry+43, 24274), -- Runic Spellthread
(@Entry+43, 23766), -- Stabilized Eternium Scope
(@Entry+43, 29536), -- Nethercleft Leg Armor
(@Entry+43, 44497), -- Scroll of Enchant Weapon - Accuracy
(@Entry+43, 24276), -- Golden Spellthread
(@Entry+43, 29535), -- Nethercobra Leg Armor
(@Entry+43, 44453), -- Scroll of Enchant Weapon - Greater Potency
(@Entry+43, 23765), -- Khorium Scope
(@Entry+43, 38948), -- Scroll of Enchant Weapon - Executioner
(@Entry+43, 38926), -- Scroll of Enchant Weapon - Spellsurge
(@Entry+43, 38927), -- Scroll of Enchant Weapon - Battlemaster
(@Entry+43, 38922), -- Scroll of Enchant 2H Weapon - Major Agility
(@Entry+43, 38924), -- Scroll of Enchant Weapon - Soulfrost
(@Entry+43, 38923), -- Scroll of Enchant Weapon - Sunfire
(@Entry+43, 38998), -- Scroll of Enchant Weapon - Deathfrost
-- Enchantments lvl 80 WOTLK white/green
(@Entry+44, 38979), -- Scroll of Enchant Gloves - Exceptional Spellpower
(@Entry+44, 39006), -- Scroll of Enchant Boots - Tuskarr's Vitality
(@Entry+44, 39003), -- Scroll of Enchant Cloak - Greater Speed
(@Entry+44, 38989), -- Scroll of Enchant Chest - Super Stats
(@Entry+44, 38975), -- Scroll of Enchant Chest - Exceptional Resilience
(@Entry+44, 44458), -- Scroll of Enchant Gloves - Crusher
(@Entry+44, 38967), -- Scroll of Enchant Gloves - Major Agility
(@Entry+44, 38986), -- Scroll of Enchant Boots - Icewalker
(@Entry+44, 39005), -- Scroll of Enchant Chest - Super Health
(@Entry+44, 38997), -- Scroll of Enchant Bracers - Greater Spellpower
(@Entry+44, 38984), -- Scroll of Enchant Bracer - Expertise
(@Entry+44, 38993), -- Scroll of Enchant Cloak - Shadow Armor
(@Entry+44, 39004), -- Scroll of Enchant Cloak - Wisdom
(@Entry+44, 38978), -- Scroll of Enchant Cloak - Titanweave
(@Entry+44, 38976), -- Scroll of Enchant Boots - Superior Agility
(@Entry+44, 38990), -- Scroll of Enchant Gloves - Armsman
(@Entry+44, 38964), -- Scroll of Enchant Gloves - Greater Assault
(@Entry+44, 38985), -- Scroll of Enchant Gloves - Greater Blasting
-- Enchantments lvl 80 WOTLK rares
(@Entry+45, 38371), -- Jormungar Leg Armor
(@Entry+45, 38372), -- Nerubian Leg Armor
(@Entry+45, 44493), -- Scroll of Enchant Weapon - Berserking
(@Entry+45, 44463), -- Scroll of Enchant 2H Weapon - Massacre
(@Entry+45, 44466), -- Scroll of Enchant Weapon - Superior Potency
(@Entry+45, 44957), -- Greater Inscription of the Gladiator
(@Entry+45, 41611), -- Eternal Belt Buckle
(@Entry+45, 44137), -- Arcanum of the Frosty Soul
(@Entry+45, 44936), -- Titanium Plating
(@Entry+45, 44069), -- Arcanum of Triumph
(@Entry+45, 44879), -- Arcanum of Torment
(@Entry+45, 44075), -- Arcanum of Dominance
(@Entry+45, 41167), -- Heartseeker Scope
(@Entry+45, 44067), -- Inscription of Triumph
(@Entry+45, 44878), -- Arcanum of the Stalwart Protector
(@Entry+45, 44068), -- Inscription of Dominance
(@Entry+45, 44877), -- Arcanum of Burning Mysteries
(@Entry+45, 44131), -- Lesser Inscription of the Axe
(@Entry+45, 44139), -- Arcanum of the Fleeing Shadow
(@Entry+45, 41601), -- Shining Spellthread
(@Entry+45, 44138), -- Arcanum of Toxic Warding
(@Entry+45, 44875), -- Arcanum of the Savage Gladiator
(@Entry+45, 44130), -- Lesser Inscription of the Crag
(@Entry+45, 41603), -- Azure Spellthread
(@Entry+45, 44129), -- Lesser Inscription of the Storm
(@Entry+45, 44140), -- Arcanum of the Eclipsed Moon
(@Entry+45, 46026), -- Scroll of Enchant Weapon - Blade Ward
(@Entry+45, 44876), -- Arcanum of Blissful Mending
(@Entry+45, 44141), -- Arcanum of the Flame's Soul
(@Entry+45, 44132), -- Lesser Inscription of the Pinnacle
(@Entry+45, 46098), -- Scroll of Enchant Weapon - Blood Draining
(@Entry+45, 45060), -- Scroll of Enchant Staff - Spellpower
(@Entry+45, 44884), -- Arcanum of the Frosty Soul
(@Entry+45, 44872), -- Greater Inscription of the Crag
(@Entry+45, 44124), -- NPC Equip 44124
(@Entry+45, 44880), -- Arcanum of the Flame's Soul
(@Entry+45, 38963), -- Scroll of Enchant Weapon - Exceptional Spirit
(@Entry+45, 44125), -- NPC Equip 44125
(@Entry+45, 44881), -- Arcanum of the Eclipsed Moon
(@Entry+45, 44883), -- Arcanum of Toxic Warding
(@Entry+45, 44882), -- Arcanum of the Fleeing Shadow
(@Entry+45, 38992), -- Scroll of Enchant 2H Weapon - Greater Savagery
(@Entry+45, 38995), -- Scroll of Enchant Weapon - Exceptional Agility
(@Entry+45, 38965), -- Scroll of Enchant Weapon - Icebreaker
(@Entry+45, 44467), -- Scroll of Enchant Weapon - Mighty Spellpower
(@Entry+45, 45056), -- Scroll of Enchant Staff - Greater Spellpower
(@Entry+45, 38972), -- Scroll of Enchant Weapon - Lifeward
(@Entry+45, 43987), -- Scroll of Enchant Weapon - Black Magic
-- Enchantments lvl 80 WOTLK epics
(@Entry+46, 41602), -- Brilliant Spellthread
(@Entry+46, 38374), -- Icescale Leg Armor
(@Entry+46, 41604), -- Sapphire Spellthread
(@Entry+46, 38373), -- Frosthide Leg Armor
(@Entry+46, 44871), -- Greater Inscription of the Axe
(@Entry+46, 44963), -- Earthen Leg Armor
(@Entry+46, 44874), -- Greater Inscription of the Storm
(@Entry+46, 44873), -- Greater Inscription of the Pinnacle
-- Potions lvl 1-60 Vanilla
(@Entry+47, 5631), -- Rage Potion
(@Entry+47, 2459), -- Swiftness Potion
(@Entry+47, 5633), -- Great Rage Potion
(@Entry+47, 5634), -- Free Action Potion
(@Entry+47, 9036), -- Magic Resistance Potion
(@Entry+47, 13442), -- Mighty Rage Potion
(@Entry+47, 13457), -- Greater Fire Protection Potion
(@Entry+47, 13456), -- Greater Frost Protection Potion
(@Entry+47, 13458), -- Greater Nature Protection Potion
(@Entry+47, 13446), -- Major Healing Potion
(@Entry+47, 13444), -- Major Mana Potion
(@Entry+47, 20008), -- Living Action Potion
-- Potions lvl 60-70 Burning Crusade
(@Entry+48, 22829), -- Super Healing Potion
(@Entry+48, 22832), -- Super Mana Potion
(@Entry+48, 22838), -- Haste Potion
(@Entry+48, 22839), -- Destruction Potion
(@Entry+48, 22837), -- Heroic Potion
(@Entry+48, 22849), -- Ironshield Potion
(@Entry+48, 22842), -- Major Frost Protection Potion
(@Entry+48, 22844), -- Major Nature Protection Potion
(@Entry+48, 22845), -- Major Arcane Protection Potion
(@Entry+48, 22841), -- Major Fire Protection Potion
(@Entry+48, 22846), -- Major Shadow Protection Potion
-- Potions lvl 70-80 WotLK
(@Entry+49, 33447), -- Runic Healing Potion
(@Entry+49, 33448), -- Runic Mana Potion
(@Entry+49, 40211), -- Potion of Speed
(@Entry+49, 40212), -- Potion of Wild Magic
(@Entry+49, 40093), -- Indestructible Potion
(@Entry+49, 40215), -- Mighty Frost Protection Potion
(@Entry+49, 40217), -- Mighty Shadow Protection Potion
(@Entry+49, 40214), -- Mighty Fire Protection Potion
(@Entry+49, 40216), -- Mighty Nature Protection Potion
(@Entry+49, 40213); -- Mighty Arcane Protection Potion
