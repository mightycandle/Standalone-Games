#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
using namespace std;

//coordinates within 8x8 are valid
bool valid(int x, int y){
    return (x >= 0) && (x < 8) && (y >= 0) && (y < 8);
}
void printhash(){
    cout<<"\033[1;35m"<<'#'<<"\033[0m"<<" ";
}
void printx(){
    cout<<"\033[1;31m"<<'x'<<"\033[0m"<<" ";
}
//shows board
void printboard(char board[][8]){
    system("clear");
    cout<< ("Current board ")<<endl<<endl;
    int i, j;
    cout<<"   ";
    for (i=0; i<8; i++)
        cout<<i<<" ";
    cout<<endl;
    cout<<"  ----------------"<<endl;
    for (i=0; i<8; i++){
        cout<<i<<"| ";
        for (j=0; j<8; j++){
            if(board[i][j]!='0' && board[i][j]!='x' && board[i][j]!='X' )
                cout<< board[i][j]<<" ";
            if(board[i][j]=='0'){
                printhash();
            }
            if(board[i][j]=='x'){
                printx();
            }
            if(board[i][j]=='X'){
                cout<<"\033[1;31m"<<'X'<<"\033[0m"<<" ";
            }
        }
        cout<<endl;
    }
}

void winboard(char board[][8]){

    cout<< ("Current board ")<<endl<<endl;
    int i, j;
    cout<<"   ";
    for (i=0; i<8; i++)
        cout<<i<<" ";
    cout<<endl;
    cout<<"  ----------------"<<endl;
    for (i=0; i<8; i++){
        cout<<i<<"| ";
        for (j=0; j<8; j++)
            if(board[i][j]!='-'){
		        if(board[i][j]=='0'){
                    printhash();
		        }
		        else{
                    cout<< board[i][j]<<" ";
		        }
	        }
        else{
                printx();
	    }
        cout<<endl;
    }
}

//generating 10 random coordinates for mines
void placemines(int mines[][2], char answer[][8]){
    bool temp[8*8];
    memset (temp, false, sizeof(temp));
    srand((unsigned) time(0));  //for it to be 'random'
    for (int i=0; i<10; )
     {
        int random = rand() % (8*8);
        int x = random / 8;
        int y = random % 8;
        //ensuring no duplicates
        if (temp[random] == false)
        {
            mines[i][0]= x;
            mines[i][1] = y;
            answer[mines[i][0]][mines[i][1]] = 'x';
            temp[random] = true;
            i++;
        }
    }
}

//creates empty board
void declare(char answer[][8], char board[][8]){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            board[i][j] ='-';
            answer[i][j] = '-';
        }
    }
}

//returns no. of neighbouring mines of (x,y)
int adjcount(int x, int y, int mines[][2],char answer[][8]){
    int i;
    int c = 0;
    //if neighbouring cell exists within the board, check for mine
        if (valid (x-1, y) == true){
            if(answer[x-1][y]=='x')
                c+=1;
        }
        if (valid (x+1, y) == true){
            if (answer[x+1][y]=='x')
                c+=1;
        }
        if (valid (x, y+1) == true){
            if (answer[x][y+1]=='x')
                c+=1;
        }
        if (valid (x, y-1) == true){
            if (answer[x][y-1]=='x')
                c+=1;
        }
        if (valid (x-1, y+1) == true){
            if (answer[x-1][y+1]=='x')
                c+=1;
        }
        if (valid (x-1, y-1) == true){
            if (answer[x-1][y-1]=='x')
                c+=1;
        }
        if (valid (x+1, y+1) == true){
            if(answer[x+1][y+1]=='x')
                c+=1;
        }
        if (valid (x+1, y-1) == true){
            if (answer[x+1][y-1]=='x')
                c+=1;
        }
    return c;
}

