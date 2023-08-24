using System;
public class Solution {
    public bool solution(int x) {
        String str = x.ToString();
			bool answer = true;
			int sum = 0;
			int n = x;
			for(int i = 0; i < str.Length; i++)
			{
				sum += n % 10;
				n = n / 10;
			}
			if(x % sum == 0)
			{
				answer = true;
			}
			else
			{
				answer = false;
			}
			return answer;
    }
}