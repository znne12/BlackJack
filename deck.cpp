#include "deck.hpp"

Deck :: Deck(){
    m_Cards.reserve(52);
    Populate();
}
void Deck :: Populate(){
    Clear();
    for (int i = Card::Ace; i < Card::King; ++i)
        for (int j = Card::Hearts; j < Card::Spades; j++){
            //Card *card = new Card(static_cast<Card::cardSuit>(j), static_cast<Card::cardNum>(i), false);
            Add(new Card(static_cast<Card::cardSuit>(j), static_cast<Card::cardNum>(i), false));
        }
    }
void Deck :: Shuffle(){
    random_device rd;
    mt19937 g(rd());
    shuffle(m_Cards.begin(), m_Cards.end(), g);
}
void Deck :: Deal(Hand& _Hand){
    if (m_Cards.empty()) cout << " Out of cards. Can't give more " << endl;
    else {
        _Hand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
}

void Deck :: AdditionalCards(GenericPlayer& _GP){
    while (!(_GP.IsBoosted()) && _GP.IsHitting()){
        Deal(_GP);
        cout << _GP << endl;
        if (_GP.IsBoosted()) _GP.Bust();
    }
}
Deck :: ~Deck(){}