/** 
 *
 * TODO: add checks for moves
 * TODO: add checks for collision with moves (like not being able to move when blocked)
 * TODO: add checks for check and checkmate
*/
#include "rules.h"


/**
 * checks moves for a white king
 * 
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
static bool kingCheck(int initx, int inity, int finalx, int finaly, Piece ** board) {
  // first check for castling
  // the king cannot move into any square that is in danger, so we must check 
  // if a piece is in danger before moving there
  
  // "Castling is permitted only if neither the king nor the rook has previously moved; 
  // the squares between the king and the rook are vacant; and the king does not leave, 
  // cross over, or finish on a square attacked by an enemy piece." from  https://en.wikipedia.org/wiki/Castling

  // also this code is special because it doesn't just check to see if the pieces can move there, it actually
  // moves the rook there when it does castling
  Piece king = board[inity][initx];
  // check for dark king
  if (king.dark == 1) {
    if (king.hasMoved == false && king.inDangerBlack == false) {
      bool validQSideRook = false;
      bool validKSideRook = false;
      Piece queensideRook;
      
      if (initx + 4 <= 7) {
        queensideRook = board[inity][initx + 4];
        validQSideRook = true;
      }
      Piece kingsideRook;
      if (initx - 3 >= 0) {
        kingsideRook = board[inity][initx - 3];
        validKSideRook = true;
      }
      // queenside castling check
      if (validQSideRook && queensideRook.hasMoved == false && queensideRook.type == ROOK && queensideRook.dark == king.dark) {
        // move 2 right
        if (finalx == initx + 2 && finaly == inity) {
          // square 1 check, square 2 check, etc 
          // s1 and s2 must be empty and not in danger
          // s3 must be empty
          bool s1Check = board[inity][initx + 1].inDangerBlack == false && board[inity][initx + 1].type == 0;
          bool s2Check = board[inity][initx + 2].inDangerBlack == false && board[inity][initx + 2].type == 0;
          bool s3Check = board[inity][initx + 3].type == 0;
          if (s1Check && s2Check && s3Check) {
            // this is a little sus
            board[inity][initx + 4] = board[finaly][finalx - 1];
            board[finaly][finalx - 1] = queensideRook;
            queensideRook.hasMoved = 1;
            king.hasMoved = 1;
            return true;
          }
        }
      }
      // kingside castling check
      if (validKSideRook && kingsideRook.hasMoved == false && kingsideRook.type == ROOK && kingsideRook.dark == king.dark) {
        // move 2 left
        if (finalx == initx - 2 && finaly == inity) {
          // square 1 check, square 2 check, etc 
          // s1 and s2 must be empty and not in danger
          // s3 must be empty
          bool s1Check = board[inity][initx - 1].inDangerBlack == false && board[inity][initx - 1].type == 0;
          bool s2Check = board[inity][initx - 2].type == 0;
          if (s1Check && s2Check) {
            board[inity][initx - 3 ] = board[finaly][finalx + 1];
            board[finaly][finalx + 1] = kingsideRook;
            queensideRook.hasMoved = 1;
            king.hasMoved = 1;
            return true;
          }
        }
      }
    }
    // second we check to see if it is in the square
    // the king can move in a square for its normal moveset
    if (finalx == initx - 1 || finalx == initx || finalx == initx + 1 ) {
      if (finaly == inity - 1 || finaly == inity || finaly == inity + 1 ) {
        // the king cannot move into squares that are in danger
        if (board[finaly][finalx].inDangerBlack == false) {
          // it can move into empty safe spaces
          if (board[finaly][finalx].type == 0) {
            return true;
          } else if (board[finaly][finalx].dark != king.dark) { // or capture pieces if that does not put it in danger
            return true;
          }
        }

      }
    }
    return false;
  } else { // check for light king
    if (king.hasMoved == false && king.inDangerWhite == false) {
    bool validQSideRook = false;
    bool validKSideRook = false;
    Piece queensideRook;
    
    if (initx + 4 <= 7) {
      queensideRook = board[inity][initx + 4];
      validQSideRook = true;
    }
    Piece kingsideRook;
    if (initx - 3 >= 0) {
      kingsideRook = board[inity][initx - 3];
      validKSideRook = true;
    }
    // queenside castling check
    if (validQSideRook && queensideRook.hasMoved == false && queensideRook.type == ROOK && queensideRook.dark == king.dark) {
      // move 2 right
      if (finalx == initx + 2 && finaly == inity) {
        // square 1 check, square 2 check, etc 
        // s1 and s2 must be empty and not in danger
        // s3 must be empty
        bool s1Check = board[inity][initx + 1].inDangerWhite == false && board[inity][initx + 1].type == 0;
        bool s2Check = board[inity][initx + 2].inDangerWhite == false && board[inity][initx + 2].type == 0;
        bool s3Check = board[inity][initx + 3].type == 0;
        if (s1Check && s2Check && s3Check) {
          // this is a little sus
          board[inity][initx + 4] = board[finaly][finalx - 1];
          board[finaly][finalx - 1] = queensideRook;
          queensideRook.hasMoved = 1;
          king.hasMoved = 1;
          return true;
        }
      }
    }
    // kingside castling check
    if (validKSideRook && kingsideRook.hasMoved == false && kingsideRook.type == ROOK && kingsideRook.dark == king.dark) {
      // move 2 left
      if (finalx == initx - 2 && finaly == inity) {
        // square 1 check, square 2 check, etc 
        // s1 and s2 must be empty and not in danger
        // s3 must be empty
        bool s1Check = board[inity][initx - 1].inDangerWhite == false && board[inity][initx - 1].type == 0;
        bool s2Check = board[inity][initx - 2].type == 0;
        if (s1Check && s2Check) {
          board[inity][initx - 3 ] = board[finaly][finalx + 1];
          board[finaly][finalx + 1] = kingsideRook;
          queensideRook.hasMoved = 1;
          king.hasMoved = 1;
          return true;
        }
      }
    }
  }
  // second we check to see if it is in the square
  // the king can move in a square for its normal moveset
  if (finalx == initx - 1 || finalx == initx || finalx == initx + 1 ) {
    if (finaly == inity - 1 || finaly == inity || finaly == inity + 1 ) {
      // the king cannot move into squares that are in danger
      if (board[finaly][finalx].inDangerWhite == false) {
        // it can move into empty safe spaces
        if (board[finaly][finalx].type == 0) {
          return true;
        } else if (board[finaly][finalx].dark != king.dark) { // or capture pieces if that does not put it in danger
          return true;
        }
      }

    }
  }
  return false;
  }


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
  // though it does have collision :(
  // we have to check one of the four lines it can go in
  // but first we have to check if it is on one of those lines
  if (!(finalx == initx || finaly == inity)) {
    return false;
  }
  // for all of these we have to start i one off of 
  // where the piece is so it does not collision check itself
  // this should not cause an out of bounds issue because
  // it will only do +1 or -1 when a finalx or finaly are at least +1 or -1 bigger or smaller than 
  // the initial value, but not out of bounds
  // this happens because there is already bounds checking in the method that calls this
  bool rColor = board[inity][initx].dark;
  // up 
  if (finaly > inity) {
    // check that nothing collides with the rook when it moves
    for (int i = inity + 1; i <= finaly; i++) {
      // [y][x]
      if (board[i][initx].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we skip this and return true
        if (board[i][initx].dark != rColor && i == finaly) {
          return true;
        } else {
          return false;
        }
      }
    }
    // if nothing was there then we are good
    return true;
  }

  // down
  if (finaly < inity) {
    // check that nothing collides with the rook when it moves
    for (int i = inity - 1; i >= finaly; i--) {
      // [y][x]
      if (board[i][initx].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we skip this and return true
        if (board[i][initx].dark != rColor && i == finaly) {
          return true;
        } else {
          return false;
        }
      }
    }
    // if nothing was there then we are good
    return true;
  }
  // left
  if (finalx < initx) {
    // check that nothing collides with the rook when it moves
    for (int i = initx - 1; i >= finalx; i--) {
      // [y][x]
      if (board[inity][i].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we skip this and return true
        if (board[inity][i].dark != rColor && i == finalx) {
          return true;
        } else {
          return false;
        }
      }
    }
    // if nothing was there then we are good
    return true;
  }
 
  // right
  if (finalx > initx) {
    // check that nothing collides with the rook when it moves
    for (int i = initx + 1; i <= finalx; i++) {
      // [y][x]
      if (board[inity][i].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we skip this and return true
        if (board[inity][i].dark != rColor && i == finalx) {
          return true;
        } else {
          return false;
        }
      }
    }
    // if nothing was there then we are good
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
  // this is actually pretty simple because there is no collision detection on different colored pieces
  // it does need collision detection for pieces of the same color
  // ++
  if (((finalx == initx + 2) && (finaly == inity + 1)) || ((finalx == initx + 1) && (finaly == inity + 2))) {
    if (board[finaly][finalx].type == 0 || board[finaly][finalx].dark != board[inity][initx].dark) {
      return true;
    }
  }
  // +-
  if (((finalx == initx + 2) && (finaly == inity - 1)) || ((finalx == initx + 1) && (finaly == inity - 2))) {
    if (board[finaly][finalx].type == 0 || board[finaly][finalx].dark != board[inity][initx].dark) {
      return true;
    }
  }
  // -+
  if (((finalx == initx - 2) && (finaly == inity + 1)) || ((finalx == initx - 1) && (finaly == inity + 2))) {
    if (board[finaly][finalx].type == 0 || board[finaly][finalx].dark != board[inity][initx].dark) {
      return true;
    }
  }
  // --
  if (((finalx == initx - 2) && (finaly == inity - 1)) || ((finalx == initx - 1) && (finaly == inity - 2))) {
    if (board[finaly][finalx].type == 0 || board[finaly][finalx].dark != board[inity][initx].dark) {
      return true;
    }
  }
  return false;
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
  if (!(abs(deltaX) == abs(deltaY))) {
    return false;
  }
  // weirdly enough, we don't need to do bounds checking here because the bounds checking was already done
  bool bColor = board[inity][initx].dark;
  // ++
  if (finaly > inity && finalx > initx) {
    // check that nothing collides with the bishop when it moves
    int x = initx + 1;
    for (int y = inity + 1; y <= finaly; y++) {
      // [y][x]
      if (board[y][x].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we return true
        if (board[y][x].dark != bColor && y == finaly) {
          return true;
        } else {
          return false;
        }
      }
      x++;
    }
    
    // if nothing was there then we are good
    return true;
  }
  // +-
  if (finaly > inity && finalx < initx) {
    // check that nothing collides with the bishop when it moves
    int x = initx - 1;
    for (int y = inity + 1; y <= finaly; y++) {
      // [y][x]
      if (board[y][x].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we return true
        if (board[y][x].dark != bColor && y == finaly) {
          return true;
        } else {
          return false;
        }
      }
      x--;
    }
    
    // if nothing was there then we are good
    return true;
  }

  // -+
  if (finaly < inity && finalx > initx) {
    // check that nothing collides with the bishop when it moves
    int x = initx + 1;
    for (int y = inity - 1; y >= finaly; y--) {
      // [y][x]
      if (board[y][x].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we return true
        if (board[y][x].dark != bColor && y == finaly) {
          return true;
        } else {
          return false;
        }
      }
      x++;
    }
    
    // if nothing was there then we are good
    return true;
  }
  // --
    if (finaly < inity && finalx < initx) {
    // check that nothing collides with the bishop when it moves
    int x = initx - 1;
    for (int y = inity - 1; y >= finaly; y--) {
      // [y][x]
      if (board[y][x].type != 0) { // if something is there we return false
        // unless there is an opposite colored piece at the final position, then we return true
        if (board[y][x].dark != bColor && y == finaly) {
          return true;
        } else {
          return false;
        }
      }
      x--;
    }
    
    // if nothing was there then we are good
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
  // just a combination of rook or bishop check
  return (rookCheck(initx, inity, finalx, finaly, board) || bishopCheck(initx, inity, finalx, finaly, board));
}
/**
 * Checks if the white king is in check or not
 * @param board the board to check for check
 */
