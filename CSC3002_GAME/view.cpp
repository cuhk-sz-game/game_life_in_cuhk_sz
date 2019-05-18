#include "view.h"
#include "player.h"
#include "role.h"
#include "shop_item.h"
#include "character.h" //人物触发事件
#include "tool.h"
#include <QKeyEvent>

extern Player player;
extern Role parameter;
extern Tools tools;
extern ShopItem items;
extern int map[14][14][10];

View::View(QWidget *parent) : QGraphicsView(parent) {         // Initialize the status to "welcome"
    status = "welcome";
    next_step = 0;
}

View::~View() {         // Empty the status string when quit
    status = "";
    next_step = 0;
}

void View::keyPressEvent(QKeyEvent * event) {         // This function will autorun when you press a key
    if (status == "main") {         // Read key and move player
        keyMain(event);
        action();         // Different actions according to Nextstep's num
    } else if (status == "tip" || status == "book" || status == "help" ) {         // One click then back to main
        SetStatus("main");
        emit change();
    } else if (status == "ending" || status == "fail")         // One click then quit
        emit quit();
    else if (status == "like")         // One click then if fail then quit else back to main
        keyLike(event);
    else if (status == "shop")         // Read key and decide which stuff player bought
        keyShop(event);
    else if (status == "welcome")         // Read key and choose to start a new game or load
        keyWelcome(event);
    else if (status == "select")         // Read key and choose sex
        keySelect(event);
    else if (status == "prof1")
        keyprof1(event);
    else if (status == "study")
        keystudy(event);
    else if (status == "lecture")
        keylecture(event);
    else if (status == "prof2")
        keyprof2(event);
    else if (status == "prof3")
        keyprof2(event);
    else if (status == "eat")
        keyeat(event);
    else if (status == "sleep")
        keysleep(event);
    else if (status == "gym")
        keygym(event);
}

void View::keyMain(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_Up:        // Move up
            if (access(player.GetPosx(), player.GetPosy()-1))
                emit move(0, -1);
            player.SetToward(1);
            break;
        case Qt::Key_Down:      // Move down
            if (access(player.GetPosx(), player.GetPosy()+1))
                emit move(0, +1);
            player.SetToward(3);
            #include <QKeyEvent>
        break;
        case Qt::Key_Left:      // Move left
            if (access(player.GetPosx()-1, player.GetPosy()))
                emit move(-1, 0);
            player.SetToward(2);
            break;
        case Qt::Key_Right:     // Move right
            if (access(player.GetPosx()+1, player.GetPosy()))
                emit move(+1, 0);
            player.SetToward(4);
            break;
        case Qt::Key_S:         // Save data
            emit events("save");
            break;
        case Qt::Key_L:         // Load data
            emit events("load");
            break;
        case Qt::Key_Q:         // Quit
            emit events("quit");
            break;
        case Qt::Key_H:         // Get help menu
            SetStatus("help");
            emit events("help");
            break;
        default:
            break;
    }
}
void View::keyShop(QKeyEvent *event){};
/*
void View::keyShop(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     // Hp + 30 , Money - 50
            if (player.GetMoney() >= 50) {
                player.SetMoney(player.GetMoney() - 50);
                player.SetHp(player.GetHp()+30);
            }
            emit events("shop");
            break;
        case Qt::Key_2:     // Attack + 2, Money - 50
            if (player.GetMoney() >= 50) {
                player.SetMoney(player.GetMoney() - 50);
                player.SetAttack(player.GetAttack()+2);
            }
            emit events("shop");
            break;
        case Qt::Key_3:     // Defend + 1, Money - 50
            if (player.GetMoney() >= 50) {
                player.SetMoney(player.GetMoney() - 50);
                player.SetDefend(player.GetDefend()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_4:     // YellowKey + 1, Money - 40
            if (player.GetMoney() >= 40) {
                player.SetMoney(player.GetMoney() - 40);
                keys.SetYellow(keys.GetYellow()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_5:     // BlueKey + 1, Money - 120
            if (player.GetMoney() >= 120) {
                player.SetMoney(player.GetMoney() - 120);
                keys.SetBlue(keys.GetBlue()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_6:     // RedKey + 1, Money - 300
            if (player.GetMoney() > 300) {
                player.SetMoney(player.GetMoney() - 300);
                keys.SetRed(keys.GetRed()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_Q:     // Back to main
            SetStatus("main");
            emit change();
            break;
        default:
            break;
    }
}
*/

