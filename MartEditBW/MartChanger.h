#pragma once

#include <atlstr.h>
#include <vector>
#include <unordered_map>

#define NULL_NAME L"---"

class MartChanger
{
public:

    MartChanger()
    {
        LoadItems();
    }
    ~MartChanger() {}

    CString GetLastMartError()
    {
        switch (last_error)
        {
        case MartChanger::Error::NULL_ITEM_DATA_PATH:
            return L"You must choose a path to edit!";
        case MartChanger::Error::ITEM_DOESNT_EXIST:
            return L"Selected item doesn't exist!";
        case MartChanger::Error::CANT_OPEN_ITEM_FILE:
            return L"Unable to open item file!";
        case MartChanger::Error::NO_ITEM_SELECTED_TO_SAVE:
            return L"No item selected!";
        case MartChanger::Error::NULL_MART_DATA_PATH:
            return L"You must choose a file to edit!";
        case MartChanger::Error::CANT_FIND_MART_DATA:
            return L"Unable to find mart data!";
        case MartChanger::Error::MART_FILE_DOESNT_EXIST:
            return L"Selected file doesn't exist or can't be opened!";
        case MartChanger::Error::INCOMPATIBLE_MART_SIZE:
            return L"Mart data trying to be saved is not the same size as the mart!";
        case MartChanger::Error::UNKNOWN:
            return L"Unknown error!";
        }
        return L"Unknown error!";
    }

    std::vector<CString> GetItemNames()
    {
        return item_names;
    }

protected:

    enum class Error
    {
        NULL_ITEM_DATA_PATH,
        ITEM_DOESNT_EXIST,
        CANT_OPEN_ITEM_FILE,
        NO_ITEM_SELECTED_TO_SAVE,
        NULL_MART_DATA_PATH,
        CANT_FIND_MART_DATA,
        MART_FILE_DOESNT_EXIST,
        NULL_ITEM,
        INCOMPATIBLE_MART_SIZE,
        UNKNOWN
    };
    Error last_error;

