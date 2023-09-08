using System;
using System.Buffers;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
		int[] arr = new int[n + 1];
		
		for(int i = 0; i < reserve.Length; i++)
		{
			arr[reserve[i]] = 1;
		}

		for (int i = 0; i < lost.Length; i++)
		{
			if (arr[lost[i]] != 1)
			{
				arr[lost[i]] = -1;
			}
			else
			{
				arr[lost[i]] = 0;
			}
		}

		for(int i = 1; i < arr.Length; i++)
		{
			if (arr[i] == -1 && i > 1 && i < arr.Length - 1)
			{
				if (arr[i - 1] == 1)
				{
					arr[i - 1] = 0;
					arr[i] = 0;
				}
				else if (arr[i + 1] == 1)
				{
					arr[i + 1] = 0;
					arr[i] = 0;
				}
			}
			else if (arr[i] == -1 && i == 1)
			{
				if (arr[i + 1] == 1)
				{
					arr[i + 1] = 0;
					arr[i] = 0;
				}
			}
			else if (arr[i] == -1 && i == arr.Length - 1)
			{
				if (arr[i - 1] == 1)
				{
					arr[i - 1] = 0;
					arr[i] = 0;
				}
			}
        }

		for(int i = 1; i < arr.Length; i++)
		{
			if (arr[i] == 0 || arr[i] == 1)
			{
				answer++;
			} 
		}

		return answer;
    }
}