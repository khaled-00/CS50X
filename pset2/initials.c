/**
 * initials.c
 * By khaled
 * 
 * Takes a name from user,
 * And displays the short name
 * 
 * Usage: ./initials
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Takes name from user
    string name    = GetString();
    // Takes the result
    string newName = malloc((strlen(name) + 1) * sizeof(char)); 
    // The key of "newName" array 
    int num        = 1;
    // Save the first character 
    newName[0]     = toupper(name[0]);
    
    // the whole name
    for(int n = 0; n < strlen(name); n++)
    {
        // Is it a space
        if(isspace(name[n]))
        {
            // Save the character that is after spaces
            newName[num] = toupper(name[n + 1]);
            num++;
        }
    }
    
    // Print the result
    printf("%s\n", newName);
}