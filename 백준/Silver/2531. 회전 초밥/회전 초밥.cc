#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, d, k, c, ans = 0, coupon = 1, dup = 0;

	cin >> N >> d >> k >> c;
	
	vector<int> sushi(N + 1);
	vector<bool>visited(d + 1, false);

	for (int i = 0; i < N; i++) cin >> sushi[i];

	for (int i = 0; i < N; i++)
	{
		dup = 0;
		coupon = 1;

		for (int j = i; j < i + k; j++)
		{
			if (visited[sushi[j % N]]) dup++;
			else visited[sushi[j % N]] = true;

			if (sushi[j % N] == c) coupon = 0;
		}

		ans = max(ans, k - dup + coupon);
		fill(visited.begin(), visited.end(), false);
	}

	cout << ans;
}