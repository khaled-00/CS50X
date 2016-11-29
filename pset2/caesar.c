/**
 * caesar.c
 * BY khaled
 * 
 * Calculates the addition of characters depends on an integer,
 * and displays the resultant characters
 * 
 * Usage: ./caesar number 
 */
 
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main (int arg, string argy[])
{
    
    if(arg > 1 && atoi(argy[1]) > 0)
    {
        // The string that inputted
        string caesar = GetString(); 
        
        // The number of characters that entered
        int arguments = strlen(caesar);
        
        // The number of arguments that entered
        int caesarNum = atoi(argy[1]); 
        
        // A variable will get the keys of characters that will be in ASCII array
        int updo[arguments + 1];     
        for (int n = 0; n <= arguments; n++) 
        {
            updo[n] = 999999999;
        }
        
        // A variable will get the results 
        string done[arguments + 1];
        for(int n = 0; n < arguments; n++)
        {
            done[n] = malloc(sizeof(char));
        }
        
        // The arrays of ASCII table
        int poinTextUp[25]; 
        int poinTextLw[25]; 
        for (int key = 0, valueUp = 65, valueLw = 97; key < 26; valueUp++, valueLw++, key++)
        {
            poinTextUp[key] = valueUp; 
            poinTextLw[key] = valueLw; 
        }


        /** 
         * Do the changes,
         * And put it into "updo" array
         */
        for(int x = 0; x < arguments; x++) 
        {
            // change the characters
            for(int z = 0; z < 26; z++)
            {
                // Upper case characters 
                if (isupper(caesar[x])) 
                {
                    if(caesar[x] == poinTextUp[z]) 
                    {
                        updo[x] = (z + caesarNum)%26;
                        break;
                    }
                }
                // Lower case characters
                else if (islower(caesar[x])) 
                {
                    if(caesar[x] == poinTextLw[z]) 
                    {
                        updo[x] = (z + caesarNum)%26;
                        break;
                    }
                }
            }
            
            // Don't change it, it's not character
            if(updo[x] == 999999999)
            {
                if (caesar[x] > 31) 
                {
                    updo[x] = caesar[x];
                }
            }
        }
        
        /**
         * Make it back as characters,
         * And put it into "done" array,
         * And show them all
         */
        for(int s = 0; s < arguments; s++)
        {
            // Make it back to characters 
            for(int d = 0; d < 26; d++) 
            {
                if(updo[s] == d)
                {
                    // Upper case characters
                    if (isupper(caesar[s]))
                    {
                       *done[s] = poinTextUp[d];
                        break;
                    }
                    // Lower case characters
                    else if (islower(caesar[s])) 
                    {
                        *done[s] = poinTextLw[d];
                        break;
                    }
                }
            }
            
            // Make it back to whatever it was, It's not character
            if(strcmp(done[s], "") == 0) 
            {
                *done[s] = updo[s];
            }
            
            // Display them all
            printf("%s",done[s]);
        } 
    
        // Make a space in the end
        printf("\n");
    }
    else
    {
        // ERORR MESSAGE
        printf("!! Usage: ./caesar number \n");
        return 1;
    }
    
}
