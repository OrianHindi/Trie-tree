#include "Trie.h"
#include <stdio.h>
#include <string.h>
#define lineSize 1024
#define wordSize 256

int main(int argc, char const *argv[]){

   char word[wordSize];
   char line[lineSize];
   int counter=0;
   char c;
   int len=0;
   node* root = getNode();
   fgets(line,sizeof(line),stdin);
   fgets(line,sizeof(line),stdin);


       while(fgets(line,sizeof(line),stdin)){
           counter=0;
           len=strlen(line);
           for (size_t i = 0; i <len ; i++){
               c = line[i];
               if(c>=97 && c<=122 && c!= ' ' && c!= '\t' && c!='\n' && c!='\0'){
                   word[counter]=c;
                   counter++;
               }
               else if(c==' ' || c== '\t' || c== '\n' || c=='\0'){
                   insert(&root,word);
                   counter=0;
               }
           }
           
           
       }
    print(&root,word,0);
    freeTrie(&root);
   

return 0;
}
