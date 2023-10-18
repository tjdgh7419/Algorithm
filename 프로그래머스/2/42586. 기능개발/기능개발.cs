using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<int> result = new List<int>();	
		Queue<int> q = new Queue<int>();
		int day = 1;
		int sCnt = 0;
		for(int i = 0; i < progresses.Length; i++)
		{
			q.Enqueue(progresses[i]);
		}

		while (q.Count != 0)
		{
			
			int exit = 0;
			while (q.Peek() + (speeds[sCnt] * day) >= 100 || exit < 1)
			{
				int peek = q.Peek();
				if (peek + (speeds[sCnt] * day) >= 100)
				{
					q.Dequeue();
					sCnt++;
					exit++;
					if(q.Count == 0)
					{
						break;
					}
				}
				else
				{
					day++;
				}
			}
			result.Add(exit);
			
		}
        
        return result.ToArray();
    }
}