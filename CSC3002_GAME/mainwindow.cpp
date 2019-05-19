#include "mainwindow.h"
#include "database.h"
#include "player.h"
#include "role.h"
#include "tool.h"
#include "character.h"
#include "shop_item.h"
#include "cheat.h"
#include "phone.h"
#include <QTime>
#include <QtMath>
#include <QApplication>
#include <QDebug>
//test

// Constants
const int kPixlen = 32;             // The pixels of each block
const int kOffsetX = 174;           // The offset of x
const int kOffsetY = 224;           // The offset of y
const int kDecimal = 10;            // Decimal system


// Differnt color
const QString kGreen = "#00EE00";
const QString kBlue = "#0000EE";
const QString kYellow = "#EEEE00";
const QString kPurple = "#8B008B";
const QString kRed = "#EE0000";

// Use extern varible
extern DataBase db;
extern Player player;
extern ShopItem items;
extern Tools tools;
extern Role parameter;
extern int map[14][14][10];
extern int mode;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Initialize private varible
    cheats = new Cheat();
    scene = new QGraphicsScene;
    view = new View(this);

    // Create all actions in mainwindow
    CreateActions();

    // Create all menus in mainwindow
    CreateMenus();
    scene->setSceneRect(-200,-200,400,400);

    view->setScene(scene);
    view->setMinimumSize(400,400);
    //view->setRenderHint(QPainter::Antialiasing);
    view->show();

    // Create CONNECT between mainwindow and view
    connect(view, SIGNAL(quit()), this, SLOT(close()));
    connect(view, SIGNAL(change()), this, SLOT(slotDrawScene()));
    connect(view, SIGNAL(date(int)), this, SLOT(slotDate(int)));
    connect(view, SIGNAL(events(QString)), this, SLOT(slotEvent(QString)));
    connect(view, SIGNAL(move(int, int)), this, SLOT(slotMovePlayerItem(int, int)));

    // Set central widget and modify titile
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("SCHOOL LIFE"));

    // Welcome page
    Welcome();
}


MainWindow::~MainWindow() {                  // Destructor
    delete scene;
    delete view;
    delete cheats;
}

void MainWindow::Welcome() {
    slotEvent("welcome");                    // Call the "welcome" slotevent
}

void MainWindow::CreateActions() {           // Create all actions in mainwindow
    // Initialize all actions
    clear = new QAction(tr("Clear"), this);
    newGame = new QAction(tr("NewGame"), this);
    saveGame = new QAction(tr("SaveGame"), this);
    loadGame = new QAction(tr("LoadGame"), this);
    exitGame = new QAction(tr("Quit"), this);
    cheatEnergy = new QAction(tr("Energy+100"), this);
    cheatIQ = new QAction(tr("IQ+10"), this);
    cheatEQ = new QAction(tr("EQ+10"), this);
    cheatMoney = new QAction(tr("Money+50"), this);
    cheatGrade = new QAction(tr("Grade+1"), this);
    cheatLike = new QAction(tr("Like+100"), this);
    cheatDay = new QAction(tr("Day+1"),this);

    callGrilfriend = new QAction(QString("CallGrilfriend"),this);
    takeout = new QAction(QString("TakeOut"),this);
    help = new QAction(QString("Help"),this);
    // newGame->setShortcut(tr("N"));
    // saveGame->setShortcut(tr("S"));
    // loadGame->setShortcut(tr("L"));
    // exitGame->setShortcut(tr("Q"));

    // Connect all actions
    connect(cheats, SIGNAL(change()), this, SLOT(slotDrawScene()));
    connect(newGame, SIGNAL(triggered()), this, SLOT(slotNewGame()));
    connect(saveGame, SIGNAL(triggered()), this, SLOT(slotSaveGame()));
    connect(loadGame, SIGNAL(triggered()), this, SLOT(slotLoadGame()));
    connect(exitGame, SIGNAL(triggered()), this, SLOT(close()));
    connect(cheatEnergy, SIGNAL(triggered()), cheats, SLOT(slotCheatEnergy()));
    connect(cheatIQ, SIGNAL(triggered()), cheats, SLOT(slotCheatIQ()));
    connect(cheatEQ, SIGNAL(triggered()), cheats, SLOT(slotCheatIQ()));
    connect(cheatMoney, SIGNAL(triggered()), cheats, SLOT(slotCheatMoney()));
    connect(cheatGrade, SIGNAL(triggered()), cheats, SLOT(slotCheatGrade()));
    connect(cheatLike, SIGNAL(triggered()), cheats, SLOT(slotCheatLike()));
    connect(cheatDay, SIGNAL(triggered()), cheats, SLOT(slotCheatDay()));
    
    connect(help,SIGNAL(triggered()),this,SLOT(slotHelp()));
}


