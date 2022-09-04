                                                     /*##SSS%%%??????????????
                                              ##SS%%?????????????????????????
                                       ##SS%%????????????????????????????????
                                ##SS%%????????????????????????????%??????????
                          ##SS%%??????##      @@@@@@                S%???????
                   ##SS%%?????????##        @%%@%%@%                 %%??????
               ##SS%%?????##               **%&&#&(##??????????????%?????????
                               ##SS%%???????   /.    ##?????????????%????????
                         ##SS%%?*?????????     ..    |********S%?????????????
                                          &&&. .     |         @?????????????
                                          &.   .     |.     *@@@@%???????????
                                          &#   |     |   .//@@@@@@@@@@@??????
                                               / //&&#  **@@%%@@@@@@@%%@%????
                   ##SS%%?************************************#@@@@@@@%%%%???
                            ##SS%%?#???????????##???????????//@@%@@@@@%??????
                 ##SS%%?     @@               ******.////////%@@@@@@@@%%?????
                       ???*@@@@@@@@@@%%*@@@**** @@@&&.(    @@@@@@@@@%??????*/
#include<bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ivec vector<int>
#define svec vector<string>
#define dvec vector<deque<int>>
#define pb push_back
#define F(i,a,b) for(int i=a;i<b;i++)
#define B(u,a,b) for(int u=a;u>b;u--)
#define rep(i,n) F(i,0,n)
#define print(x) cout<<x<<endl
#define nex cout<<endl
using namespace std;
void block(char c){
	if(c=='3'||c=='1')
		cout<<"|"<<"\033[1;4"<<c<<"m"<<"   "<<"\033[0m";
	else
		cout<<"|   ";
}
void printb(dvec board,int n){
	system("clear");
	if(n==1)
		print("Computer has played.");
	cout<<"Current board"<<endl<<endl;
	dvec clone;
	clone=board;
	int diff=0;
	rep(i,7){
		while(clone[i].size()!=6){
			clone[i].pb(0);
		}
	}
	rep(i,7)
		cout<<"  "<<i<<" ";
	nex;
	B(j,5,-1){
		cout<<string(29,'-')<<endl;
		rep(i,7){
			if(clone[i].back()==1){
				block('3');
			}
			else if(clone[i].back()==-1){
				block('1');
			}
			else{
				block('0');
			}
			clone[i].pop_back();
		}
		cout<<"|"<<endl;
	}
	cout<<string(29,'-')<<endl<<endl;
}

dvec p2c(dvec board){
	cout<<endl<<"Enter input (column index) : ";
	int n;cin>>n;
	dvec clone;
	clone=board;
	clone[n].pb(1);
	printb(clone,1);
	return clone;
}

int checkend(dvec board){
	dvec clone;
	clone=board;
	rep(i,7){
		while(clone[i].size()!=6){
			clone[i].pb(0);
		}
	}
	rep(i,7){ //column
		rep(j,3){
			if(clone[i][j]==clone[i][j+1] && clone[i][j+2]==clone[i][j+3] && clone[i][j]==clone[i][j+2]&& clone[i][j]!=0){
				if(clone[i][j]+100<102){
					return(clone[i][j]+100);
				}
			}

		}
	}
	rep(j,6){//row
		rep(i,4){
			if(clone[i][j]==clone[i+1][j]&&clone[i+2][j]==clone[i+3][j]&&clone[i][j]==clone[i+3][j] && clone[i][j]!=0){
				if(clone[i][j]+200<202){
					return(clone[i][j]+200);
				}
			}
		}
	}
	rep(i,4){//rev diag
		F(j,3,6){
			if(clone[i][j]==clone[i+1][j-1]&&clone[i][j]==clone[i+2][j-2]&&clone[i+2][j-2]==clone[i+3][j-3]&& clone[i][j]!=0){
				if(clone[i][j]+300<302){
					return(clone[i][j]+300);
				}
			}
		}
	}
	rep(i,4){//fwd diag
		rep(j,3){
			if(clone[i][j]==clone[i+1][j+1]&&clone[i][j]==clone[i+3][j+3]&&clone[i+2][j+2]==clone[i+3][j+3]&& clone[i][j]!=0){
				if(clone[i][j]+400<402){
					return(clone[i][j]+400);
				}
			}
		}
	}
	return 0;
}

