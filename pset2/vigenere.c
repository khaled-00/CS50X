/**
 * vigenere.c
 * By khaled
 * 
 * Calculates the addition of characters depends on an argument,
 * and displays the resultant characters
 * 
 * Usage: ./vigenere something
 */
 
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Call the function
bool charcterss(string charec);

int main (int arg, string argy[])
{
    // There is a second argument && It's alpha
    if(arg == 2 && charcterss(argy[1]))
    {
        // Ask to enter a charcters 
        string something ; 
        do
        {
            something = GetString();
        } 
        while (strlen(something) <= 0);
       
        // The number of characters that entered
        int characters_num = 0;
        characters_num = strlen(something);
        
        // A variable will get the characters as ASCII values
        int InputInt[characters_num]; 

        // A variable will get the keys of ASCII array "from 0 to 26"
        int argInt[strlen(argy[1])-1]; 
        
        // A variable will get the values of "argInt2" and reapet it as it needed 
        int argInt2[characters_num+1];  
        
        // A variable will get the keys of ASCII array "from 0 to 26" after make changes 
        int updo[characters_num+1];  
        
        // A variable will get the results 
        string done[characters_num+1];
        for(int m = 0; m <= characters_num; m++)
        {
            done[m]=malloc(sizeof(char));
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
         * change the argument characters to keys of ASCII array, 
         * and put in into "argInt" array
         */
        for(int x = 0; x < strlen(argy[1]); x++) 
        {
            for(int z = 0; z < 26; z++)
            {
                // Upper case characters 
                if (isupper(argy[1][x]))
                {
                    if(argy[1][x] == poinTextUp[z]) 
                    {
                        argInt[x] = (z)%26;
                        break;
                    }
                }
                // Lower case characters
                else if (islower(argy[1][x])) 
                {
                    if(argy[1][x] == poinTextLw[z])
                    {
                        argInt[x] = (z)%26;
                        break;
                    }
                }
            }
        }
        
        /**
         * Repeat the values of argument characters as it needed,
         * And put it into "argInt2" array
         */
        for (int i = 0, z = 0; z < characters_num; z++, i++)
        {
            if (strlen(argy[1]) == i)
            {
                i = 0;
            }
            argInt2[z] = argInt[i];
        }
       
        /**
         * Do the changes to the input characters, 
         * And put it into "updo" array as ASCII values 
         */
        for(int a = 0, q = 0; a < characters_num; a++) 
        {
            // Make the characters as ASCII values
            InputInt[a]    = something[a];  
            
            // Do the changes
            for(int z = 0; z < 26; z++)
            {
                // Upper case characters 
                if (isupper(InputInt[a]))
                {
                    if(InputInt[a] == poinTextUp[z]) 
                    {
                        updo[a] = (z + argInt2[q])%26;
                        q++;
                        break;
                    }
                }
                // Lower case characters
                else if (islower(InputInt[a])) 
                {
                    if(InputInt[a] == poinTextLw[z])
                    {
                        updo[a] =  (z + argInt2[q])%26;
                        q++;
                        break;
                    }
                }
                // Don't change it, it's not character
                else if  (InputInt[a] > 31 && InputInt[a] < 125)
                {
                    updo[a] = InputInt[a];
                    break;
                }
            }
        }
    
        /**
         * Make it back to characters, 
         * And put it into "done" array,
         * and show them all
         */
        for(int s = 0; s < characters_num; s++) 
        {
            // Make it back to characters 
            for(int d = 0; d < 26; d++) 
            {
                if(updo[s] == d) 
                {
                    // Upper case characters
                    if (isupper(InputInt[s])) 
                    {
                       *done[s] = poinTextUp[d];
                        break;
                    }
                    // Lower case characters
                    else if (islower(InputInt[s]))
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
            printf("%s", done[s]);
        }
        
        // Make a space in the end
        printf("\n");
    } 
    else 
    {
        // ERORR MESSAGE
        printf("Usage: ./vigenere alpha-charcters \n");
        return 1;
    }
}

/**
 * Check out if the string that inputted is alpha
 * Takes one string.
 */
bool charcterss(string charec)
{
    for(int n = 0; n < strlen(charec); n++)
    {
        if(!isalpha(charec[n]))
        {
            return false;
        }
    }
    return true;
}