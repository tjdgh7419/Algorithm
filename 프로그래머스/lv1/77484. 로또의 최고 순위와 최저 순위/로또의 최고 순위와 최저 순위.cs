using System;
using System.Collections.Generic;
using System.Linq;


public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
       List<int> answer = new List<int>();
		int cnt = 0;
		int zeroCnt = 0;
		int first = 0;
		for(int i = 0; i < lottos.Length; i++)
		{
			if (lottos[i] == 0)
			{
				zeroCnt++;
			}
			if (win_nums.Contains(lottos[i]))
			{
				cnt++;
			}
		}
		first = zeroCnt + cnt;
		if (first != 0) answer.Add(7 - first);
		else answer.Add(6);


		if (cnt != 0) answer.Add(7 - cnt);
		else answer.Add(6);

		return answer.ToArray();
    }
}