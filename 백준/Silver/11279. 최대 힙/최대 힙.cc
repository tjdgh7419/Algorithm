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
	
	priority_queue<int> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;

		if (val != 0) pq.push(val);
		else
		{
			if (pq.empty()) cout << "0" << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}