#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Trie.h"

/**
 * this function create a new node.
 * all the fields have been intilizaid accept node letter.(will be initiliaze when insert)
 * */
node* getNode(){
    
    node* temp = (node*)malloc(sizeof(node));
    temp->isEndOfWord=false; 
    (temp)->count=0;
    for (size_t i = 0; i <ALPAHBET_SIZE; i++)
    {
        temp->children[i]=NULL;
    }
    return temp;

}
/**
 * this functuin get a word and insert it into the tree.
 * */
void insert(node** head,char* str){
    int index=0;
    int len = (int)strlen(str);
    size_t level=0;
    node* runner = *head;

    for (level = 0; level < len; level++)
    {
        index=Char_To_Index(str[level]);
        if(!runner->children[index]){
            runner->children[index]=getNode();
            runner->children[index]->letter=str[level];
        }
        runner=runner->children[index];
    }
    runner->isEndOfWord=true;
    runner->count++;
}

/**
 * this function print all the tree.
 * from 'a' letter to 'z'
 * */
void print(node** head,char word[], int level){
    node* runner = * head;
    int i;
    if(runner ==NULL)   return;
    if(runner->isEndOfWord){
        word[level]='\0';
        printf("%s \t %ld \n",word,runner->count);
    }
    
    for(i=0;i<ALPAHBET_SIZE;i++){
        if(runner->children[i]!=NULL){
            word[level]=runner->children[i]->letter;
            print(&(runner->children[i]),word,level+1);
        }
    }

}
/**
 * this function print the tree in reverse.
 * from z letter to a letter.
 * */
void printR(node** head,char word[], int level){
    node* runner = * head;
    int i;
    if(runner ==NULL)   return;
  
    
    for(i=ALPAHBET_SIZE-1;i>=0;i--){
        if(runner->children[i]!=NULL){
            word[level]=runner->children[i]->letter;
            printR(&(runner->children[i]),word,level+1);
        }
    }
      if(runner->isEndOfWord){
        word[level]='\0';
        printf("%s \t %ld \n",word,runner->count);
    }

}

/**
 * this function free all the memory have been allocated to the nodes of the tree.
 * */
void freeTrie(node** head){
    node* runner = *head;
    for (size_t i = 0; i < ALPAHBET_SIZE; i++)
    {
        if(runner->children[i]!=NULL){
            freeTrie(&(runner->children[i]));
        }
    }
    free(runner);
}