void View::keyWelcome(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     // Start a new game
            emit events("new");
            break;
        case Qt::Key_2:     // Load
            SetStatus("main");
            emit events("load");
            emit change();
            break;
        case Qt::Key_3:     // Quit
            emit events("quit");
            emit change();
            break;
        default:
            break;
    }
}

void View::keySelect(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     // You are a handsome boy!
            SetStatus("main");
            emit events("boy");
            emit change();
            break;
        case Qt::Key_2:     // You are a beautiful girl~
            SetStatus("main");
            emit events("girl");
            emit change();
            break;
        case Qt::Key_3:     // What!? Who are you!? GET OUT!
            emit events("quit");
            break;
        default:
            break;
    }
}

void View::keyLike(QKeyEvent *event) {
    if ( player.GetLike() == 100) {
        SetStatus("love");
        emit events("love");
    } else {
        SetStatus("main");
        emit change();
    }
}

void View::keyprof1(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=15){
            player.SetEnergy(player.GetEnerge()-15);
            player.SetIQ(player.GetIQ()+2);
            player.SetEQ(player.GetEQ()+2);
            player.SetCharm(player.GetCharm()+2);
            player.SetMoney(player.GetMoney()+20);
        }
        emit events("prof1");
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    default:
        break;
    }
}

void View::keystudy(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=10){
            player.SetEnergy(player.GetEnerge()-10);
            player.SetIQ(player.GetIQ()+3);
            player.SetEQ(player.GetEQ()+1);
            player.SetCharm(player.GetCharm()+1);
        }
        emit events("study");
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    default:
        break;
    }
}

void View::keylecture(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=10){
            player.SetEnergy(player.GetEnerge()-10);
            player.SetIQ(player.GetIQ()+5);
            player.SetEQ(player.GetEQ()+1);
        }
        emit events("lecture");
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    default:
        break;
    }
}

void View::keyprof2(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=15 && player.GetIQ()>=150){
            player.SetEnergy(player.GetEnerge()-15);
            player.SetIQ(player.GetIQ()+10);
            player.SetCharm(player.GetCharm()+2);
            player.SetMoney(player.GetMoney()+10);
            emit events("prof2");
        }else{
            emit events("lackpf2");
        }
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    default:
        break;
    }
}

void View::keygym(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=10){
            player.SetEnergy(player.GetEnerge()-10);
            player.SetCharm(player.GetCharm()+4);
            SetStatus("main");
            emit change();
        }else{
            emit events("lackenergy");
        }
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    case Qt::Key_3:
        SetStatus("gym");
        emit events("gym");
        break;
    default:
        break;
    }
}

void View::keyprof3(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=10 && player.GetIQ()>=130 && player.GetEQ()>=120){
            player.SetEnergy(player.GetEnerge()-10);
            player.SetIQ(player.GetIQ()+2);
            player.SetEQ(player.GetEQ()+2);
            player.SetCharm(player.GetCharm()+10);
            emit events("prof3");
        }else{
            emit events("lackpf3");
        }
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    default:
        break;
    }
}

void View::keyeat(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetMoney()>=20){
            player.SetEnergy(player.GetEnerge()+15);
            player.SetMoney(player.GetMoney()-20);
            player.SetEat(player.GetEat()+1);
            SetStatus("main");
            emit change();
        }
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    case Qt::Key_3:
        SetStatus("sleep");
        emit events("sleep");
        break;
    default:
        break;
    }
}

void View::keysleep(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        player.SetDay(player.GetDay()+1);
        //setlover();
        player.SetMoney(player.GetMoney()+100);

        if(player.GetEat()==0)
        {
            if (player.GetSex()==0){player.SetEnergy(40);}
            else{player.SetEnergy(35);}
        }
        else
        {
            player.SetEat(player.GetEat()-1);
            if (player.GetSex()==0){player.SetEnergy(50);}
            else{player.SetEnergy(45);}
        }
        SetStatus("main");
        emit change();
        if(player.GetDay()==20){
            if(player.GetIQ()>500){
                emit events("highIQ");
            }else if(player.GetEQ()>160){
                emit events("highEQ");
            }else if(player.GetIQ()<300){
                emit events("lowIQ");
            }
            SetStatus("ending");
        }
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    case Qt::Key_3:
        SetStatus("sleep");
        emit events("sleep");
        break;
    default:
        break;
    }
}

