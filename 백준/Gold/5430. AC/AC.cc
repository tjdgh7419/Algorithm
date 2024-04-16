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

	int T, n;

	cin >> T;

	while (T--)
	{
		deque<string>dq;
		string p, x, str = "";
		bool er = false, rev = false;
		cin >> p >> n >> x;

		for (int i = 0; i < x.length(); i++)
		{
			if (isdigit(x[i]))
			{
				str += x[i];
			}
			else
			{
				if (!str.empty())
				{
					dq.push_back(str);
					str = "";
				}
			}
		}

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (!rev) rev = true;
				else rev = false;
			}
			else
			{
				if (dq.empty())
				{
					cout << "error" << "\n";
					er = true;
					break;
				}
				
				if (rev) dq.pop_back();
				else dq.pop_front();
			}		
		}

		if (!er)
		{
			cout << "[";

			if (rev) 
			{
				for (auto i = dq.rbegin(); i != dq.rend(); i++) {
					if (i == dq.rend() - 1)
						cout << *i;
					else
						cout << *i << ',';
				}
			}
			else 
			{
				for (auto i = dq.begin(); i != dq.end(); i++) {
					if (i == dq.end() - 1)
						cout << *i;
					else
						cout << *i << ',';
				}
			}
			
			cout << "]" << '\n';
		}
	}
}