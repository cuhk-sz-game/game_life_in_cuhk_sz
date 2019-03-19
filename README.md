# game_life_in_cuhk_sz

Introduction
===
  The school life game is the main project in course CSC3002. Our game is based on QT window application.

  CUHK(SZ) is a young university with scenic campus. One day, while taking a walk on campus, 
our team came up with the idea that our campus could be a fantastic map in a role-playing game (RPG). 
Therefore, this project is going to design an RPG game, using CUHK(SZ) as the background. 

Requirements
===
QT version >= 5.

Game description
===
  The main character is set to be a CUHK(SZ) student, and experiences similar daily activities as a university student does, 
such as attending classes, participating in student clubs’ activities, helping professors with research projects, 
self-study in the library, hanging out for fun, dating with the girlfriend/boyfriend, and so on and so force. 
The character is attached with some attributes, including energy, moeny, IQ, EQ and glamor. 
Through different activities, the degree of these attributes could be improved or reduced. 
20 days in the game are equivalent to one semester.After two semesters, the main character will graduate. Besides the daily routine, 
the character might also randomly meet non-player characters (NPCs) or encounter some random events during the time. 
The final goal is to pass all exams and graduate successfully with high GPA. 

  When playing, the player needs to control the character to move among different venues to do different activities. 
On each day, the player is free to choose any activity he/she will like to do, but energy, time and money are limited. 
It is up to the player to make decisions. Moreover, there exist some activities that can only be triggered after 
the main character’s attributes meet predefined requirements. 


Main Body
===
  As is mentioned in the previous description, this project is a simple simulation of students’ life in CUHK(SZ). Every choice of the player affects role’s IQ, EQ, glamor, energy and money. Some random events might happen when some attributes reach a predesigned level. For example, when the character has low IQ, he/she might be expelled from school. 
  
  Some basic elements in the game are as follows:
  
  • 2 main characters: a boy and girl character (the player can choose either one)
  
  • 5 attributes: IQ, EQ, glamor, money, energy 
  
  • 4 kinds of NPC: teaching professors, science professors, club professors (by meeting them the main character may trigger         
    activities and then increase or decrease his/her attributes), a boyfriend/girlfriend (randomly appearing in every map; the
    main character needs to develop favorability with him/her to build the relationship)
  
  • 3 maps: base map (dormitory; connecting with every other venue), classroom (attending class or interacting with professor),
    library (self-study or meeting professor)
      
  Noticeably, how each interaction affects the data exactly will be adjusted and determined in future game development stage.
  
Dependence Graph
===

![](https://github.com/cuhk-sz-game/game_life_in_cuhk_sz/blob/master/pic/denpendence.png)


    a) mainwindow:
    i. creating game window and basic control menu
    ii. visualization of game contents, including map, items, player...
    b) view:
    i. achieving game operations and control functions such as movement
    ii. defining all events by case
    c) database:
    i. loading the contents of sql file into c++ environment such as the position
       of every item (including map itself)
    ii. saving and reloading the game
    d) player/role/tool/shop_items:
    i. parameters used in the game
    e) cheat/phone:
    i. class which can manipulate the parameter when testing game and special functions

Screenshots from the demo
===
![](https://github.com/cuhk-sz-game/game_life_in_cuhk_sz/blob/master/pic/demo1.png)


![](https://github.com/cuhk-sz-game/game_life_in_cuhk_sz/blob/master/pic/demo2.png)

