/**
 * water.c
 * BY khaled
 * 
 * Calculates the input of float,
 * and displays the result
 * 
 * Usage: ./water
 */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    
    // Get the input
    float a;
    a = GetInt();
    
    // Make the process 
    a = (128 * ((a / 2) + a)) / 16;   
    
    // Show the result 
    printf("bottles: %.5f \n", a);
    
}