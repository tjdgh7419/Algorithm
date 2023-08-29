using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] numbers) {
       int[] answer = new int[] { };
			List<int> result = new List<int>();

			for (int i = 0; i < numbers.Length; i++)
			{
				for(int j = i + 1; j < numbers.Length; j++)
				{
					if (!result.Contains(numbers[i] + numbers[j]))
					result.Add(numbers[i] + numbers[j]);
				}
			}
			result.Sort();
			answer = result.ToArray();
			return answer;
    }
}