bool isvalid(int x,int y,dvec board){
	if(x>-1 && y>-1 && x<7 && y<6)
		return true;
	return false;
}

int nc(dvec board,ivec neu){
	int ind;
	int m;
	int f=0;
	int max=0;
	rep(i,neu.size()+1){
		int n=board[neu[i]].size()-1;
		m=neu[i];
		int c=0;
		if(n==-1)
			c=1;
		else{
			f=1;
			if(isvalid(i,n-1,board)==true)
				c-=board[i][n-1];
			if(isvalid(i-1,n-1,board)==true)
				c-=board[i-1][n-1];
			if(isvalid(i-1,n,board)==true)
				c-=board[i-1][n];
			if(isvalid(i+1,n-1,board)==true)
				c-=board[i+1][n-1];
			if(isvalid(i+1,n,board)==true)
				c-=board[i+1][n];
		}
		if(max<c){
			ind=m;
			max=c;
		}
	}
	
	if(f==1){
		if(ind>-1 && ind <7)
			return ind;
	}
	int r=rand()%neu.size();
	return neu[r];
}

dvec c2p(dvec board){
	dvec clone;
	ivec neu;
	clone=board;
	ivec fin;
	dvec temp=clone;
	int s=0;
	rep(i,7)
		s+=clone[i].size();
	
	if(s<=2){
		int random=rand()%7;
		clone[random].pb(-1);
		return clone;
	}
	rep(i,7){
		clone=board;
		if(clone[i].size()<6){
			clone[i].pb(-1);
			if(checkend(clone)%10==9)
				return clone;
			if(checkend(clone)%10!=1)
				neu.pb(i);
		}
	}
	F(i,0,neu.size()){
		if(clone[neu[i]].size()<5){
			clone=board;
			clone[neu[i]].pb(-1);
			temp=clone;
			F(j,0,7){
				if(clone[j].size()<6){
					clone[j].pb(1);
					if(checkend(clone)%10!=1)
						fin.pb(neu[i]);
					if(checkend(clone)%10==1){
						clone=board;
						clone[j].pb(-1);
						return clone;
					}
					clone=temp;
				}
			}
		}
	}
	clone=board;
	int index=nc(clone,fin);
	clone[fin[index]].pb(-1);
	return clone;
}
int main(){
	srand((unsigned) time(0));
	dvec board;
	rep(i,7)board.pb(deque<int>());
	system("clear");
	cout<<string(8,' ')<<"Welcome to Connect 4 (4-in-a-row)"<<endl;
	cout<<"Aim:"<<endl<<"  "<<"To make a horizontal/vertical/diagonal 4 in a row"<<endl<<endl;
	
	cout<<"Input:"<<endl<<"  "<<"The column number where you want to pile your pin"<<endl;
	cout<<"  "<<"(Your pin gets added by column (vertically) in the board)"<<endl<<endl;
	cout<<"Hit ENTER to begin";
	if(cin.get()=='\n'){
		printb(board,0);
		int gameover=0;
		while(gameover==0){
			board=p2c(board);
			gameover=checkend(board);
			if(gameover!=0)break;
			board=c2p(board);
			printb(board,1);
			gameover=checkend(board);
		}
		if(gameover%10==1){
			print("You won.");
			if(gameover==101)print("You made a vertical 4 in a row");
			else if(gameover==201)print("You made a horizontal 4 in a row");
			else	print("You made a diagonal 4 in a row");
		}
		else if(gameover%10==9){
			print("Computer won");
			if(gameover==99)print("It got a vertical 4 in a row");
			else if(gameover==199)print("It got a horizontal 4 in a row");	
			else	print("It got a diagonal 4 in a row");
		}
		else{
			print("Draw");
		}
	}
}
