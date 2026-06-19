#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QCheckBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("TBoI character generator by UltraDinner");

    // first line

    QLabel *modNameTitle = new QLabel("mod name: ", &w);
    modNameTitle->setGeometry(0,0,130,30);
    modNameTitle->show();

    QTextEdit *modNameEdit = new QTextEdit("", &w);
    modNameEdit->setGeometry(70,0,160,30);
    modNameEdit->show();

    QLabel *characterNameTitle = new QLabel("character name: ", &w);
    characterNameTitle->setGeometry(250,0,130,30);
    characterNameTitle->show();

    QTextEdit *characterNameEdit = new QTextEdit("", &w);
    characterNameEdit->setGeometry(350,0,160,30);
    characterNameEdit->show();

    QLabel *dmgLabel = new QLabel("dmg:", &w);
    dmgLabel->setGeometry(600,0,130,30);
    dmgLabel->show();

    QTextEdit *dmgEdit = new QTextEdit("", &w);
    dmgEdit->setGeometry(640,0,60,30);
    dmgEdit->show();

    // second line

    QLabel *healthTitle = new QLabel("health count: ", &w);
    healthTitle->setGeometry(0,40,130,30);
    healthTitle->show();

    QTextEdit *healthEdit = new QTextEdit("", &w);
    healthEdit->setGeometry(80,40,50,30);
    healthEdit->show();

    QLabel *keysTitle = new QLabel("keys count: ", &w);
    keysTitle->setGeometry(150,40,130,30);
    keysTitle->show();

    QTextEdit *keysEdit = new QTextEdit("", &w);
    keysEdit->setGeometry(220,40,50,30);
    keysEdit->show();

    QLabel *coinTitle = new QLabel("coins count: ", &w);
    coinTitle->setGeometry(280,40,130,30);
    coinTitle->show();

    QTextEdit *coinEdit = new QTextEdit("", &w);
    coinEdit->setGeometry(350,40,50,30);
    coinEdit->show();

    QLabel *speedTitle = new QLabel("spd:", &w);
    speedTitle->setGeometry(600,40,130,30);
    speedTitle->show();

    QTextEdit *speedEdit = new QTextEdit("", &w);
    speedEdit->setGeometry(640,40,60,30);
    speedEdit->show();

    // third line

    QLabel *armorTitle = new QLabel("blue hearts: ", &w);
    armorTitle->setGeometry(0,80,130,30);
    armorTitle->show();

    QTextEdit *armorEdit = new QTextEdit("", &w);
    armorEdit->setGeometry(80,80,50,30);
    armorEdit->show();

    QLabel *bombTitle = new QLabel("bombs count: ", &w);
    bombTitle->setGeometry(140,80,130,30);
    bombTitle->show();

    QTextEdit *bombEdit = new QTextEdit("", &w);
    bombEdit->setGeometry(220,80,50,30);
    bombEdit->show();

    QLabel *blackTitle = new QLabel("black hearts:", &w);
    blackTitle->setGeometry(280,80,130,30);
    blackTitle->show();

    QTextEdit *blackEdit = new QTextEdit("", &w);
    blackEdit->setGeometry(350,80,50,30);
    blackEdit->show();

    QLabel *luckLabel = new QLabel("luck:", &w);
    luckLabel->setGeometry(600,80,130,30);
    luckLabel->show();

    QTextEdit *luckEdit = new QTextEdit("", &w);
    luckEdit->setGeometry(640,80,60,30);
    luckEdit->show();

    // fourth line

    QLabel *pathTitle = new QLabel("path: ", &w);
    pathTitle->setGeometry(0,120,130,30);
    pathTitle->show();

    QTextEdit *pathEdit = new QTextEdit("", &w);
    pathEdit->setGeometry(40,120,500,30);
    pathEdit->show();

    QLabel *rangeTitle = new QLabel("range: ", &w);
    rangeTitle->setGeometry(600,120,60,30);
    rangeTitle->show();

    QTextEdit *rangeEdit = new QTextEdit("", &w);
    rangeEdit->setGeometry(640,120,60,30);
    rangeEdit->show();

    // fifth line

    QLabel *itemsTitle = new QLabel("items: ", &w);
    itemsTitle->setGeometry(0,160,130,30);
    itemsTitle->show();

    QTextEdit *itemsEdit = new QTextEdit("", &w);
    itemsEdit->setGeometry(40,160,300,30);
    itemsEdit->show();

    QLabel *trinketTitle = new QLabel("trinket:", &w);
    trinketTitle->setGeometry(345,160,130,30);
    trinketTitle->show();

    QTextEdit *trinketEdit = new QTextEdit("", &w);
    trinketEdit->setGeometry(390,160,50,30);
    trinketEdit->show();

    QLabel *shotSpeedTitle = new QLabel("shotspd: ", &w);
    shotSpeedTitle->setGeometry(590,160,60,30);
    shotSpeedTitle->show();

    QTextEdit *shotSpeedEdit = new QTextEdit("", &w);
    shotSpeedEdit->setGeometry(640,160,60,30);
    shotSpeedEdit->show();

    // sixth line

    QCheckBox *haveTainted = new QCheckBox("have tainted version", &w);
    haveTainted->setGeometry(0,200,130,30);
    haveTainted->show();

    QCheckBox *canFly = new QCheckBox("can fly", &w);
    canFly->setGeometry(160,200,130,30);
    canFly->show();

    QCheckBox *canShoot = new QCheckBox("can shoot", &w);
    canShoot->setGeometry(240,200,130,30);
    canShoot->setChecked(1);
    canShoot->show();

    // seventh line

    QCheckBox *haveActive = new QCheckBox("have pocket active", &w);
    haveActive->setGeometry(0,220,130,30);
    haveActive->show();

    QTextEdit *activeItemEdit = new QTextEdit("", &w);
    activeItemEdit->setGeometry(160,225,130,20);

    // eighth line

    QLabel *taintedHealthTitle = new QLabel("tainted health count: ", &w);
    taintedHealthTitle->setGeometry(000,250,130,30);

    QTextEdit *taintedHealthEdit = new QTextEdit("", &w);
    taintedHealthEdit->setGeometry(120,250,50,30);

    QLabel *taintedKeysTitle = new QLabel("tainted keys count: ", &w);
    taintedKeysTitle->setGeometry(180,250,130,30);

    QTextEdit *taintedKeysEdit = new QTextEdit("", &w);
    taintedKeysEdit->setGeometry(290,250,50,30);

    QLabel *taintedCoinsTitle = new QLabel("tainted coins count: ", &w);
    taintedCoinsTitle->setGeometry(350,250,130,30);

    QTextEdit *taintedCoinsEdit = new QTextEdit("", &w);
    taintedCoinsEdit->setGeometry(460,250,50,30);

    QLabel *taintedDmgTitle = new QLabel("dmg: ", &w);
    taintedDmgTitle->setGeometry(590,250,60,30);

    QTextEdit *taintedDmgEdit = new QTextEdit("", &w);
    taintedDmgEdit->setGeometry(640,250,60,30);

    // ninth line

    QLabel *taintedArmorTitle = new QLabel("tainted blue hearts: ", &w);
    taintedArmorTitle->setGeometry(0,290,130,30);

    QTextEdit *taintedArmorEdit = new QTextEdit("", &w);
    taintedArmorEdit->setGeometry(120,290,50,30);

    QLabel *taintedBombsTitle = new QLabel("tainted bombs count: ", &w);
    taintedBombsTitle->setGeometry(170,290,130,30);

    QTextEdit *taintedBombsEdit = new QTextEdit("", &w);
    taintedBombsEdit->setGeometry(290,290,50,30);

    QLabel *taintedBlackTitle = new QLabel("tainted black hearts: ", &w);
    taintedBlackTitle->setGeometry(345,290,130,30);

    QTextEdit *taintedBlackEdit = new QTextEdit("", &w);
    taintedBlackEdit->setGeometry(460,290,50,30);

    QLabel *taintedSpeedTitle = new QLabel("spd: ", &w);
    taintedSpeedTitle->setGeometry(590,290,60,30);

    QTextEdit *taintedSpeedEdit = new QTextEdit("", &w);
    taintedSpeedEdit->setGeometry(640,290,60,30);


    // tenth line

    QLabel *taintedItemsLabel = new QLabel("tainted items: ", &w);
    taintedItemsLabel->setGeometry(0,330,130,30);

    QTextEdit *taintedItemsEdit = new QTextEdit("", &w);
    taintedItemsEdit->setGeometry(100,330,300,30);

    QLabel *taintedTrinketLabel = new QLabel("tainted trinket: ", &w);
    taintedTrinketLabel->setGeometry(400,330,130,30);

    QTextEdit *taintedtrinketEdit = new QTextEdit("", &w);
    taintedtrinketEdit->setGeometry(480,330,50,30);

    QLabel *taintedLuckTitle = new QLabel("luck: ", &w);
    taintedLuckTitle->setGeometry(590,330,60,30);

    QTextEdit *taintedLuckEdit = new QTextEdit("", &w);
    taintedLuckEdit->setGeometry(640,330,60,30);

    // eleventh line

    QLabel *taintedActiveLabel = new QLabel("tainted pocket active: ", &w);
    taintedActiveLabel->setGeometry(0,370,130,30);

    QTextEdit *taintedActiveEdit = new QTextEdit("", &w);
    taintedActiveEdit->setGeometry(130,370,130,30);

    // twelfth line

    QLabel *taintedRangeTitle = new QLabel("range: ", &w);
    taintedRangeTitle->setGeometry(590,370,60,30);

    QTextEdit *taintedRangeEdit = new QTextEdit("", &w);
    taintedRangeEdit->setGeometry(640,370,60,30);

    // thirteenth line

    QLabel *taintedShotSpeedTitle = new QLabel("shotspd: ", &w);
    taintedShotSpeedTitle->setGeometry(590,410,60,30);

    QTextEdit *taintedShotSpeedEdit = new QTextEdit("", &w);
    taintedShotSpeedEdit->setGeometry(640,410,60,30);

    // last line

    QPushButton *generateButton = new QPushButton("generate", &w);
    generateButton->setGeometry(0,570,130,30);
    generateButton->show();



    // connections

    QObject::connect(generateButton, &QPushButton::clicked, [&]() {
        w.generateCharacter(
            modNameEdit->toPlainText(),
            characterNameEdit->toPlainText(),
            healthEdit->toPlainText().toInt(),
            armorEdit->toPlainText().toInt(),
            blackEdit->toPlainText().toInt(),
            pathEdit->toPlainText(),
            itemsEdit->toPlainText(),
            haveTainted->isChecked(),
            haveActive->isChecked(),
            activeItemEdit->toPlainText().toInt(),
            keysEdit->toPlainText().toInt(),
            bombEdit->toPlainText().toInt(),
            coinEdit->toPlainText().toInt(),
            taintedHealthEdit->toPlainText().toInt(),
            taintedArmorEdit->toPlainText().toInt(),
            taintedKeysEdit->toPlainText().toInt(),
            taintedBombsEdit->toPlainText().toInt(),
            taintedCoinsEdit->toPlainText().toInt(),
            taintedItemsEdit->toPlainText(),
            taintedActiveEdit->toPlainText().toInt(),
            dmgEdit->toPlainText().toFloat(),
            speedEdit->toPlainText().toFloat(),
            canFly->isChecked(),
            luckEdit->toPlainText().toFloat(),
            trinketEdit->toPlainText().toInt(),
            rangeEdit->toPlainText().toFloat(),
            shotSpeedEdit->toPlainText().toFloat(),
            taintedBlackEdit->toPlainText().toInt(),
            taintedtrinketEdit->toPlainText().toInt(),
            taintedDmgEdit->toPlainText().toFloat(),
            taintedSpeedEdit->toPlainText().toFloat(),
            taintedLuckEdit->toPlainText().toFloat(),
            taintedRangeEdit->toPlainText().toFloat(),
            taintedShotSpeedEdit->toPlainText().toFloat(),
            canShoot->isChecked()
        );
    });

    QObject::connect(haveActive, &QPushButton::clicked, [&](){
        if (haveActive->isChecked()) {
            activeItemEdit->show();
            if (haveTainted->isChecked()) {
                taintedActiveLabel->show();
                taintedActiveEdit->show();
            }
        } else {
            activeItemEdit->hide();
            taintedActiveLabel->hide();
            taintedActiveEdit->hide();
        }
    });

    QObject::connect(haveTainted, &QPushButton::clicked, [&](){
        if (haveTainted->isChecked()) {
            taintedHealthTitle->show();
            taintedHealthEdit->show();
            taintedArmorTitle->show();
            taintedArmorEdit->show();
            taintedKeysTitle->show();
            taintedKeysEdit->show();
            taintedBombsTitle->show();
            taintedBombsEdit->show();
            taintedCoinsTitle->show();
            taintedCoinsEdit->show();
            taintedItemsLabel->show();
            taintedItemsEdit->show();
            taintedTrinketLabel->show();
            taintedtrinketEdit->show();
            taintedBlackTitle->show();
            taintedBlackEdit->show();
            taintedDmgTitle->show();
            taintedDmgEdit->show();
            taintedSpeedTitle->show();
            taintedSpeedEdit->show();
            taintedLuckTitle->show();
            taintedLuckEdit->show();
            taintedRangeTitle->show();
            taintedRangeEdit->show();
            taintedShotSpeedTitle->show();
            taintedShotSpeedEdit->show();
            if (haveActive->isChecked()) {
                taintedActiveLabel->show();
                taintedActiveEdit->show();
            }
        } else {
            taintedHealthTitle->hide();
            taintedHealthEdit->hide();
            taintedArmorTitle->hide();
            taintedArmorEdit->hide();
            taintedKeysTitle->hide();
            taintedKeysEdit->hide();
            taintedBombsTitle->hide();
            taintedBombsEdit->hide();
            taintedCoinsTitle->hide();
            taintedCoinsEdit->hide();
            taintedItemsLabel->hide();
            taintedItemsEdit->hide();
            taintedActiveLabel->hide();
            taintedActiveEdit->hide();
            taintedTrinketLabel->hide();
            taintedtrinketEdit->hide();
            taintedBlackTitle->hide();
            taintedBlackEdit->hide();
            taintedDmgTitle->hide();
            taintedDmgEdit->hide();
            taintedSpeedTitle->hide();
            taintedSpeedEdit->hide();
            taintedLuckTitle->hide();
            taintedLuckEdit->hide();
            taintedRangeTitle->hide();
            taintedRangeEdit->hide();
            taintedShotSpeedTitle->hide();
            taintedShotSpeedEdit->hide();
        }
    });


    return a.exec();
}
