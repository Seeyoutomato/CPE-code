#include <stdio.h>

int main(){
  int n,a[3000],h,i,flag[n],mark=0,temp,b;
  while(scanf("%d",&n)!= EOF){
   for(h=0;h<n;h++)
      scanf("%d",&a[h]);
    for(b=0;b<n;b++)flag[b]=0;
    for(i=0;i<n-1;i++){
      temp = abs(a[i],a[i+1]);
      if(temp<=n-1 && temp >= 1 && flag[temp]==0)
        flag[temp]=temp;
      else{
        mark=1;
        printf("Not jolly");
        break;
      }
    }
    if(mark==0)printf("Jolly");
  }
}
int abs(int a,int b){
  if(a>=b)
    return a-b;
  else
    return b-a;
}
