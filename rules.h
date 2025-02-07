#include "danger.h"

/**
 * This checks if a move is valid by first checking if it has valid coordinates.
 * These coordinates must be between 0 and 7 because the board is 8 x 8.  
 * 
 * After it is done with bounds checking it does individual checks for the piece.
 * 
 * @param initx the initial x position
 * @param inity the initial y position
 * @param finalx the final x position
 * @param finaly the final y position
 * @param board the chess board
*/
bool validMove(int initx, int inity, int finalx, int finaly, Piece ** board);
/**
 * Checks if the white king is in check or not
 * @param board the board to check for check
 */
bool whiteCheckCheck(Piece ** board);
/**
 * Checks if the black king is in check or not
 * @param board the board to check for check
 */
bool blackCheckCheck(Piece ** board);
/**
 * 
 * This is used as a prerequisite to check for stalemate or checkmate
 * 
 * It checks if white is unable to move
 * 
 * @param board the board to check for stalemate
 */
bool noMoveCheckWhite(Piece ** board);
/**
 * 
 * This is used as a prerequisite to check for stalemate or checkmate
 * 
 * It checks if white is unable to move
 * 
 * @param board the board to check for stalemate
 */
bool noMoveCheckBlack(Piece ** board);
