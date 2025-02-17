// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);

    if (table[hash_value] != NULL){
        return true;
    } else {
        return false;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *input = fopen(dictionary, "r");

    if (input == NULL)
    {
        return false;
    }

    char word[45];
    while (fscanf(input, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(input);
            return false;
        }

        

        strcpy(n->word, word);
        n->next = NULL;

        unsigned int index = hash(word);

        n->next = table[index];
        table[index] = n;
    }

    fclose(input);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int total = 0;

    for (int i = 0; i < N; i++) {
        for (node *curr = table[i]; curr != NULL; curr = curr->next) {
            total++;
            // printf("%s\n", curr->word);
        }
    }

    return total;
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        node *curr = table[i];
        while (curr != NULL) {
            node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    return true;
}
