#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
/* * Class: View * -------------------------------
* This class include all method which used to key events
* when character interact with map iterms or npc those method
* will be called to control the behavior of character according
* to player's choice*/

class View : public QGraphicsView {
    Q_OBJECT
signals:
    /* * Method: move
    * Usage: move(int,int);
    * -----------------------------------
    * sent signal when player press direction key */

    void move(int x, int y);

    /* * Method: events
    * Usage: events(QString str);
    * -----------------------------------
    * send signal when interation happened connect
    * with solt method in mainwindow*/

    void events(QString str);

    /* * Method: date
    * Usage: date(int);
    * -----------------------------------
    * update date when player chopse to sleep */

    void date(int num);

    /* * Method: change
    * Usage: change();
    * -----------------------------------
    * send signal when information change or change
    * screen to mian scene*/

    void change();

    /* * Method: quit
    * Usage: quit();
    * -----------------------------------
    * send signal when reach to one of ending
    * of the game and exit program*/

    void quit();

public:
    //construction and destruction
    explicit View(QWidget *parent = 0);       // Explicit means "implicit invocation" is not allow
    ~View();

    /* * Method: GetStatus
    * Usage: GetStatus();
    * -----------------------------------
    * return the current status which determine
    * first signal to emit when interation happened*/

    QString GetStatus() { return status; }

    /* * Method: SstStatus
    * Usage: SetStatus();
    * -----------------------------------
    * setup the current status*/

    void SetStatus(QString status) { this->status = status; }

    /* * Method: keyMain
    * Usage: keyMain();
    * -----------------------------------
    * declare the key event when player in the
    * main scene*/

    void keyMain(QKeyEvent *event);

    /* * Method: keyShop
    * Usage: keyShop();
    * -----------------------------------
    * declare the key event when player in the
    * shop scene*/

    void keyShop(QKeyEvent *event);

    /* * Method: keyPhone
    * Usage: keyPhone();
    * -----------------------------------
    * declare the key event when player using the
    * phone*/

    void keyPhone(QKeyEvent *event); // 类似shop 但是可以用按键触发

    /* * Method: keyWelcome
    * Usage: keyWelcome();
    * -----------------------------------
    * declare the key event when player in the
    * Welcome scene*/

    void keyWelcome(QKeyEvent *event);

    /* * Method: keySelect
    * Usage: keySelect();
    * -----------------------------------
    * declare the key event when player in the
    * character selection scene*/

    void keySelect(QKeyEvent *event);

    /* * Method: keyLike
    * Usage: keyLike();
    * -----------------------------------
    * declare the key event when player in the
    * grilfriend interation scene*/

    void keyLike(QKeyEvent *event); //成功牵手

    /* * Method: keydate
    * Usage: keydate();
    * -----------------------------------
    * declare the key event when player in the
    * date scene*/

    void keydate();

    /* * Method: keySlecture
    * Usage: keylecture();
    * -----------------------------------
    * declare the key event when player in the
    * lecture interation scene*/

    void keylecture(QKeyEvent *event);

    /* * Method: keyprof1
    * Usage: keyprof1();
    * -----------------------------------
    * declare the key event when player interate
    * with prof1*/

    void keyprof1(QKeyEvent *event);

    /* * Method: keyprof2
    * Usage: keyprof2();
    * -----------------------------------
    * declare the key event when player interate
    * with prof2 and set up triggering condition*/

    void keyprof2(QKeyEvent *event);

    /* * Method: keyprof3
    * Usage: keyprof3();
    * -----------------------------------
    * declare the key event when player interate
    * with prof3 and set up triggering condition*/

    void keyprof3(QKeyEvent *event);

    /* * Method: keyeat
    * Usage: keyeat();
    * -----------------------------------
    * declare the key event when player interate
    * with canteen*/

    void keyeat(QKeyEvent *event);

    /* * Method: keystudy
    * Usage: keystudy();
    * -----------------------------------
    * declare the key event when player triggering
    * the self-study in library*/

    void keystudy(QKeyEvent *event);

    /* * Method: keysleep
    * Usage: keysleep();
    * -----------------------------------
    * declare the key event when player go to dormitory
    * and choose to sleep*/

    void keysleep(QKeyEvent *event); //sleep() include stave and random event triggers

    /* * Method: keymoive
    * Usage: keymovie();
    * -----------------------------------
    * declare the key event when player go to moive house*/

    void keymovie(QKeyEvent *event);

    /* * Method: setlover
    * Usage: setlover();
    * -----------------------------------
    * the method used to put lover in random place of
    * the map*/

    void setlover();

    /* * Method: meetlover
    * Usage: meetlover();
    * -----------------------------------
    * declare the key event when player interate with
    * lover*/

    void meetlover(QKeyEvent *event);

    /* * Method: keygym
    * Usage: keygym();
    * -----------------------------------
    * declare the key event when player go to gym
    * and choose to work out*/

    void keygym(QKeyEvent *event);

    /* * Method: keyexam
    * Usage: keyexam();
    * -----------------------------------
    * declare the key event when player go to attend exam*/


    void action();

protected:
    void keyPressEvent(QKeyEvent *event);       // Rewrite the virtual function keyPressEvent
    void triggerEvent(QKeyEvent *event);
private:

    /* * Method: access
    * Usage: access(int,int);
    * -----------------------------------
    * test whether the ordinate value is moveable*/

    int access(int x, int y);

    QString status;
    int next_step;
};

#endif // VIEW_H
