#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "ui_MainWindow.h"
#include "qcard.hxx"

#include "Game.hxx"

/**
	@author Alexander Smirnov <alexander.v.smirnov@gmail.com>
*/
class MainWindow : public QMainWindow, public Ui::MainWindow, public nine::Game
{
Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);



    ~MainWindow();

    void showPlayerCards();

    public slots:

        void update();

        virtual void startNewGame();

    protected:
        void paintEvent(QPaintEvent *event);

        void createPlayers();

    private:
        QWidget* topWidget;
        QWidget* centralWidget;
        QWidget* bottomWidget;
};

#endif
