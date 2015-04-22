#ifndef QCARD_HXX
#define QCARD_HXX

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include "Card.hxx"


/**
	@author Alexander Smirnov <alexander.v.smirnov@gmail.com>
*/
class QCard : public QWidget
{
    Q_OBJECT

    public:

        QCard(const nine::Card* card, QWidget *parent=0);

        ~QCard();

    protected:

        const nine::Card *card;

        QPixmap *cardPicture;

    public:
        QLabel *pixmapLabel;

    private:
        QString getCardName(const nine::Card*);

};

#endif
