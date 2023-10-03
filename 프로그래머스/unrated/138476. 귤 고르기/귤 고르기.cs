using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
		int val = 0;
		var tan = new Dictionary<string, int>();
		for (int i = 0; i < tangerine.Length; i++)
		{
			if (!tan.ContainsKey(tangerine[i].ToString()))
			{
				tan.Add(tangerine[i].ToString(), 0);
			}
		}

		for (int i = 0; i < tangerine.Length; i++)
		{
			tan[tangerine[i].ToString()]++;
		}

		tan = tan.OrderByDescending(item => item.Value).ToDictionary(x => x.Key, x => x.Value);
		foreach (var a in tan.Values)
		{
			answer++;
			val += a;
			if (k <= val)
			{
				break;
			}
		}
		return answer;
    }
}