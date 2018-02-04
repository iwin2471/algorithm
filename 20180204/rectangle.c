#include<stdio.h>
#include<string.h>
using namespace std;

#define SIZE 500000
long long int top = 0;
long long int rectangle[SIZE] = { 0, };
long long int input[SIZE];

void push(long long int caw_num) {
	if (top >= SIZE)
		printf("overflow\n");
	else
		rectangle[top++] = caw_num;
}

void pop() {
	if (top == 0)
		printf("empty\n");
	else
		rectangle[--top] = 0;
}

int main() {
	long long int int_input, j = 1;
	int tmp;
	int max = 0;
	scanf("%lld", &int_input);
	push(0);

	while (j <= int_input+1) {
		if(j <= int_input) scanf("%lld", &input[j]);
		else input[j] = 0;

		max = (tmp = input[rectangle[top - 1]] * (j -rectangle[top-2] - 1)) > max ? tmp : max;

		if (input[rectangle[top - 1]] > input[j]) {
			while (input[rectangle[top - 1]] > input[j]) {
				max = (tmp = input[rectangle[top - 1]] * (j - rectangle[top - 2] - 1)) > max ? tmp : max;
				pop();
			}
			if (input[rectangle[top - 1]] == input[j]) pop();
			push(j++);
		}
		else push(j++);
	}

	printf("%d", max);
	return 0;
}
