using System;

public class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
		int[] num = new int[number + 1];
	
		for (int i = 1; i <= number; i++)
		{
			for (int j = 1; j <= number / i; j++)
			{
				num[i * j]++;
			}

		}

		for (int i = 1; i < num.Length; i++)
		{

			if (num[i] > limit)
			{
				answer += power;
				continue;
			}
			answer += num[i];
		}
		return answer;
    }
}