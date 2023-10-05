using System;
using System.Collections.Generic;
using System.Linq;


public class Solution {
    public int solution(string s) {
      	int answer = 0;
		Stack<char> sk;
		bool chk = false;
        for (int j = 0; j < s.Length; j++)
		{
			sk = new Stack<char>();
			if (j != 0)
			{
				string tmp = "";
				tmp = s[0].ToString();
				s = s.Remove(0, 1);
				s += tmp;
			}

			for (int i = 0; i < s.Length; i++)
			{
				if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				{
					sk.Push(s[i]);				
				}
				else
				{
					if (sk.Count() == 0) 
					{
						chk = true;
						break;
					}
					if (s[i] == ')' && sk.Peek() == '(') sk.Pop();
					else if (s[i] == ']' && sk.Peek() == '[') sk.Pop();
					else if (s[i] == '}' && sk.Peek() == '{') sk.Pop();
				}
			}
			if (sk.Count > 0) chk = true;
			if (!chk)
			{
				answer++;
			}
			chk = false;
		}

		return answer;
    }
}