/**
 * mario.c
 * BY khaled
 * 
 * Calculates the addition of integers,
 * and makes a Mario's pyramid and displays it
 * 
 * Usage: ./mario
 */

#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    // Validation the inputs 
    int hights;
    
    printf("  Enter an integer number ...");
    
    hights = GetInt();
    
    while (hights < 0 || hights > 23)
    {
        printf("\n!! must be between 2 and 23...");
        hights = GetInt(); 
    };

    // Set variables
    int space   =  hights - 2,
        dashes  =  2;
    
    // Makeing all of lines
    for(int i = 0; i < hights; i++)
    {
        if(i != hights)
        {
            // Makes spaces for one line
            for(int a = space; a >= 0; a--)
            {
                printf(" ");
            }
        }
        
        // Makes dashes for one line
        for(int c = 0; c < dashes; c++) 
        {
            printf("#");
        }
        
        // Makes a space after end of the line
        printf("\n");
        
        // Less spaces and more dashes
        space --;
        dashes ++;
    }
} 
