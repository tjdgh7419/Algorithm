using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public int solution(string[,] clothes) {
       int answer = 1;
		int sum = 0;
		List<string>ls = new List<string>();
		Dictionary<string, int>dc = new Dictionary<string, int>();

		for(int i = 0; i < clothes.GetLength(0); i++)
		{
			if (dc.ContainsKey(clothes[i, 1]))
			{
				dc[clothes[i, 1]]++;
			}
			else
			{
				dc.Add(clothes[i, 1], 1);
			}
		}

		foreach(var key in dc.Keys)
		{
			answer *= dc[key] + 1;
		}
		answer -= 1;

        return answer;
    }
}