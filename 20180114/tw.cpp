
#include<stdio.h>
#include<string.h>
#include <vector>
using namespace std;

#define SIZE 500000
long long int top = 0;
long long int tower[SIZE] = { 0, };
long long int answer[SIZE] = { 0, };
vector<int> arr;

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
	long long int tmp;
	long long int now_arr;
	scanf("%lld", &int_input);
	do {
		scanf("%lld", &tmp);
		arr.push_back(tmp);
		j++;
	} while (j < int_input);

	for (long long int i = 1; i < int_input; i++) {
		while (tower[top - 1] <= arr[i] && top > 0)
			pop();
		if (top > 0 && arr[i] < tower[top - 1])
			answer[i] = (long long)(find(arr.begin(), arr.end(), tower[top - 1]) - arr.begin() + 1);
		push(arr[i]);
	}

	for (long long int i = 0; i < int_input; i++)
		printf("%lld ", answer[i]);

	return 0;
}