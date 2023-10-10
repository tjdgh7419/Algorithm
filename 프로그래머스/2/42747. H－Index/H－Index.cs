using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public int solution(int[] citations) {
    int answer = 0;
		int cnt = 0;
		Array.Sort(citations);

		for (int i = 1; i <= citations.Length; i++)
		{
			for(int j = 0; j < citations.Length; j++)
			{
				if(i <= citations[j])
				{
					cnt++;
				}

				if(cnt >= i)
				{
					answer = i;	
				}
			}
			cnt = 0;
		}
		return answer;
    }
}