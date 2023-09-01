using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string solution(int a, int b) {
        string answer = "";
			int sum = 0;
			int[] arr = new int[] {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  };
			string[] day = new string[] { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
			int cnt = 5;
			for(int i = 0; i < a - 1; i++)
			{
				sum += arr[i];
			}
			sum += b;

			for(int i = 0; i < sum; i++)
			{
				
				answer = day[cnt];
				cnt++;
				if (cnt == 7) cnt = 0;
			}
            
            return answer;
    }
}