#include "Card.hxx"

using namespace nine;
/**
 *
 */
Card::Card ( int r, int s ) : rank ( Rank::getRank ( r ) ), suit ( Suit::getSuit ( s ) ) {}

/**
 *
 */
Card::Card ( const Card& card ) :
        rank ( card.getRank() ),
        suit ( card.getSuit() )
{}

/**
 *
 */
const std::string Card::toString() const
{
    return std::string ( Rank::toString ( rank ) + ", " + Suit::toString ( suit ) );
}

/**
 *
 */
const std::string Card::toShortString() const
{
    return std::string (Rank::getLetter (rank) + Suit::getLetter ( suit ) );
}

/**
 *
 */
const CardRank& Card::getRank() const
{
    return rank;
}

/**
 *
 */
const CardSuit& Card::getSuit() const
{
    return suit;
}

/**
 *
 */
bool Card::operator < (Card* card) const
{
    bool result;

    if ( this->getSuit() == card->getSuit() )
        result = ( (this->getRank() - card->getRank()) < 0 );
    else
        result = ( (this->getSuit() - card->getSuit()) < 0 );

    return result;
}

/**
 *
 */
bool Card::isLesser(Card* c1, Card* c2)
{
    return c1->operator <( c2);
}

/**
 *
 */
bool Card::equals (CardSuit s, CardRank r) const
{
    return (this->rank == r) && (this->suit == s);
}
