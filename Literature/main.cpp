#include<bits/stdc++.h>
#include "card.cpp"
#include "print.cpp"
#include "player.cpp"
// #include "judge.cpp"
using namespace std;

int main(){
	vector<Card> deck=CreateDeck();
	ShuffleDeck(deck);
	vector<vector<Card>> dealtDeck=DealDeck(deck);

	Player p(0,dealtDeck[0]);
	p.Show();

	// Judge judge(dealtDeck);
	// judge.ShowMap();
}
