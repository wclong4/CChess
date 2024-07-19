/**
 * A test for danger.c
 * @author Warren Long (wclong4)
 */
#include <assert.h>
#include "danger.h"

/**
 * A test for black king danger
 */
void blackKingTest() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * king33 = makePiece(1, KING);
  board[3][3] = * king33;
  dangerCast(3, 3, board);
  char * actual1 = whiteDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 0  0  1  0  1  0  0  0  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 0  0  0  0  0  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);

  Piece * king70 = makePiece(1, KING);
  board[7][0] = * king70;
  dangerCast(0, 7, board);

  Piece * king07 = makePiece(1, KING);
  board[0][7] = * king07;
  dangerCast(7, 0, board);

  Piece * king00 = makePiece(1, KING);
  board[0][0] = * king00;
  dangerCast(0, 0, board);

  Piece * king77 = makePiece(1, KING);
  board[7][7] = * king77;
  dangerCast(7, 7, board);
  char * actual2 = whiteDangerToString(board);

  //printf("%s", actual2);
  char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  1  0  0  0  0  1  0  7 \n"
"6 1  1  0  0  0  0  1  1  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 0  0  1  0  1  0  0  0  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 1  1  0  0  0  0  1  1  1 \n"
"0 0  1  0  0  0  0  1  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);

  free(actual1);
  free(actual2);
  free(king33);
  free(king70);
  free(king07);
  free(king00);
  free(king77);

  freeBoard(board);
}
/**
 * A test for white king danger
 */
void whiteKingTest() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * king33 = makePiece(0, KING);
  board[3][3] = * king33;
  dangerCast(3, 3, board);
  char * actual1 = blackDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 0  0  1  0  1  0  0  0  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 0  0  0  0  0  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);

  Piece * king70 = makePiece(0, KING);
  board[7][0] = * king70;
  dangerCast(0, 7, board);

  Piece * king07 = makePiece(0, KING);
  board[0][7] = * king07;
  dangerCast(7, 0, board);

  Piece * king00 = makePiece(0, KING);
  board[0][0] = * king00;
  dangerCast(0, 0, board);

  Piece * king77 = makePiece(0, KING);
  board[7][7] = * king77;
  dangerCast(7, 7, board);
  char * actual2 = blackDangerToString(board);

  //printf("%s", actual2);
  char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  1  0  0  0  0  1  0  7 \n"
"6 1  1  0  0  0  0  1  1  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 0  0  1  0  1  0  0  0  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 1  1  0  0  0  0  1  1  1 \n"
"0 0  1  0  0  0  0  1  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);

  free(actual1);
  free(actual2);
  free(king33);
  free(king70);
  free(king07);
  free(king00);
  free(king77);

  freeBoard(board);
}
/**
 * test for black rook danger
 */
void blackRookTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * rook33 = makePiece(1, ROOK);
  board[3][3] = * rook33;
  dangerCast(3, 3, board);
  char * actual1 = whiteDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  1  0  0  0  0  7 \n"
"6 0  0  0  1  0  0  0  0  6 \n"
"5 0  0  0  1  0  0  0  0  5 \n"
"4 0  0  0  1  0  0  0  0  4 \n"
"3 1  1  1  0  1  1  1  1  3 \n"
"2 0  0  0  1  0  0  0  0  2 \n"
"1 0  0  0  1  0  0  0  0  1 \n"
"0 0  0  0  1  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  Piece * pawn53 = makePiece(1, PAWN);
  board[5][3] = * pawn53;

  Piece * pawn32 = makePiece(1, PAWN);
  board[3][2] = * pawn32;

  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;

  Piece * pawn36 = makePiece(1, PAWN);
  board[3][6] = * pawn36;

  //debugPrintBoard(board);
  // clear the previous danger states so we can test new ones
  clearDanger(board);
  dangerCast(3, 3, board);
  char * actual2 = whiteDangerToString(board);
    char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  1  0  0  0  0  5 \n"
"4 0  0  0  1  0  0  0  0  4 \n"
"3 0  0  1  0  1  1  1  0  3 \n"
"2 0  0  0  1  0  0  0  0  2 \n"
"1 0  0  0  1  0  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);
  free(rook33);
  free(pawn53);
  free(pawn32);
  free(pawn13);
  free(pawn36);
  free(actual1);
  free(actual2);
  freeBoard(board);
}
/**
 * test for white rook danger
 */
void whiteRookTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * rook33 = makePiece(0, ROOK);
  board[3][3] = * rook33;
  dangerCast(3, 3, board);
  char * actual1 = blackDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  1  0  0  0  0  7 \n"
"6 0  0  0  1  0  0  0  0  6 \n"
"5 0  0  0  1  0  0  0  0  5 \n"
"4 0  0  0  1  0  0  0  0  4 \n"
"3 1  1  1  0  1  1  1  1  3 \n"
"2 0  0  0  1  0  0  0  0  2 \n"
"1 0  0  0  1  0  0  0  0  1 \n"
"0 0  0  0  1  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  Piece * pawn53 = makePiece(1, PAWN);
  board[5][3] = * pawn53;

  Piece * pawn32 = makePiece(1, PAWN);
  board[3][2] = * pawn32;

  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;

  Piece * pawn36 = makePiece(1, PAWN);
  board[3][6] = * pawn36;

  debugPrintBoard(board);
  // clear the previous danger states so we can test new ones
  clearDanger(board);
  dangerCast(3, 3, board);
  char * actual2 = blackDangerToString(board);
    char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  1  0  0  0  0  5 \n"
