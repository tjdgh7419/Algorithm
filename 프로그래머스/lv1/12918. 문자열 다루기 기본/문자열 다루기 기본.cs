public class Solution {
    public bool solution(string s) {
       bool answer = true;
			bool chk = false;
			foreach(char i in s)
			{
				if (!char.IsDigit(i))
				{
					chk = true;
				}
			}
			if ((s.Length == 4 || s.Length == 6) && !chk) answer = true; 
			else answer = false;
			
			return answer;
    }
}