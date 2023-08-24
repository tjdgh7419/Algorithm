using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution {
    public int[] solution(int[] arr) {
      int min = arr.Min();
			int[] answer;
			if (arr.Length > 1)
			{
				answer = arr.Where(x => x != min).ToArray();
			}
            else
            {
				answer = new int[1];
				answer[0] = -1;
            }

            return answer;			
    }
}