void View::setlover(){
    int map_id;
    map_id = (rand()%1) + 1;
    int pos[196][2];
    int count = 0;

    for (int i = 0; i < 14;)
    {
        for (int j=0; j<14;)
        {
            if (map[i][j][map_id] >= 900)
            {
                pos[i][0]=i;
                pos[i][1]=j;
                count ++;
            }
            j++;
        }
        i++;
    }

    int rand_lover;
    rand_lover = (rand()%(count));
    int lover_sex = player.GetSex();
    if (lover_sex == 1){ //boy
        map[pos[rand_lover][0]][pos[rand_lover][1]][map_id] = 103; //girl pic
    }else{
        map[pos[rand_lover][0]][pos[rand_lover][1]][map_id] = 113; //boy pic
    }
}

void View::meetlover(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_1:
        if(player.GetEnerge()>=10 && player.GetIQ()>=130 && player.GetEQ()>=120){
            player.SetEnergy(player.GetEnerge()-10);
            player.SetIQ(player.GetIQ()+2);
            player.SetEQ(player.GetEQ()+2);
            player.SetCharm(player.GetCharm()+10);
            //fight();
        }
        emit events("prof3");
        break;
    case Qt::Key_2:
        SetStatus("main");
        emit change();
        break;
    default:
        break;
    }
}


void View::action() {
    switch (next_step) {
        case 640:
            SetStatus("lecture");
            emit events("lecture");
        break;

        case 999:
            SetStatus("prof1");
            emit events("prof1");
        break;

        case 998:
            SetStatus("prof2");
            emit events("prof2");
        break;

        case 6:
            SetStatus("prof3");
            emit events("prof3");
        break;

        case 122:
            SetStatus("eat");
            emit events("eat1");
        break;

        case 626:
            SetStatus("study");
            emit events("study");
        break;

        case 121:
            SetStatus("sleep");
            emit events("dormitory");
        break;
        case 10:
            SetStatus("movie");
        break;
        case 124:
            SetStatus("gym");
            emit events("gym1");
        break;




        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        /*
        case 23:

            SetStatus("");
            emit fight(next_step);
            break;
        */
//        case 27:
//            // Sorceress's tip
//            SetStatus("tip");
//            emit events("tip2");
//            break;
//        case 28:
//            player.SetMoney(player.GetMoney()+100);
//            break;

//        case 51:
//            // Shopping
//            SetStatus("shop");
//            emit events("shop");
//            break;
        case 123:
            // Upstairs
            player.SetPlace(player.GetPlace()+1);
            player.SetPosx(11);
            player.SetPosy(7);
            break;
        case 125:
            // Upstairs
            player.SetPlace(player.GetPlace()+2);
            player.SetPosx(11);
            player.SetPosy(2);
            break;
        case 126:
            // downstairs
            player.SetPlace(player.GetPlace()-1);
            player.SetPosx(9);
            player.SetPosy(8);
            break;
        case 127:
            // downstairs
            player.SetPlace(player.GetPlace()-1);
            player.SetPosx(9);
            player.SetPosy(8);
            break;
        case 668:
            // Upstairs
            player.SetPlace(player.GetPlace()-2);
            player.SetPosx(8);
            player.SetPosy(13);
            break;
        case 669:
        // Upstairs
            player.SetPlace(player.GetPlace()-2);
            player.SetPosx(8);
            player.SetPosy(13);
            break;
//        case 99:
//            // End of the game
//            SetStatus("ending");
//            emit events("ending");
//            break;
    }
    if (status == "main")
        emit change();
}

int View::access(int x, int y) {          // Check if map(x,y) is access or not
    int tmp = map[x][y][player.GetPlace()];
    next_step = tmp;
    if (tmp == 0 || (tmp > 900 && tmp < 919) || tmp == 1/* || (tmp > 10 && tmp < 27) || (tmp > 27 && tmp < 35) || tmp == 59 */) {
        map[x][y][player.GetPlace()] = 0;
        return 1;
    } else
        return 0;
}

