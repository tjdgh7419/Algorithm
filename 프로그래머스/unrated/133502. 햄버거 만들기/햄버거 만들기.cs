using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

public class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
		
		List<int> list = new List<int>();

		foreach (int i in ingredient)
		{
			list.Add(i);

			if(list.Count >= 4)
			{
				if (list[list.Count - 4] == 1 && list[list.Count - 3] == 2 && list[list.Count - 2] == 3 && list[list.Count - 1] == 1)
				{
					answer++;
					list.RemoveRange(list.Count - 4, 4);
				}
			}
		}

		return answer;
    }
}