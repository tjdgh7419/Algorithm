using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[,] sizes) {
        List<int[]> list = new List<int[]>();
        int answer = 0;
			for(int i = 0; i < sizes.GetLength(0); i++)
			{
				int tmp = 0;

				if(sizes[i, 1] > sizes[i, 0])
				{
					tmp = sizes[i, 1];
					sizes[i, 1] = sizes[i, 0];
					sizes[i, 0] = tmp;
				}
			    list.Add(new int[2] { sizes[i, 0], sizes[i, 1] });
			}
			answer = list.Max(x => x[0]) * list.Max(x => x[1]);
			return answer;
    }
}