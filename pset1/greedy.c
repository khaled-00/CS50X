/**
 * greedy.c
 * BY khaled
 * 
 * Calculates the addition of mony,
 * and converts money to Coins and displays it
 * 
 * Usage: ./greedy
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    
    // Validation the inputs 
    float vlue_of_coins = 0;
    do 
    {
        printf("How much change is owed? \n");
        vlue_of_coins = GetFloat();
    } 
    while(vlue_of_coins < 0);
    
    // Set variables
    int doing = 0, turn = 0, intInput = round(vlue_of_coins * 100);
    
    /** 
     * While there more coins,
     * Do that
     */
    while (intInput > 0)
    {
        // The value of coins
        if (intInput >= 25) 
        {
            doing = 25;
        } 
        else if (intInput >= 10)
        {
            doing = 10;
        }
        else if (intInput >= 5)
        {
            doing = 5;
        }
        else if (intInput < 5)
        {
            doing = 1;
        }
        
        // Make the change
        intInput -= doing;
        turn ++;
    }
    
    // Print the result
    printf("%i\n", turn);
}  
    