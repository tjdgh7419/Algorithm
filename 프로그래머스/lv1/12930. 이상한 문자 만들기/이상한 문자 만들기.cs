public class Solution {
    public string solution(string s) {
      string answer = "";
			string word = "";
			int cnt = 0;
			for (int i = 0; i < s.Length; i++)
			{
				if (s[i] == ' ')
				{
					cnt = 0;
					answer += s[i];
					continue;
				}
				else if (cnt % 2 == 0)
				{
					answer += s[i].ToString().ToUpper();
					cnt++;
				}
				else
				{
					answer += s[i].ToString().ToLower();
					cnt++;
				}
				
			}
			return answer;
    }
}