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
}
/**
 * This frees the piece
 */
Piece * freePiece(Piece * piece) {
  free(piece);
}