"4 0  0  0  1  0  0  0  0  4 \n"
"3 0  0  1  0  1  1  1  0  3 \n"
"2 0  0  0  1  0  0  0  0  2 \n"
"1 0  0  0  1  0  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);
  free(rook33);
  free(pawn53);
  free(pawn32);
  free(pawn13);
  free(pawn36);
  free(actual1);
  free(actual2);
  freeBoard(board);
}
void blackPawnTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * pawn33 = makePiece(1, PAWN);
  board[3][3] = * pawn33;
  dangerCast(3, 3, board);
  char * actual1 = whiteDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  1  0  1  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  0  0  0  0  0  0  2 \n"
"1 0  0  0  0  0  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  free(pawn33);
  free(actual1);
  freeBoard(board);
}
void whitePawnTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * pawn33 = makePiece(0, PAWN);
  board[3][3] = * pawn33;
  dangerCast(3, 3, board);
  char * actual1 =  blackDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  0  0  0  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  1  0  1  0  0  0  2 \n"
"1 0  0  0  0  0  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  free(pawn33);
  free(actual1);
  freeBoard(board);
}
/**
 * test for black knight
 */
void blackKnightTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * knight33 = makePiece(1, KNIGHT);
  board[3][3] = * knight33;
  dangerCast(3, 3, board);
  char * actual1 =  whiteDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  1  0  1  0  0  0  5 \n"
"4 0  1  0  0  0  1  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  1  0  0  0  1  0  0  2 \n"
"1 0  0  1  0  1  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  free(knight33);
  free(actual1);
  freeBoard(board);
}
void whiteKnightTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * knight33 = makePiece(0, KNIGHT);
  board[3][3] = * knight33;
  dangerCast(3, 3, board);
  char * actual1 =  blackDangerToString(board);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  1  0  1  0  0  0  5 \n"
"4 0  1  0  0  0  1  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  1  0  0  0  1  0  0  2 \n"
"1 0  0  1  0  1  0  0  0  1 \n"
"0 0  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  free(knight33);
  free(actual1);
  freeBoard(board);
}
/**
 * test for white bishop
 */
void whiteBishopTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * bishop33 = makePiece(0, BISHOP);
  board[3][3] = * bishop33;
  dangerCast(3, 3, board);

  char * actual1 =  blackDangerToString(board);
  //printf("BISHOP\n%s", actual1);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  1  7 \n"
"6 1  0  0  0  0  0  1  0  6 \n"
"5 0  1  0  0  0  1  0  0  5 \n"
"4 0  0  1  0  1  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  1  0  1  0  0  0  2 \n"
"1 0  1  0  0  0  1  0  0  1 \n"
"0 1  0  0  0  0  0  1  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  clearDanger(board);
  assert(strcmp(expected1, actual1) == 0);

  Piece * pawn55 = makePiece(0, PAWN);
  board[5][5] = * pawn55;

  Piece * pawn42 = makePiece(0, PAWN);
  board[4][2] = * pawn42;

  Piece * pawn00 = makePiece(0, PAWN);
  board[0][0] = * pawn00;

  Piece * pawn15 = makePiece(0, PAWN);
  board[1][5] = * pawn15;
  
  dangerCast(3, 3, board);
  char * actual2 =  blackDangerToString(board);
  //printf("BISHOP\n%s", actual2);
  char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  1  0  0  5 \n"
"4 0  0  1  0  1  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  1  0  1  0  0  0  2 \n"
"1 0  1  0  0  0  1  0  0  1 \n"
"0 1  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);

  free(bishop33);
  free(pawn55);
  free(pawn42);
  free(pawn00);
  free(pawn15);

  free(actual1);
  free(actual2);

  freeBoard(board);
}
/**
 * test for black bishop
 */
void blackBishopTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * bishop33 = makePiece(1, BISHOP);
  board[3][3] = * bishop33;
  dangerCast(3, 3, board);

  char * actual1 =  whiteDangerToString(board);
  //printf("BISHOP\n%s", actual1);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  1  7 \n"
"6 1  0  0  0  0  0  1  0  6 \n"
"5 0  1  0  0  0  1  0  0  5 \n"
"4 0  0  1  0  1  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  1  0  1  0  0  0  2 \n"
"1 0  1  0  0  0  1  0  0  1 \n"
"0 1  0  0  0  0  0  1  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  clearDanger(board);
  assert(strcmp(expected1, actual1) == 0);

  Piece * pawn55 = makePiece(0, PAWN);
  board[5][5] = * pawn55;

  Piece * pawn42 = makePiece(0, PAWN);
  board[4][2] = * pawn42;

  Piece * pawn00 = makePiece(0, PAWN);
  board[0][0] = * pawn00;

  Piece * pawn15 = makePiece(0, PAWN);
  board[1][5] = * pawn15;
  
  dangerCast(3, 3, board);
  char * actual2 =  whiteDangerToString(board);
  //printf("BISHOP\n%s", actual2);
  char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  1  0  0  5 \n"
