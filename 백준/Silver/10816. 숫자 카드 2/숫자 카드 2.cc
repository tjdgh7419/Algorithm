#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	int m2 = 0;
	int nVal = 0;
	int mVal = 0;
	
	cin >> n;

	unordered_map<int, int> m;	

	for (int i = 0; i < n; i++)
	{
		cin >> nVal;
		m[nVal]++;
	}

	cin >> m2;

	for (int i = 0; i < m2; i++)
	{
		cin >> mVal;
		cout << m[mVal] << " ";
	}		
}