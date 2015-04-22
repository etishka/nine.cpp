#include <cstdlib>
#include <iostream>
#include "players/ConsolePlayer.hxx"
#include "Card.hxx"
#include "Table.hxx"

using namespace nine;

ConsolePlayer::ConsolePlayer(Table& t): Player(t)
{
    std::string name = "";

    while (name == "")
    {
        std::cout << "Назовите свое имя: ";
        std::cin >> name;
        setName(name);
    }

    std::cout << "Привет " << getName() <<"!\n\n"<< std::endl;
}

/**
 *
 */
Card* ConsolePlayer::makeTurn()
{
    Card* result = NULL;

    std::cout << getName() << ", Ваш ход. Ваши карты:"<<std::endl;
    cards.sort ( Card::isLesser );
    printCards();

    std::list<Card*> possibleCards = getPossibleCards();
    if ( possibleCards.size() == 0 )
    {
        std::cout << "\nВам нечем ходить\n"<<std::endl;
        return NULL;
    }

    unsigned val = 0;

    while (true) {
        std::cout << "\nВведите номер карты, чтобы положить её на стол: ";
        std::string token;
        std::cin >> token;

        if (token.empty())
        {
            showHint(possibleCards);
            continue;
        }
        else if (token == "\\q" || token == "\\quit" )
        {
            std::cout << "Пока!" << std::endl;
            exit(0);
        }

        val = atoi (token.c_str());

        if ( (val < 1) || (val > cards.size()) )
        {
            showHint(possibleCards);
            continue;
        }

        std::list<Card*>::const_iterator card = cards.begin();
        for(unsigned num=1; num != val && card != cards.end(); card++, num++);

        if ( find (possibleCards.begin(), possibleCards.end(), *card) != possibleCards.end() )
        {
            result = *card;
            table.putCard ( result );
            cards.remove (result);
            break;
        }

        std::cout << "Вы не можете сходить этой картой!" << std::endl;
        showHint(possibleCards);
    }

    return result;
}

/**
 *
 */
std::list<Card*> ConsolePlayer::getPossibleCards() const
{
    std::list<Card*> result;

    for( std::list<Card*>::const_iterator card = cards.begin(); card != cards.end(); card++ )
    {
        if (table.canPutCard (*card))
            result.push_back(*card);
    }

    return result;
}

/**
 * Show all player's cards
 */
void ConsolePlayer::printCards() const
{
    int cardNumber = 1;

    CardSuit s = (*cards.begin())->getSuit();
    for ( std::list<Card*>::const_iterator card = cards.begin(); card != cards.end(); card++)
    {
         if ( (*card)->getSuit() !=  s )
             std::cout << std::endl;
        s = (*card)->getSuit();
        std::cout <<"  "<< cardNumber++ << "-" << (*card)->toShortString() << "  ";
    }
    std::cout <<"\n" << std::endl ;
}

/**
 * Show cards which user can put on the table
 */
void ConsolePlayer::showHint(std::list<Card*> possible) const
{
    std::cout << "Вы можете сходить одной из этих карт: ";
    for(std::list<Card*>::const_iterator card = possible.begin(); card != possible.end(); card++) {
        std::cout << (*card)->toShortString()<< " ";
    }
    std::cout << std::endl;
}
