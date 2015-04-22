#ifndef _NINE_CONSOLEPLAYER_HXX
#define _NINE_CONSOLEPLAYER_HXX

#include <list>
#include <string>
#include "Player.hxx"

namespace nine
{
    class Card;
    class Table;

    /**
     @author Alexander Smirnov <alexander.v.smirnov@gmail.com>
    */
    class ConsolePlayer : public Player
    {
        public:
            ConsolePlayer ( Table& t );

            virtual Card* makeTurn();

        private:
            void printCards() const;

            std::list<Card*> getPossibleCards() const;

            ConsolePlayer ( Table& t, std::string n );

            void showHint ( std::list<Card*> ) const;
    };
};
#endif
