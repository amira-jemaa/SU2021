// TD2 exo1
#include <stdio.h>
typedef struct _elt Elt;
struct _elt{
int donnee;
Elt *suivant;
};

int main() {
int taille=10;
Elt *liste=NULL;
Elt *nelt=NULL;
int i=0;
for (i=0;i<taille;i++) {
nelt=malloc(sizeof(Elt));
if (nelt == NULL) {
printf("Erreur lors de l’allocation.\n");
return 0;
}
nelt->donnee=i;
nelt->suivant=liste;
liste=nelt;
}
nelt=liste;
while (nelt) {
printf("%d ",nelt->donnee);
nelt=nelt->suivant;
}
printf("\n");
free(nelt);
    
    return 0;
}
 1.ce programme , est une liste chainée d'ordre decroissant, chaque nouveau element ajoutée devient le premier element de la liste.
 donc cette liste ajoute les elements 
au debut de la liste 
2. la liste occupe dans la memoire 10 blocs de memoire d"entiers , et 10 blocs pour le pointeur suivant qui pointe vers l'element suivant
un tableau occupera 10 blocs de memoire consécutifs 
3. free(nelt);
