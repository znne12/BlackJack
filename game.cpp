#include "game.hpp"

Game :: Game(const vector<string>& names){
     for (auto id : names) {
        m_Players.push_back(Player(id));
    } 
    //srand(time(NULL));
    deck.Populate();
    deck.Shuffle();
}
void Game :: Play(){
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i){
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
            deck.Deal(*pPlayer);
        }
        deck.Deal(dealer);
    }

    dealer.FlipFirstCard();

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {  // показывает карты игроков
        cout << *pPlayer << endl;  
    }
    cout << dealer << endl;
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        deck.AdditionalCards(*pPlayer);
    }
    dealer.FlipFirstCard();
    cout << dealer << endl;

    deck.AdditionalCards(dealer);
    if (dealer.IsBoosted()){ // проверка кто выйграл
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!(pPlayer->IsBoosted())) pPlayer->Win();
        }
    } else {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!(pPlayer->IsBoosted())) 
                if (pPlayer->GetTotal() > dealer.GetTotal()) {
                    pPlayer->Win();
                } else if (pPlayer->GetTotal() < dealer.GetTotal()){
                    pPlayer->Lose();
                } else pPlayer->Push();
        }

    }
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) pPlayer->Clear();
    dealer.Clear();

}