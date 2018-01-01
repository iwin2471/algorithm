#include <stdio.h>
char arr[10][10];
char chk[10][10];
int cnt = 0;

int movement(int now_location[2]) {
	int int_now_location = arr[now_location[0]][now_location[1]];
	int next_location[2];
	if (chk[now_location[0]][now_location[1]] == 1) return 0;
	cnt++;

	switch (int_now_location) {
	case 45: //E
		next_location[0] = now_location[0];
		next_location[1] = now_location[1] + 1;
	  chk[now_location[0]][now_location[1]] = 1;
		if (next_location[0] == -1 || next_location[1] == -1) return 1;
		if (movement(next_location)) return 1;
		break;
	case 87: //W
		next_location[0] = now_location[0];
		next_location[1] = now_location[1] - 1;
		chk[now_location[0]][now_location[1]] = 1;
		if (next_location[0] == -1 || next_location[1] == -1) return 1;
		if (movement(next_location)) return 1;
		break;
	case 83: //S
		next_location[0] = now_location[0] + 1;
		next_location[1] = now_location[1];
		chk[now_location[0]][now_location[1]] = 1;
		if (next_location[0] == -1 || next_location[1] == -1) return 1;
		if (movement(next_location)) return 1;
			break;
	case 78: //N
		next_location[0] = now_location[0] - 1;
		next_location[1] = now_location[1];
		chk[now_location[0]][now_location[1]] = 1;
		if (next_location[0] == -1 || next_location[1] == -1) return 1;
		if (movement(next_location)) return 1;
		break;
	}
}

int main() {
	int m, n, location;
	int location_arr[2];
	scanf("%d %d %d", &m, &n, &location);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}
	location_arr[0] = 0;
	location_arr[1] = location;

	movement(location_arr);
	printf("%d step(s) to exit", cnt);

	return 0;
}
