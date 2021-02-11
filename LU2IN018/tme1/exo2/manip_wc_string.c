#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN 0
#define OUT 1
int compte_mots_chaine(char *str){
 int state=OUT;
 int wordCount=0;
    while(*str){
   if(*str==' ') {
    
       state=OUT;
    }
    else if (state==OUT){
        wordCount++;
        state=IN;
    }
    ++str;
}
return wordCount;
}


void main(){
    char str1[]="mot1 et mot2 et mot3";
    int nb;
   nb=compte_mots_chaine(str1);
  printf("nombre de mots dans la chaine \"%s\"  est égale à %d",str1,nb);  
}
