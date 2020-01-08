#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>
#define ALPAHBET_SIZE (26)
#define Char_To_Index(c) ((int)c - (int)'a')
typedef struct node
{
    char letter;
    long unsigned int count;
    struct node* children[ALPAHBET_SIZE];
    bool isEndOfWord;
}node;
node* getNode();
void insert(node**,char*);
void print(node**,char[],int);
void printR(node**,char[],int);
void freeTrie(node**);

#endif