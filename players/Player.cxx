#include "players/Player.hxx"
#include "Deck.hxx"
#include "Utils.hxx"
#include "Card.hxx"
#include "Table.hxx"

using namespace nine;

/**
 * Default constructor
 */
Player::Player ( Table& t): table(t)
{
}

/**
 *
 */
Player::Player ( Table& t, std::string n, int time):
        table(t), name(n), turnTime(time)
{
}

Player::~Player()
{
}

/**
 * Give card to the player
 */
void Player::addCard (Card* card)
{
    cards.push_back (card);
}

/**
 * TODO: rename?
 */
void Player::moveCardsToDeck()
{
    while (!cards.empty()){
        Deck::getDeck().addCard ( cards.back() );
        cards.pop_back();
    }
}

/**
 * Check where player has specified card or not
 * @return pointer to checked card if found, NULL otherwise
 */
Card* Player::IHave (CardSuit suit, CardRank rank) const
{
    for (std::list<Card*>::const_iterator it = cards.begin(); it != cards.end(); it++)
    {
        if ( (*it)->getRank() == rank &&  (*it)->getSuit() == suit)
            return *it;
    }
    return NULL;
}

/**
 * Get player values in string form
 * TODO: move to debug only
 */
#include <sstream>
const std::string Player::toString() const {
    std::stringstream result;
    result << "Name:" << name << ", num of cards=" << cards.size();
    return result.str();
}

/**
 * Return list of player's cards
 */
std::list<Card*> Player::getCards() const {
     return cards;
}

/**
 * Get number of cards player has
 * @return number of cards on hands
 */
int Player::getNumberOfCards() const
{
    return cards.size();
}

/**
 */
std::string Player::getName() const {
    return name;
}

/**
 */
void Player::setName(const std::string n) {
    name = n;
}

void Player::setTurnTime(int time)
{
    turnTime = time;
}

int Player::getTurnTime() const
{
    return turnTime;
}

