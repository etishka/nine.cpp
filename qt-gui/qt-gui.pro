#CONFIG  += qt build_all debug console release
CONFIG  += qt build_all console release

TEMPLATE = app

TARGET=qNine

INCLUDEPATH += include ../include
DEPENDPATH  +=../

FORMS = MainWindow.ui

HEADERS += qcard.hxx
HEADERS += ../include/Card.hxx ../include/Deck.hxx ../include/Game.hxx ../include/Rank.hxx ../include/Suit.hxx ../include/Table.hxx ../include/Utils.hxx
#HEADERS += Card.hxx Deck.hxx Game.hxx Rank.hxx Suit.hxx Table.hxx Utils.hxx
HEADERS += mainwindow.hxx

SOURCES += qcard.cxx qtMain.cxx
SOURCES += Card.cxx Deck.cxx Game.cxx Rank.cxx Suit.cxx Table.cxx Utils.cxx
SOURCES += players/Player.cxx players/SimplePlayer.cxx
SOURCES += mainwindow.cxx

FORMS =  MainWindow.ui
