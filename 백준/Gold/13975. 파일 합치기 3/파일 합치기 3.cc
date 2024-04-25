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
	
	int T;
	cin >> T;

	for (int c = 0; c < T; c++)
	{
		priority_queue<long, vector<long>, greater<long>> pq;
		int N;
		long ans = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int val;
			cin >> val;

			pq.push(val);
		}

		while (pq.size() > 1)
		{
			long f = pq.top();
			pq.pop();
			long s = pq.top();
			pq.pop();

			long sum = f + s;
			ans += sum;

			pq.push(sum);
		}
		pq.pop();

		cout << ans << "\n";
	}
}