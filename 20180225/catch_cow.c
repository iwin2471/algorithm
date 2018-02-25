#include <stdio.h>

#include <stdio.h>

#define MAX 400000

int queue[MAX];
int check[100000] = { 0, };

int front = 0, rear = 0;

void enqueue(int d) {
	queue[rear++] = d;
}

int dequeue(void) {
	int frontQ = queue[front++];
	return frontQ;
}

int main() {
	int N, K, tmp;
	int i = 0;
	scanf("%d %d", &N, &K);

	if (N > K)
		printf("%d", (K-N)*-1);
	else {
		enqueue(K);
		check[K] = i++;
		
		while (1) {
			tmp = dequeue();
			i = ++check[tmp];

			if (tmp % 2 == 0) {
				if (check[tmp / 2] == 0) {
					if (tmp / 2 == 5) {
						printf("%d", i);
						break;
					}
					else {
						enqueue(tmp / 2);
						check[tmp / 2] = i;
					}
				}
				if (check[tmp - 1] != 1) {
					if (tmp - 1 == 5) {
						printf("%d", i);
						break;
					}
					else {
						enqueue(tmp - 1);
						check[tmp - 1] = i;
					}
				}
				if (check[tmp + 1] != 1) {
					if (tmp + 1 == 5) {
						printf("%d", i);
						break;
					}
					else {
						enqueue(tmp + 1);
						check[tmp + 1] = i;
					}

				}
			}
			else {
				if (check[tmp - 1] != 1) {
					if (tmp - 1 == 5) {
						printf("%d", i);
						break;
					}
					else {
						enqueue(tmp - 1);
						check[tmp - 1] = i;
					}
				}
				if (check[tmp + 1] != 1) {
					if (tmp + 1 == 5) {
						printf("%d", i);
						break;
					}
					else {
						enqueue(tmp + 1);
						check[tmp + 1] = i;
					}

				}
			}
		}
	}

}