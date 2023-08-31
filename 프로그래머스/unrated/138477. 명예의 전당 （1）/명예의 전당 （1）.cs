using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    public int[] solution(int k, int[] score) {
      int[] answer = new int[score.Length];
			
			List<int> hall = new List<int>();

			for(int i = 0; i < score.Length; i++)
			{
                if (hall.Count == k)
                {
					if (hall[0] > score[i])
					{
						answer[i] = hall[0];
						continue;
					}
					hall.RemoveAt(0);
                }

				hall.Add(score[i]);
				hall.Sort();
				answer[i] = hall[0];
            }
	
			return answer;
    }
}