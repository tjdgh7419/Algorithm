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

int dish[300001];
int sushi[3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, d, k, c, ans = 0, cnt = 0, coupon = 1;

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) cin >> dish[i];

	for (int i = 0; i < k; i++)
	{
		if (++sushi[dish[i]] == 1) cnt++;
	}

	if (++sushi[c] == 1) cnt++;

	int start = 0, end = k - 1;

	while (start < N)
	{
		if (--sushi[dish[start++]] == 0) cnt--;
		
		end = (end + 1) % N;

		if (++sushi[dish[end]] == 1) cnt++;

		ans = max(ans, cnt);
	}
	cout << ans;
}