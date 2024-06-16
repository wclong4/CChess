
#include "board.h"

/**
 * This is the main component and it makes sure that the code can actually be run.
 * @param argc the number of args
 * @param argv the string array of arguments
*/
int main(int argc, char *argv[]) {
  Piece ** board = initBoard();
  Piece ** emptyBoard = initEmptyBoard();
  char * string1 = toStringBoard(emptyBoard);
  char * string2 = toStringBoard(board);

  //printBoard(board);
  //printf("%s", string1);
  //printf("%s", string2);

  debugPrintBoard(emptyBoard);
  debugPrintBoard(board);

  freeBoard(board);
  freeBoard(emptyBoard);

  free(string1);
  free(string2);

} 