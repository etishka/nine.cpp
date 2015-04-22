#include "players/SimplePlayer.hxx"
#include "Card.hxx"
#include "Table.hxx"

using namespace nine;

/**
 *
 */
SimplePlayer::SimplePlayer( Table& t, const std::string name):
    Player (t,name, 2)
{
}

/**
 *
 */
Card* SimplePlayer::makeTurn() {
    // Simple algorithm
    Card* iCard = IHave ( DIAMONDS, NINE );
    // If there's no cards on the table
    if ( table.getNumberOfCards() == 0 )
        if (iCard != NULL){
            // and I have 9 diamonds, put it, return
            table.putCard ( iCard );
            cards.remove (iCard);
            return iCard;
        }
        else
            // and I have no 9 diamonds, just return
            return NULL;

    // run through suits
    // put next or prev card if possible, return
        for (int suit = SMALLEST_SUIT; suit < BIGGEST_SUIT; suit ++)
    {
        CardSuit suitValue = Suit::getSuit (suit);
        // do not put nine on this step, put neighbours instead
        if ( table.isRowEmpty( suitValue ) )
            continue;

            //TODO: extract method
            Card* card = table.getMostRightCard ( suitValue );
            CardRank rankValue = Rank::getNextRank (card->getRank());

            if ( rankValue != card->getRank()){
                Card* result = putIfIHave (suitValue, rankValue);
                if (result != NULL)
                    return result;
            }

            card = table.getMostLeftCard ( suitValue );
            rankValue = Rank::getPrevRank (card->getRank());

            if ( rankValue != card->getRank() ){
                Card* result = putIfIHave  (suitValue, rankValue);
                if (result != NULL)
                    return result;
            }
    }

    // put nine if possible, return
    for (int suit = SMALLEST_SUIT; suit < BIGGEST_SUIT; suit ++)
    {
        Card* iCard = IHave ( Suit::getSuit (suit), NINE);
        if ( iCard != NULL )
        {
            table.putCard ( iCard );
            cards.remove (iCard);
            return iCard;
        }
    }

    // put nothing, return
    return NULL;
}

Card* SimplePlayer::putIfIHave( CardSuit suit, CardRank rank ) {

    Card* iCard = IHave ( suit, rank );
    if ( iCard != NULL ){
        cards.remove ( iCard );
        table.putCard ( iCard );
        return iCard;
    }

    return NULL;
}
