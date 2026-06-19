#ifndef GENERATOR_H
#define GENERATOR_H

#endif // GENERATOR_H

#include <QString>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QDirIterator>

// активка в контексте генератора(ActiveItem/TaintedActiveItem) - карманная активка

class Character {
private:
    QString mName; // mod name
    QString cName; // character name
    QString ccName; // character name in code (without spaces)
    int health;
    int armor;
    int black;
    QString path;
    QString items;
    bool haveTainted;
    bool haveActiveItem;
    int activeItem;
    int keys;
    int bombs;
    int coins;
    float dmg;
    float speed;
    bool canFly;
    float luck;
    int trinket;
    float range;
    float shotSpeed;
    // tainted
    int tHealth;
    int tArmor;
    int tBlack;
    int tKeys;
    int tBombs;
    int tCoins;
    QString tItems;
    int tActive;
    int tTrinket;
    float tDmg;
    float tSpeed;
    float tLuck;
    float tRange;
    float tShotSpeed;
    bool canShoot;
public:
    Character(const QString &mName, const QString &cName, int health, int armor, int black, const QString &path, const QString &items, bool haveTainted, bool haveActiveItem,
              int activeItem, int keys, int bombs, int coins, int tHealth, int tArmor, int tKeys, int tBombs, int tCoins, QString tItems, int tActive, float dmg, float speed,
              bool canFly, float luck, int trinket, float range, float shotSpeed, int tBlack, int tTrinket, float tDmg, float tSpeed, float tLuck, float tRange, float tShotSpeed, bool canShoot) {
        this->mName = mName;
        this->cName = cName;
        this->health = health;
        this->armor = armor;
        this->black = black;
        this->path = path;
        this->items = items;
        this->haveTainted = haveTainted;
        this->haveActiveItem = haveActiveItem;
        this->activeItem = activeItem;
        this->keys = keys;
        this->bombs = bombs;
        this->coins = coins;
        this->tHealth = tHealth;
        this->tArmor = tArmor;
        this->tKeys = tKeys;
        this->tBombs = tBombs;
        this->tCoins = tCoins;
        this->tItems = tItems;
        this->tActive = tActive;
        this->dmg = dmg;
        this->speed = speed;
        this->canFly = canFly;
        this->luck = luck;
        this->trinket = trinket;
        this->range = range;
        this->shotSpeed = shotSpeed;
        this->tBlack = tBlack;
        this->tTrinket = tTrinket;
        this->tDmg = tDmg;
        this->tSpeed = tSpeed;
        this->tLuck = tLuck;
        this->tRange = tRange;
        this->tShotSpeed = tShotSpeed;
        this->canShoot = canShoot;

        this->ccName = cName;
        ccName.remove(' ');
    }



    void createModFolder(const QString &modPath) {
        QDir dir;
        if (dir.mkdir(modPath)) {
            dir.mkdir(modPath + "/content");
            dir.mkdir(modPath + "/resources");
            dir.mkdir(modPath + "/content/gfx");
            dir.mkdir(modPath + "/resources/gfx");
            dir.mkdir(modPath + "/resources/gfx/characters");
            dir.mkdir(modPath + "/resources/gfx/characters/costumes");
            dir.mkdir(modPath + "/resources/gfx/characters/costumes_" + this->cName +"b");
            dir.mkdir(modPath + "/resources/gfx/items");
            dir.mkdir(modPath + "/resources/gfx/items/collectibles");
            dir.mkdir(modPath + "/resources/gfx/ui");
            dir.mkdir(modPath + "/resources/gfx/ui/boss");
            dir.mkdir(modPath + "/resources/gfx/ui/stage");
            qDebug() << "success";
        }
    }

