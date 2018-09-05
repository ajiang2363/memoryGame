
/** 23.75/25 points
    IPO chart not included as comments in the file.
    Rather than displaying a 0 when numbers are matched, leave the matched numbers
    visible. Otherwise, good.
**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int setup(int playBoard[4][4]);
int randGen();
bool playGame(int playBoard[4][4]);

using namespace std;

int main()
{
    int playBoard[4][4];

    cout<<"Welcome to memory game, AJ"<<endl;
    cout<<"Cards that say 'AJ' are unflipped."<<endl;
    cout<<"Cards that match will then be printed as a '0'"<<endl;
    cout<<"A total of 16 cards will be present for 8 matches"<<endl;
    cout<<"Good luck and enjoy the game"<<endl<<endl;

    const int insertIn=100;
    for (int i=0;i<4;i++){
        for (int j=0;j<0;j++){
            playBoard[i][j]=0;
        }
    }
    int board= setup(playBoard);
    bool finished= true;

    int matched=0;
    while (finished){
        bool test;
        test= playGame(playBoard);
        if(test){
            matched+=1;
        }
        if (matched==8){
            finished=false;
            cout<<"Congrats! You finished!"<<endl;
        }
    }

    return 0;
}

int setup(int playBoard[4][4]){
    int random,numInserted,random1;
    int row=0; int column=0;
    int board[4][4];
    srand(time(NULL));
    numInserted=0;
    while (numInserted!=16){
        random=randGen();
        bool test=true;
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                if(random==board[i][j]){
                    test=false;
                    }
                }
            }
        if (test){
            board[row][column]=random;
            if (random>8){
                random1=random-8;
            }
            else{
                random1=random;
            }
            playBoard[row][column]=random1;
            //cout<<"Inserted     "<<random1<<"   at"<<"     "<<row<<" "<<column<<endl;
            //cout<<board[row][column]<<endl;
            numInserted+=1;
            if (row<3){
                row++;
            }
            else if (column<4){
                column++;
                row=0;
            }
    }
}
return 0;
}


int randGen(){
    int random=1+(rand()%16);
    return random;
}

bool playGame(int playBoard[4][4]){
    int row1, column1, row2, column2;

    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (playBoard[i][j]==0){
                cout<<"0"<<"     ";
            }
            else{
                cout<<"AJ"<<"    ";
        }

    }
    cout<<endl;
    }

    cout<<"Please enter the row, press enter, and then enter the row of the 1st card"<<endl;
    cin>>row1; cin>>column1;
    cout<<endl;
    row1-=1;column1-=1;

 //   showBoard[row1][column1]=playBoard[row2][column2];
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (i==row1 && j==column1){
                cout<<playBoard[i][j]<<"     ";
            }
            else if (playBoard[i][j]==0){
                cout<<"0"<<"     ";
            }
            else{
            cout<<"AJ"<<"    ";
            }
        }
        cout<<endl;
    }

    cout<<"Please enter the row, press enter, and then enter the row of the 2nd card"<<endl;
    cin>>row2; cin>>column2;
    cout<<endl;
    row2-=1;column2-=1;

//    showBoard[row2][column2]=playBoard[row2][column2];
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (i==row1 && j==column1){
                cout<<playBoard[i][j]<<"     ";
            }
            else if (i==row2 && j==column2){
                cout<<playBoard[i][j]<<"     ";
            }
            else if (playBoard[i][j]==0){
                cout<<"0"<<"     ";
            }
            else{cout<<"AJ"<<"    ";
            }
        }
        cout<<endl;
    }

    if (playBoard[row1][column1]==playBoard[row2][column2]){
        cout<<"That's a match!"<<endl<<endl;
        playBoard[row1][column1]=0;
        playBoard[row2][column2]=0;
        return true;
    }
    else{
        cout<<"Try again"<<endl<<endl;
        return false;
    }

}












