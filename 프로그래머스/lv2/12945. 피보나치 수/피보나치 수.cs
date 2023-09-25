using System;
public class Solution {
    public int solution(int n) {
       int answer = 0;
		int[] F = new int[n + 1];

		F[0] = 0;
		F[1] = 1;

		for(int i = 2; i <= n; i++)
		{
			F[i] = (F[i - 1] + F[i - 2]) % 1234567;
		}

		answer = F[n] % 1234567;
		return answer;
    }
}