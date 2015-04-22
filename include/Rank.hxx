#ifndef _NINE_RANK_HXX
#define _NINE_RANK_HXX

#include <string>

namespace nine
{
    enum CardRank{SIX=0,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE};

    class Rank
    {

        public:

            static CardRank getRank ( int );

            static int getScore ( int );

            static std::string getLetter ( int );

            static std::string toString ( int );

            static CardRank getNextRank ( CardRank );

            static CardRank getPrevRank ( CardRank );
    };
}
#endif /*_NINE_RANK_HXX*/
