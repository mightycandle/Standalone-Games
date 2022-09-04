#include<bits/stdc++.h>
using namespace std;

/*
For every move which forms a new tile of value 'n':
score += n*(log2(n)-1)
*/

//iterating through all rows but top row,
//to push them towards top row
int up(int board[4][4],int score){
	int i,j,x,y;
	for(j=0;j<4;j++){
		x=0,y=j;
		for(i=1;i<4;i++){
			if(board[i][j]!=0){
				int flag=0;
				if(board[i-1][j]==0 || board[i-1][j]==board[i][j]){
					if(board[x][y]==board[i][j]){
						board[x][y]*=2;
						board[i][j]=0;
						score+=(((log2(board[x][y]))-1)*board[x][y]);
					}
					else{
						if(board[x][y]==0){
							board[x][y]=board[i][j];
							board[i][j]=0;
						}
						else{
							board[x+1][y]=board[i][j];
							board[i][j]=0;
							if(flag==0)
								x++;
						}
					}
				}
				else
					x+=1;
			}
		}
	}
	return score;
}

//iterating through all rows but bottom row,
//to push them towards bottom row
int down(int board[4][4],int score){
	int i,j,x,y;
	for(j=0;j<4;j++){
		x=3,y=j;
		for(i=2;i>=0;i--){
			if(board[i][j]!=0){
				int flag=0;
				if(board[i+1][j]==0 || board[i+1][j]==board[i][j]){
					if(board[x][y]==board[i][j]){
						board[x][y]*=2;
						board[i][j]=0;
						score+=(((log2(board[x][y]))-1)*board[x][y]);
					}
					else{
						if(board[x][y]==0)
						{
							board[x][y]=board[i][j];
							board[i][j]=0;
						}
						else
						{
							board[x-1][y]=board[i][j];
							board[i][j]=0;
							if(flag==0)
								x--;
						}
					}
				}
				else
					x-=1;
			}
		}
	}
	return score;
}

//iterating through all columns but leftmost column,
//to push them towards leftmost column
int left(int board[4][4],int score){
	int i,j,x,y;
	for(i=0;i<4;i++){
		x=i,y=0;
		for(j=1;j<4;j++){
			if(board[i][j]!=0){
				int flag=0;
				if(board[i][j-1]==0 || board[i][j-1]==board[i][j]){
					if(board[x][y]==board[i][j]){
						board[x][y]*=2;
						board[i][j]=0;
						score+=(((log2(board[x][y]))-1)*board[x][y]);
					}
					else{
						if(board[x][y]==0){
							board[x][y]=board[i][j];
							board[i][j]=0;
						}
						else{
							board[x][y+1]=board[i][j];
							board[i][j]=0;
							if(flag==0)
								y++;
						}
					}
				}
				else
					y+=1;
			}
		}
	}
	return score;
}

//iterating through all columns but rightmost column,
//to push them towards rightmost column
int right(int board[4][4],int score){
	int i,j,x,y;
	for(i=0;i<4;i++){
		x=i,y=3;
		for(j=2;j>=0;j--){
			if(board[i][j]!=0){
				int flag=0;
				if(board[i][j+1]==0 || board[i][j+1]==board[i][j]){
					if(board[x][y]==board[i][j]){
						board[x][y]*=2;
						board[i][j]=0;
						score+=(((log2(board[x][y]))-1)*board[x][y]);
					}
					else{
						if(board[x][y]==0){
							board[x][y]=board[i][j];
							board[i][j]=0;
						}
						else{
							board[x][y-1]=board[i][j];
							board[i][j]=0;
							if(flag==0)
								y--;
						}
					}
				}
				else
					y-=1;

			}
		}
	}
	return score;
}

//make new random (2 or 4) tile
void maketile(int board[4][4]){
	int x,y;
	srand((unsigned) time(0));//random
	int loop=0;
	while(loop==0){
		x=rand()%4;
		y=rand()%4;
		if(board[x][y]==0){
			board[x][y]=pow(2,x%2 + 1);
			loop=1;
			break;
		}
	}
}