void MainWindow::CreateMenus() {             // Create all menus in mainwindow
    // file menu
    QMenu *fileMenu = menuBar()->addMenu(tr(" Menu "));
    fileMenu->addAction(newGame);
    fileMenu->addAction(saveGame);
    fileMenu->addAction(loadGame);
    fileMenu->addSeparator();
    fileMenu->addAction(exitGame);

    // phone menu
    QMenu *Phone = menuBar()->addMenu(QString("Phone"));
    Phone->addAction(callGrilfriend);
    Phone->addAction(takeout);
    Phone->addAction(help);
    
    // cheat menuifferent ending according to sex
    QMenu *cheatMenu = menuBar()->addMenu(tr(" Cheat! "));
    cheatMenu->addAction(cheatEnergy);
    cheatMenu->addAction(cheatIQ);
    cheatMenu->addAction(cheatEQ);
    cheatMenu->addAction(cheatMoney);
    cheatMenu->addAction(cheatGrade);
    cheatMenu->addAction(cheatLike);
    //cheatMenu->addSeparator();
    //cheatMenu->addSeparator();
    //cheatMenu->addSeparator();
    cheatMenu->addAction(cheatDay);
}

void MainWindow::CreateInform() {           // Print player information
    const char *location[]={"STREET","LIBRARY","CLASS","CANTEE","GYM"};
    AddPictureItem(-102, 0, "sidebg");
    AddPictureItem(-97, 30, "side");
    AddPictureItem(-93, 5, "info1");
    AddPictureItem(-65, 60, "sex"+QString::number(player.GetSex(), kDecimal));
    AddPictureItem(-82, 130, "info2");
    AddPictureItem(-83, 145, "info3");
    AddPictureItem(-83, 230, "info4");
    AddTextItem(-60, 5, location[player.GetPlace()]/*+QString::number(player.GetPlace()+1, kDecimal)*/, 12, QColor(0,0,0));
    AddTextItem(-62, 100, "DAY "+QString::number(player.GetDay()+1, kDecimal), 10, QColor(0,0,0));
    AddTextItem(-43, 127, QString::number(player.GetEnergy(), kDecimal), 12, QColor(0,0,0));
    AddTextItem(-43, 154, QString::number(player.GetIQ(), kDecimal), 12, QColor(0,0,0));
    AddTextItem(-43, 178, QString::number(player.GetEQ(), kDecimal), 12, QColor(0,0,0));
    AddTextItem(-40, 228, QString::number(player.GetCharm(), kDecimal), 12, QColor(0,0,0));
    AddTextItem(-40, 254, QString::number(player.GetMoney(), kDecimal), 12, QColor(0,0,0));
    AddTextItem(-40, 281, QString::number(player.GetLike(), kDecimal), 12, QColor(0,0,0));
    //AddTextItem(-40, 240, QString::number(keys.GetYellow(), kDecimal), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    //AddTextItem(-40, 265, QString::number(keys.GetBlue(), kDecimal), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    //AddTextItem(-40, 290, QString::number(keys.GetRed(), kDecimal), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
}

void MainWindow::slotDrawScene() {          // Draw the whole scene
    if (view->GetStatus() != "main") return;
    Clear();
    CreateInform();
    AddPictureItem(0, 0, "tile");
    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 14; j++)
            AddMapItem(i, j, map[i][j][player.GetPlace()]);
    AddPlayerItem(player.GetPosx(), player.GetPosy(), player.GetToward(), player.GetSex());
}

