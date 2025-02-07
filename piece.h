/**
 * This class handles information dealing with pieces and rules dealing with pieces
 * @author Warren Long (wclong4)
*/

/** A chess piece */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

// got values from here https://arxiv.org/pdf/2009.04374
#define PAWN_VAL 3.05
#define KNIGHT_VAL 3.05
#define BISHOP_VAL 3.33
#define ROOK_VAL 5.63
#define QUEEN_VAL 9.5

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

  /**
   * true if has moved, this is really just used for pawns
   */
  bool hasMoved;
  /**
   * true if in danger for a white piece
   */
  bool inDangerWhite;
  /**
   * true if in danger for a black piece
   */
  bool inDangerBlack;
  /**
   * Used specifically for pawns, true if a pawn has just moved forwards 2 spaces
   */
  bool enPassantAble;
  /**
  * the value of the piece
  */
  bool value;

} Piece;

/**
 * This makes a piece with a specific color and type
 */
Piece * makePiece(bool dark, char type);
/**
 * This frees the piece
 */
void freePiece(Piece * piece);