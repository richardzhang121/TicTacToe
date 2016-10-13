//ZhangRichard TicTacToe
#include <iostream>
#include <cstring>
//act as imports like java
using namespace std;


//intiates methods
/* printboard prints board
 * resetboard resets board for wins
 * win checks for wins
 * tie checks for ties
 */
void printBoard(char (*board)[3]);
void resetBoard(char (*board)[3], char &turn);
bool win(char (*board)[3], char player);
bool tie(char (*board)[3]);

void printBoard(char (*board)[3]){
  cout << " \tA\tB\tC" << endl; //prints board with abc and 123
  cout << "1\t" << board[0][0] << "\t" << board[1][0] << "\t" << board[2][0] << endl;
  cout << "2\t" << board[0][1] << "\t" << board[1][1] << "\t" << board[2][1] << endl;
  cout << "3\t" << board[0][2] << "\t" << board[1][2] << "\t" << board[2][2] << endl;
}

int main(){
  int x_wins = 0;
  int o_wins = 0;
  char turn = 'O'; //initial set up
  char board[3][3];
  char input[6];
  bool playing = true;
  while (playing == true){
    //still playing game
    resetBoard(board, turn);
    printBoard(board);
    while(!(win(board,turn) || tie(board))){
      //switching turns between X and O
      if (turn == 'X'){
	turn = 'O';
      }
      else{
	turn = 'X';
      }
      bool moved = false;
      while (moved == false){
	cin >> input;//checks if input is correct
	if (strlen(input) != 2){
	  cout << "Enter a letter then a number" << endl;
	}  
	else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
	  cout << "The first symbol needs to be a letter" << endl;
	}
	else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){
	  cout << "The second symbol needs to be a number" << endl;
	}
	else if (board[input[0]-'a'][input[1]-'1'] == ' '){
	  board[input[0]-'a'][input[1]-'1'] = turn;
	  moved = true;
	  printBoard(board);
	}
	else{
	  cout << "That space is taken" << endl;	  
	}
      }
    }
    if (tie(board)){ //say who won
      cout << "Tie game" << endl;
    }
    else{
      cout << turn << " Wins!" << endl;
      if (turn == 'X'){
	x_wins ++;
      }
      else{
	o_wins ++;
      }
    }
    cout << "X has won " << x_wins << " times" << endl;
    cout << "O has won " << o_wins << " times" << endl;
    cout << "Do you want to play again? (y/n)" << endl;
    cin >> input;
    if(strcmp(input,"y")){ //see if player wants to play again
      playing = false;
    }
  }
}

bool win(char (*board)[3], char player){ //checks for wins
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }
  for (int count = 0; count < 3; count++) {
    if (board[0][count] == player && board[1][count] == player && board[2][count] == player){
      return true;
    }
  }
  for (int count = 0; count < 3; count++) {
    if (board[count][0] == player && board[count][1] == player && board[count][2] == player){
      return true;
    }
  }
  return false;
}

void resetBoard(char (*board)[3], char &turn){ //clears the board after playing
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
  turn = 'O';
}

//checks for ties; if board has unplaced spots, then no tie
bool tie(char (*board)[3]){
  bool tie = true; 
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (board[i][j] == ' ')
	tie = false;
    }
  }
  return tie;
}
