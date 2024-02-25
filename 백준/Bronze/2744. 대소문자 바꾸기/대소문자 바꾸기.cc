#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string n;
	
	cin >> n;		

	for (int i = 0; i < n.length(); i++)
	{
		if ((int)n[i] >= 97)
		{
			n[i] = toupper(n[i]);
		}
		else
		{
			n[i] = tolower(n[i]);
		}
	}

	for (int i = 0; i < n.length(); i++)
	{
		cout << n[i];
	}
}