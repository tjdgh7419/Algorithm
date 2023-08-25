

public class Solution {
    public int solution(string t, string p) {
       int answer = 0;
			long equ = 0;

			long b = long.Parse(p);

			for (int i = 0; i < t.Length - p.Length + 1; i++)
			{
				equ = long.Parse(t.Substring(i, p.Length));
				if (b >= equ)
				{
					answer++;
				}
			}
			return answer;
    }
}