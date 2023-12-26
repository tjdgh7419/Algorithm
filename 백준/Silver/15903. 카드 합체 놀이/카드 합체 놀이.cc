#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>


using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int n, m = 0;
	long long res = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++)
	{
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();

		pq.push(x + y);
		pq.push(x + y);
	}

	while (!pq.empty())
	{
		res += pq.top();
		pq.pop();
	}

	cout << res;
}