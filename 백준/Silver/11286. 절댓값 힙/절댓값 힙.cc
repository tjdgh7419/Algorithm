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
	
	struct Compare
	{
		bool operator()(const int& a, const int& b)
		{
			if (abs(a) == abs(b))
			{
				return a > b;
			}
			else
			{
				return abs(a) > abs(b); //true면 새로들어오는 수가 우선순위가 높다.
			}
			
		}
	};
	
	priority_queue<int, vector<int>, Compare> pq;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{		
			if (pq.empty())
			{
				cout << "0" << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
		{
			pq.push(x);
		}
	}
}