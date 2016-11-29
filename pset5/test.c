#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    
    FILE* dic = fopen("texts/austinpowers.txt", "r");
    
    char stringss[46];
    
    while(fscanf(dic, "%s", stringss) != EOF)
    {
        
        printf("%s 00 \n", stringss);   
    }
    
}