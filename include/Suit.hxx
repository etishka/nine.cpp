#ifndef _NINE_SUIT_HXX
#define _NINE_SUIT_HXX

#include <string>

namespace nine
{
    enum CardSuit {SMALLEST_SUIT = 0,DIAMONDS = 0, SPADES, HEARTS, CLUBS, BIGGEST_SUIT};

    class Suit
    {

        public:

            static const std::string toString ( int value );

            static const std::string getLetter ( int value );

            static const CardSuit getSuit ( int s );
    };
};

#endif /*_NINE_SUIT_HXX*/
