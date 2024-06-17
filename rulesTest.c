/** simple test program to see if the rules work correctly
 * 
 */ 
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rules.h"
/**
 * This is the test for the king moveset
 */
void kingTest() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * king33 = makePiece(1, KING);
  board[3][3] = * king33;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,3,3+1,3,board);

  bool actualMove2 = validMove(3,3,3,3+1,board);

  bool actualMove3 = validMove(3,3,3-1,3,board);

  bool actualMove4 = validMove(3,3,3,3-1,board);

  bool actualMove5 = validMove(3,3,3-1,3+1,board);

  bool actualMove6 = validMove(3,3,3+1,3-1,board);

  bool actualMove7 = validMove(3,3,3-1,3-1,board);

  bool actualMove8 = validMove(3,3,3+1,3+1,board);

  bool actualMove9 = validMove(2,2,3+1,3+1,board);

  bool actualMove10 = validMove(3,3,3+2,3+1,board);
  
  bool actualMove11 = validMove(3,3,-1,3+1,board);

  bool actualMove12 = validMove(3,3,-1,-1,board);

  bool actualMove13 = validMove(3,3,3,3,board);

  assert(actualMove1);
  assert(actualMove2);
  assert(actualMove3);
  assert(actualMove4);
  assert(actualMove5);
  assert(actualMove6);
  assert(actualMove7);
  assert(actualMove8);

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(!actualMove12);
  assert(!actualMove13);

  Piece * king00 = makePiece(1, KING);
  board[0][0] = * king00;
  debugPrintBoard(board);

  bool actualMove001 = validMove(0,0,0+1,0,board);

  bool actualMove002 = validMove(0,0,0,0+1,board);

  bool actualMove003 = validMove(0,0,0-1,0,board);

  bool actualMove004 = validMove(0,0,0,0-1,board);

  bool actualMove005 = validMove(0,0,0-1,0+1,board);

  bool actualMove006 = validMove(0,0,0+1,0-1,board);

  bool actualMove007 = validMove(0,0,0-1,0-1,board);

  bool actualMove008 = validMove(0,0,0+1,0+1,board);

  assert(actualMove001);
  assert(actualMove002);
  assert(!actualMove003);
  assert(!actualMove004);
  assert(!actualMove005);
  assert(!actualMove006);
  assert(!actualMove007);
  assert(actualMove008);

  // free the memory
  freeBoard(board);
  free(king33);
  free(king00);
}
/**
 * This tests the rook's moveset
 */
void rookTest ()
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * rook33 = makePiece(1, ROOK);
  board[3][3] = * rook33;
  debugPrintBoard(board);

  // down
  bool actualMove1 = validMove(3,3,3+1,3,board);
  bool actualMove2 = validMove(3,3,3+2,3,board);
  bool actualMove3 = validMove(3,3,3+3,3,board);
  bool actualMove4 = validMove(3,3,3+4,3,board);

  bool actualMoveBad1 = validMove(3,3,3+5,3,board);//bad

  // up
  bool actualMove5 = validMove(3,3,3-1,3,board);
  bool actualMove6 = validMove(3,3,3-2,3,board);
  bool actualMove7 = validMove(3,3,3-3,3,board);

  bool actualMoveBad2 = validMove(3,3,3-4,3,board);//bad


  // right
  bool actualMove8 = validMove(3,3,3,3+1,board);
  bool actualMove9 = validMove(3,3,3,3+2,board);
  bool actualMove10 = validMove(3,3,3,3+3,board);
  bool actualMove11 = validMove(3,3,3,3+4,board);

  bool actualMoveBad3 = validMove(3,3,3,3+5,board);//bad

  // left
  bool actualMove12 = validMove(3,3,3,3-1,board);
  bool actualMove13 = validMove(3,3,3,3-2,board);
  bool actualMove14 = validMove(3,3,3,3-3,board);

  bool actualMoveBad4 = validMove(3,3,3,3-4,board);//bad

  bool actualMoveBad5 = validMove(3,3,3,3,board);//bad

  assert(actualMove1);
  assert(actualMove2);
  assert(actualMove3);
  assert(actualMove4);
  assert(actualMove5);
  assert(actualMove6);
  assert(actualMove7);
  assert(actualMove8);
  assert(actualMove9);
  assert(actualMove10);
  assert(actualMove11);
  assert(actualMove12);
  assert(actualMove13);
  assert(actualMove14);

  assert(!actualMoveBad1);
  assert(!actualMoveBad2);
  assert(!actualMoveBad3);
  assert(!actualMoveBad4);
  assert(!actualMoveBad5);

  // free the memory
  freeBoard(board);
  free(rook33);

}

