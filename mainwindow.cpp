#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "generator.h"

#define ULTRA_DEBUG

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateCharacter(const QString &mName, const QString &cName, int health, int armor, int black, QString path, QString items, bool haveTainted,
                                   bool haveActiveItem, int activeItem, int keys, int bombs, int coins, int tHealth, int tArmor, int tKeys, int tBombs, int tCoins, QString tItems,
                                   int tActive, float dmg, float spd, bool canFly, float luck, int trinket, float range, float shotSpeed, int tBlack, int tTrinket,
                                   float tDmg, float tSpeed, float tLuck, float tRange, float tShotSpeed, bool canShoot) {

    Character c(mName, cName, health, armor, black, path, items, haveTainted, haveActiveItem, activeItem, keys, bombs, coins, tHealth, tArmor, tKeys, tBombs, tCoins, tItems, tActive,
                dmg, spd, canFly, luck, trinket, range, shotSpeed, tBlack, tTrinket, tDmg, tSpeed, tLuck, tRange, tShotSpeed, canShoot);
    c.generateMod();
#ifdef ULTRA_DEBUG
    qDebug() << mName << cName << health << armor << black << path << items << haveTainted << haveActiveItem << activeItem << keys << bombs << coins;
#endif
}
