#include "piece.h"

/**
 * This class handles information dealing with pieces and rules dealing with pieces
 * @author Warren Long (wclong4)
*/
/**
 * This checks if a move is valid by first checking if it has valid coordinates.
 * These coordinates must be between 0 and 7 because the board is 8 x 8.  
 * 
 * After it is done with bounds checking it does individual checks for the piece.
 * 
 * @param piece the piece to check
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
*/
bool validMove(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {
  Piece piece = thing[initx][inity];
  // if someone tries to move an empty space then return false
  if (piece.type == 0) {
    return false;
  }
  // too small
  if (initx < 0 || inity < 0 || finalx < 0 || finaly < 0 ) {
    return false;
  }
  // too big
  if (initx < 7 || inity < 7 || finalx < 7 || finaly < 7 ) {
    return false;
  }
  
  // specific checks for different pieces
  // these delegate their responsibilities to other methods in this class
  if (piece.type == KING) {
    
  }
  if (piece.type == ROOK) {
    
  }
  if (piece.type == QUEEN) {
    
  }
  if (piece.type == PAWN) {
    
  }
  if (piece.type == KNIGHT) {
    
  }
  if (piece.type == BISHOP) {
    
  }
}
bool kingCheck(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {

}
bool rookCheck(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {

}
bool queenCheck(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {

}
bool pawnCheck(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {

}
bool knightCheck(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {

}
bool bishopCheck(int initx, int inity, int finalx, int finaly, Piece thing[8][8]) {

}
