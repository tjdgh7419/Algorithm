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

	deque<int> dq;
	int N, M, left = 0, right = 0, ans = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int loc;
		cin >> loc;

		for (int j = 0; j < N; j++)
		{
			if (dq[j] == loc)
			{
				left = j;
				right = dq.size() - left - 1;
				break;
			}
		}

		if (left <= right)
		{
			while (true)
			{
				if (dq.front() == loc)
				{
					dq.pop_front();
					break;
				}

				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}
		else
		{
			ans++;
			while (true)
			{
				if (dq.back() == loc)
				{
					dq.pop_back();
					break;
				}

				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
	}

	cout << ans;
}