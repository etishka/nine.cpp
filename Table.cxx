#include <sstream>

#include "Table.hxx"
#include "Deck.hxx"
#include "Card.hxx"

using namespace nine;

/**
 * Table constructor
 * @param r - number of rows on the table
 * @param c - number of columns on the table
 */
Table::Table ( int r, int c ) :
        numberOfCards ( 0 ), rows ( r ), columns ( c ), dataVector ( rows, std::vector<Card*> ( columns ) )
{

    clearTable();
}

/**
 *
 */
Table& Table::getTable ( int r = BIGGEST_SUIT, int c = ACE+1 )
{
    static Table table ( r,c );
    return table;
}

/**
 * Clear table
 * Move all cards from the table to the deck
 */
void Table::clearTable ()
{
    for ( int i = 0; i < rows; i++ )
        for ( int j = 0; j < columns; j++ )
        {
            Card* card = getValueAt ( i,j );
            if ( card != NULL )
            {
                setValueAt ( NULL, i, j );
                Deck::getDeck().addCard ( card );
            }
        }
}

/**
 * Check whether specified row is empty or not
 * @param suit - suit to check
 * @return
 */
bool Table::isRowEmpty ( CardSuit suit ) const
{
    for ( int column=0; column < getColumnCount(); column++ )
        if ( getValueAt ( getRow ( suit ), column ) != NULL )
            return false;

    return true;
}

/**
 * Get number of columns on the table
 * @return number of columns on the table
 * TODO: inline?
 */
const int Table::getColumnCount() const
{
    return columns;
}

/**
 * Get number of rows on the table
 * @return number of rows on the table
 * TODO: inline?
 */
const int Table::getRowCount() const
{
    return rows;
}

/**
 * Get card from specified row and column
 * @param
 * @param
 * @return card from specified row and column
 */
Card* Table::getValueAt ( int row, int column ) const
{
    return dataVector[row][column];
}

/**
 * Set value(card*) to specified row and column
 * @param
 * @param
 * @param
 */
void Table::setValueAt ( Card* aValue, int row, int column )
{
    dataVector[row][column] = aValue;
}

/**
 * Put card on the table
 * @param card - card to put
 * @return
 */
Card* Table::putCard ( Card* card )
{
    setValueAt ( card, getRow ( card->getSuit() ), getColumn ( card->getRank() ) );

    numberOfCards++;

    return card;
}

/**
 * get most right card on the specified row
 * @param suit specifies suit to get most right card for
 * @return most right card on the specified row, NULL if the row is empty or there's no free cell on the right
 * TODO: return CardRank. What should it return in case if row empty? throw exception?
 */
Card* Table::getMostRightCard ( CardSuit suit ) const
{
    for ( int column = getColumnCount()-1; column >= 0 ; column-- )
        if ( getValueAt ( getRow ( suit ) , column ) != NULL )
            return getValueAt ( getRow ( suit ) , column );

    return NULL;
}

/**
 * Get most left card on the specified row
 * @param suit specifies suit to get most left card for
 * @return most left card on the specified row, NULL if the row is empty or there's no free cell on the left
 */
Card* Table::getMostLeftCard ( CardSuit suit ) const
{
    for ( int column = 0; column < getColumnCount() ; column++ )
        if ( getValueAt ( getRow ( suit ), column ) != NULL )
            return getValueAt ( getRow ( suit ), column );

    return NULL;
}

/**
 * Get column where specified card should be placed
 * @return
 */
int Table::getColumn ( const CardRank rank ) const
{
    switch ( rank )
    {
        case SIX:  return 0;
        case SEVEN:return 1;
        case EIGHT:return 2;
        case NINE: return 3;
        case TEN:  return 4;
        case JACK: return 5;
        case QUEEN:return 6;
        case KING: return 7;
        case ACE:  return 8;
    }
    return -1;
}

/**
 * Get row where specified card should be placed
 * @return
 */
int Table::getRow ( const CardSuit suit ) const
{
    switch ( suit )
    {
        case DIAMONDS: return 0;
        case SPADES:   return 1;
        case HEARTS:   return 2;
        case CLUBS:    return 3;
        default: return -1;
    }
}

/**
 * Get number of cards on the table
 * @return
 */
int Table::getNumberOfCards() const
{
    return numberOfCards;
}

/**
 * Check whether specified card could be put or not
 * @return true if specified card could be put, false otherwise
 */
bool Table::canPutCard(Card* card) const
{
    bool result = false;
    if (card == NULL)
        result = false;
    else if (isRowEmpty(DIAMONDS) && !card->equals(DIAMONDS, NINE))
        result = false;
    else if (card->getRank() == NINE)
        result = true;
    else if (isRowEmpty (card->getSuit()) )
        result = false;
    else
    {
        const CardSuit suit = card->getSuit();
        result= (
                card->equals (suit, Rank::getPrevRank ( getMostLeftCard (suit)->getRank() ) ) ||
                card->equals (suit, Rank::getNextRank ( getMostRightCard(suit)->getRank() ) )
               );
    }

    return result;
}

/**
 * Get string representation of the table
 * @return string with ASCII-formed current table
 */
std::string Table::toString() const
{
    std::stringstream result;

    //TODO: set rows order in a separate function
    std::string rowName[] = {"D","S","H","C"};

    result << "-----------------------" << std::endl;
    result << "  | 6 7 8 9 T J Q K A  " << std::endl;
    result << "--+--------------------" << std::endl;

    for ( int row = 0; row < getRowCount(); row++ )
    {
        result <<  rowName[row] << " | ";
        for ( int column = 0; column < getColumnCount(); column++ )
        {
            Card* card = getValueAt( row, column );

            if ( card == NULL )
                result << "- ";
            else
                result << Rank::getLetter ( card->getRank() ) << " ";
        }

        result << std::endl;
    }

    result <<"-----------------------" << std::endl;
    return result.str();
}

#ifdef _NINE_DEBUG_TABLE_
#include <iostream>

int main()
{
    Table& table = Table::getTable();
//    std::cout << table.toString();
    Deck& deck = Deck::getDeck();
    deck.shuffle();

    for ( int i = 0; i < 3; i++ )
    {
        Card* card = deck.getCard();
        std::cout <<"Got card from the deck: " << card->toString() << std::endl;
        table.putCard ( card );
    }

    std::cout << Table::getTable().toString();

    Card*card;
    card = Table::getTable().getMostLeftCard ( SPADES );
    std::cout <<"LEFT: ";
    if ( card != NULL )
        std::cout << card->toString() << std::endl;
    else
        std::cout << "NULL" << std::endl;

    card = Table::getTable().getMostRightCard ( HEARTS );
    std::cout <<"RIGHT: ";
    if ( card != NULL )
        std::cout << card->toString() << std::endl;
    else
        std::cout << "NULL" << std::endl;
}
#endif
