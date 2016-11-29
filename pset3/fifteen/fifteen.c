/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // Biggest number in the array
    int n = (d * d);
    
    // Rows
    for(int q = 0; q < d; q++)
    {
        // Columns
        for(int j = 0; j < d; j++)
        {
            n--;
            // For even numbers
            if(d % 2 == 0)
            {
                // Swap 2 and 1, insert the rest as they are
                switch(n)
                {
                    case 1:
                        board[q][j] = 2;
                        break;
                    case 2:  
                        board[q][j] = 1;
                        break;
                    default:
                        board[q][j] = n;
                }
            }
            else 
            {
                // For odd numbers
                board[q][j] = n; 
            }
        }    
    }    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // Rows 
    for(int q = 0; q < d; q++)
    {   
        // Columns 
        for(int j = 0; j < d; j++)
        {  
            // Character " _ "
            if (board[q][j] == 0)
            {
                printf(" _ ");
            }
            else 
            {
                // Print all of numbers
                if(board[q][j] < 10)
                {
                    printf(" %i ", board[q][j]);
                } 
                else
                {
                    printf("%i ", board[q][j]);
                }
            }
        }
        // Space
        printf("\n");
    }    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Variables
    int a = 0, sign = 0, ti = 0, col = 0, col2 = 0, row = 0, row2 = 0, temp = 0;

    // Rows
    for(int q = 0; q < d; q++)
    {
        // Columns
        for(int j = 0; j < d; j++)
        {
            a++;
            // The blunk tile
            if(board[q][j] == 0) 
            {
                // Get keys this array
                col  = q;
                row  = j;
                // How many turns it was takeing
                sign = a;
            }
            // The tile that you entered
            if(board[q][j] == tile) 
            {
                // Get keys this array
                col2 = q;
                row2 = j;
                // How many turns it was takeing
                ti  = a;
            }
        }    
    }
    
    // Is it legal to move 
    if((sign + d) == ti || (sign - d) == ti || (sign + 1) == ti || (sign - 1) == ti )
    {
        // If it's not on the same row
        if(((sign + 1) == ti || (sign - 1) == ti) && col2 != col)
        {
            return false;
        } 
        else 
        {
            // Do the swap
            temp              = board[col][row];
            board[col][row]   = board[col2][row2];
            board[col2][row2] = temp;
        
            return true; 
        }
    }
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int var = 1;
    // Rows
    for(int q = 0; q < d; q++)
    {
        //Columns
        for(int j = 0; j < d - 1; j++)
        {
            // If it's the last element
            if(board[d-1][d-1] == board[q][var])
            {
                //  If it's not right
                if(board[q][j] < board[q][var])
                {
                    return false;
                } 
                var++;
            }
            else 
            {
                // If it's not right
                if((board[q][j] + 1) != board[q][var])
                {
                    return false;
                } 
                var++;
            }
        }
        
        // Back the value to 1
        var = 1;
    }
    
    return true;
}