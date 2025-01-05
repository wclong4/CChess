# Chess
An implementation of chess in C

There are five c files that are fully implemented and tested, board.c, driver.c, piece.c, danger.c, and rules.c.  These names are pretty self explanatory, board handles the board, driver handles the driver, piece handles the pieces, danger handles checking the danger states of the board (which squares are dangerous for which player), and rules handles checking if moves are valid and making sure that moves are carried out correctly.  There are also tests for these files and a makefile you can use to make a runnable program.  I have done some preliminary work on the AI for the game, but it doesn't work yet.  

If you want to run this program go to where the program's files are located, and type make and press enter in the terminal.  Then type ./driver and press enter and you should be able to play chess against yourself or another player on the same terminal.  If you want to quit press ctrl^c.

