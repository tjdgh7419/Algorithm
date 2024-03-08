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

int lc[27];
int rc[27];

void preorder(int cur)
{
	char node = (char)(cur + 'A' - 1);

	cout << node;
	if(lc[cur] != 0) preorder(lc[cur]);
	if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur)
{
	char node = (char)(int)(cur + 'A' - 1);

	if (lc[cur] != 0) inorder(lc[cur]);
	cout << node;
	if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur)
{
	char node = (char)(int)(cur + 'A' - 1);

	if (lc[cur] != 0) postorder(lc[cur]);
	if (rc[cur] != 0) postorder(rc[cur]);
	cout << node;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;

		if(l != '.') lc[p - 'A' + 1] = l - 'A' + 1;
		if(r != '.') rc[p - 'A' + 1] = r - 'A' + 1;
	}

	preorder(1); cout << '\n';
	inorder(1); cout << '\n';
	postorder(1); cout << '\n';
}