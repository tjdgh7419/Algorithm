using System;

public class Solution {
    public int solution(int[] arr) {
        int answer = 0;

		int i = 1;
		bool chk = false;
		Array.Sort(arr);

		while (answer == 0)
		{
			int val = arr[arr.Length - 1] * i;
			for(int j = 0; j < arr.Length - 1; j++)
			{
				if (val % arr[j] != 0)
				{
					chk = true;
					break;
				}
			}
			if (!chk)
			{
				answer = val;
				break;
			}
			else
			{
				chk = false;
			}
			i++;
		}

        return answer;
    }
}