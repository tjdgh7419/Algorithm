#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K, ans = 0;

	cin >> K;

	vector<int>vec(K);

	for (int i = 0; i < K; i++)
	{
		int val;
		cin >> val;

		if (val == 0) vec.pop_back();
		else vec.push_back(val);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		ans += vec[i];
	}

	cout << ans;
}