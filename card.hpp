#ifndef _card_hpp_

#define _card_hpp_
#include <iostream>
class Card {

public:
    enum cardSuit { Hearts, Diamonds, Clubs, Spades } suit;
    enum cardNum { Ace = 1, Two = 2, Three = 3, Four = 4, Fife = 5, Six = 6,
        Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11,
        Queen = 12, King = 13} num;
    bool cardPos;

    Card(cardSuit _suit, cardNum _num, bool _face) : suit(_suit), num(_num), cardPos(_face)  { 
    }
    Card() {
    }
    void Flip();
    friend std :: ostream& operator<< (std :: ostream& out, Card &card);
    int GetValue() const;
};
#endif