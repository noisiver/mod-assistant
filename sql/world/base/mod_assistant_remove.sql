SET @Entry := 9000000;
-- Creature template
DELETE FROM `creature_template` WHERE `entry`=@Entry;
-- Delete spawn points
DELETE FROM `creature` WHERE `id`=@Entry;

-- Vendor entries
-- Heirloom: Weapon
DELETE FROM `npc_vendor` WHERE `entry`=@Entry;
-- Heirloom: Armor
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+1;
-- Heirloom: Other
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+2;
-- Glyph: Warrior (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+3;
-- Glyph: Paladin (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+4;
-- Glyph: Hunter (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+5;
-- Glyph: Rogue (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+6;
-- Glyph: Priest (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+7;
-- Glyph: Death Knight (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+8;
-- Glyph: Shaman (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+9;
-- Glyph: Mage (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+10;
-- Glyph: Warlock (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+11;
-- Glyph: Druid (Major)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+12;
-- Glyph: Warrior (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+13;
-- Glyph: Paladin (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+14;
-- Glyph: Hunter (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+15;
-- Glyph: Rogue (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+16;
-- Glyph: Priest (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+17;
-- Glyph: Death Knight (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+18;
-- Glyph: Shaman (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+19;
-- Glyph: Mage (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+20;
-- Glyph: Warlock (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+21;
-- Glyph: Druid (Minor)
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+22;
-- Gem: Meta
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+23;
-- Gem: Red
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+24;
-- Gem: Blue
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+25;
-- Gem: Yellow
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+26;
-- Gem: Purple
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+27;
-- Gem: Green
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+28;
-- Gem: Orange
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+29;
-- Container
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+30;
-- Totem
DELETE FROM `npc_vendor` WHERE `entry`=@Entry+31;

-- Prices
-- Glyph: Warrior (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43412, 43413, 43414, 43415, 43416, 43417, 43418, 43419, 43420, 43421, 43422, 43423, 43424, 43425, 43426, 43427, 43428, 43429, 43430, 43431, 43432, 45790, 45792, 45793, 45794, 45795, 45797);
-- Glyph: Paladin (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (41092, 41094, 41095, 41096, 41097, 41098, 41099, 41100, 41101, 41102, 41103, 41104, 41105, 41106, 41107, 41108, 41109, 41110, 43867, 43868, 43869, 45741, 45742, 45743, 45744, 45745, 45746, 45747);
-- Glyph: Hunter (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (42897, 42898, 42899, 42900, 42901, 42902, 42903, 42904, 42905, 42906, 42907, 42908, 42909, 42910, 42911, 42912, 42913, 42914, 42915, 42916, 42917, 45625, 45731, 45732, 45733, 45734, 45735);
-- Glyph: Rogue (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (42954, 42955, 42956, 42957, 42958, 42959, 42960, 42961, 42962, 42963, 42964, 42965, 42966, 42967, 42968, 42969, 42970, 42971, 42972, 42973, 42974, 45761, 45762, 45764, 45766, 45767, 45768, 45769);
-- Glyph: Priest (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (42396, 42397, 42398, 42399, 42400, 42401, 42402, 42403, 42404, 42405, 42406, 42407, 42408, 42409, 42410, 42411, 42412, 42414, 42415, 42416, 42417, 45753, 45755, 45756, 45757, 45758, 45760);
-- Glyph: Death Knight (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43533, 43534, 43536, 43537, 43538, 43541, 43542, 43543, 43545, 43546, 43547, 43548, 43549, 43550, 43551, 43552, 43553, 43554, 43825, 43826, 43827, 45799, 45800, 45803, 45804, 45805, 45806);
-- Glyph: Shaman (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (41517, 41518, 41524, 41526, 41527, 41529, 41530, 41531, 41532, 41533, 41534, 41535, 41536, 41537, 41538, 41539, 41540, 41541, 41542, 41547, 41552, 45770, 45771, 45772, 45775, 45776, 45777, 45778);
-- Glyph: Mage (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (42734, 42735, 42736, 42737, 42738, 42739, 42740, 42741, 42742, 42743, 42744, 42745, 42746, 42747, 42748, 42749, 42750, 42751, 42752, 42753, 42754, 44684, 44955, 45736, 45737, 45738, 45739, 45740, 50045);
-- Glyph: Warlock (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (42453, 42454, 42455, 42456, 42457, 42458, 42459, 42460, 42461, 42462, 42463, 42464, 42465, 42466, 42467, 42468, 42469, 42470, 42471, 42473, 42742, 45779, 45780, 45781, 45782, 45783, 45785, 45789, 50077);
-- Glyph: Druid (Major)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (40896, 40897, 40899, 40900, 40901, 40902, 40903, 40906, 40908, 40909, 40912, 40913, 40914, 40915, 40916, 40919, 40920, 40921, 40922, 40923, 40924, 44928, 45601, 45602, 45603, 45604, 45622, 45623, 46372, 48720, 50125);
-- Glyph: Warrior (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43395, 43396, 43397, 43398, 43399, 43400, 49084);
-- Glyph: Paladin (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43340, 43365, 43366, 43367, 43368, 43369);
-- Glyph: Hunter (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43338, 43350, 43351, 43354, 43355, 43356);
-- Glyph: Rogue (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43343, 43376, 43377, 43378, 43379, 43380);
-- Glyph: Priest (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43342, 43370, 43371, 43372, 43373, 43374);
-- Glyph Death Knight (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43535, 43539, 43544, 43671, 43672, 43673);
-- Glyph: Shaman (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43344, 43381, 43385, 43386, 43388, 43725, 44923);
-- Glyph: Mage (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43339, 43357, 43359, 43360, 43361, 43362, 43364, 44920);
-- Glyph: Warlock (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43389, 43390, 43391, 43392, 43393, 43394);
-- Glyph: Druid (Minor)
UPDATE `item_template` SET `BuyPrice`=400, `SellPrice`=100 WHERE `entry` IN (43316, 43331, 43332, 43334, 43335, 43674, 44922);
-- Gem: Meta
UPDATE `item_template` SET `BuyPrice`=240000, `SellPrice`=60000 WHERE `entry` IN (41285, 41307, 41333, 41335, 41339, 41375, 41376, 41377, 41378, 41379, 41380, 41381, 41382, 41385, 41389, 41395, 41396, 41397, 41398, 41400, 41401);
-- Gem: Red
UPDATE `item_template` SET `BuyPrice`=360000, `SellPrice`=90000 WHERE `entry` IN (40111, 40112, 40113, 40114, 40115, 40116, 40117, 40118);
UPDATE `item_template` SET `BuyPrice`=45000, `SellPrice`=11250 WHERE `entry` IN (45862, 45879, 45883);
-- Gem: Blue
UPDATE `item_template` SET `BuyPrice`=360000, `SellPrice`=90000 WHERE `entry` IN (40119, 40120, 40121, 40122);
UPDATE `item_template` SET `BuyPrice`=45000, `SellPrice`=11250 WHERE `entry` IN (45880, 45881);
-- Gem: Yellow
UPDATE `item_template` SET `BuyPrice`=360000, `SellPrice`=90000 WHERE `entry` IN (40123, 40124, 40125, 40126, 40127, 40128);
UPDATE `item_template` SET `BuyPrice`=45000, `SellPrice`=11250 WHERE `entry` IN (45882, 45987);
-- Gem: Purple
UPDATE `item_template` SET `BuyPrice`=360000, `SellPrice`=90000 WHERE `entry` IN (40129, 40130, 40131, 40132, 40133, 40134, 40135, 40136, 40137, 40138, 40139, 40140, 40141);
-- Gem: Green
UPDATE `item_template` SET `BuyPrice`=360000, `SellPrice`=90000 WHERE `entry` IN (40164, 40165, 40166, 40167, 40168, 40169, 40170, 40171, 40172, 40173, 40174, 40175, 40176, 40177, 40178, 40179, 40180, 40181, 40182);
-- Gem: Orange
UPDATE `item_template` SET `BuyPrice`=360000, `SellPrice`=90000 WHERE `entry` IN (40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40156, 40157, 40158, 40159, 40160, 40161, 40162, 40163);
-- Container
UPDATE `item_template` SET `BuyPrice`=250000, `SellPrice`=62500 WHERE `entry`=41597;
UPDATE `item_template` SET `BuyPrice`=150000, `SellPrice`=37500 WHERE `entry` IN (44447, 44448);
