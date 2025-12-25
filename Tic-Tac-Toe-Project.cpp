#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

vector<vector<char>> board(3,vector<char>(3,'-'));
vector<bool> placed(9,false);


void show_board(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"|";
            cout<<board[i][j];
        }
        cout<<"|";
        cout<<endl;
        cout<<"-------";
        cout<<endl;
    }
}

int filled_placed(){
    for(int i=0;i<9;i++){
        if(placed[i] == false) return 0;
    }
    return 100;
}

int check_win(){

    int filled = filled_placed();
    if(filled == 100) return 100;
    // Checking 3 Rows
    for(int i=0;i<3;i++){
        if(board[i][0] != '-' and (board[i][0] == board[i][1] and board[i][1] == board[i][2])){
            if(board[i][0] == 'X') return 1;
            else return 0;
        }
    }

    // Checking 3 Columns
    for(int i=0;i<3;i++){
        if(board[i][0] != '-' and (board[0][i] == board[1][i] and board[1][i] == board[2][i])){
            if(board[0][i] == 'X') return 1;
            else return 0;
        }
    }

    // Checking 2 Diagonals
    if(board[1][1] != '-' and (board[0][0] == board[1][1] and board[1][1] == board[2][2])){
        if(board[1][1] == 'X') return 1;
            else return 0;
    }
    if(board[1][1] != '-' and (board[0][2] == board[1][1] and board[1][1] == board[3][0])){
        if(board[1][1] == 'X') return 1;
            else return 0;
    }
    
    return -1;
}

void place_position(int index,int who){
    int row = index/3;
    int col = index%3;
    
    // who->1 -> Player
    // who->0 -> Computer
    if(who){
        board[row][col] = 'X';
    }
    else{
        board[row][col] = 'O';
    }
    placed[index] = true;
}


void player(){
    
    int player_position;
    do{
        cout<<"Enter the Number you want to place X\n";
        cin>>player_position;
    }while(player_position < 1 or player_position > 9);

    player_position--;
    place_position(player_position,1);
}

void computer(){
    int random_number;
    do{
        random_number = rand()%9;
    }while(placed[random_number] == true);
    cout<<"\nComputer choose "<<(random_number+1)<<endl;
    place_position(random_number,0);
}

void results(int x){
    if(x == 1) cout<<"Bingo! You Won\n";
    else if(x == 0)  cout<<"Oops you Loose!\n";
    else cout<<"It's a Tie";
}


void game(){
    cout<<"TIC-TAC-TOE\n";
    show_board();
    int checking;
    while(1){
        player();
        show_board();
        checking = check_win();
        if(checking != -1){
            results(checking);
            break;
        }
        computer();
        show_board();
        checking = check_win();
        if(checking != -1){
            results(checking);
            break;
        }

    }
    cout<<"Thank You for Playing\n";
    cout<<"Do you want to play again? Type y or n\n";
    char x;
    cin>>x;
    if(x == 'y') game();
    else return;

}




int main(){
    game();
}