#include <stdio.h>
int n, k, i;
int arr[30] = {0,};


int pattern(int pn, int one){
  if(n == pn && one == k){
    for(i = 0; i<n; i++)
      printf("%d", arr[i]); 
    printf("\n");
    return 0;
  }else if(n == pn || one > k)
    return 0;
    
  arr[pn] = 1;
  pattern(pn+1, one+1);
  arr[pn] = 0;
  pattern(pn+1, one);
} 

int main(){
  scanf("%d %d",  &n, &k);
  pattern(0, 0);
  return 0;
}
