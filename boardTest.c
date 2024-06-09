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
  char expected[999] = 
"   a  b  c  d  e  f  g  h     "
"8 r1 n1 b1 q1 k1 b1 n1 r1 8 "
"7 p1 p1 p1 p1 p1 p1 p1 p1 7 "
"6 0  0  0  0  0  0  0  0  6 "
"5 0  0  0  0  0  0  0  0  5 "
"4 0  0  0  0  0  0  0  0  4 "
"3 0  0  0  0  0  0  0  0  3 "
"2 p0 p0 p0 p0 p0 p0 p0 p0 2 "
"1 r0 n0 b0 q0 k0 b0 n0 r0 1 "
"   a  b  c  d  e  f  g  h     ";
  assert(strcmp(expected, actual));
  // free the memory
  freeBoard(board);
  free(actual);
}
