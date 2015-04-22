#include "qcard.hxx"
#include <QPaintEvent>
#include <QRect>
#include <QPainter>
#include <QLabel>
#include <iostream>

QCard::QCard(const nine::Card* _card, QWidget *parent)
    : QWidget(parent)
{
    card = _card;
    cardPicture = new QPixmap(getCardName(_card));
    std::cerr <<"Loaded image, w="<<cardPicture->width()<<", h="<<cardPicture->height()<<std::endl;

    pixmapLabel = new QLabel(this);
    pixmapLabel->setPixmap(*cardPicture);
}

QString QCard::getCardName(const nine::Card* _card)
{
    const int rank = (8 - _card->getRank())*4;
    int suit = 0;

    switch (_card->getSuit())
    {
        case nine::DIAMONDS:
            suit = 4;
            break;
        case nine::CLUBS:
            suit = 1;
            break;
        case nine::SPADES:
            suit = 2;
            break;
        case nine::HEARTS:
            suit = 3;
            break;
    }

    const QString result = QString("./img/") +
            QString::number(rank+suit) +
            ".png";

    std::cerr << "Filename=" << result.toLatin1().data()<<std::endl;
    std::cerr << "Filename=" << rank <<"+"<<suit<<std::endl;

    return result;
}

QCard::~QCard()
{
}


