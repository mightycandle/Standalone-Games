#include<bits/stdc++.h>
using namespace std;
vector<string> colors={"black","red","green","yellow","blue","magenta","cyan","white"};
vector<string> colorIDs={"0","1","2","3","4","5","6","7"};

string GetCName(string s,string color){
	string colorID;
	for(int i=0;i<colors.size();i++){
		if(colors[i]==color){
			colorID=colorIDs[i];
		}
	}
	return "\033[1;3"+colorID+"m"+s+"\033[0m";
}

void PrintCards(vector<Card> cards){
	int n=cards.size();
	int length=4*n+3;
	cout << "\n" << string(length,'_') << "\n";
	for(int i=0;i<n;i++){
		Card currentCard=cards[i];
		int trail=3-currentCard.rank.size();
		cout << "|" << currentCard.crank << string(trail,' ');
	}
	cout << "  |\n";
	for(int i=0;i<n;i++){
		Card currentCard=cards[i];
		cout << "|" << currentCard.csymbol << "  ";
	}
	cout << "  |\n";
	for(int i=0;i<n;i++){
		cout << "|   ";
	}
	cout << "  |\n";
	for(int i=0;i<n;i++){
		cout << "|   ";
	}
	cout << "  |\n";
	for(int i=0;i<n;i++){
		int trail=3-(to_string(i).size())+(i==n-1)*2;
		cout << "|" << string(trail,' ') << "\033[1;35m"<<i<<"\033[0m";
	}
	cout << "|\n";
	cout << string(length,'-') << "\n\n";
}
