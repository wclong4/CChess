/**
 * This is used to update the danger states of pieces on the board
 * @author Warren Long (wclong4)
 */
#include "danger.h"

static void kingDanger(int initx, int inity, Piece ** board) {
  Piece * king = &board[inity][initx];
  // if the king is dark
  if (king->dark) {
    // have to check bounds, I am checking both ways all the time because I 
    // wanted to just copy paste the bounds checks and have it work
    // it would be slightly more efficient if changed to do more specific bounds checks
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx <= 7 && initx >= 0 ) {
      board[inity + 1][initx].inDangerWhite = 1;
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity + 1][initx + 1].inDangerWhite = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx <= 7 && initx >= 0 ) {
      board[inity - 1][initx].inDangerWhite = 1;
    }
    if (inity <= 7 && inity >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity][initx + 1].inDangerWhite = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity - 1][initx - 1].inDangerWhite = 1;
    }
    if (inity <= 7 && inity >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity][initx - 1].inDangerWhite = 1;
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity + 1][initx - 1].inDangerWhite = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity - 1][initx + 1].inDangerWhite = 1;
    }
  } else { // otherwise
    // have to check bounds, I am checking both ways all the time because I 
    // wanted to just copy paste the bounds checks and have it work
    // it would be slightly more efficient if changed to do more specific bounds checks
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx <= 7 && initx >= 0 ) {
      board[inity + 1][initx].inDangerBlack = 1;
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity + 1][initx + 1].inDangerBlack = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx <= 7 && initx >= 0 ) {
      board[inity - 1][initx].inDangerBlack = 1;
    }
    if (inity <= 7 && inity >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity][initx + 1].inDangerBlack = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity - 1][initx - 1].inDangerBlack = 1;
    }
    if (inity <= 7 && inity >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity][initx - 1].inDangerBlack = 1;
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity + 1][initx - 1].inDangerBlack = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity - 1][initx + 1].inDangerBlack = 1;
    }
  }
}

static void rookDanger(int initx, int inity, Piece ** board) {
 
  // for all of these we have to start i one off of 
  // where the piece is so it does not collision check itself
  // this should not cause an out of bounds issue because
  // it will only do +1 or -1 when a finalx or finaly are at least +1 or -1 bigger or smaller than 
  // the initial value, but not out of bounds, cuz the loop checks for values > 7
  bool rColor = board[inity][initx].dark;
  // up 
  for (int i = inity + 1; i <= 7; i++) {
    // [y][x]
    char pieceType = board[i][initx].type;
    if (pieceType == 0) { // if something is there we end the loop
    // we update danger states along the way
      if (rColor) { // if black
        board[i][initx].inDangerWhite = 1; // update white danger
      } else {
        board[i][initx].inDangerBlack = 1; // else update black danger
      }
    } else { // end the loop
      if (rColor) { // if black
        // then update danger
          board[i][initx].inDangerWhite = 1; // update white danger
        
      } else {
        // then update danger
          board[i][initx].inDangerBlack = 1; // update black danger

      }
      break;
    }
  }
  // all other directions, though I am too lazy to label each for loop with each direction

  for (int i = initx + 1; i <= 7; i++) {
    // [y][x]
    char pieceType = board[inity][i].type;
    if (pieceType == 0) { // if something is there we end the loop
    // we update danger states along the way
      if (rColor) { // if black
        board[inity][i].inDangerWhite = 1; // update white danger
      } else {
        board[inity][i].inDangerBlack = 1; // else update black danger
      }
    } else { // end the loop
      if (rColor) { // if black
        // then update danger
          board[inity][i].inDangerWhite = 1; // update white danger
        
      } else {
        // then update danger
          board[inity][i].inDangerBlack = 1; // update black danger

      }
      break;
    }
  }
  for (int i = inity - 1; i >= 0; i--) {
    // [y][x]
    char pieceType = board[i][initx].type;
    if (pieceType == 0) { // if something is there we end the loop
    // we update danger states along the way
      if (rColor) { // if black
        board[i][initx].inDangerWhite = 1; // update white danger
      } else {
        board[i][initx].inDangerBlack = 1; // else update black danger
      }
    } else { // end the loop
      if (rColor) { // if black
        // then update danger
          board[i][initx].inDangerWhite = 1; // update white danger
        
      } else {
        // then update danger
          board[i][initx].inDangerBlack = 1; // update black danger

      }
      break;
    }
  }
  for (int i = initx - 1; i >= 0; i--) {
    // [y][x]
    char pieceType = board[inity][i].type;
    if (pieceType == 0) { // if something is there we end the loop
    // we update danger states along the way
      if (rColor) { // if black
        board[inity][i].inDangerWhite = 1; // update white danger
      } else {
        board[inity][i].inDangerBlack = 1; // else update black danger
      }
    } else { // end the loop
      if (rColor) { // if black
        // then update danger
          board[inity][i].inDangerWhite = 1; // update white danger
        
      } else {
        // then update danger
          board[inity][i].inDangerBlack = 1; // update black danger

      }
      break;
    }
  }
}
/**
 * Clears the board danger states
 * @param board the board we are clearing the danger states of
 */
