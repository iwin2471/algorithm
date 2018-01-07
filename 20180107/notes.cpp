#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int arr[50000];
map<int, int> m;

int main() {
	int n, q, tmp, j = 0;
	int q_arr[50000] = { 0 };
	int tmp_arr[50000] = { 0 };
	int original_q[50000] = { 0 };

	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			scanf("%d", &tmp);
			arr[0] = tmp - 1;
		}
		else {
			scanf("%d", &tmp);
			arr[i] = arr[i - 1] + tmp - 1;
		}
	}

	for (int i = 0; i < q; i++) {
		scanf("%d", &q_arr[i]);
		original_q[i] = q_arr[i];
	}

	sort(q_arr, q_arr + q);

	tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += arr[i];
		for (; tmp >= q_arr[j] && j < q; j++)
			m[j] = i + 1;
	}

	for (j = 0; j < q; j++)
		printf("%d\n", m[original_q[j]]);

	return 0;
}