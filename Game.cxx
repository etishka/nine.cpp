#include "Game.hxx"
#include "Card.hxx"
#include "Deck.hxx"
#include "Table.hxx"
#include "players/SimplePlayer.hxx"
#include "players/Player.hxx"

using namespace nine;

/**
* Construct new game
*
* initialize deck, players, table, give cards to players
* @param num - number of players. Ussualy 3 or 4
*/
Game::Game ( int num ) :
        numberOfPlayers ( num ),
        deck ( Deck::getDeck() ),
        table ( Table::getTable ( BIGGEST_SUIT, ACE+1 ) )
{
    deck.shuffle();
}
/**
 * All players should die here
 */
Game::~Game()
{
    for ( unsigned i=0; i< players.size(); i++ )
        delete players[i];
}

/**
* Give all cards from the deck to Players
* Deck should be empty after this operation. All the cards are on hands
*/
void Game::dealTheCards()
{
    int playerIndex = 0;
    for ( Card* card = deck.getCard(); card != NULL; card = deck.getCard() )
    {
        players [playerIndex]->addCard ( card );
        ++playerIndex  %= numberOfPlayers;
    }
}