void MainWindow::slotShop() {               // Draw the shop scene
    Clear();
    AddPictureItem(0, 0, "shop");
    CreateInform();
}

void MainWindow::slotprof1(){
    Clear();
    AddPictureItem(0,0,"prof1");
    CreateInform();
}

void MainWindow::slotprof2(){
    Clear();
    AddPictureItem(0,0,"prof2");
    CreateInform();
}

void MainWindow::slotprof3(){
    Clear();
    AddPictureItem(0,0,"prof1");
    CreateInform();
}

void MainWindow::sloteat(){
    Clear();
    AddPictureItem(0,0,"eat");
    CreateInform();
}

void MainWindow::slotEatTogether() {
    Clear();
    AddPictureItem(0,0,"eatTogether");
}

void MainWindow::slotsleep(){
    Clear();
    AddPictureItem(0,0,"sleep");
    CreateInform();
}

void MainWindow::slotstudy(){
    Clear();
    AddPictureItem(0,0,"study");
    CreateInform();
}

void MainWindow::slotStudyTogether() {
    Clear();
    AddPictureItem(0,0,"studyTogether");
}

void MainWindow::slotlackpf2(){
    Clear();
    AddPictureItem(0,0,"lackpf2");
    CreateInform();
}

void MainWindow::slotlackpf3(){
    Clear();
    AddPictureItem(0,0,"lackpf3");
    CreateInform();
}

void MainWindow::slotlecture(){
    Clear();
    AddPictureItem(0,0,"lecture");
    CreateInform();
}

void MainWindow::slotgym(){
    Clear();
    AddPictureItem(0,0,"gym");
    CreateInform();
}

void MainWindow::slotGymTogether() {
    Clear();
    AddPictureItem(0,0,"gymTogether");
}

void MainWindow::sloteat1(){
    Clear();
    AddPictureItem(0,0,"eat1");
    CreateInform();
}

void MainWindow::slotdormitory(){
    Clear();
    AddPictureItem(0,0,"Untitled-1");
    CreateInform();
}

void MainWindow::slotgym1(){
    Clear();
    AddPictureItem(0,0,"work_out");
    CreateInform();
}

void MainWindow::slotlackenergy(){
    Clear();
    AddPictureItem(0,0,"lackenergy");
    CreateInform();
}

void MainWindow::slotlackMoney(){
    Clear();
    AddPictureItem(0,0,"lackMoney");
    CreateInform();
}

void MainWindow::slotDating() {
    Clear();
    AddPictureItem(0,0,"activitiesWithLover");
}

void MainWindow::slotMovie() {
    Clear();
    AddPictureItem(0,0,"movie");
}

void MainWindow::slotLackMovie() {
    Clear();
    AddPictureItem(0,0,"lackMovie");
}

void MainWindow::slothighIQ(){
    Clear();
    AddPictureItem(0,0,"highIQ");
    CreateInform();
}

void MainWindow::slothighEQ(){
    Clear();
    AddPictureItem(0,0,"highEQ");
    CreateInform();
}

void MainWindow::slotlowIQ(){
    Clear();
    AddPictureItem(0,0,"lowIQ");
    CreateInform();
}

void MainWindow::slotnormal(){
    Clear();
    AddPictureItem(0,0,"normal");
    CreateInform();
}