//implements input action
int action(char board[][8], char answer[][8],int mines[][2], int x, int y, int *rem){
    if (board[x][y] != '-')
        return 0;
    int i, j;
    if(answer[x][y]!='x'){
        int count = adjcount(x, y, mines, answer);
        (*rem)--;   //reduces remaining available tiles by 1.
        board[x][y] = count + '0';
        if (count==0){
            //recursive loops if the cell has no neighbouring mines
            if (valid (x-1, y) == true){
                if (answer[x-1][y]!='x')
                    action(board, answer, mines, x-1, y, rem);
            }
            if (valid (x+1, y) == true){
                if (answer[x+1][y]!='x')
                    action(board, answer, mines, x+1, y, rem);
            }
            if (valid (x, y+1) == true){
                if (answer[x][y+1]!='x')
                    action(board, answer, mines, x, y+1, rem);
            }
            if (valid (x, y-1) == true){
                if (answer[x][y-1]!='x')
                    action(board, answer, mines, x, y-1, rem);
            }

            if (valid (x-1, y+1) == true){
                if (answer[x-1][y+1]!='x')
                    action(board, answer, mines, x-1, y+1, rem);
            }

            if (valid (x-1, y-1) == true){
                if (answer[x-1][y-1]!='x')
                    action(board, answer, mines, x-1, y-1, rem);
            }

            if (valid (x+1, y+1) == true){
                if (answer[x+1][y+1]!='x')
                    action(board, answer, mines, x+1, y+1, rem);
            }

            if (valid (x+1, y-1) == true){
                if (answer[x+1][y-1]!='x')
                    action(board, answer, mines, x+1, y-1, rem);
            }
        }
        //printboard (board);
        return 0;
    }
    return 0;
}

//main()
int main(){
    system("clear");
    cout<<endl<<"Welcome to Minesweeper"<<endl;
    cout<<"The board contains 64 tiles, and 10 mines."<<endl;
    cout<<"Opening a tile which is not a mine reveals number of neighbouring mines."<<endl;
    cout<<"- : tile not visited"<<endl<<"# : explored tile with no neighbouring mines"<<endl;
    cout<<"x : mine"<<endl<<"Input: x y <--> row column"<<endl;
    cout<<"Press ENTER to start"<<endl;
    if(cin.get()=='\n'){
        int loopflag = 0;
        char answer[8][8], board[8][8];
        int rem = 54;
        int x,y;
        int mines[10][2];/*
        printf("\033[2J");
		printf("\033[%d;%dH", 0, 0);
        */
        declare (answer, board);
        placemines (mines, answer);
        int moves = 0;
        /*
        to view the solution board:
        printboard(answer);
        */
        time_t start,end;
        time(&start);
        ios_base::sync_with_stdio(false);
        while (loopflag == 0){
            printboard (board);
            cout<<endl;
            cout<<"Your move : "<<endl;
            int x,y;
            cin>>x>>y;
            cout<<endl;
            moves+=1;

            if (answer[x][y] == 'x'){
                int i;
                for (i=0; i<10; i++)
                    board[mines[i][0]][mines[i][1]]='x';
                board[x][y]='X';
                printboard (board);
                cout<< endl<<"You lost!"<<endl;
                loopflag=1;
                break;
            }
            else{
                loopflag = action (board, answer, mines, x, y, &rem);
            }
                //you win when tiles left is zero
                if ((loopflag == 0) && (rem == 0)){
                     time(&end);
                     double timetaken=double(end-start);
                     winboard(board);
                     cout<<endl<<"You won!"<<endl;
                     cout<<"You made "<<moves<<" moves."<<endl;
                     int t=(int)timetaken;
                     if(t<60){
                         cout<<"Time taken: "<<t<<" seconds. Noice!"<<endl;
                     }
                     else{
                         cout<<"Time taken: "<<t/60<<"min "<<t-60*(t/60)<<"sec. Noice!"<<endl;
                     }
                     loopflag = 1;
                }
            }
         }


    return 0;
}
