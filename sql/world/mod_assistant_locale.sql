SET
@Entry := 9000000,

DELETE FROM `creature_template_locale` WHERE `entry` = @Entry;

INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `Title`, `VerifiedBuild`) VALUES
(@Entry, "koKR", "가브리엘", "조수", 18019),
(@Entry, "frFR", "Gabriel", "Assistant", 18019),
(@Entry, "deDE", "Gabriel", "Assistent", 18019),
(@Entry, "zhCN", "加百利", "助理", 18019),
(@Entry, "zhTW", "加百利", "助理", 18019),
(@Entry, "esES", "Gabriel", "Asistente", 18019),
(@Entry, "esMX", "Gabriel", "Asistente", 18019),
(@Entry, "ruRU", "Гавриил", "Ассистент", 18019);