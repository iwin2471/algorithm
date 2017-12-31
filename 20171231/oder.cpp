#include <stdio.h>
#include <string.h>
int n, r, f, s;
int p = 0, c = 0;
char p_c[2], c_c[2];
char alpha[27];
int chk[27];
char ans[26];

void permute(int now) {
	if(now == r){
		if (++p == f) {
			for (int i = 0; i < r; i++)
				printf("%c", ans[i]);
			printf("\n");
		}
	}
	for (int i = 0; i < n; i++) {
		if (chk[i] == 0) {
			ans[now] = i+65;
			chk[i] = 1;
			permute(now+1);
			chk[i] = 0;
		}
	}
}

void combination(char *arr, int index, char *data, int i){
	if (index == r){
		if (++c == s) {
			for (int j = 0; j < r; j++)
			  printf("%c", data[j]);
			return;
		}
		return;
	}

	if (i >= n)
		return;

	data[index] = arr[i];
	combination(arr, index + 1, data, i + 1);
	combination(arr, index, data, i + 1);
}

int main() {
	int i;
	char data[26];
	scanf("%d %d", &n, &r);
	scanf("%d %d", &f, &s);

	for (i = 0; i < n; i++)
		alpha[i] = 65 + i;

	permute(0);
	combination(alpha, 0, data, 0);

	return 0;
}