void bishopTest()
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * bishop33 = makePiece(1, BISHOP);
  board[3][3] = * bishop33;
  debugPrintBoard(board);
  // I accidentally started with actualMove2, so the first move is labeled as the second, just ignore this
  // + + which is actually down right
  bool actualMove2 = validMove(3,3,3+1,3+1,board);
  bool actualMove3 = validMove(3,3,3+2,3+2,board);
  bool actualMove4 = validMove(3,3,3+3,3+3,board);

  bool actualMove5 = validMove(3,3,3+4,3+4,board); //bad
  bool actualMove6 = validMove(3,3,3-5,3+5,board); //bad

  // + - down left
  bool actualMove7 = validMove(3,3,3+1,3-1,board);
  bool actualMove8 = validMove(3,3,3+2,3-2,board);
  bool actualMove9 = validMove(3,3,3+3,3-3,board);

  bool actualMove10 = validMove(3,3,3+4,3-4,board); //bad

  // - - up left
  bool actualMove11 = validMove(3,3,3-1,3-1,board);
  bool actualMove12 = validMove(3,3,3-2,3-2,board);
  bool actualMove13 = validMove(3,3,3-3,3-3,board);
  bool actualMove14 = validMove(3,3,3-4,3-4,board); //bad

  // - + up right
  bool actualMove15 = validMove(3,3,3-1,3+1,board);
  bool actualMove16 = validMove(3,3,3-2,3+2,board);
  bool actualMove17 = validMove(3,3,3-3,3+3,board);
  bool actualMove18 = validMove(3,3,3-4,3+4,board); 

  bool actualMove19 = validMove(3,3,3,3,board); 

  assert(actualMove2);
  assert(actualMove3);
  assert(actualMove4);
  assert(actualMove5);
  assert(!actualMove6);
  assert(actualMove7);
  assert(actualMove8);
  assert(actualMove9);
  assert(!actualMove10);
  assert(actualMove11);
  assert(actualMove12);
  assert(actualMove13);
  assert(!actualMove14);
  assert(actualMove15);
  assert(actualMove16);
  assert(actualMove17);
  assert(!actualMove18);
  assert(!actualMove19);

  // free the memory
  freeBoard(board);
  free(bishop33);

}
/**
 * basically just bishop test but used for queen
 */
void queenTest1() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * queen33 = makePiece(1, QUEEN);
  board[3][3] = * queen33;
  debugPrintBoard(board);
  // I accidentally started with actualMove2, so the first move is labeled as the second, just ignore this
  // + + which is actually down right
  bool actualMove2 = validMove(3,3,3+1,3+1,board);
  bool actualMove3 = validMove(3,3,3+2,3+2,board);
  bool actualMove4 = validMove(3,3,3+3,3+3,board);

  bool actualMove5 = validMove(3,3,3+4,3+4,board); //bad
  bool actualMove6 = validMove(3,3,3-5,3+5,board); //bad

  // + - down left
  bool actualMove7 = validMove(3,3,3+1,3-1,board);
  bool actualMove8 = validMove(3,3,3+2,3-2,board);
  bool actualMove9 = validMove(3,3,3+3,3-3,board);

  bool actualMove10 = validMove(3,3,3+4,3-4,board); //bad

  // - - up left
  bool actualMove11 = validMove(3,3,3-1,3-1,board);
  bool actualMove12 = validMove(3,3,3-2,3-2,board);
  bool actualMove13 = validMove(3,3,3-3,3-3,board);
  bool actualMove14 = validMove(3,3,3-4,3-4,board); //bad

  // - + up right
  bool actualMove15 = validMove(3,3,3-1,3+1,board);
  bool actualMove16 = validMove(3,3,3-2,3+2,board);
  bool actualMove17 = validMove(3,3,3-3,3+3,board);
  bool actualMove18 = validMove(3,3,3-4,3+4,board); 

  bool actualMove19 = validMove(3,3,3,3,board); 

  assert(actualMove2);
  assert(actualMove3);
  assert(actualMove4);
  assert(actualMove5);
  assert(!actualMove6);
  assert(actualMove7);
  assert(actualMove8);
  assert(actualMove9);
  assert(!actualMove10);
  assert(actualMove11);
  assert(actualMove12);
  assert(actualMove13);
  assert(!actualMove14);
  assert(actualMove15);
  assert(actualMove16);
  assert(actualMove17);
  assert(!actualMove18);
  assert(!actualMove19);

  // free the memory
  freeBoard(board);
  free(queen33);
}
/**
 * basically just rook test but used for queen
 */
