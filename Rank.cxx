#include "Rank.hxx"

using namespace nine;
/**
 *
 */
CardRank Rank::getRank ( int v )
{
    switch ( v )
    {
        case SIX:   return SIX  ;
        case SEVEN: return SEVEN;
        case EIGHT: return EIGHT;
        case NINE:  return NINE ;
        case TEN:   return TEN  ;
        case JACK:  return JACK ;
        case QUEEN: return QUEEN;
        case KING:  return KING ;
        case ACE:   return ACE  ;
        default:    return SIX  ;
    }
}

/**
 *
 */
int Rank::getScore ( int value )
{
    switch ( value )
    {
        case SIX:  return 2;
        case SEVEN:return 3;
        case EIGHT:return 4;
        case NINE: return 9;
        case TEN:  return 5;
        case JACK: return 4;
        case QUEEN:return 3;
        case KING: return 2;
        case ACE:  return 1;
        default:   return -1;
    }
}

/**
 *
 */
std::string Rank::getLetter ( int value )
{
    switch ( value )
    {
        case SIX:   return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE:  return "9";
        case TEN:   return "T";
        case JACK:  return "J";
        case QUEEN: return "Q";
        case KING:  return "K";
        case ACE:   return "A";
        default:    return "?";
    }
}

/**
 *
 */
std::string Rank::toString ( int value )
{
    switch ( value )
    {
        case SIX:   return std::string ( "SIX" )  ;
        case SEVEN: return std::string ( "SEVEN" );
        case EIGHT: return std::string ( "EIGHT" );
        case NINE:  return std::string ( "NINE" ) ;
        case TEN:   return std::string ( "TEN" )  ;
        case JACK:  return std::string ( "JACK" ) ;
        case QUEEN: return std::string ( "QUEEN" );
        case KING:  return std::string ( "KING" ) ;
        case ACE:   return std::string ( "ACE" )  ;
        default:    return std::string ( "??ERROR RANK??" );
    }
}

/**
 *
 */
CardRank Rank::getNextRank ( CardRank rank )
{
    if ( rank == ACE )
        return rank;
    else
        return getRank ( rank+1 );
}

/**
 *
 */
CardRank Rank::getPrevRank ( CardRank rank )
{
    if ( rank == SIX )
        return rank;
    else
        return getRank ( rank-1 );
}


#ifdef _NINE_DEBUG_RANK_
#include <iostream>

int main ( int c, char *v[] )
{
    cout << Rank::toString ( SIX ) << endl;
    cout << Rank::toString ( SEVEN ) << endl;
    cout << Rank::toString ( EIGHT ) << endl;
    cout << Rank::toString ( NINE ) << endl;
    cout << Rank::toString ( TEN ) << endl;
    cout << Rank::toString ( JACK ) << endl;
    cout << Rank::toString ( QUEEN ) << endl;
    cout << Rank::toString ( KING ) << endl;
    cout << Rank::toString ( ACE ) << endl;
    cout << "----" <<endl;
    cout << Rank::toString ( Rank::getNextRank ( Rank::SIX ) ) << endl;
    cout << Rank::toString ( Rank::getNextRank ( Rank::ACE ) ) << endl;
    cout << Rank::toString ( Rank::getPrevRank ( Rank::SIX ) ) << endl;
    cout << Rank::toString ( Rank::getPrevRank ( Rank::ACE ) ) << endl;
}
#endif
