#include<stdio.h>
#include<string.h>
using namespace std;

#define SIZE 500000
long long int top = 0;
long long int rectangle[SIZE] = { 0, };
long long int input[SIZE];
long long int answer[SIZE] = { 0, };

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
	long long int int_input, j = 0;
	int tmp = 0;
	int max = 0;
	scanf("%lld", &int_input);
	push(0);

	while (j < int_input) {
		scanf("%lld", &input[j++]);
		if (rectangle[top - 1] <= input[j - 1])
			push(input[j - 1]);
		else {
			max = (tmp = rectangle[top - 1] * ((j - 1) - rectangle[top - 2]) > max) ? tmp : max;
			pop();
			push(input[j - 1]);
		}
	}

	printf("%d", max);
	return 0;
}