"4 0  0  1  0  1  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  1  0  1  0  0  0  2 \n"
"1 0  1  0  0  0  1  0  0  1 \n"
"0 1  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);

  free(bishop33);
  free(pawn55);
  free(pawn42);
  free(pawn00);
  free(pawn15);

  free(actual1);
  freeBoard(board);
}
/**
 * test for black queen
 */
void blackQueenTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * queen33 = makePiece(1, QUEEN);
  board[3][3] = * queen33;
  dangerCast(3, 3, board);

  char * actual1 =  whiteDangerToString(board);
  //printf("QUEEN\n%s", actual1);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  1  0  0  0  1  7 \n"
"6 1  0  0  1  0  0  1  0  6 \n"
"5 0  1  0  1  0  1  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 1  1  1  0  1  1  1  1  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 0  1  0  1  0  1  0  0  1 \n"
"0 1  0  0  1  0  0  1  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  clearDanger(board);

  Piece * pawn55 = makePiece(0, PAWN);
  board[5][5] = * pawn55;

  Piece * pawn42 = makePiece(0, PAWN);
  board[4][2] = * pawn42;

  Piece * pawn00 = makePiece(0, PAWN);
  board[0][0] = * pawn00;

  Piece * pawn15 = makePiece(0, PAWN);
  board[1][5] = * pawn15;
// rook moveset below
  Piece * pawn53 = makePiece(1, PAWN);
  board[5][3] = * pawn53;

  Piece * pawn32 = makePiece(1, PAWN);
  board[3][2] = * pawn32;

  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;

  Piece * pawn36 = makePiece(1, PAWN);
  board[3][6] = * pawn36;

  dangerCast(3, 3, board); // remember to actually run the danger cast

  char * actual2 =  whiteDangerToString(board);

  //printf("QUEEN\n%s", actual2);

  char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  1  0  1  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 0  0  1  0  1  1  1  0  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 0  1  0  1  0  1  0  0  1 \n"
"0 1  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);
  free(queen33);
  free(pawn55);
  free(pawn42);
  free(pawn00);
  free(pawn15);
  free(pawn53);
  free(pawn32);
  free(pawn13);
  free(pawn36);
  free(actual1);
  free(actual2);
  freeBoard(board);
}
/**
 * test for white queen
 */
void whiteQueenTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * queen33 = makePiece(0, QUEEN);
  board[3][3] = * queen33;
  dangerCast(3, 3, board);

  char * actual1 =  blackDangerToString(board);
  //printf("QUEEN\n%s", actual1);
  char expected1[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  1  0  0  0  1  7 \n"
"6 1  0  0  1  0  0  1  0  6 \n"
"5 0  1  0  1  0  1  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 1  1  1  0  1  1  1  1  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 0  1  0  1  0  1  0  0  1 \n"
"0 1  0  0  1  0  0  1  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected1, actual1) == 0);
  clearDanger(board);

  Piece * pawn55 = makePiece(0, PAWN);
  board[5][5] = * pawn55;

  Piece * pawn42 = makePiece(0, PAWN);
  board[4][2] = * pawn42;

  Piece * pawn00 = makePiece(0, PAWN);
  board[0][0] = * pawn00;

  Piece * pawn15 = makePiece(0, PAWN);
  board[1][5] = * pawn15;
// rook moveset below
  Piece * pawn53 = makePiece(1, PAWN);
  board[5][3] = * pawn53;

  Piece * pawn32 = makePiece(1, PAWN);
  board[3][2] = * pawn32;

  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;

  Piece * pawn36 = makePiece(1, PAWN);
  board[3][6] = * pawn36;

  dangerCast(3, 3, board); // remember to actually run the danger cast

  char * actual2 =  blackDangerToString(board);

  //printf("QUEEN\n%s", actual2);

  char expected2[999] = 
"  0  1  2  3  4  5  6  7    \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  1  0  1  0  0  5 \n"
"4 0  0  1  1  1  0  0  0  4 \n"
"3 0  0  1  0  1  1  1  0  3 \n"
"2 0  0  1  1  1  0  0  0  2 \n"
"1 0  1  0  1  0  1  0  0  1 \n"
"0 1  0  0  0  0  0  0  0  0 \n"
"  0  1  2  3  4  5  6  7    \n";
  assert(strcmp(expected2, actual2) == 0);
  free(queen33);
  free(pawn55);
  free(pawn42);
  free(pawn00);
  free(pawn15);
  free(pawn53);
  free(pawn32);
  free(pawn13);
  free(pawn36);
  free(actual1);
  free(actual2);
  freeBoard(board);
}
int main()
{
  whiteKingTest();
  blackKingTest();
  blackRookTest();
  whiteRookTest();
  whitePawnTest();
  blackPawnTest();
  blackKnightTest();
  whiteKnightTest();
  whiteBishopTest();
  blackQueenTest();
  whiteQueenTest();
}