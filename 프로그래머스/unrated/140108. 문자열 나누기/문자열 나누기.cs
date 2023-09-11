using System;

public class Solution {
    public int solution(string s) {
       int answer = 0;
		int cnt = 1;
		char first = 'a';
		bool chk = false;
		for(int i = 0; i < s.Length; i++)
		{
			if(i == s.Length - 1)
			{
				answer++;
				break;
			}
			if (!chk) 
			{
				first = s[i];
				chk = true;
				continue;
			}

			if (s[i] == first)
			{
				cnt++;
			}
			else
			{
				cnt--;
				if(cnt == 0)
				{
					cnt++;
					chk = false;
					answer++;
				}
			}

			
		}
		return answer; 
    }
}