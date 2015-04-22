//
// C++ Implementation: Main
//
// Description:
//
//
// Author: Alexander Smirnov <alexander.v.smirnov@gmail.com>
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "ConsoleGame.hxx"

int main ( int argc, char* argv[] )
{
    nine::Game* game = new nine::ConsoleGame ( 4 );
    game->startNewGame();
    delete game;

    return 0;
}
