// Tic-Tac-Toe Group Project
// By: Steven Nguyen, Mohammad Ali Khan, and Thu Vu
// A tic-tac-toe C program that allows a tic-tac-toe game to be played between two people.

#include <stdio.h>


char checkWinner(const char a);  //function declarations
void initialise_Board();
int playerMoves(const char move);
void printBoard();

char board[3][3]; // Creating a 2D array that accepts characters only

// Initializing global variables
const char PLAYER1 = 'X';  //Player 1 moves are X, const char for non-changing char
const char PLAYER2 = 'O';  //Player 2 moves are O, const char for non-changing char


int main(void) { // Main program execution
  // Initializing local variables
  char move; // move = the player character of X or O
  char start; // start = Y or N on starting the game, character variable
  int valid_move; // A move that a player can do, integer variable because of 0 or 1
  int moves_Count = 0;    //counts the moves in the game, up to 9
  int game_Progress = 0;  //Game in progress if 1, else 0 (FLAG)

  printf("\nWould you like to play Tic-Tac-Toe? (Y/N): \n"); // Asking user if they would like to play
  scanf("%c", &start); // Scans character into start

  if (start == 'Y'){ //start the game by initialising the board and game_Progress as True(1)
    game_Progress = 1;   //Game is started
    initialise_Board(); // Creates a board with empty spaces
  }

  while (game_Progress  == 1){

    if (moves_Count == 9){  //if completed all moves (and no winner since still in loop)
      printf("\n------ IT'S A DRAW!!------\n");
      game_Progress = 0;     //game progress as 0 and end the game with continue.
      continue;
    }

    if (moves_Count % 2 == 0){   //if move count is even then its Player 1's turn because player 1 starts at moves_Count = 0
      printf("Player One move: \n");
      valid_move = playerMoves(PLAYER1); // Calling playerMoves to check if the move is valid or not for X
      if (valid_move == 0){     //if not valid move, run the loop again without counting the move in moves_Count
        continue;
      }
      if(checkWinner(PLAYER1) == PLAYER1){  //check if player 2 won after their move
        printf("\n------Congratulations!! Player 1 WON!------\n");
        game_Progress  = 0; // game_Progress = 0, means end the game
      }
    }
    else{                       //else if move count is odd then its Player 2's turn because player 2 starts at moves_Count = 1
      printf("Player Two move: \n");
      valid_move = playerMoves(PLAYER2); // Calling playerMoves to check if the move is valid or not for O
      if (valid_move == 0){ //if not valid move, run the loop again without counting the move in moves_Count
        continue;
      }
      if(checkWinner(PLAYER2) == PLAYER2){  //check if player 2 won after their move
        printf("\n------Congratulations!! Player 2 WON!------\n\n");
        game_Progress  = 0; // game_Progress = 0, means end the game
        }
    }

    printBoard();   //print board after every turn
    moves_Count++;  //increase move count by 1 after each player's valid move!
  }

}


void initialise_Board()   //function to initialise board
{
   for(int i = 0; i < 3; i++)  //for each row
   {
      for(int j = 0; j < 3; j++)    //for each column
      {
         board[i][j] = ' ';   //initialise all positions to empty/space
      }
   }
}

int playerMoves(const char move)  //A player's move, move will be PLAYER1('X') or PLAYER2('O')
{
    // Initialize local variables as integers
    // x is row number, y is column number
    int x,y;

    printf("Enter row #(1-3): "); // Asking user (player) to enter row number between 1-3
    scanf("%d", &x); // Scan for row number
    x -= 1; // Have to decrease by one as the arrays starts with 0 and ends with 2

    printf("Enter column #(1-3): "); // Asking user (player) to enter column number between 1-3
    scanf("%d", &y); // Scan for column number
    y -= 1; // Have to decrease by one as the arrays starts with 0 and ends with 2

    if(board[x][y] != ' '){   //if that spot is not empty
        printf("Invalid move!\n"); // Telling user space is not empty therefor invalid move
        return 0; // Flags the move as invalid
    }

    else {
        board[x][y] = move; // Setting the array row x and column y as the player move character
  }

  return 1; // Return true
}

// Function to print board visually
void printBoard()
{
   // c is where the X or O will go
   // Newlines and dashes to give the board lines
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}


char checkWinner(const char a)    //check if PLAYER1 or PLAYER2 won
{
   //a will be PLAYER1('X') or PLAYER2('O'), const char value will not change, initialized locally

   //check rows for a win
   for(int i = 0; i < 3; i++)
   {  // if the row equals an X or O three times, they win
      if(board[i][0] == a && board[i][1] == a && board[i][2] == a)
      {
        return a; // Returns X or O, since these variables are tied to PLAYER1 (X) or PLAYER2 (O), the program automatically knows who won
      }
   }
   //check columns for a win
   for(int i = 0; i < 3; i++)
   {  // if the columns equals an X or O three times, they win
      if(board[0][i] == a && board[1][i] == a && board[2][i] == a)
      {
        return a; // Returns X or O, since these variables are tied to PLAYER1 (X) or PLAYER2 (O), the program automatically knows who won
      }
   }
   //check the two diagonals for a win
   // X or O three times in a diagonal, they win
   if(board[0][0] == a && board[1][1] == a && board[2][2] == a)
   {
      return a; // Returns X or O, since these variables are tied to PLAYER1 (X) or PLAYER2 (O), the program automatically knows who won
   }

   if(board[0][2] == a && board[1][1] == a && board[2][0] == a)
   {
      return a; // Returns X or O, since these variables are tied to PLAYER1 (X) or PLAYER2 (O), the program automatically knows who won
   }

  return 'Z';  //if Z returned, it means no win yet, since Z is not defined - it is just a character, means nothing is returned
}








