QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app

SOURCES += main.cpp \
    game.cpp \
    button.cpp \
    chessboard.cpp \
    chessbox.cpp \
    chesspiece.cpp \
    knight.cpp

HEADERS += \
    game.h \
    button.h \
    chessboard.h \
    chessbox.h \
    chesspiece.h \
    knight.h

RESOURCES += \
    images.qrc