    void createModFiles(const QString &modPath) {
        QFile mainLua(modPath + "/main.lua");

        if (mainLua.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&mainLua);
            stream << "local MyCharacterMod = RegisterMod(\"" << this->mName << "\", 1)" << "\n";
            stream << "\n" << "local " << this->ccName << "Type = Isaac.GetPlayerTypeByName(\"" << this->cName << "\", false)" << "\n";
            if (this->haveTainted) {
                stream << "\n" << "local TAINTED_" << this->ccName.toUpper() << "_TYPE = Isaac.GetPlayerTypeByName(\"" << this->cName << "\", true)" << "\n";
            }
            stream << "local hairCostume = Isaac.GetCostumeIdByPath(\"gfx/characters/" << this->cName << "_hair.anm2\")" << "\n";
            stream << "local stolesCostume = Isaac.GetCostumeIdByPath(\"gfx/characters/" << this->cName << "_stoles.anm2\")" << "\n";
            stream << "\n" << "function MyCharacterMod:GiveCostumesOnInit(player)" << "\n";
            stream << "    if player:GetPlayerType() ~= " << this->ccName <<  "Type then" << "\n";
            stream << "        return" << "\n";
            stream << "    end" << "\n";
            stream << "\n" << "    player:AddNullCostume(hairCostume)" << "\n";
            stream << "    player:AddNullCostume(stolesCostume)" << "\n";
            stream << "end" << "\n";
            stream << "\n" << "MyCharacterMod:AddCallback(ModCallbacks.MC_POST_PLAYER_INIT, MyCharacterMod.GiveCostumesOnInit)" << "\n";
            stream << "\n" << "local game = Game()" << "\n";
            stream << "\n" << "local dmgAtStart = " << this->dmg << " - 3.5" << "\n";
            stream << "local spdAtStart = " << this->speed << " - 1" << "\n";
            stream << "local luckAtStart = " << this->luck << "\n";
            stream << "local rangeAtStart = " << this->range << " - 7.96" << "\n";
            stream << "local shotSpeedAtStart = " << this->shotSpeed << " - 1" << "\n";
            stream << "\n" << "local tDmgAtStart = " << this->tDmg << " - 3.5" << "\n";
            stream << "local tSpdAtStart = " << this->tSpeed << " - 1" << "\n";
            stream << "local tLuckAtStart = " << this->tLuck << "\n";
            stream << "local tRangeAtStart = " << this->tRange << " - 7.96" << "\n";
            stream << "local tShotSpeedAtStart = " << this->tShotSpeed << " - 1" << "\n";
            stream << "\n" << "function MyCharacterMod:HandleStartingStats(player, flag)" << "\n";
            stream << "    if player:GetPlayerType() == " << this->ccName << "Type then" << "\n";
            stream << "        if flag == CacheFlag.CACHE_DAMAGE then" << "\n";
            stream << "            player.Damage = player.Damage + dmgAtStart"<< "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_SPEED then" << "\n";
            stream << "            player.MoveSpeed = player.MoveSpeed + spdAtStart" << "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_LUCK then" << "\n";
            stream << "            player.Luck = player.Luck + luckAtStart" << "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_RANGE then" << "\n";
            stream << "            player.TearRange = player.TearRange + rangeAtStart" << "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_SHOTSPEED then" << "\n";
            stream << "            player.ShotSpeed = player.ShotSpeed + shotSpeedAtStart" << "\n";
            stream << "        end" << "\n";
            if (this->canFly == true) {
                stream << "        if flag == CacheFlag.CACHE_FLYING then" << "\n";
                stream << "            player.CanFly = true" << "\n";
                stream << "        end" << "\n";
            }
            stream << "    end" << "\n";
            stream << "   if player:GetPlayerType() == TAINTED_" << this->ccName.toUpper() << "_TYPE then" << "\n";
            stream << "        if flag == CacheFlag.CACHE_DAMAGE then" << "\n";
            stream << "            player.Damage = player.Damage + tDmgAtStart"<< "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_SPEED then" << "\n";
            stream << "            player.MoveSpeed = player.MoveSpeed + tSpdAtStart" << "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_LUCK then" << "\n";
            stream << "            player.Luck = player.Luck + tLuckAtStart" << "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_RANGE then" << "\n";
            stream << "            player.TearRange = player.TearRange + tRangeAtStart" << "\n";
            stream << "        end" << "\n";
            stream << "        if flag == CacheFlag.CACHE_SHOTSPEED then" << "\n";
            stream << "            player.ShotSpeed = player.ShotSpeed + tShotSpeedAtStart" << "\n";
            stream << "        end" << "\n";
            if (this->canFly == true) {
                stream << "        if flag == CacheFlag.CACHE_FLYING then" << "\n";
                stream << "            player.CanFly = true" << "\n";
                stream << "        end" << "\n";
            }
            stream << "    end" << "\n";
            stream << "end" << "\n";

            stream << "\n" << "MyCharacterMod:AddCallback(ModCallbacks.MC_EVALUATE_CACHE, MyCharacterMod.HandleStartingStats)" << "\n";

            if (this->haveTainted) {
                stream << "---@param player EntityPlayer" << "\n";
                stream << "function MyCharacterMod:Tainted" << this->ccName << "Init(player)" << "\n";
                stream << "    if player:GetPlayerType() ~= TAINTED_" << this->ccName.toUpper() << "_TYPE then" << "\n";
                stream << "        return" << "\n";
                stream << "    end" << "\n";
                stream << "end" << "\n";
                stream << "\n" << "MyCharacterMod:AddCallback(ModCallbacks.MC_POST_PLAYER_INIT, MyCharacterMod.Tainted" << this->ccName << "Init)" << "\n";

            }
        }

