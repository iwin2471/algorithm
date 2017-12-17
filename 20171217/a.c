#include <stdio.h>
int n, k;
int arr[30] = {0,};
int i=0, cn = 0, st = 0;
int kcnt = 0;

int check(){
  if(cn == n)
   return 1;
  
  if(kcnt == k){
    for(i = 0; i<n; i++)
       printf("%d", arr[i]);
    printf("\n");
  }
  

  cn++;
  kcnt=1;
  return 0;
}

int pat(int kn){
  int tf = 0;

  if(arr[kn] == 1 && st != kn){
    arr[kn] = 0;
  }else if(arr[kn] == 0 && kn != st && kcnt != k){ 
    arr[kn] = 1;
    kcnt++;
  }else{
    arr[kn] = 0;
  }

  if(kn == n){
    tf = check();
    if(tf == 1)
      return 0;
    kn = 0;
    pat(kn);
  }

  pat(++kn);
}

int main(){
  scanf("%d %d",  &n, &k);
  if(k == 0){
    for(i=0; i<n; i++)
     printf("0");
  }

  arr[st] = 1;
  pat(0);
  return 0;
}
