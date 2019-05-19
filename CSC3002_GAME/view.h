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
    explicit View(QWidget *parent = 0);       // Explicit means "implicit invocation" is not allow
    ~View();
    QString GetStatus() { return status; }
    void SetStatus(QString status) { this->status = status; }
    void keyMain(QKeyEvent *event);
    void keyShop(QKeyEvent *event);
    void keyPhone(QKeyEvent *event); // 类似shop 但是可以用按键触发
    void keyWelcome(QKeyEvent *event);
    void keySelect(QKeyEvent *event);
    void keyLike(QKeyEvent *event); //成功牵手
    void keydate(); //keyfight() -> keydate()
    void keylecture(QKeyEvent *event);
    void keyprof1(QKeyEvent *event);
    void keyprof2(QKeyEvent *event);
    void keyprof3(QKeyEvent *event);
    void keyeat(QKeyEvent *event);
    void keystudy(QKeyEvent *event);
    void keysleep(QKeyEvent *event); //sleep() include stave and random event triggers
    void keymovie(QKeyEvent *event);
    void setlover();
    void meetlover(QKeyEvent *event);
    void keygym(QKeyEvent *event);
    // random events
    void keyexam(QKeyEvent *event);
    void keybook(QKeyEvent *event);
    void keymoney(QKeyEvent *event);


    void action();

protected:
    void keyPressEvent(QKeyEvent *event);       // Rewrite the virtual function keyPressEvent
    void triggerEvent(QKeyEvent *event);
private:
    int access(int x, int y);
    QString status;
    int next_step;
};

#endif // VIEW_H
