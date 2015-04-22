#ifndef _NINE_PLAYER_HXX
#define _NINE_PLAYER_HXX

#include <list>
#include <string>

//TODO: replace with forward declarations?
#include "Rank.hxx"
#include "Suit.hxx"

namespace nine
{
    class Table;
    class Card;
// class Suit;
// class Rank;
// class CardSuit;
// class CardRank;


    class Player
    {
        public:

            virtual Card* makeTurn() =0;

        public:

            Player ( Table &t );

            Player ( Table &t, std::string n, int turnTime );

            virtual ~Player();

            void addCard ( Card* card );

            Card* IHave ( CardSuit suit, CardRank rank ) const;

            std::string getName() const;

            void setName ( const std::string n );

            void setTurnTime ( int );

            int getTurnTime() const;

            void moveCardsToDeck();

            //TODO: debug only functions, move to ConsolePlayer
            const std::string toString() const;

            std::list<Card*> getCards() const; //TODO: move to protected? is it used by anyone?

            int getNumberOfCards() const;

        protected:

            std::list<Card*> cards;

            Table& table;

        private:

            std::string name;

            int turnTime;

            //TODO: introduce accounting
            //  private int money;
    };
};

#endif /*_NINE_PLAYER_HXX*/
