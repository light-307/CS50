// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

unsigned int cont_dic = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 262144;   //2147483648   262144

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char word2[LENGTH + 1];
    strcpy(word2, word);
    // printf("debug!!!!!!!!!!!!!\n");
    for(int i=0; word2[i]!=0; i++)
    {
        // printf("%c\n", word2[i]);
        if(word2[i] >= 'A' && word2[i] <= 'Z')
        {
            word2[i] = word2[i] +32;
        }
    }

    unsigned int hashnum = hash(word2);

    for (node *tmp = table[hashnum]; tmp != NULL; tmp = tmp->next)
    {
        if(strcasecmp(tmp->word, word2) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
/// @brief BKDR Hash Function
/// @detail 本 算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得 名，是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）。
unsigned int hash(const char *word)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hashnum = 0;
 
    while (*word)
    {
        hashnum = hashnum * seed + (*word++);
    }
 
    return (hashnum & 0x3FFFF);   //0x7FFFFFFF   0x3FFFF
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //初始化 hash table
    for(int i=0; i<N; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    node *n;
    for (int c = fscanf(file, "%s", word); c != EOF; c = fscanf(file, "%s", word))
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        unsigned int hashnum = hash(word);

        n->next = table[hashnum];
        table[hashnum] = n;

        cont_dic++;
    }

    // Close text
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return cont_dic;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Free table
    for(int i=0; i<N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    
    return true;
}
