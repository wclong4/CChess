#include "board.h"

/**
 * Starting size for some of the arrays
*/
#define START_SIZE 20
/**
 * Used to double the size of the array
*/
#define DOUBLE 2
/**
 * This initilized a new board with all pieces in their normal position
 * 
 * It has been awhile since I used 2d arrays in C so I referenced this
 * code from stack overflow, https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c
 * 
*/
Piece ** initBoard() {
  Piece * values = malloc(8 * 8 * sizeof(Piece));
  Piece ** board = (Piece **) malloc(sizeof(Piece * ) * 8);

  for (int i = 0; i < 8 ; i++) {
    board[i] = values + i*8;
  }
  // set all values to 0 so that all values are initialized before being used
  for (int i = 0; i < 8 ; i++) {
    for (int j = 0; j < 8 ; j++) {
      board[i][j].type = 0;
      board[i][j].enPassantAble = 0;
      board[i][j].dark = 0;
      board[i][j].hasMoved = 0;
      board[i][j].inDangerWhite = 0;
      board[i][j].inDangerBlack = 0;
    }
  }
  // setting up pawns
  for (int j = 0; j < 8 ; j++) {
    int i = 1;
    board[i][j].type = PAWN;
    board[i][j].dark = true;
  }
  for (int j = 0; j < 8 ; j++) {
    int i = 6;
    board[i][j].type = PAWN;
    board[i][j].dark = false;
  }
  // setting up the rest of the pieces
  // black side
  board[0][0].type = ROOK;
  board[0][0].dark = true;

  board[0][1].type = KNIGHT;
  board[0][1].dark = true;
  
  board[0][2].type = BISHOP;
  board[0][2].dark = true;  

  board[0][3].type = QUEEN;
  board[0][3].dark = true;

  board[0][4].type = KING;
  board[0][4].dark = true;

  board[0][5].type = BISHOP;
  board[0][5].dark = true;  

  board[0][6].type = KNIGHT;
  board[0][6].dark = true;

  board[0][7].type = ROOK;
  board[0][7].dark = true;

  // white side
  board[7][0].type = ROOK;
  board[7][0].dark = false;

  board[7][1].type = KNIGHT;
  board[7][1].dark = false;
  
  board[7][2].type = BISHOP;
  board[7][2].dark = false;  

  board[7][3].type = QUEEN;
  board[7][3].dark = false;

  board[7][4].type = KING;
  board[7][4].dark = false;

  board[7][5].type = BISHOP;
  board[7][5].dark = false;  

  board[7][6].type = KNIGHT;
  board[7][6].dark = false;

  board[7][7].type = ROOK;
  board[7][7].dark = false;

  return board;
}
/**
 * This initilized a new board with no pieces
 * 
 *
 * code from stack overflow, https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c
*/
Piece ** initEmptyBoard() {
  Piece * values = malloc(8 * 8 * sizeof(Piece));
  Piece ** board = (Piece **) malloc(sizeof(Piece * ) * 8);

  for (int i = 0; i < 8 ; i++) {
    board[i] = values + i*8;
  }
  // set all values to 0 so that all values are initialized before being used
  for (int i = 0; i < 8 ; i++) {
    for (int j = 0; j < 8 ; j++) {
      board[i][j].type = 0;
      board[i][j].enPassantAble = 0;
      board[i][j].dark = 0;
      board[i][j].hasMoved = 0;
      board[i][j].inDangerWhite = 0;
      board[i][j].inDangerBlack = 0;

    }
  }
  return board;
}
/**
 * duplicates board state
 * @param src the source
 * @param the destination
 */
void boardCopy(Piece ** dest, Piece ** src) 
{
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      dest[y][x].dark = src[y][x].dark;
      dest[y][x].enPassantAble = src[y][x].enPassantAble;
      dest[y][x].hasMoved = src[y][x].hasMoved;
      dest[y][x].inDangerBlack = src[y][x].inDangerBlack;
      dest[y][x].inDangerWhite = src[y][x].inDangerWhite;
      dest[y][x].type = src[y][x].type;
    }
  }
}
/**
 * Will move a piece, DOES NOT CHECK FOR MOVE VALIDITY!!!
 * Use carefully.
 * @param initx the initial x value
 * @param inity the initial y value
 * @param board the board
 * 
 */
