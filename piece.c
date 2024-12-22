#include "piece.h"

/**
 * This class handles information dealing with pieces and rules dealing with pieces
 * @author Warren Long (wclong4)
*/

/**
 * This makes a piece with a specific color and type
 */
Piece * makePiece(bool dark, char type) {
  Piece * piece = (Piece *)malloc(sizeof(Piece));
  piece->dark = dark;
  piece->type = type;
  piece->hasMoved = false;
  piece->inDangerWhite = false;
  piece->inDangerBlack = false;
  piece->enPassantAble = false;
  // set up piece value
  if (piece->type == KING) {
    piece->value = 9999;
  }
  if (piece->type == ROOK) {
    piece->value = ROOK_VAL;
  }
  if (piece->type == QUEEN) {
    piece->value = QUEEN_VAL;
  }
  if (piece->type == PAWN) {
    piece->value = PAWN_VAL;
  }
  if (piece->type == KNIGHT) {
    piece->value = KNIGHT_VAL;
  }
  if (piece->type == BISHOP) {
    piece->value = BISHOP_VAL;
  }
  // return our piece
  return piece;
}
/**
 * This frees the piece
 */
void freePiece(Piece * piece) {
  free(piece);
}