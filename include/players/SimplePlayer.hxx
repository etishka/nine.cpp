#ifndef _NINE_SIMPLE_PLAYER_HXX
#define _NINE_SIMPLE_PLAYER_HXX

#include <string>
#include "Player.hxx"

//TODO: replace with forward declarations?
#include "Rank.hxx"
#include "Suit.hxx"

namespace nine
{
    class Table;
    class Card;

    class SimplePlayer: public Player
    {

        public:

            SimplePlayer ( Table& t, const std::string );

            Card* makeTurn();

        private:

            Card* putIfIHave ( CardSuit suit, CardRank rank );
    };
};

#endif
