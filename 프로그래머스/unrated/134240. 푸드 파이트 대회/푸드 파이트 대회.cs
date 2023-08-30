using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string solution(int[] food) {
        string answer = "";
			Stack<char> sk = new Stack<char>();
			for(int i = 1; i < food.Length; i++)
			{
				if (food[i] / 2 > 0)
				{
					for (int j = 0; j < food[i] / 2; j++)
					{
						answer += i;
					}
				}
			}
			for (int i = 0; i < answer.Length; i++)
			{
				sk.Push(answer[i]);
			}
			answer += "0";
			while (sk.Any())
			{
				answer += sk.Pop().ToString();
			}
			return answer;
    }
}