void queenTest2() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * queen33 = makePiece(1, QUEEN);
  board[3][3] = * queen33;
  debugPrintBoard(board);

  // down
  bool actualMove1 = validMove(3,3,3+1,3,board);
  bool actualMove2 = validMove(3,3,3+2,3,board);
  bool actualMove3 = validMove(3,3,3+3,3,board);
  bool actualMove4 = validMove(3,3,3+4,3,board);

  bool actualMoveBad1 = validMove(3,3,3+5,3,board);//bad

  // up
  bool actualMove5 = validMove(3,3,3-1,3,board);
  bool actualMove6 = validMove(3,3,3-2,3,board);
  bool actualMove7 = validMove(3,3,3-3,3,board);

  bool actualMoveBad2 = validMove(3,3,3-4,3,board);//bad


  // right
  bool actualMove8 = validMove(3,3,3,3+1,board);
  bool actualMove9 = validMove(3,3,3,3+2,board);
  bool actualMove10 = validMove(3,3,3,3+3,board);
  bool actualMove11 = validMove(3,3,3,3+4,board);

  bool actualMoveBad3 = validMove(3,3,3,3+5,board);//bad

  // left
  bool actualMove12 = validMove(3,3,3,3-1,board);
  bool actualMove13 = validMove(3,3,3,3-2,board);
  bool actualMove14 = validMove(3,3,3,3-3,board);

  bool actualMoveBad4 = validMove(3,3,3,3-4,board);//bad

  bool actualMoveBad5 = validMove(3,3,3,3,board);//bad

  assert(actualMove1);
  assert(actualMove2);
  assert(actualMove3);
  assert(actualMove4);
  assert(actualMove5);
  assert(actualMove6);
  assert(actualMove7);
  assert(actualMove8);
  assert(actualMove9);
  assert(actualMove10);
  assert(actualMove11);
  assert(actualMove12);
  assert(actualMove13);
  assert(actualMove14);

  assert(!actualMoveBad1);
  assert(!actualMoveBad2);
  assert(!actualMoveBad3);
  assert(!actualMoveBad4);
  assert(!actualMoveBad5);

  // free the memory
  freeBoard(board);
  free(queen33);
}
/**
 * This tests the pawn moving up 2 spaces
 */
void blackPawnTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;
  debugPrintBoard(board);
  // move up 2
  // x1, y1, x2, y2
  bool actualMove1 = validMove(3,1,3,1+2,board);
  bool actualMove2 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove3 = validMove(3,1,3+1,1+1,board);// bad
  bool actualMove4 = validMove(3,1,3-1,1+1,board);// bad

  assert(actualMove1);
  assert(!actualMove2);
  assert(!actualMove3);
  assert(!actualMove4);

  Piece * pawn23 = makePiece(0, PAWN);
  board[2][3] = * pawn23;

  bool actualMove5 = validMove(3,1,3,1+2,board);
  bool actualMove6 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove7 = validMove(3,1,3+1,1+1,board);// bad
  bool actualMove8 = validMove(3,1,3-1,1+1,board);// bad

  assert(!actualMove5);
  assert(!actualMove6);
  assert(!actualMove7);
  assert(!actualMove8);

  debugPrintBoard(board);

  Piece * pawn22 = makePiece(0, PAWN);
  board[2][2] = * pawn23;

  bool actualMove9 = validMove(3,1,3,1+2,board);
  bool actualMove10 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove11 = validMove(3,1,3+1,1+1,board);// bad
  bool actualMove12 = validMove(3,1,3-1,1+1,board);// bad

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(actualMove12);

  debugPrintBoard(board);

  Piece * pawn24 = makePiece(0, PAWN);
  board[2][4] = * pawn24;

  bool actualMove13 = validMove(3,1,3,1+2,board);
  bool actualMove14 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove15 = validMove(3,1,3+1,1+1,board);// bad
  bool actualMove16 = validMove(3,1,3-1,1+1,board);// bad

  assert(!actualMove13);
  assert(!actualMove14);
  assert(actualMove15);
  assert(actualMove16);

  debugPrintBoard(board);

  Piece * pawn12 = makePiece(0, PAWN);
  board[1][2] = * pawn12;
  board[1][2].enPassantAble = 1;
  bool actualMove17 = validMove(3,1,2,1,board);

  assert(actualMove17);

  Piece * pawn14 = makePiece(0, PAWN);
  board[1][4] = * pawn12;
  board[1][4].enPassantAble = 1;
  bool actualMove18 = validMove(3,1,4,1,board);

  assert(actualMove18);
  // make it so en passant is not possible
  board[1][2].enPassantAble = 0;
  board[1][4].enPassantAble = 0;
  
  bool actualMove20 = validMove(3,1,2,1,board);
  assert(!actualMove20);

  bool actualMove21 = validMove(3,1,4,1,board);
  assert(!actualMove21);
 
  debugPrintBoard(board);

  freeBoard(board);
  free(pawn13);
  free(pawn23);
  free(pawn22);
  free(pawn24);
  free(pawn12);
  free(pawn14);
}
/**
 * Tests the white pawn
 */