void movePiece(int initx, int inity, int finalx, int finaly, Piece ** board) 
{
  // move piece
  board[finaly][finalx] = board[inity][initx];
  // set initial position to empty/all zeros
  board[inity][initx].dark = 0;
  board[inity][initx].enPassantAble = 0;
  board[inity][initx].hasMoved = 0;
  board[inity][initx].inDangerBlack = 0;
  board[inity][initx].inDangerWhite = 0;
  board[inity][initx].type = 0;
}
/**
 * Destroys the board
 * 
 * I referenced this because the way I initialized this was based
 * on this. https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c
 */
void freeBoard(Piece ** board)
{
    free(*board);
    free(board);
}
/**
 * This prints out the board
*/
void printBoard(Piece ** board) {
  // y is vertical x is horizontal
  for (int y = 0; y < 10 ; y++) {
    for (int x = 0; x < 10 ; x++) {
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        char type = board[y - 1][x - 1].type;
        bool dark = board[y - 1][x - 1].dark;
        if (type != 0 || dark != 0) {
          printf("%c%d ", type, dark);
        } else {
          printf("0  ");
        }
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        printf("%d ", 9 - y);
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        printf("%c  ", x + 'a' - 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
/**
 * This prints out the board, from the perspective of black
*/
void printBoardBlack(Piece ** board) {
  // y is horizontal x is vertical
  for (int y = 9; y >= 0 ; y--) {
    for (int x = 0; x < 10 ; x++) {
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        char type = board[y - 1][x - 1].type;
        bool dark = board[y - 1][x - 1].dark;
        if (type != 0 || dark != 0) {
          printf("%c%d ", type, dark);
        } else {
          printf("0  ");
        }
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        printf("%d ", 9 - y);
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        printf("%c  ", x + 'a' - 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
/**
 * This creates a string version of the board
*/
char * toStringBoard(Piece ** board) {
    // Allocate a string with a small, initial capacity.
    int capacity = START_SIZE;
    char * buffer = malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        // Handle allocation failure
        return NULL;
    }
    // Initialize the buffer to avoid garbage values.
    memset(buffer, 0, capacity * sizeof(char));
    int len = 0;
    // y is vertical, x is horizontal
    for (int y = 0; y < 10 ; y++) {
      for (int x = 0; x < 10 ; x++) {
        // Ensure there is enough space for new characters and the null terminator.
        if (len + 4 >= capacity) { // +4 for 3 characters and a null terminator
          capacity *= DOUBLE;
          char * tempbuffer = realloc(buffer, capacity * sizeof(char));
          if (tempbuffer == NULL) {
            // Handle reallocation failure
            free(buffer);
            return NULL;
          }
          buffer = tempbuffer;
        }
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        char type = board[y - 1][x - 1].type;
        bool dark = board[y - 1][x - 1].dark;
        if (type != 0 || dark != 0) {
          buffer[len++] = type;
          buffer[len++] = dark + '0';
          buffer[len++] = ' ';
        } else {
          buffer[len++] = '0';
          buffer[len++] = ' ';
          buffer[len++] = ' ';
        }
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        buffer[len++] = 9 - y + '0';
        buffer[len++] = ' ';
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        buffer[len++] = x + 'a' - 1;
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      } else {
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      }
    }
    buffer[len] = '\n';
    len++;
  }
  buffer[len] = '\0';
  return buffer;
}
/**
 * This uses array coordinates as coordinates instead of 1-8 and a-h
*/
void debugPrintBoard(Piece ** board) {
  // y is horizontal x is vertical
  for (int y = 9; y >= 0 ; y--) {
    for (int x = 0; x < 10 ; x++) {
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        char type = board[y - 1][x - 1].type;
        bool dark = board[y - 1][x - 1].dark;
        if (type != 0 || dark != 0) {
          printf("%c%d ", type, dark);
        } else {
          printf("0  ");
        }
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        printf("%d ", y - 1);
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        printf("%d  ", x - 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void whiteDangerPrintBoard(Piece ** board) {
  // y is horizontal x is vertical
  for (int y = 9; y >= 0 ; y--) {
    for (int x = 0; x < 10 ; x++) {
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        bool wDanger = board[y - 1][x - 1].inDangerWhite;
        printf("%d  ", wDanger);
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        printf("%d ", y - 1);
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        printf("%d  ", x - 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
void blackDangerPrintBoard(Piece ** board) {
  // y is horizontal x is vertical
  for (int y = 9; y >= 0 ; y--) {
    for (int x = 0; x < 10 ; x++) {
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        bool wDanger = board[y - 1][x - 1].inDangerBlack;
        printf("%d  ", wDanger);
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        printf("%d ", y - 1);
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        printf("%d  ", x - 1);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
/**
 * This creates a string version of the board showing white danger states
*/
char * whiteDangerToString(Piece ** board) {
    // Allocate a string with a small, initial capacity.
    int capacity = START_SIZE;
    char * buffer = malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        // Handle allocation failure
        return NULL;
    }
    // Initialize the buffer to avoid garbage values.
    memset(buffer, 0, capacity * sizeof(char));
    int len = 0;
    // y is vertical, x is horizontal
    for (int y = 9; y >= 0 ; y--) {
      for (int x = 0; x < 10 ; x++) {
      // Ensure there is enough space for new characters and the null terminator.
      if (len + 4 >= capacity) { // +4 for 3 characters and a null terminator
        capacity *= DOUBLE;
        char * tempbuffer = realloc(buffer, capacity * sizeof(char));
        if (tempbuffer == NULL) {
          // Handle reallocation failure
          free(buffer);
          return NULL;
        }
        buffer = tempbuffer;
      }
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        bool wDanger = board[y - 1][x - 1].inDangerWhite;
        buffer[len++] = wDanger + '0';
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        buffer[len++] = y - 1 + '0';
        buffer[len++] = ' ';
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        buffer[len++] = x + '0' - 1;
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      } else {
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      }
    }
    buffer[len] = '\n';
    len++;
  }
  buffer[len] = '\0';
  return buffer;
}
/**
 * This creates a string version of the board showing black danger states
*/
char * blackDangerToString(Piece ** board) {
    // Allocate a string with a small, initial capacity.
    int capacity = START_SIZE;
    char * buffer = malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        // Handle allocation failure
        return NULL;
    }
    // Initialize the buffer to avoid garbage values.
    memset(buffer, 0, capacity * sizeof(char));
    int len = 0;
    // y is vertical, x is horizontal
    for (int y = 9; y >= 0 ; y--) {
      for (int x = 0; x < 10 ; x++) {
      // Ensure there is enough space for new characters and the null terminator.
      if (len + 4 >= capacity) { // +4 for 3 characters and a null terminator
        capacity *= DOUBLE;
        char * tempbuffer = realloc(buffer, capacity * sizeof(char));
        if (tempbuffer == NULL) {
          // Handle reallocation failure
          free(buffer);
          return NULL;
        }
        buffer = tempbuffer;
      }
      if (y < 9 && x < 9 && x > 0 && y > 0) {
        bool wDanger = board[y - 1][x - 1].inDangerBlack;
        buffer[len++] = wDanger + '0';
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      } else if ((x == 0 || x == 9 ) && (y < 9 && y > 0)){
        buffer[len++] = y - 1 + '0';
        buffer[len++] = ' ';
      } else if ((y == 0 || y == 9 ) && (x < 9 && x > 0)) {
        buffer[len++] = x + '0' - 1;
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      } else {
        buffer[len++] = ' ';
        buffer[len++] = ' ';
      }
    }
    buffer[len] = '\n';
    len++;
  }
  buffer[len] = '\0';
  return buffer;
}