void MainWindow::slotEvent(QString str) {           // Choose different event according to str
    if (str == "new") slotNewGame();
    else if (str == "boy") player.ChooseSex(1);
    else if (str == "girl") player.ChooseSex(0);
    else if (str == "save") slotSaveGame();
    else if (str == "load") slotLoadGame();
    /*
    //else if (str == "phone") slotPhone();
    */
    else if (str == "shop") slotShop();
    else if (str == "quit") close();
    else if (str == "prof1") slotprof1();
    else if (str == "prof2") slotprof2();
    else if (str == "prof3") slotprof3();
    else if (str == "eat") sloteat();
    else if (str == "eatTogether") slotEatTogether();
    else if (str == "sleep") slotsleep();
    else if (str == "study") slotstudy();
    else if (str == "studyTogether") slotStudyTogether();
    else if (str == "lackpf2") slotlackpf2();
    else if (str == "lecture") slotlecture();
    else if (str == "gym") slotgym();
    else if (str == "gymTogether") slotGymTogether();
    else if (str == "lackenergy") slotlackenergy();
    else if (str == "lackMoney") slotlackMoney();
    else if (str == "dating") slotDating();
    else if (str == "movie") slotMovie();
    else if (str == "lackMovie") slotLackMovie();
    else if (str == "eat1") sloteat1();
    else if (str == "dormitory") slotdormitory();
    else if (str == "gym1") slotgym1();
    else if (str == "highIQ") slothighIQ();
    else if (str == "highEQ") slothighEQ();
    else if (str == "lowIQ") slotlowIQ();
    else {
        Clear();
        AddPictureItem(-102, 0, "background");
        if (str == "ending")                // Different ending according to sex
            str += QString::number(player.GetSex(), kDecimal);
        AddPictureItem(-102, 0, str);
    }
}

void MainWindow::Clear() {              // Clear all the items in scene
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::slotNewGame() {        // Start a new game
    Clear();

    // Load initial data
    db.LoadMap(0);
    db.LoadTools(0);
    db.LoadIteam(0);
    db.LoadCharacter();

    // Select sex
    view->SetStatus("select");
    slotEvent("select");
}


void MainWindow::slotHelp(){
    Clear();
    view->SetStatus("help");
    slotEvent("help");
}


void MainWindow::slotSaveGame() {           // Save data
    db.SaveMap(1);
    db.SaveTools(1);
    db.SaveIteam(1);
    db.SavePlayer();
}

void MainWindow::slotLoadGame() {           // Load data
    db.LoadMap(1);
    db.LoadTools(1);
    db.LoadIteam(1);
    db.LoadPlayer();
    db.LoadCharacter();
    view->SetStatus("main");
    slotDrawScene();
}

void MainWindow::slotMovePlayerItem(int x, int y) {             // Move player item
    if (playerItem->zValue() == 0.0) {
        playerItem->moveBy(x*kPixlen, y*kPixlen);
        player.SetPosx(player.GetPosx() + x);
        player.SetPosy(player.GetPosy() + y);
        if (player.GetPlace() == 0){
            map[player.GetPosx()][player.GetPosy()][player.GetPlace()] = 1;
        }
        else if (player.GetPlace() == 1) map[player.GetPosx()][player.GetPosy()][player.GetPlace()] = 0;
        else if (player.GetPlace() == 2) map[player.GetPosx()][player.GetPosy()][player.GetPlace()] = 918;
    }
}

void MainWindow::AddMapItem(int x, int y, int num) {            // Add a map block item
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(":/images/" + QString::number(num, kDecimal)));
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(x*kPixlen-kOffsetX,y*kPixlen-kOffsetY);
}

void MainWindow::AddPictureItem(int x, int y, QString str) {           // Add a picture item
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(":/images/" + str));
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(x-kOffsetX,y-kOffsetY);
}

void MainWindow::AddPlayerItem(int x, int y, int toward, int sex) {         // Add a player item
    QString str = ":/images/1" + QString::number(sex, kDecimal) + QString::number(toward, kDecimal);
    playerItem = scene->addPixmap(QPixmap(str));
    playerItem->setPos(x*kPixlen-kOffsetX, y*kPixlen-kOffsetY);
}

void MainWindow::AddTextItem(int x, int y, QString str, int size, QColor color) {           // Add a text string item
    QFont font("Arial", size);
    QGraphicsTextItem *item = new QGraphicsTextItem(str);
    item->setFont(font);
    item->setDefaultTextColor(color);
    scene->addItem(item);
    item->setPos(x-kOffsetX,y-kOffsetY);
}

