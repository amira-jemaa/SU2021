#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compte_mots_chaine(char *str){
    int c=1;
   for(int i=0; str[i]!='\0'; i++){
  
   if(str[i]==' '){
       c=c+1;
   }
     }
    
    return c;

}  


int main(){
    char str1[]="mot1 et mot2 et mot3";
    int nb;
    int nbchar1=strlen(str1)+1;
    nb=compte_mots_chaine(str1);
  printf("nombre de mots dans la chaine \"%s\"  est égale à %d",str1,nb);  
  return 0;

}
