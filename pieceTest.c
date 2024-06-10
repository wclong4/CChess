// simple test program to see if piece works correctly
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "piece.h"

int main()
{
  Piece * piece = makePiece(1, KING);\
  assert(piece != NULL);
  assert(piece->dark == 1);
  assert(piece->type == KING);
  free(piece);

}

