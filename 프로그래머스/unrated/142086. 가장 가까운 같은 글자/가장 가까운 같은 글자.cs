using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(string s) {
        int[] answer = new int[s.Length];
			int cnt = 0;
			Stack<char> stack = new Stack<char>();
			Stack<char> tmp = new Stack<char>();
			for (int i = 0; i < s.Length; i++)
			{
				if (!stack.Contains(s[i]))
				{
					stack.Push(s[i]);
					answer[i] = -1;
				}
				else
				{
					while (true)
					{
						char val = stack.Pop();
						cnt++;
						if(val == s[i])
						{
							answer[i] = cnt;
							cnt = 0;
							tmp.Push(val);
							break;
						}
						tmp.Push(val);
					}
					while (tmp.Any())
					{
						stack.Push(tmp.Pop());
					}
					stack.Push(s[i]);
				}
			}
			return answer;
    }
}