//routes to its action
int action(int board[4][4], string val,int score){
	if(val=="2" || val=="s")
		score=down(board,score);
	if(val=="4" || val=="a")
		score=left(board,score);
	if(val=="6" || val=="d")
		score=right(board,score);
	if(val=="8" || val=="w")
		score=up(board,score);
	return score;
}

//show board
int printboard(int board[4][4],int score){
	cout<<endl;
	int flag=0;
	int i,j;
	cout<<string(8,' ')<<"Score :"<<score<<endl;
	for(i=0;i<4;i++){
		cout<<string(29,'-')<<endl;
		cout<<"|      |      |      |      |"<<endl;
		for(j=0;j<4;j++){
			if(board[i][j]==0)
				cout<<"|      ";
			else{
				if(board[i][j]==2048){
					flag=1;}
				cout<<"|  "<<board[i][j]<<string(4-floor(log10(board[i][j]) + 1),' ');
			}
		}
		cout<<"|"<<endl<<"|      |      |      |      |"<<endl;
	}
	cout<<string(29,'-')<<endl<<endl;
	if(flag==1)
		return 1;
	return 0;
}

//generates initial board, with a 2 and a 4 randomly placed
void initboard(int board[4][4]){
	int a,b,c,d;
	int foo=0;
	srand((unsigned) time(0));
	a=rand()%4;
	b=rand()%4;
	int loop=0;
	while(loop==0){
		c=rand()%4;
		d=rand()%4;
		if(c!=a && d!=b){
			board[a][b]=2;
			board[c][d]=4;
			loop=1;
		}
	}
	foo=printboard(board,0);
}

//if check returns false, it'll make a new tile
bool check(int arr[4][4],int board[4][4]){
	int flag=1;
	int i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(arr[i][j]!=board[i][j])
				return false;
	return true;
}

//board when you lose
bool lost(int board[4][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if (board[i][j]==0){
				return false;
			}
		}
	}
	int newb[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			newb[i][j]=board[i][j];
	int sc=0;
	sc+=right(newb,sc);
	if(sc!=0){
		return false;
	}
	sc+=up(newb,sc);
	if(sc!=0){
		return false;
	}
	sc+=down(newb,sc);
	if(sc!=0){
		return false;
	}
	sc+=left(newb,sc);
	if(sc!=0){
		return false;
	}
	return true;
}

int main(){
	system("clear");
	cout<<"Welcome to 2048."<<endl;
	cout<<"Controls-"<<endl<<endl;
	cout<<"   w              8       "<<endl<<" a s d    or    4   6"<<endl<<"                  2";
	cout<<endl<<endl<<"You can quit anytime by pressing CTRL+C"<<endl;
	cout<<"Hit ENTER to play!"<<endl;
	if(cin.get()=='\n'){
		int board[4][4]={0};
		int arr[4][4]={0};
		int i,j;
		int score=0;
		int win=0;
		printf("\033[2J");
		printf("\033[%d;%dH", 0, 0);
		initboard(board);
		while(true){
	    	for(i=0;i<4;i++)
	    		for(j=0;j<4;j++)
	    			arr[i][j]=board[i][j];
			cout<<"Your move :";
			string val;
	    	cin>>val;
			printf("\033[2J");
			printf("\033[%d;%dH", 0, 0);
			score=action(board,val,score);
			if(check(arr,board)==false)
				maketile(board);

			win=printboard(board,score);

			if(lost(board)==true){
				cout<<endl<<"GAME OVER!!"<<endl;
				cout<<"Your score is "<<score<<". Well played."<<endl;
				break;
			}
			if(win==1){
				cout<<"YOU WIN!!"<<endl;
				cout<<"You score is "<<score<<"! Noice!"<<endl;
				break;

			}
		}
	}
	return 0;
}
