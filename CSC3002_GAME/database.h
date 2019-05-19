#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

/*
 * Class:DataBase
 * ----------------
 * This class models a sql database structure for the game_data storage.
 * Including the initialization, save and load functions for different kinds of game_data.
 */

class DataBase {
public:

    /*
     * Constructor: DataBase()
     * ----------------------------
     * Initizlizes a empty SQLITE database.
     */
    DataBase();

    /*
     * Destructor: ~PriorityQueue()
     * ----------------------------
     * Close the datebase.
     */
    ~DataBase();

    /* Method:Connect(Qstring dbpath)
     * Usage: db.Connect(Qstring database_path_in_the_system)
     *         where db is declared using "DataBase db";
     * -------------------------------------------------------
     * Connect to SQLITE database.
     *
     * If the database file haven't been open before, initial the database using following method:
     *      1, create QMessageBox.
     *      2, set the Icon, Text and StandardButtons for database.
     *
     * Read the sql file.
     *
     * Create Sql query db. Read the text in sql file by step, which script by ";".
     * Using the foreach loop to implement the sql command line.
     *      The control transfer from main() function to QT using exec().
     *      During the exec(), QT will accept and process the user's order,
     *      pass the result to the corresponding window application.
     *      Allowing us to use sql command directly.
     */
    void Connect(QString dbpath);

    /*
     * Method: SaveMap(int num)
     * Usage: db.SaveMap(1);
     * ------------------------
     * Map in sql file have two level. Level one is constant for creating new game, level two store the current
     * db query whenever user call save command.
     * Using sql command "UPDATE map SET layer0=..." to update the map.
     */
    void SaveMap(int num);

    /*
     * Method: LoadMap(int num)
     * Usage: db.LoadMap(0); // Load new game.
     *        db.LoadMap(1); // Load saved game.
     * -----------------------------------------
     * Using the "SELECT layer0, layer1, ..." to read the map, and tranform the data type first in strings, than integer.
     * The map data is store in arrry form "map[x][y][layer]".
     */
    void LoadMap(int num);

    // The below Save&Load functions are similar with the upper SaveMap&LoadMap.
    void SaveTools(int num);
    void LoadTools(int num);
    void SaveIteam(int num); //boyfriend & girlfriend & research professor
    void LoadIteam(int num);
    void SavePlayer();
    void LoadPlayer();
    void LoadCharacter(); //professor & friend

private:
    QString place(int num);
    QSqlDatabase db;
};

#endif // DATABASE_H
