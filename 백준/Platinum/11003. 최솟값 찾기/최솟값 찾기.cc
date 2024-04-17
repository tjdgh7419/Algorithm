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
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> dq;
	vector<int> N_vec(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> N_vec[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (!dq.empty() && i == dq.front().second + L) dq.pop_front();

		while (!dq.empty() && dq.back().first > N_vec[i]) dq.pop_back();
			
		dq.push_back({ N_vec[i], i });
		cout << dq.front().first << " ";
	}
}