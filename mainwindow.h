#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generateCharacter(const QString &mName, const QString &cName, int health, int armor, int black, QString path, QString items, bool haveTainted,
                           bool haveActiveItem, int activeItem, int keys, int bombs, int coins, int tHealth, int tArmor, int tKeys, int tBombs,
                           int tCoins, QString tItems, int tActive, float dmg, float spd, bool canFly, float luck, int trinket, float range, float shotSpeed, int tBlack,
                           int tTrinket, float tDmg, float tSpeed, float tLuck, float tRange, float tShotSpeed, bool canShoot);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
