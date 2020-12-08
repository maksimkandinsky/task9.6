#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
void tr(float **a,int n,int i){
int k,j;
float max,t;
max=fabs(a[i][i]);
j=i;
for(k=i+1;k<n;k++){
  if(fabs(a[k][i])>max){
    j=k;
    max=fabs(a[k][i]);
  }
}
for(k=0;k<2*n;k++){
    t=a[i][k];
    a[i][k]=a[j][k];
    a[j][k]=t;
}
for(k=i;k<n;k++){
    if(a[k][i]!=0){
        for(j=i+1;j<2*n;j++){
            a[k][j]=1.0*(a[k][j]/a[k][i]);
        }
    a[k][i]=1;
    }
}
for(k=i+1;k<n;k++){
    if(a[k][i]!=0){
        for(j=0;j<2*n;j++){
            a[k][j]-=a[i][j];
        }
    }
}
    if(i<n-1){
    tr(a,n,i+1);
    }
}
void obr(float **a,int n,int i){
int j,k;
for(j=i+1;j<n;j++){
    if(a[i][j]!=0){
        for(k=j+1;k<2*n;k++){
            a[i][k]-=a[j][k]*a[i][j];
        }
        a[i][j]=0;
    }
}
if(i<n-2){
    obr(a,n,i+1);
}
}
int main()
{
    setlocale(LC_ALL,"Rus");
    float **a;
    int i,j,n;
    printf("¬ведите размер матрицы и еЄ элементы\n");
    scanf("%d",&n);
    a=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++){
        a[i]=(float*)malloc((2*n)*sizeof(float));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%f",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=n;j<2*n;j++){
            if(j-i==n){
                a[i][j]=1;
            }else{
            a[i][j]=0;
            }
        }
    }
    tr(a,n,0);
printf("\nќбратна€ матрица:\n");
   obr(a,n,0);
   for(i=0; i<n; i++, printf("\n")){
        for(j=0; j<n; j++)
            printf("%f ",a[i][j+n]);
}

    return 0;
}
