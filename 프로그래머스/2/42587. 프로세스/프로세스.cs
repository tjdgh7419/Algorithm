using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
		Queue<int> q = new Queue<int>();
		Queue<int> nq = new Queue<int>();
		int chk = 0;
		for (int i = 0; i < priorities.Length; i++)
		{
			q.Enqueue(priorities[i]);
			nq.Enqueue(i);
		}
		while (true)
		{		
			if(q.Max() == q.Peek())
			{
				q.Dequeue();
				chk = nq.Dequeue();	
				
				answer += 1;
				if (chk == location)
				{
					break;
				}
			}
			else
			{
				q.Enqueue(q.Dequeue());
				nq.Enqueue(nq.Dequeue());
			}
		}

		return answer;
    }
}