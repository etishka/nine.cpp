#include <iostream>
#include <list>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "mainwindow.hxx"
#include "qcard.hxx"

#include "Deck.hxx"
#include "players/SimplePlayer.hxx"

const int number_of_players = 4;// TODO:get number of players from options

MainWindow::MainWindow(QWidget *parent):
         QMainWindow(parent),
         nine::Game(number_of_players)
{
    setupUi(this);
    connect (actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect (actionNew, SIGNAL(triggered()), this, SLOT(startNewGame()));

    topWidget = new QWidget;
    topWidget->setLayout (new QHBoxLayout);

    centralWidget = new QWidget;
    centralWidget->setLayout (new QHBoxLayout);
    //TODO: add left player widget
    //TODO: add table widget
    //TODO: add right player widget

    bottomWidget = new QWidget;
    bottomWidget->setLayout (new QHBoxLayout);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(topWidget);
    mainLayout->addWidget(centralWidget);
    mainLayout->addWidget(bottomWidget);

    centralwidget->setLayout(mainLayout);
}

void MainWindow::createPlayers()
{
    const char* playersNames[] = { "Трус","Балбес", "Бывалый", "Шурик" };

    int p = 0;
    for ( ; p < numberOfPlayers - 1; p++ )
        players.push_back ( new nine::SimplePlayer ( table, playersNames[p] ) ); //TODO: get type of player from options

//    players.push_back ( new GUIPlayer(table));
    players.push_back ( new nine::SimplePlayer ( table, playersNames[p+1] ) );
}

/*!
    \fn MainWindow::showPlayerCards()
 */
void MainWindow::showPlayerCards()
{
    nine::Player* guiPlayer = players[number_of_players-1];
    std::list<nine::Card*> cards = guiPlayer->getCards();

    for ( std::list<nine::Card*>::iterator card = cards.begin();card != cards.end();  card++ )
    {
        QCard* qcard = new QCard(*card, bottomWidget);

        bottomWidget->layout()->addWidget(qcard);
    }
}

void MainWindow::startNewGame()
{
    createPlayers();
    dealTheCards();
    showPlayerCards();
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent* /*event*/)
{
    //std::cerr << "MainWindow::paintEvent called" << std::endl;
}

void MainWindow::update()
{
    std::cerr << "Update called" << std::endl;
//     QMainWindow::update();
//     std::cerr << "CentralWidgetVisible="<<centralwidget->isVisible() << std::endl;
//     centralwidget->layout();
//     centralwidget->update();
}


