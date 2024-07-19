/**
 * This is used to make the functions in danger.c visible to other programs
 * 
 * @author Warren Long (wclong4)
 */
#include "board.h"
/**
 * Clears the board danger states
 */
void clearDanger(Piece ** board);
/**
 * Updates the danger states of the board using the given piece at
 * x, y on the board.
 * @param initx the x value of the piece we are using to update danger states
 * @param inity the y value of the piece we are using to update danger states
 * @param board the board for which we are updating danger states
 */
void dangerCast(int initx, int inity, Piece ** board);
