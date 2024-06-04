# Chess
An implementation of chess in C

I don't really know how I want to approach this.  I have not done a project in C for more than a month.  My first idea is to have a struct for pieces with all the necessary information like color, and type.  There will be a 2D array that represents the board, and text files will be used to save and read in info about the board state.  Different pieces will be represented as different letters when saved or loaded in.  

A player will be allowed to enter any move they want and if that move is not valid the system will output that it is not valid and then request new input.  The chess board will be represented in the command line and the moves will be inputted using a modified version of algebraic notation for chess where each move is designated by a piece to move and a destination (like a2 to a3).  

There are four separate c files, board.c, driver.c, piece.c, and rules.c.  These names are pretty self explanatory, board handles the board, driver handles the driver, piece handles the pieces, and rules handles checking if moves are valid and making sure that moves are carried out correctly.  

