
QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_project

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
    database.cpp \
    player.cpp \
    view.cpp \
    mainwindow.cpp \
    cheat.cpp

HEADERS += mainwindow.h \
    cheat.h \
    database.h \
    player.h \
    role.h \
    view.h \
    phone.h \
    shop_item.h \
    tool.h \
    character.h

RESOURCES += \
    application.qrc
