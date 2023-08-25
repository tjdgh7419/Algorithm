using System;

public class Solution
	{
		int answer = 0;
		public int solution(int[] number)
		{
			for(int i = 0; i < number.Length; i++)
			{
				dfs(number, 1, number[i], i + 1);
			}
			return answer;

		}

		void dfs(int[] num, int cnt, int sum, int start)
		{
			if (cnt == 3 && sum == 0)
			{
				answer++;
				return;
			}

			for(int i = start; i < num.Length; i++)
			{
				dfs(num, cnt + 1, sum + num[i], i + 1);
			}

		}
	}