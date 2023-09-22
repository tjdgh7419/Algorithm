using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;


public class Solution {
    public int[] solution(string s) {
       int[] answer = new int[2];
		int zeroCnt = 0;
		int numCnt = 0;
		int transCnt = 0;
		while (s != "1")
		{
			for (int i = 0; i < s.Length; i++)
			{
				if (s[i] == '0')
				{
					zeroCnt++;
					continue;
				}
				numCnt++;
			}
			s = Convert.ToString(numCnt, 2);
			transCnt++;
			numCnt = 0;
		}
		answer[0] = transCnt;
		answer[1] = zeroCnt;

		return answer;
    }
}