void clearDanger(Piece ** board) {
  for (int y = 0; y < 8 ; y++) {
    for (int x = 0; x < 8 ; x++) {
      board[y][x].inDangerBlack = 0;
      board[y][x].inDangerWhite = 0;
    }
  }
}
/**
 * checks danger for the pawn
 * @param initx the initial x position
 * @param inity the initial y position
 * @param board the chess board
*/
static void pawnDanger(int initx, int inity, Piece ** board) {
  // this one should be pretty simple compared to the rules implementation of pawn stuff
  // I am not going to deal with en passant at all because it only affects pawns and danger states are
  // implemented to check for check and checkmate, so the only real danger is danger that can affect the king
  // thus, we only have to deal with the normal pawn moveset like this
  // can take here   NO   can take here
  //                 p
  Piece pawn = board[inity][initx];
  if (pawn.dark) { // if is dark
    // need to check the bounds
    if (inity + 1 < 8 && initx + 1 < 8) {
      board[inity + 1][initx + 1].inDangerWhite = 1;
    }
    if (inity + 1 < 8 && initx - 1 > 0) {
      board[inity + 1][initx - 1].inDangerWhite = 1;
    }
  } else { // if light
    if (inity - 1 > 0 && initx + 1 < 8) {
      board[inity - 1][initx + 1].inDangerBlack = 1;
    }
    if (inity - 1 > 0 && initx - 1 > 0) {
      board[inity - 1][initx - 1].inDangerBlack = 1;
    }
  }
}
/**
 * checks danger for the knight
 * @param initx the initial x position
 * @param inity the initial y position
 *
 * @param board the chess board
*/
static void knightDanger(int initx, int inity, Piece ** board) {
  // this is actually pretty simple because there is no collision detection on different colored pieces
  // it does need collision detection for pieces of the same color
  // ++
  Piece * knight = &board[inity][initx];
  if (knight->dark) { // if dark
    if (inity + 2 <= 7 && inity + 2 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity + 2][initx + 1].inDangerWhite = 1; // set white danger
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx + 2 <= 7 && initx + 2 >= 0 ) {
      board[inity + 1][initx + 2].inDangerWhite = 1;
    }
    if (inity - 2 <= 7 && inity - 2 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity - 2][initx + 1].inDangerWhite = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx + 2 <= 7 && initx + 2 >= 0 ) {
      board[inity - 1][initx + 2].inDangerWhite = 1;
    }
    if (inity + 2 <= 7 && inity + 2 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity + 2][initx - 1].inDangerWhite = 1;
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx - 2 <= 7 && initx - 2 >= 0 ) {
      board[inity + 1][initx - 2].inDangerWhite = 1;
    }
    if (inity - 2 <= 7 && inity - 2 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity - 2][initx - 1].inDangerWhite = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx - 2 <= 7 && initx - 2 >= 0 ) {
      board[inity - 1][initx - 2].inDangerWhite = 1;
    }

  } else { // if light
    if (inity + 2 <= 7 && inity + 2 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity + 2][initx + 1].inDangerBlack = 1; // set black danger
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx + 2 <= 7 && initx + 2 >= 0 ) {
      board[inity + 1][initx + 2].inDangerBlack = 1;
    }
    if (inity - 2 <= 7 && inity - 2 >= 0 && initx + 1 <= 7 && initx + 1 >= 0 ) {
      board[inity - 2][initx + 1].inDangerBlack = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx + 2 <= 7 && initx + 2 >= 0 ) {
      board[inity - 1][initx + 2].inDangerBlack = 1;
    }
    if (inity + 2 <= 7 && inity + 2 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity + 2][initx - 1].inDangerBlack = 1;
    }
    if (inity + 1 <= 7 && inity + 1 >= 0 && initx - 2 <= 7 && initx - 2 >= 0 ) {
      board[inity + 1][initx - 2].inDangerBlack = 1;
    }
    if (inity - 2 <= 7 && inity - 2 >= 0 && initx - 1 <= 7 && initx - 1 >= 0 ) {
      board[inity - 2][initx - 1].inDangerBlack = 1;
    }
    if (inity - 1 <= 7 && inity - 1 >= 0 && initx - 2 <= 7 && initx - 2 >= 0 ) {
      board[inity - 1][initx - 2].inDangerBlack = 1;
    }
  }
}
/**
 * checks danger for the bishop
 * @param initx the initial x position
 * @param inity the initial y position
 *
 * @param board the chess board
*/
static void bishopDanger(int initx, int inity, Piece ** board) {
  bool bColor = board[inity][initx].dark;
      // check that nothing collides with the bishop when it moves
    // up and right ++
    int x = initx + 1;
    for (int y = inity + 1; y <= 7 && x <= 7; y++) {
      // [y][x]
      if (bColor) { // if dark
        board[y][x].inDangerWhite = 1;
      } else { // if light
        board[y][x].inDangerBlack = 1;
      }
      if (board[y][x].type != 0) { // break out of loop if there is a piece there
        break; // because it blocks line of sight
      }
      x++;
    }
    // +-
    x = initx + 1;
    for (int y = inity - 1; y >= 0 && x <= 7; y--) {
      // [y][x]
      if (bColor) { // if dark
        board[y][x].inDangerWhite = 1;
      } else { // if light
        board[y][x].inDangerBlack = 1;
      }
      if (board[y][x].type != 0) { // break out of loop if there is a piece there
        break; // because it blocks line of sight
      }
      x++;
    }
    // -+
    x = initx - 1;
    for (int y = inity + 1; y <= 7 && x >= 0; y++) {
      // [y][x]
      if (bColor) { // if dark
        board[y][x].inDangerWhite = 1;
      } else { // if light
        board[y][x].inDangerBlack = 1;
      }
      if (board[y][x].type != 0) { // break out of loop if there is a piece there
        break; // because it blocks line of sight
      }
      x--;
    }
    // --
    x = initx - 1;
    for (int y = inity - 1; y >= 0 && x >= 0; y--) {
      // [y][x]
      if (bColor) { // if dark
        board[y][x].inDangerWhite = 1;
      } else { // if light
        board[y][x].inDangerBlack = 1;
      }
      if (board[y][x].type != 0) { // break out of loop if there is a piece there
        break; // because it blocks line of sight
      }
      x--;
    }

}
/**
 * checks danger for the queen
 * @param initx the initial x position
 * @param inity the initial y position
 *
 * @param board the chess board
*/
static void queenDanger(int initx, int inity, Piece ** board) {
  // just a combination of rook and bishop danger
  rookDanger(initx, inity, board);
  bishopDanger(initx, inity, board);
}

