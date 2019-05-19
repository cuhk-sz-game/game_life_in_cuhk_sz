#include "cheat.h"
#include "player.h"
#include "role.h"
#include "tool.h"
#include "shop_item.h"
#include <QtMath>


extern Player player;
extern Tools tools;
extern ShopItem items;
extern int mode;

void Cheat::slotCheatEnergy() {             // Cheat: Engergy+100
    player.SetEnergy(player.GetEnergy() + 100);
    emit change();
}

void Cheat::slotCheatIQ() {           // Cheat: IQ+10
    player.SetIQ(player.GetIQ() + 10);
    emit change();
}

void Cheat::slotCheatEQ() {             // Cheat: EQ+10
    player.SetEQ(player.GetEQ() + 10);
    emit change();
}

void Cheat::slotCheatCharm() {          // Cheat: Charm+10
    player.SetCharm(player.GetCharm() + 10);
    emit change();
}

void Cheat::slotCheatMoney() {          // Cheat: Money+100
    player.SetMoney(player.GetMoney() + 100);
    emit change();
}

void Cheat::slotCheatGrade() {          // Cheat: grade+1
    player.GradeUp();
    emit change();
}

void Cheat::slotCheatLike() {          // Cheat: Like+100
    player.SetLike(player.GetLike() + 100);
    emit change();
}

void Cheat::slotCheatDay() {           // Cheat: day+1
    player.SetDay(player.GetDay()+1);
    emit change();
}