bool whiteCheckCheck(Piece ** board) {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      // if the type is king, and the king is white and in danger, then we have check for white
      if (board[y][x].type == KING && !board[y][x].dark && board[y][x].inDangerWhite) {
        return true;
      }
    }
  }
  return false;
}
/**
 * Checks if the black king is in check or not
 * @param board the board to check for check
 */
bool blackCheckCheck(Piece ** board) {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      // if the type is king, and the king is white and in danger, then we have check for white
      if (board[y][x].type == KING && board[y][x].dark && board[y][x].inDangerBlack) {
        return true;
      }
    }
  }
  return false;
}
/**
 * Checks if the king can move
 * @param b the board to check
 * @param ix the x coord of the king
 * @param iy the y coord of the king
 * @return false if there are no valid moves
 */
bool kingMoveCheck(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the king so
  //  ***
  // **k**
  //  ***
  // the extra moves on the side are for castling
  if (validMove(ix, iy, ix + 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 1, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 0, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 0, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 2, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 2, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  return false;
}
/**
 * Checks if the pawn can move
 * @param b the board to check
 * @param ix the x coord of the pawn
 * @param iy the y coord of the pawn
 * @return false if there are no valid moves
 */
bool pawnMoveCheck(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the pawn so
  //  *
  // ***
  //  p
  // ***
  //  *
  // remember that it is flipped for black so we check both the white and black moveset
  // black moveset
  if (validMove(ix, iy, ix + 0, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 0, iy + 2, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }

  // white moveset
  if (validMove(ix, iy, ix + 0, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 0, iy - 2, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  return false;
}
/**
 * Checks if the rook can move
 * @param b the board to check
 * @param ix the x coord of the rook
 * @param iy the y coord of the rook
 * @return false if there are no valid moves
 */
bool rookMoveCheck(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the rook so
  //   *
  //  *r*
  //   *
  // I am not drawing this all out, you can fill in the pieces
  for (int i = 0; i < 8; i++) {
    if (validMove(ix, iy, ix + i, iy + 0, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix - i, iy + 0, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + 0, iy - i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + 0, iy + i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
  }
  return false;
}
/**
 * Checks if the bishop can move
 * @param b the board to check
 * @param ix the x coord of the bishop
 * @param iy the y coord of the bishop
 * @return false if there are no valid moves
 */
bool bishopMoveCheck(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the bishop so
  //  * *
  //   b
  //  * *
  // I am not drawing this all out, you can fill in the pieces
  for (int i = 0; i < 8; i++) {
    if (validMove(ix, iy, ix + i, iy + i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix - i, iy + i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + i, iy - i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix - i, iy - i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
  }
  return false;
}
/**
 * Checks if the queen can move
 * @param b the board to check
 * @param ix the x coord of the queen
 * @param iy the y coord of the queen
 * @return false if there are no valid moves
 */
bool queenMoveCheck(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the queen so
  //  ***
  //  *b*
  //  ***
  // and so on and so forth, it's a queen
  // I am not drawing this all out, you can fill in the pieces
  // just check the bishop and rook moves
  for (int i = 0; i < 8; i++) {
    if (validMove(ix, iy, ix + i, iy + i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix - i, iy + i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + i, iy - i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix - i, iy - i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + i, iy + 0, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix - i, iy + 0, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + 0, iy - i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
    if (validMove(ix, iy, ix + 0, iy + i, b)) {
      // if there are any valid moves then there is not a stalemate
      
      return true;
    }
  }
  return false;
}
/**
 * Checks if the king can move
 * @param b the board to check
 * @param ix the x coord of the king
 * @param iy the y coord of the king
 * @return false if there are no valid moves
 */
bool knightMoveCheck(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the king so
  // ***
  // *k*
  // ***
  if (validMove(ix, iy, ix + 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    
    return true;
  }
  if (validMove(ix, iy, ix + 1, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    return true;
  }
  if (validMove(ix, iy, ix + 0, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    return true;
  }
  if (validMove(ix, iy, ix - 1, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    return true;
  }
  if (validMove(ix, iy, ix + 0, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    return true;
  }
  return false;
}
/**
 * 
 * This is used as a prerequisite to check for stalemate or checkmate
 * 
 * It checks if white is unable to move
 * 
 * @param board the board to check for stalemate
 * @return false if there is a move that can be made, and true if there is no move that can be made
 */
bool noMoveCheckWhite(Piece ** b) {
  Piece ** board = initEmptyBoard();
  boardCopy(board, b);
  updateDanger(board);
  // this is massively inefficient, but it should work
  // but this seriously needs to be optimized
  // I could just check only certain positions that could be valid
  // instead of checking all positions
  // but I am too lazy to implement that now
  for (int ix = 0; ix < 8; ix++) {
    for (int iy = 0; iy < 8; iy++) {
      // check that the piece is white
      if (board[iy][ix].dark != 0) {
        // skip this iteration if we are black
        continue;
      }
      // different checks for different pieces
      if (board[iy][ix].type == KING) {
        // if there is a move, return false because we can move
        if (kingMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == ROOK) {
        if (rookMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == QUEEN) {
        if (queenMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == PAWN) {
        if (pawnMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == KNIGHT) {
        if (knightMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == BISHOP) {
        if (bishopMoveCheck(board, ix, iy)) {
          return false;
        }
      }
    }
  }
  free(board);
  return true;
}
/**
 * 
 * This is used as a prerequisite to check for stalemate or checkmate
 * 
 * It checks if black is unable to move
 * 
 * @param board the board to check for stalemate
 * @return false if there is a move that can be made, and true if there is no move that can be made
 */
bool noMoveCheckBlack(Piece ** b) {
  Piece ** board = initEmptyBoard();
  boardCopy(board, b);
  updateDanger(board);
  // this is massively inefficient, but it should work
  // but this seriously needs to be optimized
  // I could just check only certain positions that could be valid
  // instead of checking all positions
  // but I am too lazy to implement that now
  for (int ix = 0; ix < 8; ix++) {
    for (int iy = 0; iy < 8; iy++) {
      // check that the piece is black
      if (board[iy][ix].dark != 1) {
        // skip this iteration if we are white
        continue;
      }
      // different checks for different pieces
      if (board[iy][ix].type == KING) {
        // if there is a move, return false because we can move
        if (kingMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == ROOK) {
        if (rookMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == QUEEN) {
        if (queenMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == PAWN) {
        if (pawnMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == KNIGHT) {
        if (knightMoveCheck(board, ix, iy)) {
          return false;
        }
      }
      if (board[iy][ix].type == BISHOP) {
        if (bishopMoveCheck(board, ix, iy)) {
          return false;
        }
      }
    }
  }
  free(board);
  return true;
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
  // there is a check here for check, if a move does not get you out of check then it is 
  // not a valid move
  if (piece.dark) { // if black
    // carry out move with duplicate board and see if it puts black in check
    Piece ** duplicateBoard = initEmptyBoard();
    boardCopy(duplicateBoard, board);
    movePiece(initx, initx, finalx, finaly, duplicateBoard);
    // make sure that the danger states are accurate after the move
    updateDanger(duplicateBoard);
    // if this move puts black into check then it is invalid so we return false
    if (blackCheckCheck(duplicateBoard)) {
      // make sure to free memory
      freeBoard(duplicateBoard);
      return false;
    }
    // make sure to free memory
    freeBoard(duplicateBoard);
  } else { // if white
    // carry out move with duplicate board and see if it puts black in check
    Piece ** duplicateBoard = initEmptyBoard();
    boardCopy(duplicateBoard, board);
    movePiece(initx, initx, finalx, finaly, duplicateBoard);
    // make sure that the danger states are accurate after the move
    updateDanger(duplicateBoard);
    // if this move puts black into check then it is invalid so we return false
    if (whiteCheckCheck(duplicateBoard)) {
      // make sure to free memory
      freeBoard(duplicateBoard);
      return false;
    }
    // make sure to free memory
    freeBoard(duplicateBoard);
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
  // something went wrong
  return false;
}