#include <stdlib.h>
#include <stdio.h>

void f(int *tab, int size,int *min, int *max,int *sum){

size=size-1;
 if(size>=0){

     *sum+=tab[size];
if(tab[size]<*min)
{
    *min=tab[size];
}
else if (tab[size]>*max){
   *max=tab[size];
    }
f(tab, size, min, max,sum);
}

if(size<0)
{
printf("min = %d , max= %d ",*min,*max);
}
}
int main(){
int n;
int *nmax;
int a[n];
int min;
int max;
int sum;
double moy;

printf("saisir la taille:");

scanf("%d",&n);

if (n<=100){
    nmax=(int *)malloc(n*sizeof(int));
for(int i=0;i<n;i++){
    a[i]=rand()%n;
     }
printf("{");
 printf("%d,",a[0]);
for(int i=1;i<n-1;i++){
   printf("%d,",a[i]);
    }
 printf("%d",a[9]);
printf("}\n");
min=a[0];
max=a[0];
sum=a[0];
f(a,n,&min,&max,&sum);
moy=(double)(sum/n);
printf(" moy =%f",moy);
}
}
