#include <cs50.h>
#include <stdio.h>


/*
int main(void)
{
    int arr[3];
    
    arr[0]  = 42;
    arr[1]  = 43;
    arr[2]  = 44;
    
    
    int start, middel, end, target , count = 0;
    
    start  = 0;
    end    = 2;
    middel = (start + end) / 2;
    
    target = 42;
    
    while(start <= end)
    {
        printf("%i \n", arr[middel]);
        count++;
        if(arr[middel] == target)
        {
            printf("%iis here \n", arr[middel]);
            break;
        }
        else if(arr[middel] > target)
        {
            end    = middel - 1;
        }
        else if(arr[middel] < target)
        {
            start  = middel + 1;
        } 
        
        middel = (start + end) / 2;
        printf("--%i, t = %i; v = %i\n", middel, target, arr[middel]);
    }
    
    printf("%i round, %i is not found \n", count, arr[middel]);
}
*/



int main(void)
{
    int arr[5];
    
    arr[4] = 10;
    arr[3] = 40;
    arr[2] = 20;
    arr[1] = 60;
    arr[0] = 30;
    
    for(int n = 0; n < 5; n++)
    {
        printf("%i\n", arr[n]);
    }
    
    printf("----------\n");
    
    int  count = 0;
    for(int i = 0; i < 5; i++)
    {
        count = 0;
        for(int n = 0; n < 5; n++)
        {
            if((n + 1) == 5)
            {
                break;
            }
            else
            {
                if(arr[n] > arr[n + 1])
                {
                    arr[n]       = arr[n] ^ arr[n + 1];
                    arr[n + 1]   = arr[n] ^ arr[n + 1];
                    arr[n]       = arr[n] ^ arr[n + 1];
                    count++;
                }   
            }
        }
        if( count == 0)
        {
            break;
        }
    }
    
    for(int n = 0; n < 5; n++)
    {
         printf("%i\n", arr[n]);
    }
   
}








/*

int main(void)
{
    printf("Enter an integer number: \n");
    
    // Get the value
    int d = GetInt();
    // How many numbers 
    int n = (d * d);
    
    // Array of board
    int board[d][d];
    
    // Make the Array of board
    for(int q = 0; q < d; q++)
    {
        for(int j = 0; j < d; j++)
        {
            n--;
            if (n == 0)
            {
                board[q][j] = 123456789;
            }
            else 
            {
                if(d % 2 == 0)
                {
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
                    board[q][j] = n; 
                }
            }
        }    
    }    
    printf("\n");

    float s = 9/2;
    printf("  %f \n", s);
 }   
    // Show the array of board
    for(int q = 0; q < d; q++)
    {
        for(int j = 0; j < d; j++)
        { 
            if (board[q][j] == 123456789)
            {
                printf(" _ ");
            }
            else 
            {
               printf(" %i ", board[q][j]);
            }
        }    
        printf("\n");
    }    
}
int draw(int board[][])
{
    
}*/

