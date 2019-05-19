#ifndef CHEAT_H
#define CHEAT_H
#include <QObject>

class Cheat : public QObject {
    Q_OBJECT
public:
    Cheat() {}
    ~Cheat() {}
signals:
    void change();
public slots:
    void slotCheatEnergy();
    void slotCheatIQ();
    void slotCheatEQ();
    void slotCheatCharm();
    void slotCheatMoney();
    void slotCheatGrade();
    void slotCheatLike();
    void slotCheatDay();
};

#endif // CHEAT_H
