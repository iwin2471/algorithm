#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int input[2];
vector<int> arr;
int middle;
int cnt;
int f, s;

int check(int first, int last) {
	int sum = 0;
	int tmp_cnt = 0;

	for (int i = first; i <= last; i++) {
		sum += arr[i];
		tmp_cnt++;
		if (sum >= input[1])
			return tmp_cnt;
	}
	return 0;
}

void subsequence(int first, int last) {
	if (last - first == 2) return;
	middle = ((first + 1) + (last + 1)) / 2 - 1;
	f = check(first, middle); //0
	s = check(middle, last); //3
	if (f < s && f !=0) {
		cnt = f;
		subsequence(first, middle);
		return;
	}
	else if(s < f && s !=0){
		cnt = s;
		subsequence(middle, last);
		return;
	}
	else {
		cnt = s > f ? s : f;
		if(cnt == f)
			subsequence(first, middle);
		else
			subsequence(middle, last);
	}
}

int main() {
	int tmp;
	scanf("%d %d", &input[0], &input[1]);
	for (int i = 0; i < input[0]; i++) {
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	if (find(arr.begin(), arr.end(), input[1]) != arr.end())
		printf("1");
	else
		subsequence(0,input[0] - 1);
	printf("%d", cnt);
}