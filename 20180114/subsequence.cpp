#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int input[2];
vector<int> arr;

int main() {
	int tmp;
	int sum = 0;
	int cnt = INT_MAX;
	int tmp_cnt;

	scanf("%d %d", &input[0], &input[1]);
	for (int i = 0; i < input[0]; i++) {
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	
	for (int i = 0; i < input[0]; i++) {
		sum += arr[i];
		tmp = sum;
		tmp_cnt = 0;

		for (int j = i; j < input[0]; j++) {
			sum += arr[j];
			tmp_cnt++;
			if (sum >= input[1]) {
				if (tmp_cnt < cnt)
					cnt = tmp_cnt;
				break;
			}
		}
		sum = tmp - arr[i];
	}

	if (find(arr.begin(), arr.end(), input[1]) != arr.end())
		printf("1");
	else
		printf("%d", cnt+1);
}