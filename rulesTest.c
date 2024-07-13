/** Test program to see if the rules work correctly
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
void kingTest1() 
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
 * another test for the king where we test for collision
 * 
 */
void kingTest2() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * king33 = makePiece(1, KING);
  board[3][3] = * king33;
  debugPrintBoard(board);
  // make same colored pawns and check that it cannot move there
  Piece * pawn32 = makePiece(1, PAWN);
  board[3][3-1] = * pawn32;

  Piece * pawn23 = makePiece(1, PAWN);
  board[3-1][3] = * pawn23;

  Piece * pawn22 = makePiece(1, PAWN);
  board[3-1][3-1] = * pawn22;

  Piece * pawn43 = makePiece(1, PAWN);
  board[3+1][3] = * pawn43;

  Piece * pawn34 = makePiece(1, PAWN);
  board[3][3+1] = * pawn34;

  Piece * pawn44 = makePiece(1, PAWN);
  board[3+1][3+1] = * pawn44;

  Piece * pawn42 = makePiece(1, PAWN);
  board[3+1][3-1] = * pawn42;

  Piece * pawn24 = makePiece(1, PAWN);
  board[3-1][3+1] = * pawn24;

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

  assert(!actualMove1);
  assert(!actualMove2);
  assert(!actualMove3);
  assert(!actualMove4);
  assert(!actualMove5);
  assert(!actualMove6);
  assert(!actualMove7);
  assert(!actualMove8);

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(!actualMove12);
  assert(!actualMove13);

  free(king33);
  free(pawn32);
  free(pawn23);
  free(pawn22);
  free(pawn43);
  free(pawn34);
  free(pawn44);
  free(pawn42);
  free(pawn24);

  freeBoard(board);
}
/**
 *  also we test for castling functionality
 */
