#include "hand.hpp"

Hand :: Hand(){
    m_Cards.reserve(7);
}

void Hand :: Clear(){
    vector<Card*>::iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();
}
void Hand :: Add(Card* pCard) {
    m_Cards.push_back(pCard);
}
int Hand :: GetTotal() const{
    if (m_Cards.empty()) return 0;
    int sumTotal = 0;
     int  acesInHand= 0;
    for (auto ind : m_Cards) {
        sumTotal += ind->GetValue();
        if (ind->GetValue() == Card::Ace && acesInHand == 0) { acesInHand++; sumTotal += 10; }
    }
    return sumTotal;
}
Hand :: ~Hand(){
        Clear();
}