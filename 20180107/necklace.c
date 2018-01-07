
#include <stdio.h>
#include <limits.h>

char arr[350];
int max = INT_MIN;


int main() {
	int n, j;
	int tmp, tmp2;
	int f_cnt = 0, b_cnt = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf(" %c", &arr[i]);

	for (int i = 0; i < n; i++) {
		f_cnt = 0;
		b_cnt = 0;
		tmp = arr[i]; 

		if ((i - 1) != -1) {
			tmp2 = arr[i - 1];
		}
		else {
			tmp2 = arr[n - 1];
		}

		j = i;
		while (1) {
			if (arr[j] == tmp || arr[j] == 119)
				f_cnt++;
			else break;

			if (j == 28) {
				j = 0;
			}
			else j++;
		}

		j = i - 1;
		while (1) {
			if (arr[j] == tmp2 || arr[j] == 119)
				b_cnt++;
			else break;

			if (j == 0) {
				j = n;
			}else j--;
		}

		
		if (max < f_cnt + b_cnt) {
			max = f_cnt + b_cnt;
			//printf("%d ", i);
		}
	}
	printf("\n%d", max);
}