        QFile costumes2(modPath + "/content/costumes2.xml");

        if (costumes2.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&costumes2);

            stream << "<costumes anm2root=\"gfx/characters/\">" << "\n";
            stream << "    <costume anm2path=\"" << this->cName << "_hair.anm2\" type=\"none\" priority=\"100\" />" << "\n";
            stream << "    <costume anm2path=\"" << this->cName << "_stoles.anm2\" type=\"none\" priority=\"100\" />" << "\n";
            stream << "</costumes>";
        }

        QFile playersXml(modPath + "/content/players.xml");

        if (playersXml.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&playersXml);

            stream << "<players root=\"gfx/characters/costumes/\" portraitroot=\"gfx/ui/stage/\" nameimageroot=\"gfx/ui/boss/\">" << "\n";
            stream << "    <player name=\"" << this->cName << "\"" << "\n";
            stream << "        skin=\"character_" << this->cName << ".png\"" << "\n";
            stream << "        nameimage=\"playername_" << this->cName << ".png\"" << "\n";
            stream << "        hp=\"" << this->health << "\"" << "\n";
            stream << "        armor=\"" << this->armor << "\"" << "\n";
            stream << "        black=\"" << this->black << "\"" << "\n";
            stream << "        keys=\"" << this->keys << "\"" << "\n";
            stream << "        bombs=\"" << this->bombs << "\"" << "\n";
            stream << "        coins=\"" << this->coins << "\"" << "\n";
            stream << "        trinket=\"" << this->trinket << "\"" << "\n";
            stream << "        portrait=\"playerportrait_" << this->cName << ".png\"" << "\n";
            stream << "        skinColor=\"-1\"" << "\n";
            stream << "        items=\"" << this->items << "\"" << "\n";
            stream << "        canShoot=\"" << this->canShoot << "\"" << "\n";
            if (this->haveActiveItem) {
                stream << "        pocketActive=\"" << this->activeItem << "\"" << "\n";
            }
            stream << "    />" << "\n";

            if (this->haveTainted) {
                stream << "    <player name=\"" << this->cName << "\"" << "\n";
                stream << "        skin=\"character_" << this->cName << "_b.png\"" << "\n";
                stream << "        hp=\"" << this->tHealth << "\"" << "\n";
                stream << "        armor=\"" << this->tArmor << "\"" << "\n";
                stream << "        keys=\"" << this->tKeys << "\"" << "\n";
                stream << "        bombs=\"" << this->tBombs << "\"" << "\n";
                stream << "        coins=\"" << this->tCoins << "\"" << "\n";
                stream << "        trinket=\"" << this->tTrinket << "\"" << "\n";
                stream << "        nameimage=\"playername_" << this->cName << ".png\"" << "\n";
                stream << "        portrait=\"playerportrait_" << this->cName << "_b.png\"" << "\n";
                stream << "        skinColor=\"-1\"" << "\n";
                stream << "        bSkinParent=\"" << this->cName << "\"" << "\n";
                stream << "        costumeSuffix=\"" << this->cName << "b\"" << "\n";
                stream << "        items=\"" << this->tItems << "\"" << "\n";
                if (this->haveActiveItem) {
                    stream << "        pocketActive=\"" << this->tActive << "\"" << "\n";
                }
                if (this->canShoot) {
                    stream << "        canShoot=\"1\"" << "\n";
                }
                stream << "    />" << "\n";
            }

            stream << "</players>";
        }

        QFile itemsXml (modPath + "/content/items.xml");

        if (itemsXml.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&itemsXml);

            stream << "<items gfxroot=\"gfx/items/\" version=\"1\">" << "\n";
            stream << "\n" << "</items>";
        }


    }

    void insertResources(const QString &modPath) {
        QString path = QDir::currentPath() + "/resources/content-gfx";
        QString path2 = modPath + "/content/gfx";

        QFile::copy(path + "/charactermenu.anm2", path2 + "/charactermenu.anm2");
        QFile::copy(path + "/charactermenualt.anm2", path2 + "/charactermenualt.anm2");
        QFile::copy(path + "/characterportraits.anm2", path2 + "/characterportraits.anm2");
        QFile::copy(path + "/characterportraitsalt.anm2", path2 + "/characterportraitsalt.anm2");
        QFile::copy(path + "/controls alt.anm2", path2 + "/controls alt.anm2");
        QFile::copy(path + "/controls alt.png", path2 + "/controls alt.png");
        QFile::copy(path + "/controls.anm2", path2 + "/controls.anm2");
        QFile::copy(path + "/controls.png", path2 + "/controls.png");
        QFile::copy(path + "/coop menu alt.anm2", path2 + "//coop menu alt.anm2");
        QFile::copy(path + "/coop menu.anm2", path2 + "//coop menu.anm2");
        QFile::copy(path + "/coop_icon.png", path2 + "/coop_icon.png");
        QFile::copy(path + "/death screen alt.anm2", path2 + "/death screen alt.anm2");
        QFile::copy(path + "/death screen.anm2", path2 + "/death screen.anm2");
        QFile::copy(path + "/deathname_gabriel.png", path2 + "/deathname_" + this->cName + ".anm2");
        QFile::copy(path + "/menu gabriel.aseprite", path2 + "/menu " + this->cName + ".aseprite");
        QFile::copy(path + "/menu gabriel.png", path2 + "/menu " + this->cName + ".png");

        path = QDir::currentPath() + "/resources/characters";
        path2 = modPath + "/resources/gfx/characters";

        QFile::copy(path + "/gabriel_hair.anm2", path2 + "/" + this->cName + ".anm2");
        QFile::copy(path + "/gabriel_stoles.anm2", path2 + "/" + this->cName + "gabriel_stoles.anm2");

        path = QDir::currentPath() + "/resources/characters-costumes";
        path2 = modPath + "/resources/gfx/characters/costumes";

        QFile::copy(path + "/character_gabriel.png", path2 + "/character_" + this->cName + ".png");
        QFile::copy(path + "/character_gabriel_b.png", path2 + "/character_" + this->cName + "_b.png");
        QFile::copy(path + "/character_gabriel_b_black.png", path2 + "/character_" + this->cName + "_b_black.png");
        QFile::copy(path + "/character_gabriel_b_blue.png", path2 + "/character_" + this->cName + "_b_blue.png");
        QFile::copy(path + "/character_gabriel_b_green.png", path2 + "/character_" + this->cName + "_b_green.png");
        QFile::copy(path + "/character_gabriel_b_grey.png", path2 + "/character_" + this->cName + "_b_grey.png");
        QFile::copy(path + "/character_gabriel_b_red.png", path2 + "/character_" + this->cName + "_b_red.png");
        QFile::copy(path + "/character_gabriel_b_white.png", path2 + "/character_" + this->cName + "_b_white.png");
        QFile::copy(path + "/character_gabriel_black.png", path2 + "/character_" + this->cName + "_black.png");
        QFile::copy(path + "/character_gabriel_blue.png", path2 + "/character_" + this->cName + "_blue.png");
        QFile::copy(path + "/character_gabriel_gray.png", path2 + "/character_" + this->cName + "_gray.png");
        QFile::copy(path + "/character_gabriel_green.png", path2 + "/character_" + this->cName + "_green.png");
        QFile::copy(path + "/character_gabriel_red.png", path2 + "/character_" + this->cName + "_red.png");
        QFile::copy(path + "/character_gabriel_white.png", path2 + "/character_" + this->cName + "_white.png");
        QFile::copy(path + "/gabriel body.png", path2 + "/" + this->cName + "body.png");
        QFile::copy(path + "/gabriel hair.png", path2 + "/" + this->cName + "hair.png");

        path = QDir::currentPath() + "/resources/characters-costumes_b";
        path2 = modPath + "/resources/gfx/characters/costumes_" + this->cName + "b";

        QFile::copy(path + "/character_009b_lazarus2hair.png", path2 + "/character_009b_lazarus2hair.png");
        QFile::copy(path + "/character_009b_lazarusbody.png", path2 + "/character_009b_lazarusbody.png");

        path = QDir::currentPath() + "/resources/ui-boss";
        path2 = modPath + "/resources/gfx/ui/boss";

        QFile::copy(path + "/playername_gabriel.png", path2 + "/playername_" + this->cName + ".png");
        QFile::copy(path + "/playername_gabriel_b.png", path2 + "/playername_" + this->cName + "_b.png");

        path = QDir::currentPath() + "/resources/ui-stage";
        path2 = modPath + "/resources/gfx/ui/stage";

        QFile::copy(path + "/playerportrait_gabriel.png", path2 + "/playerportrait_" + this->cName + ".png");
        QFile::copy(path + "/playerportrait_gabriel_b.png", path2 + "/playerportrait_" + this->cName + "_b.png");

    }

    void generateMod() {
        QString modPath = this->path + "/" + this->mName;
        createModFolder(modPath);
        createModFiles(modPath);
        insertResources(modPath);
    }
};