void whitePawnTest() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * pawn23 = makePiece(0, PAWN);
  board[2][3] = * pawn23;
  debugPrintBoard(board);
  // move up 2
  // x1, y1, x2, y2
  bool actualMove1 = validMove(3,2,3,2-2,board);
  bool actualMove2 = validMove(3,2,3,2-2-2,board);// bad, should not be able to jump twice
  bool actualMove3 = validMove(3,2,3+1,2-1,board);// bad
  bool actualMove4 = validMove(3,2,3-1,2-1,board);// bad

  assert(actualMove1);
  assert(!actualMove2);
  assert(!actualMove3);
  assert(!actualMove4);

  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;

  bool actualMove5 = validMove(3,2,3,2-2,board);
  bool actualMove6 = validMove(3,2,3,2-2-2,board);// bad, should not be able to jump twice
  bool actualMove7 = validMove(3,2,3+1,2-1,board);// bad
  bool actualMove8 = validMove(3,2,3-1,2-1,board);// bad

  assert(!actualMove5);
  assert(!actualMove6);
  assert(!actualMove7);
  assert(!actualMove8);

  debugPrintBoard(board);

  Piece * pawn12 = makePiece(1, PAWN);
  board[1][2] = * pawn12;

  bool actualMove9 = validMove(3,2,3,2-2,board);
  bool actualMove10 = validMove(3,2,3,2-2-2,board);// bad, should not be able to jump twice
  bool actualMove11 = validMove(3,2,3+1,2-1,board);// bad
  bool actualMove12 = validMove(3,2,3-1,2-1,board);// bad

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(actualMove12);

  debugPrintBoard(board);

  Piece * pawn14 = makePiece(1, PAWN);
  board[1][4] = * pawn14;

  bool actualMove13 = validMove(3,2,3,2-2,board);//bad
  bool actualMove14 = validMove(3,2,3,2-2-2,board);// bad, should not be able to jump twice
  bool actualMove15 = validMove(3,2,3+1,2-1,board);
  bool actualMove16 = validMove(3,2,3-1,2-1,board);

  assert(!actualMove13);
  assert(!actualMove14);
  assert(actualMove15);
  assert(actualMove16);

  debugPrintBoard(board);

  Piece * pawn22 = makePiece(1, PAWN);
  board[2][2] = * pawn22;
  board[2][2].enPassantAble = 1;
  bool actualMove17 = validMove(3,2,2,2,board);

  assert(actualMove17);

  Piece * pawn24 = makePiece(1, PAWN);
  board[2][4] = * pawn24;
  board[2][4].enPassantAble = 1;
  bool actualMove18 = validMove(3,2,4,2,board);

  assert(actualMove18);
  // make it so en passant is not possible
  board[2][2].enPassantAble = 0;
  board[2][4].enPassantAble = 0;
  
  bool actualMove20 = validMove(3,2,2,2,board);
  assert(!actualMove20);

  bool actualMove21 = validMove(3,2,4,2,board);
  assert(!actualMove21);
 
  debugPrintBoard(board);

  freeBoard(board);
 
}
int main()
{
  kingTest();
  rookTest();
  bishopTest();
  queenTest1();
  queenTest2();
  blackPawnTest();
  whitePawnTest();
}
