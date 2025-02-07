
#include "rules.h"
/**
 * This parses input from the user
 * @param string the string to parse for an x coordinate
 */
int parseXCoordinate(char * string) {
  int i = 0;
  while (string[i] != '\0') {
    if ('a' <= string[i] && string[i] <= 'h') {
      return (string[i] - 'a');
    }
    i++;
  }
  // we failed somehow
  return -1;
}
/**
 * This parses input from the user
 * @param string the string to parse for an y coordinate
 */
int parseYCoordinate(char * string) {
  int i = 0;
  while (string[i] != '\0') {
    if ('1' <= string[i] && string[i] <= '8') {
      return BOARD_SIZE - (string[i] - '0');
    }
    i++;
  }
  // we failed somehow
  return -1;
}
/**
 * This performs the actions necessary for white's turn
 * @param board the board to perform the actions on
 */
void whiteTurn(Piece ** board) {
  while(true) { // only break when a valid move is entered
    // string initial x
    char strix[99];
    char striy[99]; 
    // string final x
    char strfx[99];
    char strfy[99]; 
    printf("%s\n", "input an initial x coordinate (a-h)");
    scanf("%98s", strix);

    printf("%s\n", "input an initial y coordinate (1-8)");
    scanf("%98s", striy);
    // turn the character into a coordinate
    int ix = parseXCoordinate(strix);
    // make y indexed by 0
    int iy = parseYCoordinate(striy);
    printf("%s\n", "input a final x coordinate (a-h)");
    scanf("%98s", strfx);
    printf("%s\n", "input a final y coordinate (1-8)");
    scanf("%98s", strfy);
    // turn the character into a coordinate
    int fx = parseXCoordinate(strfx);
    // make y indexed by 0
    int fy = parseYCoordinate(strfy);
    // now we have our initial and final coordinates, so we check that the move is valid then carry it out
    bool white = board[iy][ix].dark == 0;
    bool valid = validMove(ix, iy, fx, fy, board);
    if (white && valid) { // also check that the piece moved is white
      movePiece(ix, iy, fx, fy, board);
      updateDanger(board);
      break;
    } else {
      printf("%s\n", "Invalid move");
    }
  }
}
/**
 * This performs the actions necessary for black's turn
 * @param board the board to perform the actions on
 */
void blackTurn(Piece ** board) {
  while(true) { // only break when a valid move is entered
    // string initial x
    char strix[99];
    char striy[99]; 
    // string final x
    char strfx[99];
    char strfy[99]; 
    printf("%s\n", "input an initial x coordinate (a-h)");
    scanf("%98s", strix);

    printf("%s\n", "input an initial y coordinate (1-8)");
    scanf("%98s", striy);
    // turn the character into a coordinate
    int ix = parseXCoordinate(strix);
    // make y indexed by 0
    int iy = parseYCoordinate(striy);
    printf("%s\n", "input a final x coordinate (a-h)");
    scanf("%98s", strfx);
    printf("%s\n", "input a final y coordinate (1-8)");
    scanf("%98s", strfy);
    // turn the character into a coordinate
    int fx = parseXCoordinate(strfx);
    // make y indexed by 0
    int fy = parseYCoordinate(strfy);
    // now we have our initial and final coordinates, so we check that the move is valid then carry it out
    bool black = board[iy][ix].dark == 1;
    bool valid = validMove(ix, iy, fx, fy, board);
    if (black && valid) { // also check that the piece moved is white
      movePiece(ix, iy, fx, fy, board);
      updateDanger(board);
      break;
    } else {
      printf("%s\n", "Invalid move");
    }
  }
}
/**
 * This method checks for checkmate and stalemate
 * @param board the board to check
 * @return true if the game is over, false if it continues
 */
bool checkmateAndStalemateCheck(Piece ** board) {
  // check for checkmate and stalemate
  if (noMoveCheckBlack(board)) {
    if (blackCheckCheck(board)) {
      printf("%s\n", "Checkmate, white wins!");
      return true;
    } else {
      printf("%s\n", "Stalemate");
      return true;
    }
  }
  if (noMoveCheckWhite(board)) {
    if (whiteCheckCheck(board)) {
      printf("%s\n", "Checkmate, black wins!");
      return true;
    } else {
      printf("%s\n", "Stalemate");
      return true;
    }
  }
  return false;
}
/**
 * This is the main component and it makes sure that the code can actually be run.
 * @param argc the number of args
 * @param argv the string array of arguments
*/
int main(int argc, char *argv[]) {
  Piece ** board = initBoard();
  printf("%s\n", "This is a chess program where you control both sides");
  printf("%s\n", "Otherwise, you play by inputting initial and final coordinates for a piece");
  printf("%s\n", "to move a piece.");
  while(true) {
    if (checkmateAndStalemateCheck(board)) {
      break;
    }
    printf("%s\n", "White's turn");
    printBoard(board);
    //debugPrintBoard(board);
    // white's turn
    whiteTurn(board);
    if (checkmateAndStalemateCheck(board)) {
      break;
    }
    printf("%s\n", "Black's turn");
    printBoardBlack(board);
    blackTurn(board);
  }
  printf("Game over, goodbye");
}