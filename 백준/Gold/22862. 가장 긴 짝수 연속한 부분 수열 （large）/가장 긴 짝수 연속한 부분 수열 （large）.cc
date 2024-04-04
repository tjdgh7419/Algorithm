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

int N, K, M;
vector<vector<int>>station(101001);
bool visited[101001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int>vec;

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		vec.push_back(val);
	}

	int start = 0, end = 0, odd = 0, even = 0, ans = 0;

	while (end < N)
	{
		if (odd <= K)
		{
			if (vec[end] % 2 != 0)
			{
				odd++;
			}
			else
			{
				even++;
				ans = max(even, ans);
			}
			end++;
		}
		else
		{
			if (vec[start] % 2 != 0) odd--;
			else even--;

			start++;
		}
	}

	cout << ans;
}