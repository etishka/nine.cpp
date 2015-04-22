#ifndef _NINE_CARD_HXX
#define _NINE_CARD_HXX

#include <string>
#include "Rank.hxx"
#include "Suit.hxx"

namespace nine
{
    class Card
    {

        private:

            CardRank rank;

            CardSuit suit;

        public:

            Card ( int r, int s );

            Card ( const Card& card );

            const std::string toString() const;

            const std::string toShortString() const;

            const CardRank& getRank() const;

            const CardSuit& getSuit() const;

            bool operator < ( Card* ) const;

            static bool isLesser ( Card* c1, Card* c2 );

            bool equals ( CardSuit, CardRank ) const;

    };
};
#endif /*_NINE_CARD_HXX*/
