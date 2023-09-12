using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

public class Solution {
    public string solution(string s, string skip, int index) {
    	string answer = "";
		int cnt = 0;
		int plus = 1;
		int val = 0;
		List<char> ls = new List<char>();	

		for(int i = 0; i < s.Length; i++)
		{
			ls.Add(s[i]);
		}

		for(int i = 0; i < s.Length; i++)
		{
			while (cnt != index)
			{
				val = ls[i] + plus;
				if(val > 122)
				{
					ls[i] = 'a';
					plus = 0;
					val = 97;
				}
				if (skip.Contains((char)val))
				{
					plus++;
					continue;
				}
				plus++;
				cnt++;
			}
			plus = 1;
			cnt = 0;
			answer += (char)val;
		}
        return answer;
    }
}