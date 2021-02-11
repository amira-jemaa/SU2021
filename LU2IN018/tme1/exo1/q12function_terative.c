#include <stdlib.h>
#include <stdio.h>
#define N 10
void f(int *tab, int size,int *min, int *max,double *moy){
double som =0;
for(int i=0; i<size; i++)
{
som+=tab[i];
*moy=som/size;
if(tab[i]<*min)
{
    *min=tab[i];
}
else if (tab[i]>*max){
    *max=tab[i];


}

}
    printf("min = %d , max= %d moy = %f ",*min,*max,*moy);
}
int main(){
int n;
int a[10];
int min;
int max;
double moy=0;
for(int i=0;i<N;i++){
    printf("saisir element %d ",i);
    scanf("%d",&n);
    a[i]=n;

}
printf("{");
 printf("%d,",a[0]);
for(int i=1;i<N-1;i++){
   printf("%d,",a[i]);
    }
 printf("%d",a[9]);
printf("}\n");
min=a[0];
max=a[0];
f(a,N,&min,&max,&moy);
}
