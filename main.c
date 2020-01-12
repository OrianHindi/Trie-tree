#include "Trie.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// #define lineSize 1024
// #define wordSize 256

int main(int argc, char* argv[]){

   bool isReverse=false;
   char word[256];
   char line[1024];
   int counter=0;
   char c;
   int len=0;
   node* root = getNode();
     if(argc==2 && strcmp(argv[1],"r")==0)
     isReverse=true;

       while(fgets(line,sizeof(line),stdin)){
           counter=0;
           len=strlen(line);
           for (size_t i = 0; i <len ; i++){
               c = line[i];
               if(c>=65 && c<=90){
                   c=c+32;

               }
               if(c>=97 && c<=122 && c!= ' ' && c!= '\t' && c!='\n' && c!='\0'){
                   word[counter]=c;
                   counter++;
               }
               else if(c==' ' || c== '\t' || c== '\n' || c=='\0'){
                   word[counter]='\0';
                   insert(&root,word);
                   counter=0;
               }
           }
           
           
       }

   if(isReverse) {
       printR(&root,word,0);
   }
   else {
       print(&root,word,0);
   }
    freeTrie(&root);
   

return 0;
}
