// got this from https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-4-alpha-beta-pruning/
// then changed it for what I needed
// Alpha-Beta Pruning
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

// the max number of moves a piece can make is a queen which is not blocked by anything which can move in 32 ways
#define MAX_MOVES 32
// Initial values of
// Alpha and Beta
const int MAX = 1000;
const int MIN = -1000;
 
// Returns optimal value for
// current player(Initially called
// for root and maximizer)
int minimax(int depth, int nodeIndex,
            bool maximizingPlayer,
            int values[], int alpha, 
            int beta)
{
     
    // Terminating condition. i.e 
    // leaf node is reached
    if (depth == 4)
        return values[nodeIndex];
 
    if (maximizingPlayer)
    {
        int best = MIN;
 
        // Recur for left and 
        // right children
        for (int i = 0; i < 32; i++)
        {
             
            int val = minimax(depth + 1, nodeIndex * 2 + i, 
                              false, values, alpha, beta);
            if (val > best) {
              best = val;
            }
            
            if (best > alpha) {
              alpha = best;
            }
 
            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
    else
    {
        int best = MAX;
 
        // Recur for left and
        // right children
        for (int i = 0; i < 32; i++)
        {
            int val = minimax(depth + 1, nodeIndex * 2 + i,
                              true, values, alpha, beta);
            if (val < best) {
              best = val;
            }
            
            if (best < beta) {
              beta = best;
            }
            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
}
/**
 * Creates a board array with everything set to NULL
 */
Piece *** initBoardArray() {
  // literally cannot have more than this many moves
  Piece ** boards[MAX_MOVES];
  for (int i = 0; i < MAX_MOVES; i++) {
    boards[i] = NULL;
  }
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
Piece *** knightMoveBoardState(Piece ** b, int ix, int iy) {
  // check all the reasonable moves for the king so
  // ***
  // *k*
  // ***
  Piece ** boardArray[MAX_MOVES] = initBoardArray();
  int i = 0;
  if (validMove(ix, iy, ix + 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix + 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix - 1, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix - 1, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix + 1, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix + 0, iy + 1, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix - 1, iy + 0, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  if (validMove(ix, iy, ix + 0, iy - 1, b)) {
    // if there are any valid moves then there is not a stalemate
    Piece ** newBoard = initBoard();
    boardCopy(newBoard, b);
    movePiece(ix, iy, ix + 1, iy + 1, newBoard);
    boardArray[i] = newBoard;
    i++;
  }
  return boardArray;
}

int playBlack(Piece ** board, int array) {
  int moves = 0;
  for (int iy = 0; iy < 64; iy++) {
    for (int ix = 0; ix < 64; ix++) {
      bool black = board[iy][ix].dark == 1;
      bool valid = validMove(ix, iy, fx, fy, board);
      if (black && valid) { // also check that the piece moved is white
        array[moves] = board[ix];
        updateDanger(board);
        break;
      } else {
        printf("%s\n", "Invalid move");
      }
    }
  }
}

// Driver Code
int main()
{
    int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
    printf("The optimal value is : %d", minimax(0, 0, true, values, MIN, MAX));
    return 0;
}