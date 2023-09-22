using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
public class Solution {
    public string solution(string s) {
       string answer = "";
		bool chk = false;

		for(int i = 0; i < s.Length; i++)
		{
			if (!chk && s[i] != ' ')
			{
				string fir = s[i].ToString();
				fir = fir.ToUpper();
				answer += fir;
				chk = true;
				continue;
			}
			if (s[i] == ' ')
			{
				chk = false;
			}
			string sec = s[i].ToString().ToLower();
			answer += sec;
		}	
        return answer;
    }
}