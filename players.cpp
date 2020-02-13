#include "players.hpp"

bool GenericPlayer :: IsBoosted() const{
    if (GetTotal() > 21) return true;
    else return false;
}
void GenericPlayer :: Bust() const{
    cout << name << " is Boosted !"<< endl;
}
ostream& operator<< (ostream& out, GenericPlayer &gp){
    out << gp.name << " with cards:";
    for (auto ind : gp.m_Cards){
        out << *ind;
        if (ind != gp.m_Cards.back()) out << ", ";
    }
    out << " and total points: "<< gp.GetTotal();
    return out;
}
bool Player :: IsHitting() const{
    char answer = '0';
    while(!(answer == 'y' || answer == 'Y' || answer =='n' || answer == 'N')){
        cout << name << " do you want one more card? (y/Y - yes, n/N - no):";
        cin >> answer;
        cout << endl;
    }
    if (answer == 'y' || answer == 'Y') return true;
    else return false;
} 
void Player :: Win() const{
    cout << name << " win!" << endl;
}
void Player :: Lose()const {
    cout << name << " lose!" << endl;
}    
void Player :: Push() const{
    cout << name << " played a draw!" << endl;
}
House :: House(){
    name = "Dealer";
}
bool House :: IsHitting() const{
    if (GetTotal() < 16) return true;
    else return false;
}  
void House :: FlipFirstCard(){
    m_Cards[0]->Flip();
}