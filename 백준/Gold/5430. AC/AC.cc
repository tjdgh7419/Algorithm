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
		string p, x, str = "", ans = "";
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

			if (rev && !dq.empty()) {
				for (auto o = dq.rbegin(); o != dq.rend(); o++) {
					if (o == dq.rend() - 1)
						cout << *o;
					else
						cout << *o << ',';
				}
			}
			else if (!rev && !dq.empty()) {
				for (auto o = dq.begin(); o != dq.end(); o++) {
					if (o == dq.end() - 1)
						cout << *o;
					else
						cout << *o << ',';
				}
			}
			
			cout << ans + "]" << '\n';
		}
	}
}