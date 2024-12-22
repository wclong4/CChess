#include "piece.h"
/** The size of the board */
#define BOARD_SIZE 8
// got values from here https://arxiv.org/pdf/2009.04374
#define PAWN_VAL 3.05
#define KNIGHT_VAL 3.05
#define BISHOP_VAL 3.33
#define ROOK_VAL 5.63
#define QUEEN_VAL 9.5

/**
 * This initilized a new board with all pieces in their normal position
 * 
 * You are white, your opponent is black.
 * 
 * TODO: being able to choose what color you are
*/
Piece ** initBoard();
/**
 * This prints out the board
*/
void printBoard(Piece ** board);
/**
 * Destroys the board
 * 
 * I referenced this because the way I initialized this was based
 * on this. https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c
 */
void freeBoard(Piece ** board);
/**
 * This creates a string version of the board
*/
char * toStringBoard(Piece ** board);
/**
 * This initilized a new board with no pieces
 * 
 *
 * code from stack overflow, https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c
*/
Piece ** initEmptyBoard();
/**
 * This uses array coordinates as coordinates instead of 1-8 and a-h
*/
void debugPrintBoard(Piece ** board);
/**
 * This uses array coordinates as coordinates instead of 1-8 and a-h
 * and prints white danger states
*/
void whiteDangerPrintBoard(Piece ** board);
/**
 * This uses array coordinates as coordinates instead of 1-8 and a-h
 * and prints black danger states
*/
void blackDangerPrintBoard(Piece ** board);
/**
 * This uses array coordinates as coordinates instead of 1-8 and a-h
 * and gives a char * that shows white danger states
*/
char * whiteDangerToString(Piece ** board);
/**
 * This uses array coordinates as coordinates instead of 1-8 and a-h
 * and gives a char * that shows black danger states
*/
char * blackDangerToString(Piece ** board);
/**
 * duplicates board state
 * @param src the source
 * @param the destination
 */
void boardCopy(Piece ** dest, Piece ** src);
/**
 * Will move a piece, DOES NOT CHECK FOR MOVE VALIDITY!!!
 * Use carefully.
 * @param initx the initial x value
 * @param inity the initial y value
 * @param board the board
 * 
 */
void movePiece(int initx, int inity, int finalx, int finaly, Piece ** board);
/**
 * This prints out the board, from the perspective of black
*/
void printBoardBlack(Piece ** board);