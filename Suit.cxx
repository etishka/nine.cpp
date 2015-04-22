#include "Suit.hxx"

using namespace nine;

/**
 *
 */
const std::string Suit::toString ( int value )
{
    switch ( value )
    {
        case DIAMONDS: return std::string ( "DIAMONDS" );
        case CLUBS:    return std::string ( "CLUBS" );
        case SPADES:   return std::string ( "SPADES" );
        case HEARTS:   return std::string ( "HEARTS" );
        default:       return std::string ( "??ERROR??" );
    }
}

/**
 *
 */
const std::string Suit::getLetter ( int value )
{
    switch ( value )
    {
        case DIAMONDS: return "D";
        case CLUBS:    return "C";
        case SPADES:   return "S";
        case HEARTS:   return "H";
        default:       return "?";
    }
}

/**
 *
 */
const CardSuit Suit::getSuit ( int value )
{
    switch ( value )
    {
        case DIAMONDS: return DIAMONDS;
        case CLUBS:    return CLUBS;
        case SPADES:   return SPADES;
        case HEARTS:   return HEARTS;
        default: return BIGGEST_SUIT;
    }
}


#ifdef _NINE_DEBUG_SUIT_
#include <iostream>


int main ( int c, char *v[] )
{
    std::cout << Suit::toString ( DIAMONDS ) << endl;
    std::cout << Suit::toString ( HEARTS ) << endl;
    std::cout << Suit::toString ( CLUBS ) << endl;
    std::cout << Suit::toString ( SPADES ) << endl;
}
#endif
