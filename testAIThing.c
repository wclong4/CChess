// C++ program to demonstrate
// working of Alpha-Beta Pruning
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

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
        for (int i = 0; i < 2; i++)
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
        for (int i = 0; i < 2; i++)
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
 
// Driver Code
int main()
{
    int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
    printf("The optimal value is : %d", minimax(0, 0, true, values, MIN, MAX));
    return 0;
}