    void LoadItems()
    {
        item_names.push_back(NULL_NAME); item_IDs.push_back(-1);
        item_names.push_back(L"Absorb Bulb"); item_IDs.push_back(545);
        item_names.push_back(L"Adamant Orb"); item_IDs.push_back(135);
        item_names.push_back(L"Aguav Berry"); item_IDs.push_back(162);
        item_names.push_back(L"Air Balloon"); item_IDs.push_back(541);
        item_names.push_back(L"Amulet Coin"); item_IDs.push_back(223);
        item_names.push_back(L"Antidote"); item_IDs.push_back(18);
        item_names.push_back(L"Apicot Berry"); item_IDs.push_back(205);
        item_names.push_back(L"Armor Fossil"); item_IDs.push_back(104);
        item_names.push_back(L"Aspear Berry"); item_IDs.push_back(153);
        item_names.push_back(L"Awakening"); item_IDs.push_back(21);
        item_names.push_back(L"Babiri Berry"); item_IDs.push_back(199);
        item_names.push_back(L"BalmMushroom"); item_IDs.push_back(580);
        item_names.push_back(L"Belue Berry"); item_IDs.push_back(183);
        item_names.push_back(L"Berry Juice"); item_IDs.push_back(43);
        item_names.push_back(L"Big Mushroom"); item_IDs.push_back(87);
        item_names.push_back(L"Big Nugget"); item_IDs.push_back(581);
        item_names.push_back(L"Big Pearl"); item_IDs.push_back(89);
        item_names.push_back(L"Big Root"); item_IDs.push_back(296);
        item_names.push_back(L"Binding Band"); item_IDs.push_back(544);
        item_names.push_back(L"Black Belt"); item_IDs.push_back(241);
        item_names.push_back(L"Black Flute"); item_IDs.push_back(68);
        item_names.push_back(L"Black Sludge"); item_IDs.push_back(281);
        item_names.push_back(L"BlackGlasses"); item_IDs.push_back(240);
        item_names.push_back(L"Blue Flute"); item_IDs.push_back(65);
        item_names.push_back(L"Blue Scarf"); item_IDs.push_back(261);
        item_names.push_back(L"Blue Shard"); item_IDs.push_back(73);
        item_names.push_back(L"Bluk Berry"); item_IDs.push_back(165);
        item_names.push_back(L"BridgeMail D"); item_IDs.push_back(145);
        item_names.push_back(L"BridgeMail M"); item_IDs.push_back(148);
        item_names.push_back(L"BridgeMail S"); item_IDs.push_back(144);
        item_names.push_back(L"BridgeMail T"); item_IDs.push_back(146);
        item_names.push_back(L"BridgeMail V"); item_IDs.push_back(147);
        item_names.push_back(L"BrightPowder"); item_IDs.push_back(213);
        item_names.push_back(L"Bug Gem"); item_IDs.push_back(558);
        item_names.push_back(L"Burn Drive"); item_IDs.push_back(118);
        item_names.push_back(L"Burn Heal"); item_IDs.push_back(19);
        item_names.push_back(L"Calcium"); item_IDs.push_back(49);
        item_names.push_back(L"Carbos"); item_IDs.push_back(48);
        item_names.push_back(L"Casteliacone"); item_IDs.push_back(591);
        item_names.push_back(L"Cell Battery"); item_IDs.push_back(546);
        item_names.push_back(L"Charcoal"); item_IDs.push_back(249);
        item_names.push_back(L"Charti Berry"); item_IDs.push_back(195);
        item_names.push_back(L"Cheri Berry"); item_IDs.push_back(149);
        item_names.push_back(L"Cherish Ball"); item_IDs.push_back(16);
        item_names.push_back(L"Chesto Berry"); item_IDs.push_back(150);
        item_names.push_back(L"Chilan Berry"); item_IDs.push_back(200);
        item_names.push_back(L"Chill Drive"); item_IDs.push_back(119);
        item_names.push_back(L"Choice Band"); item_IDs.push_back(220);
        item_names.push_back(L"Choice Scarf"); item_IDs.push_back(287);
        item_names.push_back(L"Choice Specs"); item_IDs.push_back(297);
        item_names.push_back(L"Chople Berry"); item_IDs.push_back(189);
        item_names.push_back(L"Claw Fossil"); item_IDs.push_back(100);
        item_names.push_back(L"Cleanse Tag"); item_IDs.push_back(224);
        item_names.push_back(L"Clever Wing"); item_IDs.push_back(569);
        item_names.push_back(L"Coba Berry"); item_IDs.push_back(192);
        item_names.push_back(L"Colbur Berry"); item_IDs.push_back(198);
        item_names.push_back(L"Comet Shard"); item_IDs.push_back(583);
        item_names.push_back(L"Cornn Berry"); item_IDs.push_back(175);
        item_names.push_back(L"Cover Fossil"); item_IDs.push_back(572);
        item_names.push_back(L"Custap Berry"); item_IDs.push_back(210);
        item_names.push_back(L"Damp Mulch"); item_IDs.push_back(96);
        item_names.push_back(L"Damp Rock"); item_IDs.push_back(285);
        item_names.push_back(L"Dark Gem"); item_IDs.push_back(562);
        item_names.push_back(L"Dawn Stone"); item_IDs.push_back(109);
        item_names.push_back(L"DeepSeaScale"); item_IDs.push_back(227);
        item_names.push_back(L"DeepSeaTooth"); item_IDs.push_back(226);
        item_names.push_back(L"Destiny Knot"); item_IDs.push_back(280);
        item_names.push_back(L"Dire Hit"); item_IDs.push_back(56);
        item_names.push_back(L"Dive Ball"); item_IDs.push_back(7);
        item_names.push_back(L"Dome Fossil"); item_IDs.push_back(102);
        item_names.push_back(L"Douse Drive"); item_IDs.push_back(116);
        item_names.push_back(L"Draco Plate"); item_IDs.push_back(311);
        item_names.push_back(L"Dragon Fang"); item_IDs.push_back(250);
        item_names.push_back(L"Dragon Gem"); item_IDs.push_back(561);
        item_names.push_back(L"Dragon Scale"); item_IDs.push_back(235);
        item_names.push_back(L"Dread Plate"); item_IDs.push_back(312);
        item_names.push_back(L"Dream Ball"); item_IDs.push_back(576);
        item_names.push_back(L"Dubious Disc"); item_IDs.push_back(324);
        item_names.push_back(L"Durin Berry"); item_IDs.push_back(182);
        item_names.push_back(L"Dusk Ball"); item_IDs.push_back(13);
        item_names.push_back(L"Dusk Stone"); item_IDs.push_back(108);
        item_names.push_back(L"Earth Plate"); item_IDs.push_back(305);
        item_names.push_back(L"Eject Button"); item_IDs.push_back(547);
        item_names.push_back(L"Electirizer"); item_IDs.push_back(322);
        item_names.push_back(L"Electric Gem"); item_IDs.push_back(550);
        item_names.push_back(L"Elixir"); item_IDs.push_back(40);
        item_names.push_back(L"Energy Root"); item_IDs.push_back(35);
        item_names.push_back(L"EnergyPowder"); item_IDs.push_back(34);
        item_names.push_back(L"Enigma Berry"); item_IDs.push_back(208);
        item_names.push_back(L"Escape Rope"); item_IDs.push_back(78);
        item_names.push_back(L"Ether"); item_IDs.push_back(38);
        item_names.push_back(L"Everstone"); item_IDs.push_back(229);
        item_names.push_back(L"Eviolite"); item_IDs.push_back(538);
        item_names.push_back(L"Exp. Share"); item_IDs.push_back(216);
        item_names.push_back(L"Expert Belt"); item_IDs.push_back(268);
        item_names.push_back(L"Fast Ball"); item_IDs.push_back(492);
        item_names.push_back(L"Favored Mail"); item_IDs.push_back(138);
        item_names.push_back(L"Fighting Gem"); item_IDs.push_back(553);
        item_names.push_back(L"Figy Berry"); item_IDs.push_back(159);
        item_names.push_back(L"Fire Gem"); item_IDs.push_back(548);
        item_names.push_back(L"Fire Stone"); item_IDs.push_back(82);
        item_names.push_back(L"Fist Plate"); item_IDs.push_back(303);
        item_names.push_back(L"Flame Orb"); item_IDs.push_back(273);
        item_names.push_back(L"Flame Plate"); item_IDs.push_back(298);
        item_names.push_back(L"Float Stone"); item_IDs.push_back(539);
        item_names.push_back(L"Fluffy Tail"); item_IDs.push_back(64);
        item_names.push_back(L"Flying Gem"); item_IDs.push_back(556);
        item_names.push_back(L"Focus Band"); item_IDs.push_back(230);
        item_names.push_back(L"Focus Sash"); item_IDs.push_back(275);
        item_names.push_back(L"Fresh Water"); item_IDs.push_back(30);
        item_names.push_back(L"Friend Ball"); item_IDs.push_back(497);
        item_names.push_back(L"Full Heal"); item_IDs.push_back(27);
        item_names.push_back(L"Full Incense"); item_IDs.push_back(316);
        item_names.push_back(L"Full Restore"); item_IDs.push_back(23);
        item_names.push_back(L"Ganlon Berry"); item_IDs.push_back(202);
        item_names.push_back(L"GB Sounds"); item_IDs.push_back(502);
        item_names.push_back(L"Genius Wing"); item_IDs.push_back(568);
        item_names.push_back(L"Ghost Gem"); item_IDs.push_back(560);
        item_names.push_back(L"Gooey Mulch"); item_IDs.push_back(98);
        item_names.push_back(L"Grass Gem"); item_IDs.push_back(551);
        item_names.push_back(L"Great Ball"); item_IDs.push_back(3);
        item_names.push_back(L"Green Scarf"); item_IDs.push_back(263);
        item_names.push_back(L"Green Shard"); item_IDs.push_back(75);
        item_names.push_back(L"Greet Mail"); item_IDs.push_back(137);
        item_names.push_back(L"Grepa Berry"); item_IDs.push_back(173);
        item_names.push_back(L"Grip Claw"); item_IDs.push_back(286);
        item_names.push_back(L"Griseous Orb"); item_IDs.push_back(112);
        item_names.push_back(L"Ground Gem"); item_IDs.push_back(555);
        item_names.push_back(L"Growth Mulch"); item_IDs.push_back(95);
        item_names.push_back(L"Guard Spec."); item_IDs.push_back(55);
        item_names.push_back(L"Haban Berry"); item_IDs.push_back(197);
        item_names.push_back(L"Hard Stone"); item_IDs.push_back(238);
        item_names.push_back(L"Heal Ball"); item_IDs.push_back(14);
        item_names.push_back(L"Heal Powder"); item_IDs.push_back(36);
        item_names.push_back(L"Health Wing"); item_IDs.push_back(565);
        item_names.push_back(L"Heart Scale"); item_IDs.push_back(93);
        item_names.push_back(L"Heat Rock"); item_IDs.push_back(284);
        item_names.push_back(L"Heavy Ball"); item_IDs.push_back(495);
        item_names.push_back(L"Helix Fossil"); item_IDs.push_back(101);
        item_names.push_back(L"HM01"); item_IDs.push_back(420);
        item_names.push_back(L"HM02"); item_IDs.push_back(421);
        item_names.push_back(L"HM03"); item_IDs.push_back(422);
        item_names.push_back(L"HM04"); item_IDs.push_back(423);
        item_names.push_back(L"HM05"); item_IDs.push_back(424);
        item_names.push_back(L"HM06"); item_IDs.push_back(425);
        item_names.push_back(L"Hondew Berry"); item_IDs.push_back(172);
        item_names.push_back(L"Honey"); item_IDs.push_back(94);
        item_names.push_back(L"HP Up"); item_IDs.push_back(45);
        item_names.push_back(L"Hyper Potion"); item_IDs.push_back(25);
        item_names.push_back(L"Iapapa Berry"); item_IDs.push_back(163);
        item_names.push_back(L"Ice Gem"); item_IDs.push_back(552);
        item_names.push_back(L"Ice Heal"); item_IDs.push_back(20);
        item_names.push_back(L"Icicle Plate"); item_IDs.push_back(302);
        item_names.push_back(L"Icy Rock"); item_IDs.push_back(282);
        item_names.push_back(L"Inquiry Mail"); item_IDs.push_back(141);
        item_names.push_back(L"Insect Plate"); item_IDs.push_back(308);
        item_names.push_back(L"Iron"); item_IDs.push_back(47);
        item_names.push_back(L"Iron Ball"); item_IDs.push_back(278);
        item_names.push_back(L"Iron Plate"); item_IDs.push_back(313);
        item_names.push_back(L"Jaboca Berry"); item_IDs.push_back(211);
        item_names.push_back(L"Kasib Berry"); item_IDs.push_back(196);
        item_names.push_back(L"Kebia Berry"); item_IDs.push_back(190);
        item_names.push_back(L"Kelpsy Berry"); item_IDs.push_back(170);
        item_names.push_back(L"King's Rock"); item_IDs.push_back(221);
        item_names.push_back(L"Lagging Tail"); item_IDs.push_back(279);
        item_names.push_back(L"Lansat Berry"); item_IDs.push_back(206);
        item_names.push_back(L"Lava Cookie"); item_IDs.push_back(42);
        item_names.push_back(L"Lax Incense"); item_IDs.push_back(255);
        item_names.push_back(L"Leaf Stone"); item_IDs.push_back(85);
        item_names.push_back(L"Leftovers"); item_IDs.push_back(234);
        item_names.push_back(L"Lemonade"); item_IDs.push_back(32);
        item_names.push_back(L"Leppa Berry"); item_IDs.push_back(154);
        item_names.push_back(L"Level Ball"); item_IDs.push_back(493);
        item_names.push_back(L"Liechi Berry"); item_IDs.push_back(201);
        item_names.push_back(L"Life Orb"); item_IDs.push_back(270);
        item_names.push_back(L"Light Ball"); item_IDs.push_back(236);
        item_names.push_back(L"Light Clay"); item_IDs.push_back(269);
        item_names.push_back(L"Like Mail"); item_IDs.push_back(142);
        item_names.push_back(L"Love Ball"); item_IDs.push_back(496);
        item_names.push_back(L"Luck Incense"); item_IDs.push_back(319);
        item_names.push_back(L"Lucky Egg"); item_IDs.push_back(231);
        item_names.push_back(L"Lucky Punch"); item_IDs.push_back(256);
        item_names.push_back(L"Lum Berry"); item_IDs.push_back(157);
        item_names.push_back(L"Lure Ball"); item_IDs.push_back(494);
        item_names.push_back(L"Lustrous Orb"); item_IDs.push_back(136);
        item_names.push_back(L"Luxury Ball"); item_IDs.push_back(11);
        item_names.push_back(L"Macho Brace"); item_IDs.push_back(215);
        item_names.push_back(L"Magmarizer"); item_IDs.push_back(323);
        item_names.push_back(L"Magnet"); item_IDs.push_back(242);
        item_names.push_back(L"Mago Berry"); item_IDs.push_back(161);
        item_names.push_back(L"Magost Berry"); item_IDs.push_back(176);
        item_names.push_back(L"Master Ball"); item_IDs.push_back(1);
        item_names.push_back(L"Max Elixir"); item_IDs.push_back(41);
        item_names.push_back(L"Max Ether"); item_IDs.push_back(39);
        item_names.push_back(L"Max Potion"); item_IDs.push_back(24);
        item_names.push_back(L"Max Repel"); item_IDs.push_back(77);
        item_names.push_back(L"Max Revive"); item_IDs.push_back(29);
        item_names.push_back(L"Meadow Plate"); item_IDs.push_back(301);
        item_names.push_back(L"Mental Herb"); item_IDs.push_back(219);
        item_names.push_back(L"Metal Coat"); item_IDs.push_back(233);
        item_names.push_back(L"Metal Powder"); item_IDs.push_back(257);
        item_names.push_back(L"Metronome"); item_IDs.push_back(277);
        item_names.push_back(L"Micle Berry"); item_IDs.push_back(209);
        item_names.push_back(L"Mind Plate"); item_IDs.push_back(307);
        item_names.push_back(L"Miracle Seed"); item_IDs.push_back(239);
        item_names.push_back(L"Moomoo Milk"); item_IDs.push_back(33);
        item_names.push_back(L"Moon Ball"); item_IDs.push_back(498);
        item_names.push_back(L"Moon Stone"); item_IDs.push_back(81);
        item_names.push_back(L"Muscle Band"); item_IDs.push_back(266);
        item_names.push_back(L"Muscle Wing"); item_IDs.push_back(566);
        item_names.push_back(L"Mystic Water"); item_IDs.push_back(243);
        item_names.push_back(L"Nanab Berry"); item_IDs.push_back(166);
        item_names.push_back(L"Nest Ball"); item_IDs.push_back(8);
        item_names.push_back(L"Net Ball"); item_IDs.push_back(6);
        item_names.push_back(L"NeverMeltIce"); item_IDs.push_back(246);
        item_names.push_back(L"Nomel Berry"); item_IDs.push_back(178);
        item_names.push_back(L"Normal Gem"); item_IDs.push_back(564);
        item_names.push_back(L"Nugget"); item_IDs.push_back(92);
        item_names.push_back(L"Occa Berry"); item_IDs.push_back(184);
        item_names.push_back(L"Odd Incense"); item_IDs.push_back(314);
        item_names.push_back(L"Odd Keystone"); item_IDs.push_back(111);
        item_names.push_back(L"Old Amber"); item_IDs.push_back(103);
        item_names.push_back(L"Old Gateau"); item_IDs.push_back(54);
        item_names.push_back(L"Oran Berry"); item_IDs.push_back(155);
        item_names.push_back(L"Oval Stone"); item_IDs.push_back(110);
        item_names.push_back(L"Pamtre Berry"); item_IDs.push_back(180);
        item_names.push_back(L"Park Ball"); item_IDs.push_back(500);
        item_names.push_back(L"Parlyz Heal"); item_IDs.push_back(22);
        item_names.push_back(L"Pass Orb"); item_IDs.push_back(575);
        item_names.push_back(L"Passho Berry"); item_IDs.push_back(185);
        item_names.push_back(L"Payapa Berry"); item_IDs.push_back(193);
        item_names.push_back(L"Pearl"); item_IDs.push_back(88);
        item_names.push_back(L"Pearl String"); item_IDs.push_back(582);
        item_names.push_back(L"Pecha Berry"); item_IDs.push_back(151);
        item_names.push_back(L"Persim Berry"); item_IDs.push_back(156);
        item_names.push_back(L"Petaya Berry"); item_IDs.push_back(204);
        item_names.push_back(L"Photo Album"); item_IDs.push_back(501);
        item_names.push_back(L"Pinap Berry"); item_IDs.push_back(168);
        item_names.push_back(L"Pink Scarf"); item_IDs.push_back(262);
        item_names.push_back(L"Plume Fossil"); item_IDs.push_back(573);
        item_names.push_back(L"Poison Barb"); item_IDs.push_back(245);
        item_names.push_back(L"Poison Gem"); item_IDs.push_back(554);
        item_names.push_back(L"Poké Ball"); item_IDs.push_back(4);
        item_names.push_back(L"Poké Doll"); item_IDs.push_back(63);
        item_names.push_back(L"Poké Toy"); item_IDs.push_back(577);
        item_names.push_back(L"Pomeg Berry"); item_IDs.push_back(169);
        item_names.push_back(L"Potion"); item_IDs.push_back(17);
        item_names.push_back(L"Power Anklet"); item_IDs.push_back(293);
        item_names.push_back(L"Power Band"); item_IDs.push_back(292);
        item_names.push_back(L"Power Belt"); item_IDs.push_back(290);
        item_names.push_back(L"Power Bracer"); item_IDs.push_back(289);
        item_names.push_back(L"Power Herb"); item_IDs.push_back(271);
        item_names.push_back(L"Power Lens"); item_IDs.push_back(291);
        item_names.push_back(L"Power Weight"); item_IDs.push_back(294);
        item_names.push_back(L"PP Max"); item_IDs.push_back(53);
        item_names.push_back(L"PP Up"); item_IDs.push_back(51);
        item_names.push_back(L"Premier Ball"); item_IDs.push_back(12);
        item_names.push_back(L"Pretty Wing"); item_IDs.push_back(571);
        item_names.push_back(L"Prism Scale"); item_IDs.push_back(537);
        item_names.push_back(L"Protector"); item_IDs.push_back(321);
        item_names.push_back(L"Protein"); item_IDs.push_back(46);
        item_names.push_back(L"Psychic Gem"); item_IDs.push_back(557);
        item_names.push_back(L"Pure Incense"); item_IDs.push_back(320);
        item_names.push_back(L"Qualot Berry"); item_IDs.push_back(171);
        item_names.push_back(L"Quick Ball"); item_IDs.push_back(15);
        item_names.push_back(L"Quick Claw"); item_IDs.push_back(217);
        item_names.push_back(L"Quick Powder"); item_IDs.push_back(274);
        item_names.push_back(L"Rabuta Berry"); item_IDs.push_back(177);
        item_names.push_back(L"RageCandyBar"); item_IDs.push_back(504);
        item_names.push_back(L"Rare Bone"); item_IDs.push_back(106);
        item_names.push_back(L"Rare Candy"); item_IDs.push_back(50);
        item_names.push_back(L"Rawst Berry"); item_IDs.push_back(152);
        item_names.push_back(L"Razor Claw"); item_IDs.push_back(326);
        item_names.push_back(L"Razor Fang"); item_IDs.push_back(327);
        item_names.push_back(L"Razz Berry"); item_IDs.push_back(164);
        item_names.push_back(L"Reaper Cloth"); item_IDs.push_back(325);
        item_names.push_back(L"Red Card"); item_IDs.push_back(542);
        item_names.push_back(L"Red Flute"); item_IDs.push_back(67);
        item_names.push_back(L"Red Scarf"); item_IDs.push_back(260);
        item_names.push_back(L"Red Shard"); item_IDs.push_back(72);
        item_names.push_back(L"Relic Band"); item_IDs.push_back(588);
        item_names.push_back(L"Relic Copper"); item_IDs.push_back(584);
        item_names.push_back(L"Relic Crown"); item_IDs.push_back(590);
        item_names.push_back(L"Relic Gold"); item_IDs.push_back(586);
        item_names.push_back(L"Relic Silver"); item_IDs.push_back(585);
        item_names.push_back(L"Relic Statue"); item_IDs.push_back(589);
        item_names.push_back(L"Relic Vase"); item_IDs.push_back(587);
        item_names.push_back(L"Repeat Ball"); item_IDs.push_back(9);
        item_names.push_back(L"Repel"); item_IDs.push_back(79);
        item_names.push_back(L"Reply Mail"); item_IDs.push_back(143);
        item_names.push_back(L"Resist Wing"); item_IDs.push_back(567);
        item_names.push_back(L"Revival Herb"); item_IDs.push_back(37);
        item_names.push_back(L"Revive"); item_IDs.push_back(28);
        item_names.push_back(L"Rindo Berry"); item_IDs.push_back(187);
        item_names.push_back(L"Ring Target"); item_IDs.push_back(543);
        item_names.push_back(L"Rock Gem"); item_IDs.push_back(559);
        item_names.push_back(L"Rock Incense"); item_IDs.push_back(315);
        item_names.push_back(L"Rocky Helmet"); item_IDs.push_back(540);
        item_names.push_back(L"Root Fossil"); item_IDs.push_back(99);
        item_names.push_back(L"Rose Incense"); item_IDs.push_back(318);
        item_names.push_back(L"Rowap Berry"); item_IDs.push_back(212);
        item_names.push_back(L"RSVP Mail"); item_IDs.push_back(139);
        item_names.push_back(L"Sacred Ash"); item_IDs.push_back(44);
        item_names.push_back(L"Safari Ball"); item_IDs.push_back(5);
        item_names.push_back(L"Salac Berry"); item_IDs.push_back(203);
        item_names.push_back(L"Scope Lens"); item_IDs.push_back(232);
        item_names.push_back(L"Sea Incense"); item_IDs.push_back(254);
        item_names.push_back(L"Sharp Beak"); item_IDs.push_back(244);
        item_names.push_back(L"Shed Shell"); item_IDs.push_back(295);
        item_names.push_back(L"Shell Bell"); item_IDs.push_back(253);
        item_names.push_back(L"Shiny Stone"); item_IDs.push_back(107);
        item_names.push_back(L"Shoal Salt"); item_IDs.push_back(70);
        item_names.push_back(L"Shoal Shell"); item_IDs.push_back(71);
        item_names.push_back(L"Shock Drive"); item_IDs.push_back(117);
        item_names.push_back(L"Shuca Berry"); item_IDs.push_back(191);
        item_names.push_back(L"Silk Scarf"); item_IDs.push_back(251);
        item_names.push_back(L"SilverPowder"); item_IDs.push_back(222);
        item_names.push_back(L"Sitrus Berry"); item_IDs.push_back(158);
        item_names.push_back(L"Skull Fossil"); item_IDs.push_back(105);
        item_names.push_back(L"Sky Plate"); item_IDs.push_back(306);
        item_names.push_back(L"Smoke Ball"); item_IDs.push_back(228);
        item_names.push_back(L"Smooth Rock"); item_IDs.push_back(283);
        item_names.push_back(L"Soda Pop"); item_IDs.push_back(31);
        item_names.push_back(L"Soft Sand"); item_IDs.push_back(237);
        item_names.push_back(L"Soothe Bell"); item_IDs.push_back(218);
        item_names.push_back(L"Soul Dew"); item_IDs.push_back(225);
        item_names.push_back(L"Spell Tag"); item_IDs.push_back(247);
        item_names.push_back(L"Spelon Berry"); item_IDs.push_back(179);
        item_names.push_back(L"Splash Plate"); item_IDs.push_back(299);
        item_names.push_back(L"Spooky Plate"); item_IDs.push_back(310);
        item_names.push_back(L"Sport Ball"); item_IDs.push_back(499);
        item_names.push_back(L"Stable Mulch"); item_IDs.push_back(97);
        item_names.push_back(L"Star Piece"); item_IDs.push_back(91);
        item_names.push_back(L"Stardust"); item_IDs.push_back(90);
        item_names.push_back(L"Starf Berry"); item_IDs.push_back(207);
        item_names.push_back(L"Steel Gem"); item_IDs.push_back(563);
        item_names.push_back(L"Stick"); item_IDs.push_back(259);
        item_names.push_back(L"Sticky Barb"); item_IDs.push_back(288);
        item_names.push_back(L"Stone Plate"); item_IDs.push_back(309);
        item_names.push_back(L"Sun Stone"); item_IDs.push_back(80);
        item_names.push_back(L"Super Potion"); item_IDs.push_back(26);
        item_names.push_back(L"Super Repel"); item_IDs.push_back(76);
        item_names.push_back(L"Sweet Heart"); item_IDs.push_back(134);
        item_names.push_back(L"Swift Wing"); item_IDs.push_back(570);
        item_names.push_back(L"Tamato Berry"); item_IDs.push_back(174);
        item_names.push_back(L"Tanga Berry"); item_IDs.push_back(194);
        item_names.push_back(L"Thanks Mail"); item_IDs.push_back(140);
        item_names.push_back(L"Thick Club"); item_IDs.push_back(258);
        item_names.push_back(L"Thunder Stone"); item_IDs.push_back(83);
        item_names.push_back(L"Tidal Bell"); item_IDs.push_back(503);
        item_names.push_back(L"Timer Ball"); item_IDs.push_back(10);
        item_names.push_back(L"TinyMushroom"); item_IDs.push_back(86);
        item_names.push_back(L"TM01"); item_IDs.push_back(328);
        item_names.push_back(L"TM02"); item_IDs.push_back(329);
        item_names.push_back(L"TM03"); item_IDs.push_back(330);
        item_names.push_back(L"TM04"); item_IDs.push_back(331);
        item_names.push_back(L"TM05"); item_IDs.push_back(332);
        item_names.push_back(L"TM06"); item_IDs.push_back(333);
        item_names.push_back(L"TM07"); item_IDs.push_back(334);
        item_names.push_back(L"TM08"); item_IDs.push_back(335);
        item_names.push_back(L"TM09"); item_IDs.push_back(336);
        item_names.push_back(L"TM10"); item_IDs.push_back(337);
        item_names.push_back(L"TM11"); item_IDs.push_back(338);
        item_names.push_back(L"TM12"); item_IDs.push_back(339);
        item_names.push_back(L"TM13"); item_IDs.push_back(340);
        item_names.push_back(L"TM14"); item_IDs.push_back(341);
        item_names.push_back(L"TM15"); item_IDs.push_back(342);
        item_names.push_back(L"TM16"); item_IDs.push_back(343);
        item_names.push_back(L"TM17"); item_IDs.push_back(344);
        item_names.push_back(L"TM18"); item_IDs.push_back(345);
        item_names.push_back(L"TM19"); item_IDs.push_back(346);
        item_names.push_back(L"TM20"); item_IDs.push_back(347);
        item_names.push_back(L"TM21"); item_IDs.push_back(348);
        item_names.push_back(L"TM22"); item_IDs.push_back(349);
        item_names.push_back(L"TM23"); item_IDs.push_back(350);
        item_names.push_back(L"TM24"); item_IDs.push_back(351);
        item_names.push_back(L"TM25"); item_IDs.push_back(352);
        item_names.push_back(L"TM26"); item_IDs.push_back(353);
        item_names.push_back(L"TM27"); item_IDs.push_back(354);
        item_names.push_back(L"TM28"); item_IDs.push_back(355);
        item_names.push_back(L"TM29"); item_IDs.push_back(356);
        item_names.push_back(L"TM30"); item_IDs.push_back(357);
        item_names.push_back(L"TM31"); item_IDs.push_back(358);
        item_names.push_back(L"TM32"); item_IDs.push_back(359);
        item_names.push_back(L"TM33"); item_IDs.push_back(360);
        item_names.push_back(L"TM34"); item_IDs.push_back(361);
        item_names.push_back(L"TM35"); item_IDs.push_back(362);
        item_names.push_back(L"TM36"); item_IDs.push_back(363);
        item_names.push_back(L"TM37"); item_IDs.push_back(364);
        item_names.push_back(L"TM38"); item_IDs.push_back(365);
        item_names.push_back(L"TM39"); item_IDs.push_back(366);
        item_names.push_back(L"TM40"); item_IDs.push_back(367);
        item_names.push_back(L"TM41"); item_IDs.push_back(368);
        item_names.push_back(L"TM42"); item_IDs.push_back(369);
        item_names.push_back(L"TM43"); item_IDs.push_back(370);
        item_names.push_back(L"TM44"); item_IDs.push_back(371);
        item_names.push_back(L"TM45"); item_IDs.push_back(372);
        item_names.push_back(L"TM46"); item_IDs.push_back(373);
        item_names.push_back(L"TM47"); item_IDs.push_back(374);
        item_names.push_back(L"TM48"); item_IDs.push_back(375);
        item_names.push_back(L"TM49"); item_IDs.push_back(376);
        item_names.push_back(L"TM50"); item_IDs.push_back(377);
        item_names.push_back(L"TM51"); item_IDs.push_back(378);
        item_names.push_back(L"TM52"); item_IDs.push_back(379);
        item_names.push_back(L"TM53"); item_IDs.push_back(380);
        item_names.push_back(L"TM54"); item_IDs.push_back(381);
        item_names.push_back(L"TM55"); item_IDs.push_back(382);
        item_names.push_back(L"TM56"); item_IDs.push_back(383);
        item_names.push_back(L"TM57"); item_IDs.push_back(384);
        item_names.push_back(L"TM58"); item_IDs.push_back(385);
        item_names.push_back(L"TM59"); item_IDs.push_back(386);
        item_names.push_back(L"TM60"); item_IDs.push_back(387);
        item_names.push_back(L"TM61"); item_IDs.push_back(388);
        item_names.push_back(L"TM62"); item_IDs.push_back(389);
        item_names.push_back(L"TM63"); item_IDs.push_back(390);
        item_names.push_back(L"TM64"); item_IDs.push_back(391);
        item_names.push_back(L"TM65"); item_IDs.push_back(392);
        item_names.push_back(L"TM66"); item_IDs.push_back(393);
        item_names.push_back(L"TM67"); item_IDs.push_back(394);
        item_names.push_back(L"TM68"); item_IDs.push_back(395);
        item_names.push_back(L"TM69"); item_IDs.push_back(396);
        item_names.push_back(L"TM70"); item_IDs.push_back(397);
        item_names.push_back(L"TM71"); item_IDs.push_back(398);
        item_names.push_back(L"TM72"); item_IDs.push_back(399);
        item_names.push_back(L"TM73"); item_IDs.push_back(400);
        item_names.push_back(L"TM74"); item_IDs.push_back(401);
        item_names.push_back(L"TM75"); item_IDs.push_back(402);
        item_names.push_back(L"TM76"); item_IDs.push_back(403);
        item_names.push_back(L"TM77"); item_IDs.push_back(404);
        item_names.push_back(L"TM78"); item_IDs.push_back(405);
        item_names.push_back(L"TM79"); item_IDs.push_back(406);
        item_names.push_back(L"TM80"); item_IDs.push_back(407);
        item_names.push_back(L"TM81"); item_IDs.push_back(408);
        item_names.push_back(L"TM82"); item_IDs.push_back(409);
        item_names.push_back(L"TM83"); item_IDs.push_back(410);
        item_names.push_back(L"TM84"); item_IDs.push_back(411);
        item_names.push_back(L"TM85"); item_IDs.push_back(412);
        item_names.push_back(L"TM86"); item_IDs.push_back(413);
        item_names.push_back(L"TM87"); item_IDs.push_back(414);
        item_names.push_back(L"TM88"); item_IDs.push_back(415);
        item_names.push_back(L"TM89"); item_IDs.push_back(416);
        item_names.push_back(L"TM90"); item_IDs.push_back(417);
        item_names.push_back(L"TM91"); item_IDs.push_back(418);
        item_names.push_back(L"TM92"); item_IDs.push_back(419);
        item_names.push_back(L"Toxic Orb"); item_IDs.push_back(272);
        item_names.push_back(L"Toxic Plate"); item_IDs.push_back(304);
        item_names.push_back(L"TwistedSpoon"); item_IDs.push_back(248);
        item_names.push_back(L"Ultra Ball"); item_IDs.push_back(2);
        item_names.push_back(L"Up-Grade"); item_IDs.push_back(252);
        item_names.push_back(L"Wacan Berry"); item_IDs.push_back(186);
        item_names.push_back(L"Water Gem"); item_IDs.push_back(549);
        item_names.push_back(L"Water Stone"); item_IDs.push_back(84);
        item_names.push_back(L"Watmel Berry"); item_IDs.push_back(181);
        item_names.push_back(L"Wave Incense"); item_IDs.push_back(317);
        item_names.push_back(L"Wepear Berry"); item_IDs.push_back(167);
        item_names.push_back(L"White Flute"); item_IDs.push_back(69);
        item_names.push_back(L"White Herb"); item_IDs.push_back(214);
        item_names.push_back(L"Wide Lens"); item_IDs.push_back(265);
        item_names.push_back(L"Wiki Berry"); item_IDs.push_back(160);
        item_names.push_back(L"Wise Glasses"); item_IDs.push_back(267);
        item_names.push_back(L"X Accuracy"); item_IDs.push_back(60);
        item_names.push_back(L"X Attack"); item_IDs.push_back(57);
        item_names.push_back(L"X Defend"); item_IDs.push_back(58);
        item_names.push_back(L"X Sp. Def"); item_IDs.push_back(62);
        item_names.push_back(L"X Special"); item_IDs.push_back(61);
        item_names.push_back(L"X Speed"); item_IDs.push_back(59);
        item_names.push_back(L"Yache Berry"); item_IDs.push_back(188);
        item_names.push_back(L"Yellow Flute"); item_IDs.push_back(66);
        item_names.push_back(L"Yellow Scarf"); item_IDs.push_back(264);
        item_names.push_back(L"Yellow Shard"); item_IDs.push_back(74);
        item_names.push_back(L"Zap Plate"); item_IDs.push_back(300);
        item_names.push_back(L"Zinc"); item_IDs.push_back(52);
        item_names.push_back(L"Zoom Lens"); item_IDs.push_back(276);
    }

    int GetItemID(CString name)
    {
        int ID = -1;
        for (unsigned int i = 0u; i < item_names.size(); ++i)
            if (item_names[i] == name)
            {
                ID = item_IDs[i];
                break;
            }
        return ID;
    }

    CString GetItemName(int ID)
    {
        CString name;
        for (unsigned int i = 0u; i < item_names.size(); ++i)
            if (item_IDs[i] == ID)
            {
                name = item_names[i];
                break;
            }
        return name;
    }

    std::vector<CString> item_names;
    std::vector<int> item_IDs;
};

