#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Trie.h"


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
void insert(node** head,char* str){
    int index=0;
    int len = (int)strlen(str);
    char temp[len];
    size_t level=0;
    node* runner = *head;
    int i;
    for(i=0;i<len;i++){
        if(str[i]!= " ")temp[i]=str[i];
    }
    int templen=(int)strlen(temp);
    if(templen==0) return;

    for (level = 0; level < templen; level++)
    {
        index=Char_To_Index(temp[level]);
        if(!runner->children[index]){
            runner->children[index]=getNode();
            runner->children[index]->letter=temp[level];
        }
        runner=runner->children[index];
    }
    runner->isEndOfWord=true;
    runner->count++;
}
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

