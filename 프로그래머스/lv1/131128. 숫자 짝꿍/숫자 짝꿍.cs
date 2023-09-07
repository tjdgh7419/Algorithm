using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string solution(string X, string Y) {
       string answer = "";
		int[] arrX = new int[10];
		int[] arrY = new int[10];

		for(int i = 0; i < X.Length; i++)
		{
			arrX[X[i] - '0']++;
		}

		for (int i = 0; i < Y.Length; i++)
		{
			arrY[Y[i] - '0']++;
		}

		for(int i = 9; i >= 0; i--)
		{
			if (arrY[i] == 0 || arrX[i] == 0) continue;

			int min = Math.Min(arrX[i], arrY[i]);
			answer += string.Concat(Enumerable.Repeat(i, min));
		}
        
        if (answer.Length == 0)
			answer = "-1";
		else if (answer[0] == '0')
			answer = "0";
		return answer;
    }
}