using System;

public class Solution {
    public int solution(int k, int m, int[] score) {
       int answer = 0;
			int cnt = 0;
			int min = int.MaxValue;
			Array.Sort(score);

			for(int i = score.Length - 1; i >= 0; i--)
			{
				min = Math.Min(min, score[i]);
				cnt++;
				if(cnt == m)
				{
					answer += min * m;
					cnt = 0;
				}
			}

			return answer;
    }
}