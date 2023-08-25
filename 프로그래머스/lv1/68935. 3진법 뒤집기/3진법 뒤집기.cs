using System;

public class Solution {
    public int solution(int n) {
       int answer = 0;
			int cnt = 0;
			int res = 0;

			string str = "";
			while (n != 0)
			{
				res = n % 3;
				n = n / 3;
				cnt++;
				str += res.ToString();
			}
            
			for(int i = 0; i < cnt; i++)
			{
				answer += (int)Math.Pow(3, i) * (int)char.GetNumericValue(str[cnt - i - 1]);
			}
            return answer;
    }
}