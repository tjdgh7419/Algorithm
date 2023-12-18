#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
string screen[64];

void Recur(int size, int x, int y)
{
	char fVal = screen[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (fVal != screen[i][j])
			{
				cout << '(';
				Recur(size / 2, x, y);
				Recur(size / 2, x + size / 2, y);
				Recur(size / 2, x, y + size / 2);
				Recur(size / 2, x + size / 2, y + size / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << fVal;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> screen[i];
	}

	Recur(N, 0, 0);
}