/**
 * Updates the danger states of the board using the given piece at
 * x, y on the board.
 * @param initx the x value of the piece we are using to update danger states
 * @param inity the y value of the piece we are using to update danger states
 * @param board the board for which we are updating danger states
 */
void dangerCast(int initx, int inity, Piece ** board) {
  if (initx < 0 || initx > 7 || inity < 0 || inity > 7) {
    return; // end the danger cast if there are invalid parameters
  }
  Piece piece = board[inity][initx];
  // specific checks for different pieces
  // these delegate their responsibilities to other methods in this class
  if (piece.type == KING) {
    kingDanger(initx, inity, board);
  }
  if (piece.type == ROOK) {
    rookDanger(initx, inity, board);
  }
  if (piece.type == QUEEN) {
    queenDanger(initx, inity, board);
  }
  if (piece.type == PAWN) {
    pawnDanger(initx, inity, board);
  }
  if (piece.type == KNIGHT) {
    knightDanger(initx, inity, board);
  }
  if (piece.type == BISHOP) {
    bishopDanger(initx, inity, board);
  }
}
/**
 * This updates the danger states of the board
 * @param board the board to update 
 */
void updateDanger(Piece ** board) {
  clearDanger(board);
  for (int y = 0; y < 8 ; y++) {
    for (int x = 0; x < 8 ; x++) {
      dangerCast(x, y, board);
    }
  }
}

