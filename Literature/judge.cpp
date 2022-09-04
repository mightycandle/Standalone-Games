#include<bits/stdc++.h>
using namespace std;

class Judge{ public:
	vector<vector<int>> cardMap;
	vector<Player> players;
	Judge(vector<vector<Card>> dealtDeck){
		for(int i=0;i<4;i++){
			players.push_back(Player(i,dealtDeck[i]));
		}
		cardMap.assign(4,vector<int>(52));
		for(int i=0;i<dealtDeck.size();i++){
			cout << i << "\n";
			for(int j=0;j<dealtDeck[i].size();j++){
				cardMap[i][dealtDeck[i][j].value]=1;
			}
		}
	}
	bool IsCorrectGuess(Player &giver,Player &taker,Card card){
		return taker.cardMap[taker.playerID][card.value]==0;
	}
	void Transfer(Player &giver,Player &taker,Card card){
		int cardIndex;
		for(int i=0;i<taker.deck.size();i++){
			if(taker.deck[i]==card){
				cardIndex=i;
			}
		}
		taker.lostCards.push_back(make_pair(taker.playerID,card));
		taker.deck.erase(taker.deck.begin()+cardIndex);
		giver.push_back(card);
		cardMap[giver.playerID][card.value]=0;
		cardMap[taker.playerID][card.value]=1;
		for(int i=0;i<4;i++){
			players[i].cardMap[giver.playerID][card.value]=0;
			players[i].cardMap[taker.playerID][card.value]=1;
		}
	}
	void ShowMap(){
		for(auto _x:cardMap){
			for(auto it=_x.begin();it!=_x.end();it++){
				cout << *it << " \n"[it+1==_x.end()];
			}
		}
	}
};
