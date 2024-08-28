#include "mod_assistant.h"

Assistant::Assistant() : CreatureScript("npc_assistant"), WorldScript("AssistantWorldScript") {}

void Addmod_assistantScripts()
{
    new Assistant();
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_HEIRLOOMS = {
    {LOCALE_enUS, "I want heirlooms"},
    {LOCALE_koKR, "유산품을 원합니다"},
    {LOCALE_frFR, "Je veux des objets d'héritage"},
    {LOCALE_deDE, "Ich möchte Erbstücke"},
    {LOCALE_zhCN, "我要传家宝"},
    {LOCALE_zhTW, "我要傳家寶"},
    {LOCALE_esES, "Quiero reliquias"},
    {LOCALE_esMX, "Quiero reliquias"},
    {LOCALE_ruRU, "Я хочу наследные вещи"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_HEIRLOOMS_WEAPONS = {
    {LOCALE_enUS, "I want weapons"},
    {LOCALE_koKR, "무기를 원합니다"},
    {LOCALE_frFR, "Je veux des armes"},
    {LOCALE_deDE, "Ich möchte Waffen"},
    {LOCALE_zhCN, "我要武器"},
    {LOCALE_zhTW, "我要武器"},
    {LOCALE_esES, "Quiero armas"},
    {LOCALE_esMX, "Quiero armas"},
    {LOCALE_ruRU, "Я хочу оружие"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_HEIRLOOMS_ARMOR = {
    {LOCALE_enUS, "I want armor"},
    {LOCALE_koKR, "방어구를 원합니다"},
    {LOCALE_frFR, "Je veux de l'armure"},
    {LOCALE_deDE, "Ich möchte Rüstung"},
    {LOCALE_zhCN, "我要护甲"},
    {LOCALE_zhTW, "我要護甲"},
    {LOCALE_esES, "Quiero armaduras"},
    {LOCALE_esMX, "Quiero armaduras"},
    {LOCALE_ruRU, "Я хочу броню"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_HEIRLOOMS_OTHER = {
    {LOCALE_enUS, "I want something else"},
    {LOCALE_koKR, "다른 것을 원합니다"},
    {LOCALE_frFR, "Je veux autre chose"},
    {LOCALE_deDE, "Ich möchte etwas anderes"},
    {LOCALE_zhCN, "我想要其他东西"},
    {LOCALE_zhTW, "我想要其他東西"},
    {LOCALE_esES, "Quiero algo más"},
    {LOCALE_esMX, "Quiero algo más"},
    {LOCALE_ruRU, "Я хочу что-то другое"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GLYPHS = {
    {LOCALE_enUS, "I want glyphs"},
    {LOCALE_koKR, "문양을 원합니다"},
    {LOCALE_frFR, "Je veux des glyphes"},
    {LOCALE_deDE, "Ich möchte Glyphen"},
    {LOCALE_zhCN, "我要雕文"},
    {LOCALE_zhTW, "我要雕文"},
    {LOCALE_esES, "Quiero glifos"},
    {LOCALE_esMX, "Quiero glifos"},
    {LOCALE_ruRU, "Я хочу глифы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GLYPHS_MAJOR = {
    {LOCALE_enUS, "I want some major glyphs"},
    {LOCALE_koKR, "주요 문양을 원합니다"},
    {LOCALE_frFR, "Je veux des glyphes majeurs"},
    {LOCALE_deDE, "Ich möchte große Glyphen"},
    {LOCALE_zhCN, "我要主要雕文"},
    {LOCALE_zhTW, "我要主要雕文"},
    {LOCALE_esES, "Quiero glifos mayores"},
    {LOCALE_esMX, "Quiero glifos mayores"},
    {LOCALE_ruRU, "Я хочу большие глифы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GLYPHS_MINOR = {
    {LOCALE_enUS, "I want some minor glyphs"},
    {LOCALE_koKR, "소형 문양을 원합니다"},
    {LOCALE_frFR, "Je veux des glyphes mineurs"},
    {LOCALE_deDE, "Ich möchte kleine Glyphen"},
    {LOCALE_zhCN, "我要次要雕文"},
    {LOCALE_zhTW, "我要次要雕文"},
    {LOCALE_esES, "Quiero glifos menores"},
    {LOCALE_esMX, "Quiero glifos menores"},
    {LOCALE_ruRU, "Я хочу малые глифы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS = {
    {LOCALE_enUS, "I want gems"},
    {LOCALE_koKR, "보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes"},
    {LOCALE_deDE, "Ich möchte Edelsteine"},
    {LOCALE_zhCN, "我想要宝石"},
    {LOCALE_zhTW, "我想要寶石"},
    {LOCALE_esES, "Quiero gemas"},
    {LOCALE_esMX, "Quiero gemas"},
    {LOCALE_ruRU, "Я хочу самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_META = {
    {LOCALE_enUS, "I want some meta gems"},
    {LOCALE_koKR, "메타 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des méta-gemmes"},
    {LOCALE_deDE, "Ich möchte Meta-Edelsteine"},
    {LOCALE_zhCN, "我想要多彩宝石"},
    {LOCALE_zhTW, "我想要多彩寶石"},
    {LOCALE_esES, "Quiero algunas meta-gemas"},
    {LOCALE_esMX, "Quiero algunas meta-gemas"},
    {LOCALE_ruRU, "Я хочу мета-самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_RED = {
    {LOCALE_enUS, "I want some red gems"},
    {LOCALE_koKR, "붉은 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes rouges"},
    {LOCALE_deDE, "Ich möchte rote Edelsteine"},
    {LOCALE_zhCN, "我想要红色宝石"},
    {LOCALE_zhTW, "我想要紅色寶石"},
    {LOCALE_esES, "Quiero algunas gemas rojas"},
    {LOCALE_esMX, "Quiero algunas gemas rojas"},
    {LOCALE_ruRU, "Я хочу красные самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_BLUE = {
    {LOCALE_enUS, "I want some blue gems"},
    {LOCALE_koKR, "푸른 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes bleues"},
    {LOCALE_deDE, "Ich möchte blaue Edelsteine"},
    {LOCALE_zhCN, "我想要蓝色宝石"},
    {LOCALE_zhTW, "我想要藍色寶石"},
    {LOCALE_esES, "Quiero algunas gemas azules"},
    {LOCALE_esMX, "Quiero algunas gemas azules"},
    {LOCALE_ruRU, "Я хочу синие самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_YELLOW = {
    {LOCALE_enUS, "I want some yellow gems"},
    {LOCALE_koKR, "노란 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes jaunes"},
    {LOCALE_deDE, "Ich möchte gelbe Edelsteine"},
    {LOCALE_zhCN, "我想要黄色宝石"},
    {LOCALE_zhTW, "我想要黃色寶石"},
    {LOCALE_esES, "Quiero algunas gemas amarillas"},
    {LOCALE_esMX, "Quiero algunas gemas amarillas"},
    {LOCALE_ruRU, "Я хочу желтые самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_PURPLE = {
    {LOCALE_enUS, "I want some purple gems"},
    {LOCALE_koKR, "보라색 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes violettes"},
    {LOCALE_deDE, "Ich möchte lila Edelsteine"},
    {LOCALE_zhCN, "我想要紫色宝石"},
    {LOCALE_zhTW, "我想要紫色寶石"},
    {LOCALE_esES, "Quiero algunas gemas moradas"},
    {LOCALE_esMX, "Quiero algunas gemas moradas"},
    {LOCALE_ruRU, "Я хочу фиолетовые самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_GREEN = {
    {LOCALE_enUS, "I want some green gems"},
    {LOCALE_koKR, "녹색 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes vertes"},
    {LOCALE_deDE, "Ich möchte grüne Edelsteine"},
    {LOCALE_zhCN, "我想要绿色宝石"},
    {LOCALE_zhTW, "我想要綠色寶石"},
    {LOCALE_esES, "Quiero algunas gemas verdes"},
    {LOCALE_esMX, "Quiero algunas gemas verdes"},
    {LOCALE_ruRU, "Я хочу зеленые самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_GEMS_ORANGE = {
    {LOCALE_enUS, "I want some orange gems"},
    {LOCALE_koKR, "주황색 보석을 원합니다"},
    {LOCALE_frFR, "Je veux des gemmes orange"},
    {LOCALE_deDE, "Ich möchte orange Edelsteine"},
    {LOCALE_zhCN, "我想要橙色宝石"},
    {LOCALE_zhTW, "我想要橙色寶石"},
    {LOCALE_esES, "Quiero algunas gemas naranjas"},
    {LOCALE_esMX, "Quiero algunas gemas naranjas"},
    {LOCALE_ruRU, "Я хочу оранжевые самоцветы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_CONTAINERS = {
    {LOCALE_enUS, "I want containers"},
    {LOCALE_koKR, "용기를 원합니다"},
    {LOCALE_frFR, "Je veux des conteneurs"},
    {LOCALE_deDE, "Ich möchte Behälter"},
    {LOCALE_zhCN, "我想要容器"},
    {LOCALE_zhTW, "我想要容器"},
    {LOCALE_esES, "Quiero contenedores"},
    {LOCALE_esMX, "Quiero contenedores"},
    {LOCALE_ruRU, "Я хочу контейнеры"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES = {
    {LOCALE_enUS, "I want utilities"},
    {LOCALE_koKR, "도구를 원합니다"},
    {LOCALE_frFR, "Je veux des utilitaires"},
    {LOCALE_deDE, "Ich möchte Hilfsmittel"},
    {LOCALE_zhCN, "我想要实用工具"},
    {LOCALE_zhTW, "我想要實用工具"},
    {LOCALE_esES, "Quiero utilidades"},
    {LOCALE_esMX, "Quiero utilidades"},
    {LOCALE_ruRU, "Я хочу утилиты"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES_NAME = {
    {LOCALE_enUS, "I want to change my name"},
    {LOCALE_koKR, "이름을 변경하고 싶습니다"},
    {LOCALE_frFR, "Je veux changer mon nom"},
    {LOCALE_deDE, "Ich möchte meinen Namen ändern"},
    {LOCALE_zhCN, "我想要改名"},
    {LOCALE_zhTW, "我想要改名"},
    {LOCALE_esES, "Quiero cambiar mi nombre"},
    {LOCALE_esMX, "Quiero cambiar mi nombre"},
    {LOCALE_ruRU, "Я хочу изменить имя"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES_APPEARANCE = {
    {LOCALE_enUS, "I want to change my appearance"},
    {LOCALE_koKR, "외모를 변경하고 싶습니다"},
    {LOCALE_frFR, "Je veux changer mon apparence"},
    {LOCALE_deDE, "Ich möchte mein Aussehen ändern"},
    {LOCALE_zhCN, "我想要改变外貌"},
    {LOCALE_zhTW, "我想要改變外貌"},
    {LOCALE_esES, "Quiero cambiar mi apariencia"},
    {LOCALE_esMX, "Quiero cambiar mi apariencia"},
    {LOCALE_ruRU, "Я хочу изменить внешность"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES_RACE = {
    {LOCALE_enUS, "I want to change my race"},
    {LOCALE_koKR, "종족을 변경하고 싶습니다"},
    {LOCALE_frFR, "Je veux changer de race"},
    {LOCALE_deDE, "Ich möchte meine Rasse ändern"},
    {LOCALE_zhCN, "我想要改变种族"},
    {LOCALE_zhTW, "我想要改變種族"},
    {LOCALE_esES, "Quiero cambiar mi raza"},
    {LOCALE_esMX, "Quiero cambiar mi raza"},
    {LOCALE_ruRU, "Я хочу изменить расу"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES_FACTION = {
    {LOCALE_enUS, "I want to change my faction"},
    {LOCALE_koKR, "진영을 변경하고 싶습니다"},
    {LOCALE_frFR, "Je veux changer de faction"},
    {LOCALE_deDE, "Ich möchte meine Fraktion ändern"},
    {LOCALE_zhCN, "我想要改变阵营"},
    {LOCALE_zhTW, "我想要改變陣營"},
    {LOCALE_esES, "Quiero cambiar de facción"},
    {LOCALE_esMX, "Quiero cambiar de facción"},
    {LOCALE_ruRU, "Я хочу изменить фракцию"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES_IN_PROGRESS = {
    {LOCALE_enUS, "You must complete the previously activated feature before trying to perform another."},
    {LOCALE_koKR, "다른 작업을 수행하기 전에 이전에 활성화된 기능을 완료해야 합니다."},
    {LOCALE_frFR, "Vous devez terminer la fonction activée précédemment avant d'essayer d'en effectuer une autre."},
    {LOCALE_deDE, "Sie müssen die zuvor aktivierte Funktion abschließen, bevor Sie eine andere versuchen."},
    {LOCALE_zhCN, "在尝试执行其他操作之前，您必须完成先前激活的功能。"},
    {LOCALE_zhTW, "在嘗試執行其他操作之前，您必須完成先前啟動的功能。"},
    {LOCALE_esES, "Debe completar la función activada previamente antes de intentar realizar otra."},
    {LOCALE_esMX, "Debe completar la función activada previamente antes de intentar realizar otra."},
    {LOCALE_ruRU, "Вы должны завершить ранее активированную функцию, прежде чем пытаться выполнить другую."},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_UTILITIES_DONE = {
    {LOCALE_enUS, "You can now log out to continue using the activated feature."},
    {LOCALE_koKR, "이제 로그아웃하여 활성화된 기능을 계속 사용할 수 있습니다."},
    {LOCALE_frFR, "Vous pouvez maintenant vous déconnecter pour continuer à utiliser la fonctionnalité activée."},
    {LOCALE_deDE, "Sie können sich jetzt abmelden, um die aktivierte Funktion weiter zu nutzen."},
    {LOCALE_zhCN, "您现在可以注销以继续使用已激活的功能。"},
    {LOCALE_zhTW, "您現在可以登出以繼續使用已啟動的功能。"},
    {LOCALE_esES, "Ahora puede cerrar sesión para continuar utilizando la función activada."},
    {LOCALE_esMX, "Ahora puede cerrar sesión para continuar utilizando la función activada."},
    {LOCALE_ruRU, "Теперь вы можете выйти, чтобы продолжить использование активированной функции."},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_FLIGHT_PATHS = {
    {LOCALE_enUS, "I want to unlock flight paths"},
    {LOCALE_koKR, "비행 경로를 해제하고 싶습니다"},
    {LOCALE_frFR, "Je veux débloquer les trajets aériens"},
    {LOCALE_deDE, "Ich möchte Flugrouten freischalten"},
    {LOCALE_zhCN, "我想解锁飞行路线"},
    {LOCALE_zhTW, "我想解鎖飛行路線"},
    {LOCALE_esES, "Quiero desbloquear rutas de vuelo"},
    {LOCALE_esMX, "Quiero desbloquear rutas de vuelo"},
    {LOCALE_ruRU, "Я хочу разблокировать пути полетов"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_FLIGHT_PATHS_KALIMDOR_EASTERN_KINGDOMS = {
    {LOCALE_enUS, "Kalimdor & Eastern Kingdoms"},
    {LOCALE_koKR, "칼림도어 & 동부 왕국"},
    {LOCALE_frFR, "Kalimdor & Royaumes de l'Est"},
    {LOCALE_deDE, "Kalimdor & Östliche Königreiche"},
    {LOCALE_zhCN, "卡利姆多和东部王国"},
    {LOCALE_zhTW, "卡利姆多和東部王國"},
    {LOCALE_esES, "Kalimdor & Reinos del Este"},
    {LOCALE_esMX, "Kalimdor & Reinos del Este"},
    {LOCALE_ruRU, "Калимдор и Восточные Королевства"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_FLIGHT_PATHS_OUTLAND = {
    {LOCALE_enUS, "Outland"},
    {LOCALE_koKR, "아웃랜드"},
    {LOCALE_frFR, "Outreterre"},
    {LOCALE_deDE, "Scherbenwelt"},
    {LOCALE_zhCN, "外域"},
    {LOCALE_zhTW, "外域"},
    {LOCALE_esES, "Terrallende"},
    {LOCALE_esMX, "Terrallende"},
    {LOCALE_ruRU, "Запределье"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_FLIGHT_PATHS_NORTHREND = {
    {LOCALE_enUS, "Northrend"},
    {LOCALE_koKR, "노스렌드"},
    {LOCALE_frFR, "Norfendre"},
    {LOCALE_deDE, "Nordend"},
    {LOCALE_zhCN, "诺森德"},
    {LOCALE_zhTW, "北裂境"},
    {LOCALE_esES, "Rasganorte"},
    {LOCALE_esMX, "Rasganorte"},
    {LOCALE_ruRU, "Нордскол"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS = {
    {LOCALE_enUS, "I want help with my professions"},
    {LOCALE_koKR, "내 전문 기술에 대한 도움을 받고 싶습니다"},
    {LOCALE_frFR, "Je veux de l'aide avec mes professions"},
    {LOCALE_deDE, "Ich möchte Hilfe bei meinen Berufen"},
    {LOCALE_zhCN, "我想获得专业帮助"},
    {LOCALE_zhTW, "我想獲得專業幫助"},
    {LOCALE_esES, "Quiero ayuda con mis profesiones"},
    {LOCALE_esMX, "Quiero ayuda con mis profesiones"},
    {LOCALE_ruRU, "Я хочу получить помощь с моими профессиями"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_CHOOSE = {
    {LOCALE_enUS, "I want help with my skill in"},
    {LOCALE_koKR, "내 기술에 대한 도움을 받고 싶습니다"},
    {LOCALE_frFR, "Je veux de l'aide avec ma compétence en"},
    {LOCALE_deDE, "Ich möchte Hilfe mit meinen Fähigkeiten in"},
    {LOCALE_zhCN, "我想在以下方面获得技能帮助"},
    {LOCALE_zhTW, "我想在以下方面獲得技能幫助"},
    {LOCALE_esES, "Quiero ayuda con mi habilidad en"},
    {LOCALE_esMX, "Quiero ayuda con mi habilidad en"},
    {LOCALE_ruRU, "Я хочу помощь с моим навыком в"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_FIRST_AID = {
    {LOCALE_enUS, "First Aid"},
    {LOCALE_koKR, "응급 처치"},
    {LOCALE_frFR, "Premiers soins"},
    {LOCALE_deDE, "Erste Hilfe"},
    {LOCALE_zhCN, "急救"},
    {LOCALE_zhTW, "急救"},
    {LOCALE_esES, "Primeros auxilios"},
    {LOCALE_esMX, "Primeros auxilios"},
    {LOCALE_ruRU, "Первая помощь"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_BLACKSMITHING = {
    {LOCALE_enUS, "Blacksmithing"},
    {LOCALE_koKR, "대장기술"},
    {LOCALE_frFR, "Forge"},
    {LOCALE_deDE, "Schmiedekunst"},
    {LOCALE_zhCN, "锻造"},
    {LOCALE_zhTW, "鍛造"},
    {LOCALE_esES, "Herrería"},
    {LOCALE_esMX, "Herrería"},
    {LOCALE_ruRU, "Кузнечное дело"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_LEATHERWORKING = {
    {LOCALE_enUS, "Leatherworking"},
    {LOCALE_koKR, "가죽세공"},
    {LOCALE_frFR, "Travail du cuir"},
    {LOCALE_deDE, "Lederverarbeitung"},
    {LOCALE_zhCN, "制皮"},
    {LOCALE_zhTW, "製皮"},
    {LOCALE_esES, "Peletería"},
    {LOCALE_esMX, "Peletería"},
    {LOCALE_ruRU, "Кожевничество"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_ALCHEMY = {
    {LOCALE_enUS, "Alchemy"},
    {LOCALE_koKR, "연금술"},
    {LOCALE_frFR, "Alchimie"},
    {LOCALE_deDE, "Alchemie"},
    {LOCALE_zhCN, "炼金"},
    {LOCALE_zhTW, "鍊金"},
    {LOCALE_esES, "Alquimia"},
    {LOCALE_esMX, "Alquimia"},
    {LOCALE_ruRU, "Алхимия"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_HERBALISM = {
    {LOCALE_enUS, "Herbalism"},
    {LOCALE_koKR, "약초 채집"},
    {LOCALE_frFR, "Herboristerie"},
    {LOCALE_deDE, "Kräuterkunde"},
    {LOCALE_zhCN, "草药学"},
    {LOCALE_zhTW, "草藥學"},
    {LOCALE_esES, "Herboristería"},
    {LOCALE_esMX, "Herboristería"},
    {LOCALE_ruRU, "Травничество"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_COOKING = {
    {LOCALE_enUS, "Cooking"},
    {LOCALE_koKR, "요리"},
    {LOCALE_frFR, "Cuisine"},
    {LOCALE_deDE, "Kochen"},
    {LOCALE_zhCN, "烹饪"},
    {LOCALE_zhTW, "烹飪"},
    {LOCALE_esES, "Cocina"},
    {LOCALE_esMX, "Cocina"},
    {LOCALE_ruRU, "Кулинария"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_MINING = {
    {LOCALE_enUS, "Mining"},
    {LOCALE_koKR, "채광"},
    {LOCALE_frFR, "Minage"},
    {LOCALE_deDE, "Bergbau"},
    {LOCALE_zhCN, "采矿"},
    {LOCALE_zhTW, "採礦"},
    {LOCALE_esES, "Minería"},
    {LOCALE_esMX, "Minería"},
    {LOCALE_ruRU, "Горное дело"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_TAILORING = {
    {LOCALE_enUS, "Tailoring"},
    {LOCALE_koKR, "재봉술"},
    {LOCALE_frFR, "Couture"},
    {LOCALE_deDE, "Schneiderei"},
    {LOCALE_zhCN, "裁缝"},
    {LOCALE_zhTW, "裁縫"},
    {LOCALE_esES, "Sastrería"},
    {LOCALE_esMX, "Sastrería"},
    {LOCALE_ruRU, "Портняжное дело"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_ENGINEERING = {
    {LOCALE_enUS, "Engineering"},
    {LOCALE_koKR, "기계공학"},
    {LOCALE_frFR, "Ingénierie"},
    {LOCALE_deDE, "Ingenieurskunst"},
    {LOCALE_zhCN, "工程学"},
    {LOCALE_zhTW, "工程學"},
    {LOCALE_esES, "Ingeniería"},
    {LOCALE_esMX, "Ingeniería"},
    {LOCALE_ruRU, "Инженерное дело"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_ENCHANTING = {
    {LOCALE_enUS, "Enchanting"},
    {LOCALE_koKR, "마법부여"},
    {LOCALE_frFR, "Enchantement"},
    {LOCALE_deDE, "Verzauberkunst"},
    {LOCALE_zhCN, "附魔"},
    {LOCALE_zhTW, "附魔"},
    {LOCALE_esES, "Encantamiento"},
    {LOCALE_esMX, "Encantamiento"},
    {LOCALE_ruRU, "Наложение чар"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_FISHING = {
    {LOCALE_enUS, "Fishing"},
    {LOCALE_koKR, "낚시"},
    {LOCALE_frFR, "Pêche"},
    {LOCALE_deDE, "Angeln"},
    {LOCALE_zhCN, "钓鱼"},
    {LOCALE_zhTW, "釣魚"},
    {LOCALE_esES, "Pesca"},
    {LOCALE_esMX, "Pesca"},
    {LOCALE_ruRU, "Рыбная ловля"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_SKINNING = {
    {LOCALE_enUS, "Skinning"},
    {LOCALE_koKR, "무두질"},
    {LOCALE_frFR, "Dépeçage"},
    {LOCALE_deDE, "Kürschnerei"},
    {LOCALE_zhCN, "剥皮"},
    {LOCALE_zhTW, "剝皮"},
    {LOCALE_esES, "Desuello"},
    {LOCALE_esMX, "Desuello"},
    {LOCALE_ruRU, "Снятие шкур"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_INSCRIPTION = {
    {LOCALE_enUS, "Inscription"},
    {LOCALE_koKR, "주문각인"},
    {LOCALE_frFR, "Calligraphie"},
    {LOCALE_deDE, "Inschriftenkunde"},
    {LOCALE_zhCN, "铭文"},
    {LOCALE_zhTW, "銘文"},
    {LOCALE_esES, "Inscripción"},
    {LOCALE_esMX, "Inscripción"},
    {LOCALE_ruRU, "Начертание"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PROFESSIONS_JEWELCRAFTING = {
    {LOCALE_enUS, "Jewelcrafting"},
    {LOCALE_koKR, "보석세공"},
    {LOCALE_frFR, "Joaillerie"},
    {LOCALE_deDE, "Juwelenschmiedekunst"},
    {LOCALE_zhCN, "珠宝"},
    {LOCALE_zhTW, "珠寶"},
    {LOCALE_esES, "Joyería"},
    {LOCALE_esMX, "Joyería"},
    {LOCALE_ruRU, "Ювелирное дело"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES = {
    {LOCALE_enUS, "I want to reset instances"},
    {LOCALE_koKR, "인스턴스를 초기화하고 싶습니다"},
    {LOCALE_frFR, "Je veux réinitialiser les instances"},
    {LOCALE_deDE, "Ich möchte Instanzen zurücksetzen"},
    {LOCALE_zhCN, "我想重置副本"},
    {LOCALE_zhTW, "我想重置副本"},
    {LOCALE_esES, "Quiero reiniciar instancias"},
    {LOCALE_esMX, "Quiero reiniciar instancias"},
    {LOCALE_ruRU, "Я хочу сбросить подземелья"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_HEROIC = {
    {LOCALE_enUS, "I want to reset heroic dungeons"},
    {LOCALE_koKR, "영웅 던전을 초기화하고 싶습니다"},
    {LOCALE_frFR, "Je veux réinitialiser les donjons héroïques"},
    {LOCALE_deDE, "Ich möchte heroische Dungeons zurücksetzen"},
    {LOCALE_zhCN, "我想重置英雄副本"},
    {LOCALE_zhTW, "我想重置英雄副本"},
    {LOCALE_esES, "Quiero reiniciar las mazmorras heroicas"},
    {LOCALE_esMX, "Quiero reiniciar las mazmorras heroicas"},
    {LOCALE_ruRU, "Я хочу сбросить героические подземелья"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_RAID = {
    {LOCALE_enUS, "I want to reset raids"},
    {LOCALE_koKR, "공격대를 초기화하고 싶습니다"},
    {LOCALE_frFR, "Je veux réinitialiser les raids"},
    {LOCALE_deDE, "Ich möchte Raids zurücksetzen"},
    {LOCALE_zhCN, "我想重置团队副本"},
    {LOCALE_zhTW, "我想重置團隊副本"},
    {LOCALE_esES, "Quiero reiniciar las bandas"},
    {LOCALE_esMX, "Quiero reiniciar las bandas"},
    {LOCALE_ruRU, "Я хочу сбросить рейды"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_PLAYER = {
    {LOCALE_enUS, "Just for me"},
    {LOCALE_koKR, "저만을 위해"},
    {LOCALE_frFR, "Pour moi seulement"},
    {LOCALE_deDE, "Nur für mich"},
    {LOCALE_zhCN, "仅为我"},
    {LOCALE_zhTW, "僅為我"},
    {LOCALE_esES, "Solo para mí"},
    {LOCALE_esMX, "Solo para mí"},
    {LOCALE_ruRU, "Только для меня"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_GROUP = {
    {LOCALE_enUS, "For my entire group"},
    {LOCALE_koKR, "제 그룹 전체를 위해"},
    {LOCALE_frFR, "Pour mon groupe entier"},
    {LOCALE_deDE, "Für meine gesamte Gruppe"},
    {LOCALE_zhCN, "为我的整个队伍"},
    {LOCALE_zhTW, "為我的整個小隊"},
    {LOCALE_esES, "Para todo mi grupo"},
    {LOCALE_esMX, "Para todo mi grupo"},
    {LOCALE_ruRU, "Для всей моей группы"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_HEROIC_RESET = {
    {LOCALE_enUS, "All heroic dungeons have been reset."},
    {LOCALE_koKR, "모든 영웅 던전이 초기화되었습니다."},
    {LOCALE_frFR, "Tous les donjons héroïques ont été réinitialisés."},
    {LOCALE_deDE, "Alle heroischen Dungeons wurden zurückgesetzt."},
    {LOCALE_zhCN, "所有英雄副本已重置。"},
    {LOCALE_zhTW, "所有英雄副本已重置。"},
    {LOCALE_esES, "Todas las mazmorras heroicas han sido reiniciadas."},
    {LOCALE_esMX, "Todas las mazmorras heroicas han sido reiniciadas."},
    {LOCALE_ruRU, "Все героические подземелья были сброшены."},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_HEROIC_GROUP_RESET = {
    {LOCALE_enUS, "All of your group's heroic dungeons have been reset."},
    {LOCALE_koKR, "그룹의 모든 영웅 던전이 초기화되었습니다."},
    {LOCALE_frFR, "Tous les donjons héroïques de votre groupe ont été réinitialisés."},
    {LOCALE_deDE, "Alle heroischen Dungeons deiner Gruppe wurden zurückgesetzt."},
    {LOCALE_zhCN, "你组的所有英雄副本已重置。"},
    {LOCALE_zhTW, "你隊伍的所有英雄副本已重置。"},
    {LOCALE_esES, "Todas las mazmorras heroicas de tu grupo han sido reiniciadas."},
    {LOCALE_esMX, "Todas las mazmorras heroicas de tu grupo han sido reiniciadas."},
    {LOCALE_ruRU, "Все героические подземелья вашей группы были сброшены."},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_RAID_RESET = {
    {LOCALE_enUS, "All raids have been reset."},
    {LOCALE_koKR, "모든 공격대가 초기화되었습니다."},
    {LOCALE_frFR, "Tous les raids ont été réinitialisés."},
    {LOCALE_deDE, "Alle Raids wurden zurückgesetzt."},
    {LOCALE_zhCN, "所有团队副本已重置。"},
    {LOCALE_zhTW, "所有團隊副本已重置。"},
    {LOCALE_esES, "Todos los asaltos han sido reiniciados."},
    {LOCALE_esMX, "Todos los asaltos han sido reiniciados."},
    {LOCALE_ruRU, "Все рейды были сброшены."},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_INSTANCES_RAID_GROUP_RESET = {
    {LOCALE_enUS, "All of your group's raids have been reset."},
    {LOCALE_koKR, "그룹의 모든 공격대가 초기화되었습니다."},
    {LOCALE_frFR, "Tous les raids de votre groupe ont été réinitialisés."},
    {LOCALE_deDE, "Alle Raids deiner Gruppe wurden zurückgesetzt."},
    {LOCALE_zhCN, "你组的所有团队副本已重置。"},
    {LOCALE_zhTW, "你隊伍的所有團隊副本已重置。"},
    {LOCALE_esES, "Todos los asaltos de tu grupo han sido reiniciados."},
    {LOCALE_esMX, "Todos los asaltos de tu grupo han sido reiniciados."},
    {LOCALE_ruRU, "Все рейды вашей группы были сброшены."},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_CONTINUE_TRANSACTION = {
    {LOCALE_enUS, "Do you wish to continue the transaction?"},
    {LOCALE_koKR, "거래를 계속 진행하시겠습니까?"},
    {LOCALE_frFR, "Souhaitez-vous poursuivre la transaction ?"},
    {LOCALE_deDE, "Möchten Sie die Transaktion fortsetzen?"},
    {LOCALE_zhCN, "您希望继续交易吗？"},
    {LOCALE_zhTW, "您希望繼續交易嗎？"},
    {LOCALE_esES, "¿Deseas continuar con la transacción?"},
    {LOCALE_esMX, "¿Deseas continuar con la transacción?"},
    {LOCALE_ruRU, "Вы хотите продолжить транзакцию?"},
};

const std::unordered_map<LocaleConstant, std::string> GOSSIP_PREVIOUS_PAGE = {
    {LOCALE_enUS, "Previous Page"},
    {LOCALE_koKR, "이전 페이지"},
    {LOCALE_frFR, "Page précédente"},
    {LOCALE_deDE, "Vorherige Seite"},
    {LOCALE_zhCN, "上一页"},
    {LOCALE_zhTW, "上一頁"},
    {LOCALE_esES, "Página anterior"},
    {LOCALE_esMX, "Página anterior"},
    {LOCALE_ruRU, "Предыдущая страница"},
};

std::unordered_map<std::string, const std::unordered_map<LocaleConstant, std::string>*> assistantTextMaps = {
    {"heirlooms", &GOSSIP_HEIRLOOMS},
    {"heirlooms_weapons", &GOSSIP_HEIRLOOMS_WEAPONS},
    {"heirlooms_armor", &GOSSIP_HEIRLOOMS_ARMOR},
    {"heirlooms_other", &GOSSIP_HEIRLOOMS_OTHER},
    {"glyphs", &GOSSIP_GLYPHS},
    {"glyphs_major", &GOSSIP_GLYPHS_MAJOR},
    {"glyphs_minor", &GOSSIP_GLYPHS_MINOR},
    {"gems", &GOSSIP_GEMS},
    {"gems_meta", &GOSSIP_GEMS_META},
    {"gems_red", &GOSSIP_GEMS_RED},
    {"gems_blue", &GOSSIP_GEMS_BLUE},
    {"gems_yellow", &GOSSIP_GEMS_YELLOW},
    {"gems_purple", &GOSSIP_GEMS_PURPLE},
    {"gems_green", &GOSSIP_GEMS_GREEN},
    {"gems_orange", &GOSSIP_GEMS_ORANGE},
    {"containers", &GOSSIP_CONTAINERS},
    {"utilities", &GOSSIP_UTILITIES},
    {"utilities_name", &GOSSIP_UTILITIES_NAME},
    {"utilities_appearance", &GOSSIP_UTILITIES_APPEARANCE},
    {"utilities_race", &GOSSIP_UTILITIES_RACE},
    {"utilities_faction", &GOSSIP_UTILITIES_FACTION},
    {"utilities_in_progress", &GOSSIP_UTILITIES_IN_PROGRESS},
    {"utilities_done", &GOSSIP_UTILITIES_DONE},
    {"flight_paths", &GOSSIP_FLIGHT_PATHS},
    {"flight_paths_kalimdor_eastern_kingdoms", &GOSSIP_FLIGHT_PATHS_KALIMDOR_EASTERN_KINGDOMS},
    {"flight_paths_outland", &GOSSIP_FLIGHT_PATHS_OUTLAND},
    {"flight_paths_northrend", &GOSSIP_FLIGHT_PATHS_NORTHREND},
    {"professions", &GOSSIP_PROFESSIONS},
    {"professions_choose", &GOSSIP_PROFESSIONS_CHOOSE},
    {"professions_first_aid", &GOSSIP_PROFESSIONS_FIRST_AID},
    {"professions_blacksmithing", &GOSSIP_PROFESSIONS_BLACKSMITHING},
    {"professions_leatherworking", &GOSSIP_PROFESSIONS_LEATHERWORKING},
    {"professions_alchemy", &GOSSIP_PROFESSIONS_ALCHEMY},
    {"professions_herbalism", &GOSSIP_PROFESSIONS_HERBALISM},
    {"professions_cooking", &GOSSIP_PROFESSIONS_COOKING},
    {"professions_mining", &GOSSIP_PROFESSIONS_MINING},
    {"professions_tailoring", &GOSSIP_PROFESSIONS_TAILORING},
    {"professions_engineering", &GOSSIP_PROFESSIONS_ENGINEERING},
    {"professions_enchanting", &GOSSIP_PROFESSIONS_ENCHANTING},
    {"professions_fishing", &GOSSIP_PROFESSIONS_FISHING},
    {"professions_skinning", &GOSSIP_PROFESSIONS_SKINNING},
    {"professions_inscription", &GOSSIP_PROFESSIONS_INSCRIPTION},
    {"professions_jewelcrafting", &GOSSIP_PROFESSIONS_JEWELCRAFTING},
    {"instances", &GOSSIP_INSTANCES},
    {"instances_heroic", &GOSSIP_INSTANCES_HEROIC},
    {"instances_raid", &GOSSIP_INSTANCES_RAID},
    {"instances_player", &GOSSIP_INSTANCES_PLAYER},
    {"instances_group", &GOSSIP_INSTANCES_GROUP},
    {"instances_heroic_reset", &GOSSIP_INSTANCES_HEROIC_RESET},
    {"instances_heroic_group_reset", &GOSSIP_INSTANCES_HEROIC_GROUP_RESET},
    {"instances_raid_reset", &GOSSIP_INSTANCES_RAID_RESET},
    {"instances_raid_group_reset", &GOSSIP_INSTANCES_RAID_GROUP_RESET},
    {"continue_transaction", &GOSSIP_CONTINUE_TRANSACTION},
    {"previous_page", &GOSSIP_PREVIOUS_PAGE},
};

std::string GetAssistantLocaleText(LocaleConstant locale, const std::string& titleType)
{
    auto textMapIt = assistantTextMaps.find(titleType);
    if (textMapIt != assistantTextMaps.end())
    {
        const std::unordered_map<LocaleConstant, std::string>* textMap = textMapIt->second;
        auto it = textMap->find(locale);
        if (it != textMap->end())
        {
            return it->second;
        }
    }

    return "";
};