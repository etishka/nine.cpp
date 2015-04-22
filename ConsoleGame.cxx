#include "ConsoleGame.hxx"
#include "players/SimplePlayer.hxx"
#include "players/ConsolePlayer.hxx"
#include <iostream>

#include "players/Player.hxx"
#include "Deck.hxx"
#include "Table.hxx"
#include "Card.hxx"

using namespace nine;

/**
 * Constructor
 *
 * Create table, deck, and specified number of players. Deal the cards
 */
ConsoleGame::ConsoleGame ( int num ) : Game ( num )
{
    if (num > 4)
        std::cout << "Fucking sheet!" << std::endl;
    //TODO: get from game settings
    const char* playersNames[] = { "Трус","Балбес", "Бывалый" };

    int p = 0;
    for ( ; p < numberOfPlayers - 1; p++ )
        players.push_back ( new SimplePlayer ( table, playersNames[p] ) );

    players.push_back ( new ConsolePlayer(table));

    dealTheCards();
}

/**
 * Destructor which does nothing. Ok, almost nothing :-)
 */
ConsoleGame::~ConsoleGame()
{
}

/**
 * Game controller
 */
void ConsoleGame::startNewGame()
{
#ifdef _NINE_DEBUG_CONSOLE_GAME_
    printPlayers();
#endif

    int curPlayer = 0;
    Card* newcard = players[curPlayer]->makeTurn();
    std::cout << "Ходит игрок " << players[curPlayer]->getName() <<std::endl;
    std::cout << getTurnDescription ( newcard ) <<std::endl;
    std::cout << table.toString();
    std::cout <<std::endl<<std::endl;

    while ( players[curPlayer]->getCards().size() != 0 )
    {
        // next player's turn
        ++curPlayer %= numberOfPlayers;

        Card* newcard = players[curPlayer]->makeTurn();

//         for (int i=0; i<50; i++)
//             std::cout <<std::endl;

        std::cout << "Ходит игрок " << players[curPlayer]->getName() <<std::endl;
        std::cout << getTurnDescription ( newcard ) <<std::endl;
        std::cout << "Осталось карт: " << players[curPlayer]->getNumberOfCards() << std::endl;
        std::cout << table.toString();
        std::cout <<std::endl<<std::endl;
        sleep (players[curPlayer]->getTurnTime());
    }
    std::cout << players[curPlayer]->getName() << " выиграл!"<<std::endl;
}

/**
 * Return short description of turn which just have been made
 * @return name of card which has been put. If NULL then "Nothing changed"
 */
std::string ConsoleGame::getTurnDescription ( Card* card ) const
{

    std::string change;

    if ( card == NULL )
        change= "Нечего положить...";
    else
        change = std::string ( "Положил " ) +card->toString();

    return change;
}


#ifdef _NINE_DEBUG_CONSOLE_GAME_

/**
 * DEBUG: print all player's cards
 */
void ConsoleGame::printPlayers()
{
    for ( vector<Player*>::iterator p = players.begin(); p != players.end(); p++ )
    {
        std::cout << ( *p )->toString() << std::endl << "===" << std::endl;
        printCards ( ( *p )->getCards() );
        std::cout << std::endl << std::endl;
    }
}

/**
 * DEBUG: print specified card collection
 * @param cards
 */
void ConsoleGame::printCards ( list<Card*> cards )
{
    for ( list<Card*>::iterator card = cards.begin();card != cards.end();  card++ )
        std::cout << ( *card )->toString() << " ||| ";
}
#endif
