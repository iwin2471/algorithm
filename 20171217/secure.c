#include <stdio.h>
int l, c, i, j;
char a_temp[26] = {0,};
char arr[26], temp;

void secure(int n, int al){
  int cons = 0, vowels = 0;
  char c_vowels[5] = {'a', 'e', 'i', 'o', 'u'};

  if(n == l){
    for(i = 0; i<n; i++){
      for(j = 0; j < 5; j++){
        if(a_temp[i] == c_vowels[j]){
          vowels++;
          break;
        }
      }
      if(j == 5){
        cons++;
        if(cons >= 2 && vowels >= 1)
         break;
      }
    }
       
    if(cons >= 2 && vowels >= 1){
      for(i = 0; i<n; i++)
        printf("%c", a_temp[i]); 
      printf("\n");
    }
    return;
  }

  if(a_temp[n-1] < arr[al]){
    a_temp[n] = arr[al];
    secure(n+1, al+1);
  }else{
    return;
  }
  secure(n, al+1);
  return;
}


int main(){
  scanf("%d %d", &l, &c);

  for(i=0; i<c; i++)
    scanf(" %c", &arr[i]);

  for(i=0; i<c-1; i++){
    for(j=i+1; j<c; j++){
      if(arr[i] > arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  secure(0, 0);

  return 0;
}
