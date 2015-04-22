#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Deck.hxx"
#include "Card.hxx"

using namespace nine;

/**
 * Make new Deck of known Cards and known Suits. Calculate number of cards in the deck.
 */
Deck::Deck()
{
    for ( int r = SIX; r <= ACE; r++ )
        for ( int s = SMALLEST_SUIT; s < BIGGEST_SUIT; s++ )
        {
            m_cards.push_back ( new Card ( r, s ) );
        }
}

/**
 * Destructor
 */
Deck::~Deck()
{
    //TODO: trace this event
#ifdef _NINE_DEBUG_DECK_
    cout << "Destructor called" <<endl;
#endif
    free();
}

/**
 * Free memory used by cards
 */
void Deck::free()
{
    for ( std::vector<Card*>::iterator it = m_cards.begin(); it != m_cards.end(); it++ )
        delete *it;
}

/**
 * Initially shuffle the deck
 * Override this method if want implement another shuffle algorithm
 */
void Deck::shuffle()
{
    srand ( time ( NULL ) );
    for ( unsigned c1 = 0; c1 < m_cards.size(); c1++ )
    {
        Card* tmp = m_cards[c1];


//     In  Numerical  Recipes  in  C: The Art of Scientific Computing (William H. Press, Brian P. Flannery, Saul A. Teukolsky,
//     William T. Vetterling; New York: Cambridge University Press, 1992 (2nd ed., p. 277)), the following comments are made:
//
//     "If you want to generate a random integer between 1 and 10, you should always do it by using high-order bits, as in
//
//                      j = 1 + (int) (10.0 * (rand() / (RAND_MAX + 1.0)));
//
//               and never by anything resembling
//
//                      j = 1 + (rand() % 10);
//
//               (which uses lower-order bits)."

        int c2 = 1 + ( int ) ( ( m_cards.size()-1 ) * ( rand() / ( RAND_MAX + 1.0 ) ) );

        m_cards[c1] = m_cards[c2];
        m_cards[c2] = tmp;
    }
}


/**
  * Singleton, produce new deck if not produced yet, shuffle it
  * @return shuffled deck
  */
Deck& Deck::getDeck()
{
    static Deck deck;
    return deck;
}

/**
  * Get next card from the deck
  */
Card* Deck::getCard()
{
    Card* result = NULL;

    if ( !m_cards.empty() )
    {
        result = m_cards.back();
        m_cards.pop_back();
    }

    return result;
}

/**
 * add card to the deck
 */
void Deck::addCard ( Card * card )
{
    //TODO: ensure card is not in already
    m_cards.push_back ( card );
}

/**
 * return number of cards in the deck
 */
size_t Deck::size() const
{
    return m_cards.size();
}


#ifdef _NINE_DEBUG_DECK_
#include <sstream>
/**
  * Get deck string representation
  * for debug purposes only
  */
std::string Deck::toString() const
{
    std::stringstream buf;

    for ( std::vector<Card*>::const_iterator it = m_cards.begin(); it != m_cards.end(); it++ )
        buf << ( *it )->toString() +<<endl;

    buf << "====\n";
    buf << std::string ( "Total:" ) << ( m_cards.size() ) + "\n";
    return buf;
}

int main ( int c, char *v[] )
{
    Deck& deck = Deck::getDeck();
    deck.shuffle();
    cout << "Before: " << endl << deck.toString();

    while ( deck.size() != 5 )
        cout << "get card: " << deck.getCard()->toString() <<endl;

    Deck& deck1 = Deck::getDeck();
    cout << "After: " << endl << deck1.toString();
}

#endif
