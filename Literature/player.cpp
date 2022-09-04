#include<bits/stdc++.h>
using namespace std;

class Player{ public:
	int playerID;
	vector<Card> deck;
	vector<pair<int,Card>> lostCards;
	vector<vector<int>> cardMap;
	Player(int playerID,vector<Card> deck){
		this->playerID=playerID;
		this->deck=deck;
		StoreCardInfo();
	}
	void MakeQuery(){
		while(!lostCards.empty()){

		}
	}
	bool ValidQuery(Card card){
		return cardMap[playerID][card.value]==0;
	}
	void StoreCardInfo(){
		cardMap.assign(4,vector<int>(52,-1));
		for(int i=0;i<deck.size();i++){
			cardMap[playerID][deck[i].value]=1;
		}
		for(int i=0;i<deck.size();i++){
			cardMap[playerID][i]=max(cardMap[playerID][i],0);
		}
	}
	void Show(){
		PrintCards(deck);
	}
};

class Players{ public:
	vector<Player> people;
	Players(vector<vector<Card>> dealtDeck){
		
	}
	
};
