/**
 * This class handles information dealing with pieces and rules dealing with pieces
 * @author Warren Long (wclong4)
*/

/** A chess piece */
#include <stdbool.h>

/** Piece type char for a king */
#define KING 'k'

/** Piece type char for a rook */
#define ROOK 'r'

/** Piece type char for a queen */
#define QUEEN 'q'

/** Piece type char for a pawn. */
#define PAWN 'p'

/** Piece type char for a knight */
#define KNIGHT 'n'

/** Piece type char for a bishop */
#define BISHOP 'b'

typedef struct {
  /** True if dark piece */
  bool dark;
  
  /** Type of the piece where each piece is encoded like this
   * 
   * k = king
   * r = rook
   * q = queen
   * p = pawn
     n = knight
     b = bishop
  */
  char type;
} Piece;