void kingTest3() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(1, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(1, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(1, ROOK);
  board[0][7] = * rook07;
  debugPrintBoard(board);
  // check to see if it fails when in the king is in danger or passes through or ends on a danger square
  board[0][3].inDangerBlack = 1;
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  board[0][3].inDangerBlack = 0;
  board[0][2].inDangerBlack = 1;
  board[0][4].inDangerBlack = 1;
  bool actualMove3 = validMove(3,0,1,0,board);
  bool actualMove4 = validMove(3,0,5,0,board);
  assert(!actualMove3);
  assert(!actualMove4);
  board[0][2].inDangerBlack = 0;
  board[0][4].inDangerBlack = 0;
  board[0][1].inDangerBlack = 1;
  board[0][5].inDangerBlack = 1;
  bool actualMove5 = validMove(3,0,1,0,board);
  bool actualMove6 = validMove(3,0,5,0,board);
  assert(actualMove5);
  assert(!actualMove6);
  debugPrintBoard(board);
  // move rook back
  free(rook00);
  Piece * empty1 =  makePiece(0,0);
  board[0][2] = * empty1;
  Piece * rook002 =  makePiece(1, ROOK);
  board[0][0] = * rook002;

  board[0][1].inDangerBlack = 0;
  board[0][5].inDangerBlack = 0;
  board[0][0].inDangerBlack = 1;
  board[0][6].inDangerBlack = 1;
  board[0][7].inDangerBlack = 1;
  debugPrintBoard(board);

  bool actualMove7 = validMove(3,0,1,0,board);
  bool actualMove8 = validMove(3,0,5,0,board);
  assert(actualMove7);
  assert(actualMove8);
  debugPrintBoard(board);

  // check to see if it works under normal conditions
  // move rooks back
  free(rook002);
  Piece * empty2 =  makePiece(0,0);
  board[0][2] = * empty2;
  Piece * rook003 = makePiece(1, ROOK);
  board[0][0] = * rook003;

  free(rook07);
  Piece * empty3 =  makePiece(0,0);
  board[0][4] = * empty3;
  Piece * rook072 = makePiece(1, ROOK);
  board[0][7] = * rook072;

  board[0][0].inDangerBlack = 0;
  board[0][6].inDangerBlack = 0;
  board[0][7].inDangerBlack = 0;
  bool actualMoveNormal1 = validMove(3,0,1,0,board);
  bool actualMoveNormal2 = validMove(3,0,5,0,board);
  assert(actualMoveNormal1);
  assert(actualMoveNormal2);


  free(king03);
  free(rook072);
  free(rook003);
  free(empty1);
  free(empty2);
  free(empty3);

  freeBoard(board);
}
/**
 *  test for castling collision functionality
 */
void kingTest4() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(1, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(1, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(1, ROOK);
  board[0][7] = * rook07;
  Piece * pawn01 = makePiece(1, PAWN);
  board[0][1] = * pawn01;
  Piece * pawn06 = makePiece(1, PAWN);
  board[0][6] = * pawn06;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  free(king03);
  free(rook00);
  free(rook07);
  free(pawn01);
  free(pawn06);
  freeBoard(board);

}
/**
 *  test for castling collision functionality
 */
void kingTest5() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(1, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(1, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(1, ROOK);
  board[0][7] = * rook07;
  Piece * pawn02 = makePiece(1, PAWN);
  board[0][2] = * pawn02;
  Piece * pawn05 = makePiece(1, PAWN);
  board[0][5] = * pawn05;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  free(king03);
  free(rook00);
  free(rook07);
  free(pawn02);
  free(pawn05);
  freeBoard(board);

}
/**
 *  test for castling collision functionality
 */
void kingTest6() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(1, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(1, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(1, ROOK);
  board[0][7] = * rook07;
  Piece * pawn02 = makePiece(1, PAWN);
  board[0][2] = * pawn02;
  Piece * pawn04 = makePiece(1, PAWN);
  board[0][4] = * pawn04;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  free(king03);
  free(rook00);
  free(rook07);
  free(pawn02);
  free(pawn04);
  freeBoard(board);

}
/**
 * This is the test for the king moveset
 */
void kingTest1Light() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * king33 = makePiece(0, KING);
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

  Piece * king00 = makePiece(0, KING);
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
 * another test for the king where we test for collision
 * 
 */
void kingTest2Light() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the king moveset
  Piece * king33 = makePiece(0, KING);
  board[3][3] = * king33;
  debugPrintBoard(board);
  // make same colored pawns and check that it cannot move there
  Piece * pawn32 = makePiece(0, PAWN);
  board[3][3-1] = * pawn32;

  Piece * pawn23 = makePiece(0, PAWN);
  board[3-1][3] = * pawn23;

  Piece * pawn22 = makePiece(0, PAWN);
  board[3-1][3-1] = * pawn22;

  Piece * pawn43 = makePiece(0, PAWN);
  board[3+1][3] = * pawn43;

  Piece * pawn34 = makePiece(0, PAWN);
  board[3][3+1] = * pawn34;

  Piece * pawn44 = makePiece(0, PAWN);
  board[3+1][3+1] = * pawn44;

  Piece * pawn42 = makePiece(0, PAWN);
  board[3+1][3-1] = * pawn42;

  Piece * pawn24 = makePiece(0, PAWN);
  board[3-1][3+1] = * pawn24;

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

  assert(!actualMove1);
  assert(!actualMove2);
  assert(!actualMove3);
  assert(!actualMove4);
  assert(!actualMove5);
  assert(!actualMove6);
  assert(!actualMove7);
  assert(!actualMove8);

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(!actualMove12);
  assert(!actualMove13);

  free(king33);
  free(pawn32);
  free(pawn23);
  free(pawn22);
  free(pawn43);
  free(pawn34);
  free(pawn44);
  free(pawn42);
  free(pawn24);

  freeBoard(board);
}
/**
 *  also we test for castling functionality
 */
void kingTest3Light() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(0, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(0, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(0, ROOK);
  board[0][7] = * rook07;
  debugPrintBoard(board);
  // check to see if it fails when in the king is in danger or passes through or ends on a danger square
  board[0][3].inDangerWhite = 1;
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  board[0][3].inDangerWhite = 0;
  board[0][2].inDangerWhite = 1;
  board[0][4].inDangerWhite = 1;
  bool actualMove3 = validMove(3,0,1,0,board);
  bool actualMove4 = validMove(3,0,5,0,board);
  assert(!actualMove3);
  assert(!actualMove4);
  board[0][2].inDangerWhite = 0;
  board[0][4].inDangerWhite = 0;
  board[0][1].inDangerWhite = 1;
  board[0][5].inDangerWhite = 1;
  bool actualMove5 = validMove(3,0,1,0,board);
  bool actualMove6 = validMove(3,0,5,0,board);
  assert(actualMove5);
  assert(!actualMove6);
  debugPrintBoard(board);
  // move rook back
  free(rook00);
  Piece * empty1 =  makePiece(1,0);
  board[0][2] = * empty1;
  Piece * rook002 =  makePiece(0, ROOK);
  board[0][0] = * rook002;

  board[0][1].inDangerWhite = 0;
  board[0][5].inDangerWhite = 0;
  board[0][0].inDangerWhite = 1;
  board[0][6].inDangerWhite = 1;
  board[0][7].inDangerWhite = 1;
  debugPrintBoard(board);

  bool actualMove7 = validMove(3,0,1,0,board);
  bool actualMove8 = validMove(3,0,5,0,board);
  assert(actualMove7);
  assert(actualMove8);
  debugPrintBoard(board);

  // check to see if it works under normal conditions
  // move rooks back
  free(rook002);
  Piece * empty2 =  makePiece(0,0);
  board[0][2] = * empty2;
  Piece * rook003 = makePiece(0, ROOK);
  board[0][0] = * rook003;

  free(rook07);
  Piece * empty3 =  makePiece(0,0);
  board[0][4] = * empty3;
  Piece * rook072 = makePiece(0, ROOK);
  board[0][7] = * rook072;

  board[0][0].inDangerWhite = 0;
  board[0][6].inDangerWhite = 0;
  board[0][7].inDangerWhite = 0;
  bool actualMoveNormal1 = validMove(3,0,1,0,board);
  bool actualMoveNormal2 = validMove(3,0,5,0,board);
  assert(actualMoveNormal1);
  assert(actualMoveNormal2);


  free(king03);
  free(rook072);
  free(rook003);
  free(empty1);
  free(empty2);
  free(empty3);

  freeBoard(board);
}
/**
 *  test for castling collision functionality
 */
void kingTest4Light() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(0, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(0, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(0, ROOK);
  board[0][7] = * rook07;
  Piece * pawn01 = makePiece(0, PAWN);
  board[0][1] = * pawn01;
  Piece * pawn06 = makePiece(0, PAWN);
  board[0][6] = * pawn06;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  free(king03);
  free(rook00);
  free(rook07);
  free(pawn01);
  free(pawn06);
  freeBoard(board);

}
/**
 *  test for castling collision functionality
 */
void kingTest5Light() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(0, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(0, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(0, ROOK);
  board[0][7] = * rook07;
  Piece * pawn02 = makePiece(0, PAWN);
  board[0][2] = * pawn02;
  Piece * pawn05 = makePiece(0, PAWN);
  board[0][5] = * pawn05;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  free(king03);
  free(rook00);
  free(rook07);
  free(pawn02);
  free(pawn05);
  freeBoard(board);

}
/**
 *  test for castling collision functionality
 */
void kingTest6Light() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is a test for the king moveset
  Piece * king03 = makePiece(0, KING);
  board[0][3] = * king03;
  Piece * rook00 = makePiece(0, ROOK);
  board[0][0] = * rook00;
  Piece * rook07 = makePiece(0, ROOK);
  board[0][7] = * rook07;
  Piece * pawn02 = makePiece(0, PAWN);
  board[0][2] = * pawn02;
  Piece * pawn04 = makePiece(0, PAWN);
  board[0][4] = * pawn04;
  debugPrintBoard(board);
  bool actualMove1 = validMove(3,0,1,0,board);
  bool actualMove2 = validMove(3,0,5,0,board);
  assert(!actualMove1);
  assert(!actualMove2);
  free(king03);
  free(rook00);
  free(rook07);
  free(pawn02);
  free(pawn04);
  freeBoard(board);

}
/**
 * This tests the rook's moveset
 */
void rookTest ()
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the rook moveset
  Piece * rook33 = makePiece(1, ROOK);
  board[3][3] = * rook33;
  //debugPrintBoard(board);

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

  // now do collision checks with light pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53 = makePiece(0, PAWN);
  board[5][3] = * pawn53;

  Piece * pawn30 = makePiece(0, PAWN);
  board[3][0] = * pawn30;

  Piece * pawn23 = makePiece(0, PAWN);
  board[2][3] = * pawn23;

  Piece * pawn35 = makePiece(0, PAWN);
  board[3][5] = * pawn35;
  //debugPrintBoard(board);
  // right
  bool actualMove1c = validMove(3,3,3+1,3,board);
  bool actualMove2c = validMove(3,3,3+2,3,board);
  bool actualMove3c = validMove(3,3,3+3,3,board);// bad
  bool actualMove4c = validMove(3,3,3+4,3,board);// bad

  // left
  bool actualMove5c = validMove(3,3,3-1,3,board);
  bool actualMove6c = validMove(3,3,3-2,3,board);
  bool actualMove7c = validMove(3,3,3-3,3,board);

  // up
  bool actualMove8c = validMove(3,3,3,3+1,board);
  bool actualMove9c = validMove(3,3,3,3+2,board);
  bool actualMove10c = validMove(3,3,3,3+3,board);// bad
  bool actualMove11c = validMove(3,3,3,3+4,board);// bad

  // down
  bool actualMove12c = validMove(3,3,3,3-1,board);
  bool actualMove13c = validMove(3,3,3,3-2,board);// bad
  bool actualMove14c = validMove(3,3,3,3-3,board);// bad

  assert(actualMove1c);
  assert(actualMove2c);
  assert(!actualMove3c);
  assert(!actualMove4c);
  assert(actualMove5c);
  assert(actualMove6c);
  assert(actualMove7c);
  assert(actualMove8c);
  assert(actualMove9c);
  assert(!actualMove10c);
  assert(!actualMove11c);
  assert(actualMove12c);
  assert(!actualMove13c);
  assert(!actualMove14c);

  // now do collision checks with dark pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53d = makePiece(1, PAWN);
  board[5][3] = * pawn53d;

  Piece * pawn30d = makePiece(1, PAWN);
  board[3][0] = * pawn30d;

  Piece * pawn23d = makePiece(1, PAWN);
  board[2][3] = * pawn23d;

  Piece * pawn35d = makePiece(1, PAWN);
  board[3][5] = * pawn35d;
  //debugPrintBoard(board);
  // right
  bool actualMove1cd = validMove(3,3,3+1,3,board);
  bool actualMove2cd = validMove(3,3,3+2,3,board);// bad
  bool actualMove3cd = validMove(3,3,3+3,3,board);// bad
  bool actualMove4cd = validMove(3,3,3+4,3,board);// bad

  // left
  bool actualMove5cd = validMove(3,3,3-1,3,board);
  bool actualMove6cd = validMove(3,3,3-2,3,board);
  bool actualMove7cd = validMove(3,3,3-3,3,board);// bad

  // up
  bool actualMove8cd = validMove(3,3,3,3+1,board);
  bool actualMove9cd = validMove(3,3,3,3+2,board);// bad
  bool actualMove10cd = validMove(3,3,3,3+3,board);// bad
  bool actualMove11cd = validMove(3,3,3,3+4,board);// bad

  // down
  bool actualMove12cd = validMove(3,3,3,3-1,board);// bad
  bool actualMove13cd = validMove(3,3,3,3-2,board);// bad
  bool actualMove14cd = validMove(3,3,3,3-3,board);// bad

  assert(actualMove1cd);
  assert(!actualMove2cd);
  assert(!actualMove3cd);
  assert(!actualMove4cd);
  assert(actualMove5cd);
  assert(actualMove6cd);
  assert(!actualMove7cd);
  assert(actualMove8cd);
  assert(!actualMove9cd);
  assert(!actualMove10cd);
  assert(!actualMove11cd);
  assert(!actualMove12cd);
  assert(!actualMove13cd);
  assert(!actualMove14cd);
  // free the memory
  freeBoard(board);
  free(rook33);

  free(pawn53);
  free(pawn30);
  free(pawn23);
  free(pawn35);

  free(pawn53d);
  free(pawn30d);
  free(pawn23d);
  free(pawn35d);


}

void bishopTest()
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the bishop moveset
  Piece * bishop33 = makePiece(1, BISHOP);
  board[3][3] = * bishop33;
  //debugPrintBoard(board);
  // I accidentally started with actualMove2, so the first move is labeled as the second, just ignore this
  // + + 
  bool actualMove2 = validMove(3,3,3+1,3+1,board);
  bool actualMove3 = validMove(3,3,3+2,3+2,board);
  bool actualMove4 = validMove(3,3,3+3,3+3,board);
  bool actualMove5 = validMove(3,3,3+4,3+4,board); 

  bool actualMove6 = validMove(3,3,3-5,3+5,board); //bad

  // + - 
  bool actualMove7 = validMove(3,3,3+1,3-1,board);
  bool actualMove8 = validMove(3,3,3+2,3-2,board);
  bool actualMove9 = validMove(3,3,3+3,3-3,board);

  bool actualMove10 = validMove(3,3,3+4,3-4,board); //bad

  // - - 
  bool actualMove11 = validMove(3,3,3-1,3-1,board);
  bool actualMove12 = validMove(3,3,3-2,3-2,board);
  bool actualMove13 = validMove(3,3,3-3,3-3,board);
  bool actualMove14 = validMove(3,3,3-4,3-4,board); //bad

  // - + 
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



  // I accidentally started with actualMove2, so the first move is labeled as the second, just ignore this
  // test for collision light colored pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53 = makePiece(0, PAWN);
  board[6][0] = * pawn53;

  Piece * pawn30 = makePiece(0, PAWN);
  board[1][1] = * pawn30;

  Piece * pawn23 = makePiece(0, PAWN);
  board[2][4] = * pawn23;

  Piece * pawn35 = makePiece(0, PAWN);
  board[7][7] = * pawn35;
  //debugPrintBoard(board);
  // + + up up
  bool actualMove2l = validMove(3,3,3+1,3+1,board);
  bool actualMove3l = validMove(3,3,3+2,3+2,board);
  bool actualMove4l = validMove(3,3,3+3,3+3,board);
  bool actualMove5l = validMove(3,3,3+4,3+4,board); 
  bool actualMove6l = validMove(3,3,3+5,3+5,board); //bad

  // + - right down
  bool actualMove7l = validMove(3,3,3+1,3-1,board);
  bool actualMove8l = validMove(3,3,3+2,3-2,board); //bad
  bool actualMove9l = validMove(3,3,3+3,3-3,board); //bad
  bool actualMove10l = validMove(3,3,3+4,3-4,board); //bad

  // - - left down
  bool actualMove11l = validMove(3,3,3-1,3-1,board);
  bool actualMove12l = validMove(3,3,3-2,3-2,board);
  bool actualMove13l = validMove(3,3,3-3,3-3,board); //bad
  bool actualMove14l = validMove(3,3,3-4,3-4,board); //bad

  // - + left up
  bool actualMove15l = validMove(3,3,3-1,3+1,board);
  bool actualMove16l = validMove(3,3,3-2,3+2,board);
  bool actualMove17l = validMove(3,3,3-3,3+3,board);
  bool actualMove18l = validMove(3,3,3-4,3+4,board); //bad
  bool actualMove19l = validMove(3,3,3-5,3+5,board); //bad


  assert(actualMove2l);
  assert(actualMove3l);
  assert(actualMove4l);
  assert(actualMove5l);
  assert(!actualMove6l);
  assert(actualMove7l);
  assert(!actualMove8l);
  assert(!actualMove9l);
  assert(!actualMove10l);
  assert(actualMove11l);
  assert(actualMove12l);
  assert(!actualMove13l);
  assert(!actualMove14l);
  assert(actualMove15l);
  assert(actualMove16l);
  assert(actualMove17l);
  assert(!actualMove18l);
  assert(!actualMove19l);

  // test for collision dark colored pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53d = makePiece(1, PAWN);
  board[6][0] = * pawn53d;

  Piece * pawn30d = makePiece(1, PAWN);
  board[1][1] = * pawn30d;

  Piece * pawn23d = makePiece(1, PAWN);
  board[2][4] = * pawn23d;

  Piece * pawn35d = makePiece(1, PAWN);
  board[7][7] = * pawn35d;
  //debugPrintBoard(board);
  // + + up up
  bool actualMove2d = validMove(3,3,3+1,3+1,board);
  bool actualMove3d = validMove(3,3,3+2,3+2,board);
  bool actualMove4d = validMove(3,3,3+3,3+3,board);
  bool actualMove5d = validMove(3,3,3+4,3+4,board); //bad
  bool actualMove6d = validMove(3,3,3+5,3+5,board); //bad

  // + - right down
  bool actualMove7d = validMove(3,3,3+1,3-1,board); //bad
  bool actualMove8d = validMove(3,3,3+2,3-2,board); //bad
  bool actualMove9d = validMove(3,3,3+3,3-3,board); //bad
  bool actualMove10d = validMove(3,3,3+4,3-4,board); //bad

  // - - left down
  bool actualMove11d = validMove(3,3,3-1,3-1,board);
  bool actualMove12d = validMove(3,3,3-2,3-2,board); //bad
  bool actualMove13d = validMove(3,3,3-3,3-3,board); //bad
  bool actualMove14d = validMove(3,3,3-4,3-4,board); //bad

  // - + left up
  bool actualMove15d = validMove(3,3,3-1,3+1,board);
  bool actualMove16d = validMove(3,3,3-2,3+2,board);
  bool actualMove17d = validMove(3,3,3-3,3+3,board); //bad
  bool actualMove18d = validMove(3,3,3-4,3+4,board); //bad
  bool actualMove19d = validMove(3,3,3-5,3+5,board); //bad


  assert(actualMove2d);
  assert(actualMove3d);
  assert(actualMove4d);
  assert(!actualMove5d);
  assert(!actualMove6d);
  assert(!actualMove7d);
  assert(!actualMove8d);
  assert(!actualMove9d);
  assert(!actualMove10d);
  assert(actualMove11d);
  assert(!actualMove12d);
  assert(!actualMove13d);
  assert(!actualMove14d);
  assert(actualMove15d);
  assert(actualMove16d);
  assert(!actualMove17d);
  assert(!actualMove18d);
  assert(!actualMove19d);

  // free the memory
  freeBoard(board);
  free(bishop33);
  free(pawn53);
  free(pawn30);
  free(pawn23);
  free(pawn35);
  free(pawn53d);
  free(pawn30d);
  free(pawn23d);
  free(pawn35d);
}
/**
 * basically just bishop test but used for queen
 */
void queenTest1() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the bishop moveset
  Piece * queen33 = makePiece(1, QUEEN);
  board[3][3] = * queen33;
  //debugPrintBoard(board);
  // I accidentally started with actualMove2, so the first move is labeled as the second, just ignore this
  // + + 
  bool actualMove2 = validMove(3,3,3+1,3+1,board);
  bool actualMove3 = validMove(3,3,3+2,3+2,board);
  bool actualMove4 = validMove(3,3,3+3,3+3,board);
  bool actualMove5 = validMove(3,3,3+4,3+4,board); 

  bool actualMove6 = validMove(3,3,3-5,3+5,board); //bad

  // + - 
  bool actualMove7 = validMove(3,3,3+1,3-1,board);
  bool actualMove8 = validMove(3,3,3+2,3-2,board);
  bool actualMove9 = validMove(3,3,3+3,3-3,board);

  bool actualMove10 = validMove(3,3,3+4,3-4,board); //bad

  // - - 
  bool actualMove11 = validMove(3,3,3-1,3-1,board);
  bool actualMove12 = validMove(3,3,3-2,3-2,board);
  bool actualMove13 = validMove(3,3,3-3,3-3,board);
  bool actualMove14 = validMove(3,3,3-4,3-4,board); //bad

  // - + 
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



  // I accidentally started with actualMove2, so the first move is labeled as the second, just ignore this
  // test for collision light colored pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53 = makePiece(0, PAWN);
  board[6][0] = * pawn53;

  Piece * pawn30 = makePiece(0, PAWN);
  board[1][1] = * pawn30;

  Piece * pawn23 = makePiece(0, PAWN);
  board[2][4] = * pawn23;

  Piece * pawn35 = makePiece(0, PAWN);
  board[7][7] = * pawn35;
  //debugPrintBoard(board);
  // + + up up
  bool actualMove2l = validMove(3,3,3+1,3+1,board);
  bool actualMove3l = validMove(3,3,3+2,3+2,board);
  bool actualMove4l = validMove(3,3,3+3,3+3,board);
  bool actualMove5l = validMove(3,3,3+4,3+4,board); 
  bool actualMove6l = validMove(3,3,3+5,3+5,board); //bad

  // + - right down
  bool actualMove7l = validMove(3,3,3+1,3-1,board);
  bool actualMove8l = validMove(3,3,3+2,3-2,board); //bad
  bool actualMove9l = validMove(3,3,3+3,3-3,board); //bad
  bool actualMove10l = validMove(3,3,3+4,3-4,board); //bad

  // - - left down
  bool actualMove11l = validMove(3,3,3-1,3-1,board);
  bool actualMove12l = validMove(3,3,3-2,3-2,board);
  bool actualMove13l = validMove(3,3,3-3,3-3,board); //bad
  bool actualMove14l = validMove(3,3,3-4,3-4,board); //bad

  // - + left up
  bool actualMove15l = validMove(3,3,3-1,3+1,board);
  bool actualMove16l = validMove(3,3,3-2,3+2,board);
  bool actualMove17l = validMove(3,3,3-3,3+3,board);
  bool actualMove18l = validMove(3,3,3-4,3+4,board); //bad
  bool actualMove19l = validMove(3,3,3-5,3+5,board); //bad


  assert(actualMove2l);
  assert(actualMove3l);
  assert(actualMove4l);
  assert(actualMove5l);
  assert(!actualMove6l);
  assert(actualMove7l);
  assert(!actualMove8l);
  assert(!actualMove9l);
  assert(!actualMove10l);
  assert(actualMove11l);
  assert(actualMove12l);
  assert(!actualMove13l);
  assert(!actualMove14l);
  assert(actualMove15l);
  assert(actualMove16l);
  assert(actualMove17l);
  assert(!actualMove18l);
  assert(!actualMove19l);

  // test for collision dark colored pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53d = makePiece(1, PAWN);
  board[6][0] = * pawn53d;

  Piece * pawn30d = makePiece(1, PAWN);
  board[1][1] = * pawn30d;

  Piece * pawn23d = makePiece(1, PAWN);
  board[2][4] = * pawn23d;

  Piece * pawn35d = makePiece(1, PAWN);
  board[7][7] = * pawn35d;
  //debugPrintBoard(board);
  // + + up up
  bool actualMove2d = validMove(3,3,3+1,3+1,board);
  bool actualMove3d = validMove(3,3,3+2,3+2,board);
  bool actualMove4d = validMove(3,3,3+3,3+3,board);
  bool actualMove5d = validMove(3,3,3+4,3+4,board); //bad
  bool actualMove6d = validMove(3,3,3+5,3+5,board); //bad

  // + - right down
  bool actualMove7d = validMove(3,3,3+1,3-1,board); //bad
  bool actualMove8d = validMove(3,3,3+2,3-2,board); //bad
  bool actualMove9d = validMove(3,3,3+3,3-3,board); //bad
  bool actualMove10d = validMove(3,3,3+4,3-4,board); //bad

  // - - left down
  bool actualMove11d = validMove(3,3,3-1,3-1,board);
  bool actualMove12d = validMove(3,3,3-2,3-2,board); //bad
  bool actualMove13d = validMove(3,3,3-3,3-3,board); //bad
  bool actualMove14d = validMove(3,3,3-4,3-4,board); //bad

  // - + left up
  bool actualMove15d = validMove(3,3,3-1,3+1,board);
  bool actualMove16d = validMove(3,3,3-2,3+2,board);
  bool actualMove17d = validMove(3,3,3-3,3+3,board); //bad
  bool actualMove18d = validMove(3,3,3-4,3+4,board); //bad
  bool actualMove19d = validMove(3,3,3-5,3+5,board); //bad


  assert(actualMove2d);
  assert(actualMove3d);
  assert(actualMove4d);
  assert(!actualMove5d);
  assert(!actualMove6d);
  assert(!actualMove7d);
  assert(!actualMove8d);
  assert(!actualMove9d);
  assert(!actualMove10d);
  assert(actualMove11d);
  assert(!actualMove12d);
  assert(!actualMove13d);
  assert(!actualMove14d);
  assert(actualMove15d);
  assert(actualMove16d);
  assert(!actualMove17d);
  assert(!actualMove18d);
  assert(!actualMove19d);

  // free the memory
  freeBoard(board);
  free(queen33);
  free(pawn53);
  free(pawn30);
  free(pawn23);
  free(pawn35);
  free(pawn53d);
  free(pawn30d);
  free(pawn23d);
  free(pawn35d);
}
/**
 * basically just rook test but used for queen
 */
void queenTest2() 
{
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the rook moveset
  Piece * rook33 = makePiece(1, ROOK);
  board[3][3] = * rook33;
  //debugPrintBoard(board);

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

  // now do collision checks with light pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53 = makePiece(0, PAWN);
  board[5][3] = * pawn53;

  Piece * pawn30 = makePiece(0, PAWN);
  board[3][0] = * pawn30;

  Piece * pawn23 = makePiece(0, PAWN);
  board[2][3] = * pawn23;

  Piece * pawn35 = makePiece(0, PAWN);
  board[3][5] = * pawn35;
  //debugPrintBoard(board);
  // right
  bool actualMove1c = validMove(3,3,3+1,3,board);
  bool actualMove2c = validMove(3,3,3+2,3,board);
  bool actualMove3c = validMove(3,3,3+3,3,board);// bad
  bool actualMove4c = validMove(3,3,3+4,3,board);// bad

  // left
  bool actualMove5c = validMove(3,3,3-1,3,board);
  bool actualMove6c = validMove(3,3,3-2,3,board);
  bool actualMove7c = validMove(3,3,3-3,3,board);

  // up
  bool actualMove8c = validMove(3,3,3,3+1,board);
  bool actualMove9c = validMove(3,3,3,3+2,board);
  bool actualMove10c = validMove(3,3,3,3+3,board);// bad
  bool actualMove11c = validMove(3,3,3,3+4,board);// bad

  // down
  bool actualMove12c = validMove(3,3,3,3-1,board);
  bool actualMove13c = validMove(3,3,3,3-2,board);// bad
  bool actualMove14c = validMove(3,3,3,3-3,board);// bad

  assert(actualMove1c);
  assert(actualMove2c);
  assert(!actualMove3c);
  assert(!actualMove4c);
  assert(actualMove5c);
  assert(actualMove6c);
  assert(actualMove7c);
  assert(actualMove8c);
  assert(actualMove9c);
  assert(!actualMove10c);
  assert(!actualMove11c);
  assert(actualMove12c);
  assert(!actualMove13c);
  assert(!actualMove14c);

  // now do collision checks with dark pieces
  // place light pawns at [5][3],[3][0],[2][3],[3][5]
  Piece * pawn53d = makePiece(1, PAWN);
  board[5][3] = * pawn53d;

  Piece * pawn30d = makePiece(1, PAWN);
  board[3][0] = * pawn30d;

  Piece * pawn23d = makePiece(1, PAWN);
  board[2][3] = * pawn23d;

  Piece * pawn35d = makePiece(1, PAWN);
  board[3][5] = * pawn35d;
  //debugPrintBoard(board);
  // right
  bool actualMove1cd = validMove(3,3,3+1,3,board);
  bool actualMove2cd = validMove(3,3,3+2,3,board);// bad
  bool actualMove3cd = validMove(3,3,3+3,3,board);// bad
  bool actualMove4cd = validMove(3,3,3+4,3,board);// bad

  // left
  bool actualMove5cd = validMove(3,3,3-1,3,board);
  bool actualMove6cd = validMove(3,3,3-2,3,board);
  bool actualMove7cd = validMove(3,3,3-3,3,board);// bad

  // up
  bool actualMove8cd = validMove(3,3,3,3+1,board);
  bool actualMove9cd = validMove(3,3,3,3+2,board);// bad
  bool actualMove10cd = validMove(3,3,3,3+3,board);// bad
  bool actualMove11cd = validMove(3,3,3,3+4,board);// bad

  // down
  bool actualMove12cd = validMove(3,3,3,3-1,board);// bad
  bool actualMove13cd = validMove(3,3,3,3-2,board);// bad
  bool actualMove14cd = validMove(3,3,3,3-3,board);// bad

  assert(actualMove1cd);
  assert(!actualMove2cd);
  assert(!actualMove3cd);
  assert(!actualMove4cd);
  assert(actualMove5cd);
  assert(actualMove6cd);
  assert(!actualMove7cd);
  assert(actualMove8cd);
  assert(!actualMove9cd);
  assert(!actualMove10cd);
  assert(!actualMove11cd);
  assert(!actualMove12cd);
  assert(!actualMove13cd);
  assert(!actualMove14cd);
  // free the memory
  freeBoard(board);
  free(rook33);

  free(pawn53);
  free(pawn30);
  free(pawn23);
  free(pawn35);

  free(pawn53d);
  free(pawn30d);
  free(pawn23d);
  free(pawn35d);

}
/**
 * This tests the pawn moving up 2 spaces
 */
void blackPawnTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the pawn moveset
  Piece * pawn13 = makePiece(1, PAWN);
  board[1][3] = * pawn13;
  //debugPrintBoard(board);
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

  bool actualMove5 = validMove(3,1,3,1+2,board);// bad
  bool actualMove6 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove7 = validMove(3,1,3+1,1+1,board);// bad
  bool actualMove8 = validMove(3,1,3-1,1+1,board);// bad

  assert(!actualMove5);
  assert(!actualMove6);
  assert(!actualMove7);
  assert(!actualMove8);

  //debugPrintBoard(board);

  Piece * pawn22 = makePiece(0, PAWN);
  board[2][2] = * pawn22;

  bool actualMove9 = validMove(3,1,3,1+2,board);// bad
  bool actualMove10 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove11 = validMove(3,1,3+1,1+1,board);// bad
  bool actualMove12 = validMove(3,1,3-1,1+1,board);

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(actualMove12);

  //debugPrintBoard(board);

  Piece * pawn24 = makePiece(0, PAWN);
  board[2][4] = * pawn24;

  bool actualMove13 = validMove(3,1,3,1+2,board);// bad
  bool actualMove14 = validMove(3,1,3,1+2+2,board);// bad, should not be able to jump twice
  bool actualMove15 = validMove(3,1,3+1,1+1,board);
  bool actualMove16 = validMove(3,1,3-1,1+1,board);

  assert(!actualMove13);
  assert(!actualMove14);
  assert(actualMove15);
  assert(actualMove16);

  //debugPrintBoard(board);

  Piece * pawn12 = makePiece(0, PAWN);
  board[1][2] = * pawn12;
  board[1][2].enPassantAble = 1;
  bool actualMove17 = validMove(3,1,2,1,board);

  assert(actualMove17);

  Piece * pawn14 = makePiece(0, PAWN);
  board[1][4] = * pawn14;
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
 
  //debugPrintBoard(board);

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
  // also this is the test for the pawn moveset
  Piece * pawn23 = makePiece(0, PAWN);
  board[2][3] = * pawn23;
  //debugPrintBoard(board);
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

  bool actualMove5 = validMove(3,2,3,2-2,board);// bad
  bool actualMove6 = validMove(3,2,3,2-2-2,board);// bad, should not be able to jump twice
  bool actualMove7 = validMove(3,2,3+1,2-1,board);// bad
  bool actualMove8 = validMove(3,2,3-1,2-1,board);// bad

  assert(!actualMove5);
  assert(!actualMove6);
  assert(!actualMove7);
  assert(!actualMove8);

  //debugPrintBoard(board);

  Piece * pawn12 = makePiece(1, PAWN);
  board[1][2] = * pawn12;

  bool actualMove9 = validMove(3,2,3,2-2,board);// bad
  bool actualMove10 = validMove(3,2,3,2-2-2,board);// bad, should not be able to jump twice
  bool actualMove11 = validMove(3,2,3+1,2-1,board);// bad
  bool actualMove12 = validMove(3,2,3-1,2-1,board);

  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(actualMove12);

  //debugPrintBoard(board);

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

  //debugPrintBoard(board);

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
 
  //debugPrintBoard(board);

  freeBoard(board);
  free(pawn24);
  free(pawn22);
  free(pawn14);
  free(pawn12);
  free(pawn13);
  free(pawn23);

}
void knightTest() {
  Piece ** board = initEmptyBoard();
  // y, x the coordinates for the board are backwards
  // also this is the test for the knight moveset
  Piece * knight33 = makePiece(0, KNIGHT);
  board[3][3] = * knight33;
  debugPrintBoard(board);
  // x1, y1, x2, y2
  // valid moves
  bool actualMove1 = validMove(3,3,3+2,3+1,board);
  bool actualMove2 = validMove(3,3,3+2,3-1,board);
  bool actualMove3 = validMove(3,3,3-2,3+1,board);
  bool actualMove4 = validMove(3,3,3-2,3-1,board);

  bool actualMove5 = validMove(3,3,3+1,3+2,board);
  bool actualMove6 = validMove(3,3,3+1,3-2,board);
  bool actualMove7 = validMove(3,3,3-1,3+2,board);
  bool actualMove8 = validMove(3,3,3-1,3-2,board);
  // invalid moves
  bool actualMove9 = validMove(3,3,3-2,3-2,board);
  bool actualMove10 = validMove(3,3,3-1,3-3,board);
  bool actualMove11 = validMove(3,3,3-1,3-1,board);
  bool actualMove12 = validMove(3,3,3+1,3+4,board);
  bool actualMove13 = validMove(3,3,3,3,board);

  // valid moves
  assert(actualMove1);
  assert(actualMove2);
  assert(actualMove3);
  assert(actualMove4);
  assert(actualMove5);
  assert(actualMove6);
  assert(actualMove7);
  assert(actualMove8);

  // invalid moves
  assert(!actualMove9);
  assert(!actualMove10);
  assert(!actualMove11);
  assert(!actualMove12);
  assert(!actualMove13);

  // collision check light 
  Piece * pawn45 = makePiece(0, PAWN);
  board[4][5] = * pawn45;

  Piece * pawn54 = makePiece(0, PAWN);
  board[5][4] = * pawn54;

  Piece * pawn41 = makePiece(0, PAWN);
  board[4][1] = * pawn41;

  Piece * pawn52 = makePiece(0, PAWN);
  board[5][2] = * pawn52;

  Piece * pawn12 = makePiece(0, PAWN);
  board[1][2] = * pawn12;

  Piece * pawn21 = makePiece(0, PAWN);
  board[2][1] = * pawn21;

  Piece * pawn14 = makePiece(0, PAWN);
  board[1][4] = * pawn14;

  Piece * pawn25 = makePiece(0, PAWN);
  board[2][5] = * pawn25;

  // invalid moves because of collision
  bool actualMove1c = validMove(3,3,3+2,3+1,board);
  bool actualMove2c = validMove(3,3,3+2,3-1,board);
  bool actualMove3c = validMove(3,3,3-2,3+1,board);
  bool actualMove4c = validMove(3,3,3-2,3-1,board);

  bool actualMove5c = validMove(3,3,3+1,3+2,board);
  bool actualMove6c = validMove(3,3,3+1,3-2,board);
  bool actualMove7c = validMove(3,3,3-1,3+2,board);
  bool actualMove8c = validMove(3,3,3-1,3-2,board);

  // invalid moves
  assert(!actualMove1c);
  assert(!actualMove2c);
  assert(!actualMove3c);
  assert(!actualMove4c);
  assert(!actualMove5c);
  assert(!actualMove6c);
  assert(!actualMove7c);
  assert(!actualMove8c);
  // collision check light 
  Piece * pawn45d = makePiece(1, PAWN);
  board[4][5] = * pawn45d;

  Piece * pawn54d = makePiece(1, PAWN);
  board[5][4] = * pawn54d;

  Piece * pawn41d = makePiece(1, PAWN);
  board[4][1] = * pawn41d;

  Piece * pawn52d = makePiece(1, PAWN);
  board[5][2] = * pawn52d;

  Piece * pawn12d = makePiece(1, PAWN);
  board[1][2] = * pawn12d;

  Piece * pawn21d = makePiece(1, PAWN);
  board[2][1] = * pawn21d;

  Piece * pawn14d = makePiece(1, PAWN);
  board[1][4] = * pawn14d;

  Piece * pawn25d = makePiece(1, PAWN);
  board[2][5] = * pawn25d;
  // valid moves because opposite color
  bool actualMove1cd = validMove(3,3,3+2,3+1,board);
  bool actualMove2cd = validMove(3,3,3+2,3-1,board);
  bool actualMove3cd = validMove(3,3,3-2,3+1,board);
  bool actualMove4cd = validMove(3,3,3-2,3-1,board);

  bool actualMove5cd = validMove(3,3,3+1,3+2,board);
  bool actualMove6cd = validMove(3,3,3+1,3-2,board);
  bool actualMove7cd = validMove(3,3,3-1,3+2,board);
  bool actualMove8cd = validMove(3,3,3-1,3-2,board);

  // valid moves
  assert(actualMove1cd);
  assert(actualMove2cd);
  assert(actualMove3cd);
  assert(actualMove4cd);
  assert(actualMove5cd);
  assert(actualMove6cd);
  assert(actualMove7cd);
  assert(actualMove8cd);


  //debugPrintBoard(board);
  // free memory
  free(knight33);
  free(pawn45d);
  free(pawn54d);
  free(pawn41d);
  free(pawn52d);
  free(pawn12d);
  free(pawn21d);
  free(pawn14d);
  free(pawn25d);

  free(pawn45);
  free(pawn54);
  free(pawn41);
  free(pawn52);
  free(pawn12);
  free(pawn21);
  free(pawn14);
  free(pawn25);

  freeBoard(board);

}
int main()
{
  kingTest1();
  kingTest2();
  kingTest3();
  kingTest4();
  kingTest5();
  kingTest6();

  kingTest1Light();
  kingTest2Light();
  kingTest3Light();
  kingTest4Light();
  kingTest5Light();
  kingTest6Light();

  rookTest();
  bishopTest();
  queenTest1();
  queenTest2();
  blackPawnTest();
  whitePawnTest();
  knightTest();
}
