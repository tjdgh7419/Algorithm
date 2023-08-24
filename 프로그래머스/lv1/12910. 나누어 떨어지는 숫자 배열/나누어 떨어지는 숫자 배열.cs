using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
public class Solution {
    public int[] solution(int[] arr, int divisor) {
        List<int> result = new List<int>();
			for(int i = 0; i < arr.Length; i++)
			{
				if (arr[i] % divisor == 0)
				{
					result.Add(arr[i]);
				}				
			}
			if (result.Count == 0)
			{
				result.Add(-1);
			}

			int[] answer = new int[result.Count];
			for(int i = 0; i < answer.Length; i++)
			{
				answer[i] = result[i];
			}
            Array.Sort(answer);
			return answer;
    }
}