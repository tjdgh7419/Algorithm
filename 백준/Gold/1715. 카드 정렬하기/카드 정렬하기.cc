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
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}


	while (pq.size() != 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}

	cout << ans;
}