#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int f = 0;
	int s = 0;
	int t = 0;
	
	cin >> f;
	cin >> s;
	cin >> t;

	if (f == 60 && s == 60 && t == 60)
	{
		cout << "Equilateral";
	}
	else if ((f + s + t == 180) && (f != s && s != t && t != f))
	{
		cout << "Scalene";
	}
	else if ((f + s + t == 180) && (f == s || s == t || t == f))
	{
		cout << "Isosceles";
	}
	else
	{
		cout << "Error";
	}
}