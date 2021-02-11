#include <stdlib.h>
#include <stdio.h>
#define N 10
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
int a[10];
int min;
int max;
int sum;
double moy;
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
sum=a[0];
f(a,N,&min,&max,&sum);
moy=(double)(sum/N);
printf(" moy =%f",moy);

}
