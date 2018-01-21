
#include<stdio.h>
#include<string.h>

#define SIZE 80000 
long long int top = 0;
long long int caw[SIZE] = { 0, };
long long int input[SIZE];
long long int cnt = 0;

void push(int caw_num) {
	if (top >= SIZE)
		printf("overflow\n");
	else
		caw[top++] = caw_num;
}

void pop() {
	cnt++;
	if (top == 0)
		printf("empty\n");
	else
		caw[--top] = 0;
}

int main() {
	int int_input, j = 0;
	scanf("%lld", &int_input);
	while (scanf("%lld", &input[j++]) && j<int_input);

	push(input[0]);

	for (int i = 1; i < int_input; i++) {
		while (caw[top - 1] < input[i] && top > 0)
			pop();
		push(input[i]);
	}

	printf("%lld", cnt + top - 1);
	return 0;
}