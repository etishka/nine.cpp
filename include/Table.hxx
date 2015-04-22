#ifndef _NINE_TABLE_HXX
#define _NINE_TABLE_HXX

#include <vector>
#include <string>

//TODO: make forward declaration instead?
#include "Rank.hxx"
#include "Suit.hxx"

namespace nine
{
    class Card;

    /**   | 0 1 2 3  4 5 6 7 8
     * ---+-------------------
     * D | 6 7 8 9 10 J Q K A
     * S | 6 7 8 9 10 J Q K A
     * H | 6 7 8 9 10 J Q K A
     * C | 6 7 8 9 10 J Q K A
     * @author asmirnov
     */
    class Table
    {
        public:

            static Table& getTable ( int r, int c );

            void clearTable ();

            bool isRowEmpty ( CardSuit suit ) const;

            Card* putCard ( Card* card );

            Card* getMostRightCard ( CardSuit suit ) const;

            Card* getMostLeftCard ( CardSuit suit ) const;

            int getNumberOfCards() const;

            bool canPutCard ( Card* ) const;

            const int getColumnCount() const;

            const int getRowCount() const;

            Card* getValueAt ( int row, int column ) const;

            void setValueAt ( Card* aValue, int row, int column );

            std::string toString() const;

        private:

            //Since table is a singleton, deny access to constructor, copy constructor and operator=
            Table ( int r, int c );

            Table ( const Table& );

            Table& operator= ( const Table& );

            int getColumn ( const CardRank ) const;

            int getRow ( const CardSuit ) const;

        private:

            int numberOfCards;

            int rows;

            int columns;

        protected:

            std::vector< std::vector <Card*> > dataVector;
    };
};
#endif /* _NINE_TABLE_HXX */
