
#include<stdio.h>
#include<string.h>
using namespace std;

#define SIZE 500000
long long int top = 0;
long long int tower[SIZE] = { 0, };
long long int input[SIZE];
long long int answer[SIZE] = { 0, };

void push(long long int caw_num) {
	if (top >= SIZE)
		printf("overflow\n");
	else
		tower[top++] = caw_num;
}

void pop() {
	if (top == 0)
		printf("empty\n");
	else
		tower[--top] = 0;
}

int main() {
	long long int int_input, j = 0;
	scanf("%lld", &int_input);

	while (scanf("%lld", &input[j++]) && j < int_input);

	for (long long int i = int_input - 1; i > -1; i--) {
		while (input[i] >= input[tower[top - 1] - 1] && top > 0) {
			answer[tower[top - 1] - 1] = i + 1;
			pop();
		}
		push(i + 1);
	}

	for (long long int i = 0; i < int_input; i++)
		printf("%lld ", answer[i]);

	return 0;
}