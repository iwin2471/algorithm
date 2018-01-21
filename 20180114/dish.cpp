#include<stdio.h>
#include<string.h>

#define SIZE 30
int top = 0;
char washing[SIZE] = {0,};
char dish[30];

int flag = 0, j, cnt_answer = 0;
int answer[60] = {0,};

void push(char alpha){
	if (top >= SIZE)
		printf("overflow\n");
	else
		washing[top++] = alpha;
}

void pop(){
	if (top == 0)
		printf("empty\n");
	else
		washing[--top] = 0;
}

void next(int dishnum, int alpha) {
	if (dish[dishnum] == 0)
		return;

	if ((washing[top-1] == 0 || dish[dishnum] != washing[top-1]) && j != 0){
		answer[++cnt_answer] = 2;
		push(alpha + 1);
		j--;
		next(dishnum, alpha + 1);
	}else if ((dish[dishnum] == washing[top-1])) {
		answer[++cnt_answer] = 1;
		pop();
		next(dishnum + 1, alpha);
	}else{
		printf("impossible\n");
		flag = 1;
		return;
	}
}


int main() {
	char ch;
	char start = 97;

	while ((ch = getchar()) != '\n' && j < 31)
		dish[j++] = ch;
	push(start);
	answer[++cnt_answer] = 2; // push는 2
	j--;
	next(0, start);

	if (flag == 0) {
		for (int i = 1; i <= cnt_answer; i++) {
			if (answer[i] == 1)
				printf("pop\n");
			else
				printf("push\n");
		}
	}
	return 0;
}
