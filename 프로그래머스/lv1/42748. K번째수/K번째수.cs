using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        int[] a = new int[] { };
			int[] answer = new int[commands.GetLength(0)];
			for (int i = 0; i < commands.GetLength(0); i++)
			{
				var seg = new ArraySegment<int>(array, commands[i,0] - 1, Math.Abs(commands[i,0] - commands[i,1]) + 1).OrderBy(s => s);
				a = seg.ToArray();
				
				answer[i] = a[commands[i, 2] - 1];
			}
			return answer;
    }
}