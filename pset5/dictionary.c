/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>


#include "dictionary.h"

#define HASH_MAX  65000

// Node structure
typedef struct node
{
    char val[46];
    struct node* next;
}
node;

// Hash Table
node* words[HASH_MAX + 1] ;

// How many of words
int num_words; 

// Hash function
int hash(const char* word)
{
    unsigned int hash = 0;
    
    for (int i=0, n = strlen(word); i < n ; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HASH_MAX;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // A variable will get the word
    char aword[strlen(word) + 1];

    // Change the word to smallcase 
    for (int nu = 0; nu < strlen(word); nu++)
    {
        if (isupper(word[nu])) 
        {
            aword[nu] = tolower(word[nu]);   
        }
        else 
        {
            aword[nu] = word[nu];
        }
    }
    aword[strlen(word)] = '\0';
    
    // Hash code
    int  hashcode  = hash(aword);
    
    // Make a pointing 
    node* pointing = words[hashcode];
    
    while (pointing != NULL)
    {
        // If it match
        if (strcmp(pointing->val, aword) == 0)
        {
            return true;
        } 
        
        // To the next node
        pointing = pointing -> next;        
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // A node
    node* anode;
    
    // A word form file
    char stringss[46]; 
    
    // Hash code 
    int  hashcode;

    // Open file
    FILE* dic = fopen(dictionary, "r");
    
    // Until EOF 
    while (fscanf(dic, "%s", stringss) != EOF)
    {
        // Make a node
        anode    = malloc(sizeof(node));

        // Hash code
        hashcode = hash(stringss);
        
        //words[hashcode] = malloc(sizeof(node));

        strcpy(anode->val, stringss);
        
        // Pointing to the first node
        if (words[hashcode] == NULL)
        {
            // Add the node
            words[hashcode] = anode;
            
            // Make if point to nothing
            anode->next = NULL;  
            
            // Count 
            num_words++;
        } 
        else
        {
            // Make if point to the old node
            anode->next     = words[hashcode];  
            
            // Add the node
            words[hashcode] = anode;
            
            // Count
            num_words++;
        }
    }
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // The number of words
    return num_words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    
    // Make a pointing 
    node* pointing = malloc(sizeof(node));
    
    // Free the hashtable
    for (int n = 0; n < 65000; n++)
    {
        pointing = words[n];

        while (pointing != NULL)
        {
        	node* temp = pointing;
        	pointing   = pointing->next;
        	free(temp);
        }
    }
    
    return true;
}
