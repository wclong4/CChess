// got this from https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-4-alpha-beta-pruning/
// then changed it for what I needed
// Alpha-Beta Pruning
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "piece.h"

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
    if (depth == 3)
        return values[nodeIndex];
 
    if (maximizingPlayer)
    {
        int best = MIN;
 
        // Recur for left and 
        // right children
        for (int i = 0; i < 64; i++)
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
        for (int i = 0; i < 64; i++)
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

int playBlack(Piece ** board, int array) {
  int moves = 0;
  for (int iy = 0; iy < 64; iy++) {
    for (int ix = 0; ix < 64; ix++) {
      for (int fy = 0; fy < 64; fy++) {
        for (int fx = 0; fx < 64; fx++) {
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
  }
}

// Driver Code
int main()
{
    int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
    printf("The optimal value is : %d", minimax(0, 0, true, values, MIN, MAX));
    return 0;
}