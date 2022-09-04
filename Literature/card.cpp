#include<bits/stdc++.h>
using namespace std;

const vector<string> suits={"hearts","diamonds","clubs","spades"};
const vector<string> ranks={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const vector<string> symbols={"♥","♦","♣","♠"};

class Card{ public:
	int value;
	string symbol;
	int rankIndex,suitIndex;
	string rank,suit;
	string crank,csuit,csymbol;
	Card(string rank,string suit){
		this->rank=rank;
		this->suit=suit;

		rankIndex=GetRankIndex();
		suitIndex=GetSuitIndex();
		
		value=rankIndex+13*suitIndex;
		symbol=symbols[suitIndex];

		AssignColor();
	}
	void AssignColor(){
		string colorID=to_string(suitIndex+1);
		crank="\033[1;3"+colorID+"m"+rank+"\033[0m";
		csuit="\033[1;3"+colorID+"m"+suit+"\033[0m";
		csymbol="\033[1;3"+colorID+"m"+symbol+"\033[0m";
	}
	int GetSuitIndex(){
		return Find(suits,suit);
	}
	int GetRankIndex(){
		return Find(ranks,rank);
	}
	int Find(vector<string> collection,string element){
		for(int i=0;i<collection.size();i++){
			if(collection[i]==element){
				return i;
			}
		}
		return -1;
	}
	void debug(){
		cout << "Card: " << crank << csymbol << " - " << value << "\n";
	}
};

vector<Card> CreateDeck(){
	vector<Card> deck;
	for(int i=0;i<suits.size();i++){
		for(int j=0;j<ranks.size();j++){
			deck.push_back(Card(ranks[j],suits[i]));
		}
	}
	return deck;
}

void ShuffleDeck(vector<Card>& deck){
	srand(time(NULL));
	random_shuffle(deck.begin(),deck.end());
}

void Sort(vector<Card>& deck){
	auto cmp=[&](Card X,Card Y)->bool{
		return X.value<Y.value;
	};
	sort(deck.begin(),deck.end(),cmp);
}

vector<vector<Card>> DealDeck(vector<Card> deck,int n=4){
	vector<vector<Card>> split(n);
	int eachShare=(deck.size())/n;
	for(int i=0;i<deck.size();i++){
		split[i/eachShare].push_back(deck[i]);
	}
	for(int i=0;i<n;i++){
		Sort(split[i]);
	}
	return split;
}
