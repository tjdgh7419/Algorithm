using System;
public class Solution {
    public long solution(long n) {
        int i = 0;
			long answer = 0;
			long tmp = 0;
			while (tmp < n)
			{
				tmp = (long)Math.Pow(i, 2);
				if(tmp == n)
				{
					answer = (long)Math.Pow(i + 1, 2);
					return answer;
				}
				i++;
			}
			return -1;
    }
}