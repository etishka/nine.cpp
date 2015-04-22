#ifndef _NINE_GAME_HXX
#define _NINE_GAME_HXX

#include <vector>

namespace nine
{

    class Player;
    class Deck;
    class Table;

//TODO: include accounting
//TODO: add persistence...SQLLite?
    class Game
    {

        public:

            Game ( int num = 4 );

            virtual ~Game();

            virtual void dealTheCards();

            virtual void startNewGame() = 0;

        protected:

            int numberOfPlayers;

            std::vector<Player*> players;

            Deck& deck;

            Table& table;

    };
};
#endif /* _NINE_GAME_HXX */
