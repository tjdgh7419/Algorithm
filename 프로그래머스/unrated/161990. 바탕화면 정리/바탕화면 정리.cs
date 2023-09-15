using System;

public class Solution {
    public int[] solution(string[] wallpaper) {
        int[] answer = new int[4];
		int min = int.MaxValue;
		int max = int.MinValue;
		for(int i = 0; i < wallpaper.Length; i++)
		{
			if (wallpaper[i].Contains('#'))
			{
				answer[0] = i; break;
			}
		}

		for(int i = 0; i < wallpaper.Length; i++)
		{
			for(int j = 0; j < wallpaper[i].Length; j++)
			{
				if (wallpaper[i][j] == '#')
				{
					min = Math.Min(min, j);
					break;
				}
			}
			if(min == 0)
			{
				break;
			}
		}
		answer[1] = min;

		for(int i = wallpaper.Length - 1; i >= 0; i--)
		{
			if (wallpaper[i].Contains('#'))
			{
				answer[2] = i + 1; break;
			}
		}

		for (int i = 0; i < wallpaper.Length; i++)
		{
			for (int j = wallpaper[i].Length - 1; j >= 0; j--)
			{
				if (wallpaper[i][j] == '#')
				{				
					max = Math.Max(max, j + 1);
					break;
				}
			}
			if (max == wallpaper[i].Length + 1)
			{
				break;
			}
		}
		answer[3] = max;

		return answer;
    }
}