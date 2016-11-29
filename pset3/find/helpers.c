/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Set variabels
    int start, middel, end;
    start  = 0;
    end    = n;
    middel = (start + end) / 2;
    
    while(start <= end)
    {
        // Is it found 
        if(values[middel] == value)
        {
            return true;
        }
        // If number higher 
        else if(values[middel] > value)
        {
            end    = middel - 1;
        }
        // If number lower
        else if(values[middel] < value)
        {
            start  = middel + 1;
        } 
        
        // Make the middel point
        middel = (start + end) / 2;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Counter
    int count = 0;
    
    for(int i = 0; i < n; i++)
    {
        // Recount from 0
        count = 0;
        
        for(int j = 0; j < n; j++)
        {
            // Is it the last element 
            if((j + 1) == n)
            {
                break;
            }
            else
            {
                // Does the first element bigger than the second
                if(values[j] > values[j + 1])
                {
                    // Change those elements
                    values[j]       = values[j] ^ values[j + 1];
                    values[j + 1]   = values[j] ^ values[j + 1];
                    values[j]       = values[j] ^ values[j + 1];
                    // Count it
                    count++;
                }   
            }
        }
        
        // It's sorted
        if( count == 0)
        {
            break;
        }
    }
}