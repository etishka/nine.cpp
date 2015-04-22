#ifndef _NINE_CONSOLEGAME_HXX
#define _NINE_CONSOLEGAME_HXX

#include <Game.hxx>
#include <string>

#ifdef _NINE_DEBUG_CONSOLE_GAME_
#include <list>
#endif /*_NINE_DEBUG_CONSOLE_GAME_*/

namespace nine{

    class Card;

    /**
     *  @author Alexander Smirnov <alexander.v.smirnov@gmail.com>
     */
    class ConsoleGame : public Game
    {
        public:

            ConsoleGame ( int num );

            ~ConsoleGame();

            void startNewGame();

        private:

            std::string getTurnDescription ( Card* card ) const;

            void printTable() const;

#ifdef _NINE_DEBUG_CONSOLE_GAME_
            void printPlayers();

            void printCards ( list<Card*> cards );
#endif

    };
};

#endif /*_NINE_CONSOLEGAME_HXX*/
