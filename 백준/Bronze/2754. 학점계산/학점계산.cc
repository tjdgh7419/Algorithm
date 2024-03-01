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

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map < string, string > m;
	m.insert({ "A+", "4.3" });
	m.insert({ "A0", "4.0"});
	m.insert({ "A-", "3.7" });
	m.insert({ "B+", "3.3" });
	m.insert({ "B0", "3.0" });
	m.insert({ "B-", "2.7" });
	m.insert({ "C+", "2.3" });
	m.insert({ "C0", "2.0" });
	m.insert({ "C-", "1.7" });
	m.insert({ "D+", "1.3" });
	m.insert({ "D0", "1.0" });
	m.insert({ "D-", "0.7" });
	m.insert({ "F", "0.0" });

	string input;
	cin >> input;

	cout << m[input];
}

