// simple test program to see if board works correctly
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"

int main()
{
  Piece ** board = initBoard();
  char * actual = toStringBoard(board);
  char * expected = 
"  a  b  c  d  e  f  g  h     \n"
"8 r1 n1 b1 q1 k1 b1 n1 r1 8 \n"
"7 p1 p1 p1 p1 p1 p1 p1 p1 7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  0  0  0  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 p0 p0 p0 p0 p0 p0 p0 p0 2 \n"
"1 r0 n0 b0 q0 k0 b0 n0 r0 1 \n"
"  a  b  c  d  e  f  g  h     \n";
  FILE output = 
  printf("%s", actual);

  printf("%s", expected);

  assert(expected != NULL);

  assert(strcmp(expected, actual) == 0);
  free(board);
  board = initEmptyBoard();  
  actual = toStringBoard(board);
  expected = 
"  a  b  c  d  e  f  g  h     \n"
"8 0  0  0  0  0  0  0  0  8 \n"
"7 0  0  0  0  0  0  0  0  7 \n"
"6 0  0  0  0  0  0  0  0  6 \n"
"5 0  0  0  0  0  0  0  0  5 \n"
"4 0  0  0  0  0  0  0  0  4 \n"
"3 0  0  0  0  0  0  0  0  3 \n"
"2 0  0  0  0  0  0  0  0  2 \n"
"1 0  0  0  0  0  0  0  0  1 \n"
"  a  b  c  d  e  f  g  h     \n";
  assert(expected != NULL);

  assert(strcmp(expected, actual) == 0);
  // free the memory
  freeBoard(board);
  free(actual);
}
