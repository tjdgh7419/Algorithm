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

		if (first == 6) answer.Add(1);
		else if (first == 5) answer.Add(2);
		else if (first == 4) answer.Add(3);
		else if (first == 3) answer.Add(4);
		else if (first == 2) answer.Add(5);
		else answer.Add(6);

		if (cnt == 6) answer.Add(1);
		else if (cnt == 5) answer.Add(2);
		else if (cnt == 4) answer.Add(3);
		else if (cnt == 3) answer.Add(4);
		else if (cnt == 2) answer.Add(5);
		else answer.Add(6);

		return answer.ToArray();
    }
}