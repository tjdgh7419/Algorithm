using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {
        int[,] answer = new int[arr1.GetLength(0),arr2.GetLength(1)];
		List<int> ans = new List<int>();
		int a1 = 0;
		int a2 = 0;
		int n = 0;
		while (a1 != arr1.GetLength(0)) 
		{
			int sum = 0;
			for (int j = 0; j < arr1.GetLength(1); j++)
			{	
				sum += arr1[a1, j] * arr2[j, a2];
			}
			a2++;
			if(a2 == arr2.GetLength(1))
			{
				a2 = 0;
				a1++;
			}
			ans.Add(sum);
		}

		for(int i = 0; i < answer.GetLength(0); i++)
		{
			for(int j = 0; j < answer.GetLength(1); j++)
			{
				answer[i, j] = ans[n];
				n++;
			}
		}
	
		return answer;
    }
}