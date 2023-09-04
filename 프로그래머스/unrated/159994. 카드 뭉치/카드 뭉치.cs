using System;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        string answer = "Yes";
			int cnt1 = 0;
			int cnt2 = 0;
			for(int i = 0; i < goal.Length; i++)
			{
				if (cnt1 < cards1.Length && cards1[cnt1] == goal[i])
				{
					cnt1++;
					continue;
				}

				else if(cnt2 < cards2.Length && cards2[cnt2] == goal[i])
				{
					cnt2++;
					continue;
				}
				else
				{
					return "No";
				}
			}
			return answer;
    }
}