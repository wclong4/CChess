/** 
 *
 * TODO: add checks for moves
 * TODO: add checks for collision with moves (like not being able to move when blocked)
 * TODO: add checks for check and checkmate
*/
#include "piece.h"


/**
 * checks moves for the king
 * 
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool kingCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {
  // the king can move in a square
  if (finalx == initx - 1 || finalx == initx || finalx == initx + 1 ) {
    if (finaly == inity - 1 || finaly == inity || finaly == inity + 1 ) {
      return true;
    }
  }
  return false;
}
/**
 * checks moves for the rook
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool rookCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {
  // the rook can move in straight lines
  if (finalx == initx || finaly == inity) {
    return true;
  }
  return false;
}
/**
 * checks moves for the queen
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool queenCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {
  // the queen can move in straight lines
  if (finalx == initx || finaly == inity) {
    return true;
  }
  // and in diagonals
  int deltaX = finalx - initx;
  int deltaY = finaly - inity;
  if (abs(deltaX) == abs(deltaY)) {
    return true;
  }
  return false;
}
/**
 * checks moves for the pawn
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool pawnCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {
  Piece * pawn = &board[inity][initx];
  // the pawn, like all other pieces cannot take pieces of the same type
  if (pawn->dark) {
    // NON TAKING MOVES
    // have to let the pawn move forwards twice if it has not moved yet
    // but the space it moves to must be empty, again this is [y][x] NOT x, y
    // and the space right in front of it must be empty, it cannot jump over pieces
    if (!pawn->hasMoved && board[inity + 2][initx].type == 0 && board[inity + 1][initx].type == 0) {
      if ((finalx == initx) && finaly == inity + 2) {
        pawn->hasMoved = true;
        // every piece must have this set to false after each turn
        // to make sure that the special pawn moveset cannot be used when it should not
        pawn->enPassantAble = true;
        return true;
      }
    }
    // this is just moving up 1, there cannot be a piece there
    if ((finalx == initx) && (finaly == inity + 1) && board[inity + 1][initx].type == 0) {
      pawn->hasMoved = true;
      return true;
    }
    
    // TAKING MOVES, MUST CHECK PIECE COLOR!
    // normal pawn moveset stuff
    // this is only allowed if there is already a piece there of the opposite type, the piece is taken also
    if ((finalx == initx - 1) && finaly == inity + 1 && board[inity + 1][initx - 1].type != 0 && board[inity + 1][initx - 1].dark == 0) {
      pawn->hasMoved = true;
      return true;
    } 
    if ((finalx == initx + 1) && finaly == inity + 1 && board[inity + 1][initx + 1].type != 0 && board[inity + 1][initx + 1].dark == 0) {
      pawn->hasMoved = true;
      return true;
    } 
    // special en passant moveset
    if ((finalx == initx + 1) && finaly == inity && board[inity][initx + 1].enPassantAble == 1 && board[inity][initx + 1].dark == 0) {
      pawn->hasMoved = true;
      return true;
    }
    if ((finalx == initx - 1) && finaly == inity && board[inity][initx - 1].enPassantAble == 1 && board[inity][initx - 1].dark == 0) {
      pawn->hasMoved = true;
      return true;
    }
    return false;
  } else { // this is the moveset for the white pawn, it is the same except where we add 1 to y we subtract 1
    // NON TAKING MOVES
    // have to let the pawn move forwards twice if it has not moved yet
    // but the space it moves to must be empty, again this is [y][x] NOT x, y
    // and the space right in front of it must be empty, it cannot jump over pieces
    if (!pawn->hasMoved && board[inity - 2][initx].type == 0 && board[inity - 1][initx].type == 0) {
      if ((finalx == initx) && finaly == inity - 2) {
        pawn->hasMoved = true;
        // every piece must have this set to false after each turn
        // to make sure that the special pawn moveset cannot be used when it should not
        pawn->enPassantAble = true;
        return true;
      }
    }
    // this is just moving up 1, there cannot be a piece there
    if ((finalx == initx) && (finaly == inity - 1) && board[inity - 1][initx].type == 0) {
      pawn->hasMoved = true;
      return true;
    }
    
    // TAKING MOVES, MUST CHECK PIECE COLOR!
    // normal pawn moveset stuff
    // this is only allowed if there is already a piece there of the opposite type, the piece is taken also
    if ((finalx == initx - 1) && finaly == inity - 1 && board[inity - 1][initx - 1].type != 0 && board[inity - 1][initx - 1].dark == 1) {
      pawn->hasMoved = true;
      return true;
    } 
    if ((finalx == initx + 1) && finaly == inity - 1 && board[inity - 1][initx + 1].type != 0 && board[inity - 1][initx + 1].dark == 1) {
      pawn->hasMoved = true;
      return true;
    } 
    // special en passant moveset
    if ((finalx == initx + 1) && finaly == inity && board[inity][initx + 1].enPassantAble == 1 && board[inity][initx + 1].dark == 1) {
      pawn->hasMoved = true;
      return true;
    }
    if ((finalx == initx - 1) && finaly == inity && board[inity][initx - 1].enPassantAble == 1 && board[inity][initx - 1].dark == 1) {
      pawn->hasMoved = true;
      return true;
    }
    return false;
  }

}
/**
 * checks moves for the knight
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool knightCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {

}
/**
 * checks moves for the bishop
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool bishopCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {
  // check if the absolute value of the difference is the same for both of them
  int deltaX = finalx - initx;
  int deltaY = finaly - inity;
  if (abs(deltaX) == abs(deltaY)) {
    return true;
  }
  return false;
}


bool validMove(int initx, int inity, int finalx, int finaly, Piece ** board) {
  Piece piece = board[inity][initx];
  // if someone tries to move an empty space then return false
  if (piece.type == 0) {
    return false;
  }
  // too small
  if (initx < 0 || inity < 0 || finalx < 0 || finaly < 0 ) {
    return false;
  }
  // too big
  if (initx > 7 || inity > 7 || finalx > 7 || finaly > 7 ) {
    return false;
  }
  // if the same
  if (initx == finalx && inity == finaly) {
    return false;
  }
  
  // specific checks for different pieces
  // these delegate their responsibilities to other methods in this class
  if (piece.type == KING) {
    return kingCheck(initx, inity, finalx, finaly, board);
  }
  if (piece.type == ROOK) {
    return rookCheck(initx, inity, finalx, finaly, board);
  }
  if (piece.type == QUEEN) {
    return queenCheck(initx, inity, finalx, finaly, board);
  }
  if (piece.type == PAWN) {
    return pawnCheck(initx, inity, finalx, finaly, board);
  }
  if (piece.type == KNIGHT) {
    return knightCheck(initx, inity, finalx, finaly, board);
  }
  if (piece.type == BISHOP) {
    return bishopCheck(initx, inity, finalx, finaly, board);
  }
}