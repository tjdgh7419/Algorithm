using System;

public class Solution {
    public int[] solution(string[] keymap, string[] targets) {
       int[] answer = new int[targets.Length];
		string str = "";
		int ans = 0;
		int min = int.MaxValue;
		bool chk = false;
		for(int i = 0; i < targets.Length; i++)
		{
			chk = false;
			str = targets[i];
			for (int j = 0; j < targets[i].Length; j++)
			{
				for (int k = 0; k < keymap.Length; k++)
				{
					if (keymap[k].Contains(str[j]))
					{
						min = Math.Min(min, keymap[k].IndexOf(str[j]));
					}
				}
				if(min == int.MaxValue)
				{
					ans = 0;
					chk = true;
					answer[i] = -1;
					break;
				}
				ans += min + 1;
				min = int.MaxValue;
			}
			if (!chk)
			{
				answer[i] = ans;
				ans = 0;
			}
		}
		
		return answer;
    }
}