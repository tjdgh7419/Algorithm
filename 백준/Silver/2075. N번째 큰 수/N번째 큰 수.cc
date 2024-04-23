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
	
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int val;
			cin >> val;
			pq.push(val);
		}

		while (pq.size() > N)
		{
			pq.pop();
		}
	}
	cout << pq.top();
}