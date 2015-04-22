#ifndef _NINE_DECK_HXX
#define _NINE_DECK_HXX

#include <vector>

#ifdef _NINE_DEBUG_DECK_
#include <string>
#endif

#include "Rank.hxx"
#include "Suit.hxx"



namespace nine
{
    class Card;

    class Deck
    {

        protected:

            Deck();

        private:

            Deck& operator= ( const Deck& );

            Deck ( const Deck& );

        public:

            virtual ~Deck();

            static Deck& getDeck();

            Card* getCard();

            void addCard ( Card * );

            size_t size() const;

            void shuffle();

#ifdef _NINE_DEBUG_DECK_
            std::string toString() const;
#endif

        private:

            void free();

            std::vector<Card*> m_cards;
    };
}

#endif
