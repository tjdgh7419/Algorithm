public class Solution {
    public string solution(string s) {
      string answer;
			string m1 = "";
			string m2 = "";
			int len = s.Length;
			if(len % 2 == 0)
			{
				m1 = s[len / 2 - 1].ToString();
				m2 = s[len / 2].ToString();
			}
			else
			{
				m1 = s[len / 2].ToString();
			}
			answer = m1 + m2;
			
			return answer;
    }
}