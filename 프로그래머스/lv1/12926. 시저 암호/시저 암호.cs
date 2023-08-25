public class Solution {
    public string solution(string s, int n) {
      string answer = "";
			char Cval;
			int Ival = 0;
			int ori = 0;
			for(int i = 0; i < s.Length; i++)
			{
				if (s[i] != ' ')
				{
					ori = s[i];
					Ival = s[i] + n;
					if(Ival > 122)
					{
						Ival -= 26;
					}
					 if(ori > 64 && ori < 91 && 116 > Ival && Ival > 90)
					{
						Ival -= 26;
					}
					Cval = (char)Ival;
					answer += Cval.ToString();
					continue;
				}
				answer += s[i];
			}
			return answer;
    }
}