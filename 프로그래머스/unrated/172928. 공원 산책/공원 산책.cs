using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
public class Solution {
    public int[] solution(string[] park, string[] routes) {
     int[] answer = new int[2];
		int w = 0;
		int h = 0;
		for(int i = 0; i < park.Length; i++)
		{
			if (park[i].Contains('S'))
			{
				w = park[i].IndexOf('S');
				h = i; 
				break;
			}
		}

		for(int i = 0; i < routes.Length; i++)
		{
			if (routes[i][0] == 'E' && w + (routes[i][2] - '0') <= park[0].Length - 1)
			{
				bool chk = false;
				for(int j = w; j <= w + (routes[i][2] - '0'); j++)
				{
					if(park[h][j] == 'X')
					{
						chk = true;
						break;
					}
				}
				if (!chk)
				{
					w += routes[i][2] - '0';
				}
			}
			else if (routes[i][0] == 'W' && w - (routes[i][2] - '0') >= 0)
			{
				bool chk = false;
				for (int j = w; j >= w - (routes[i][2] - '0'); j--)
				{
					if (park[h][j] == 'X')
					{
						chk = true;
						break;
					}
				}
				if (!chk)
				{
					w -= routes[i][2] - '0';
				}
			}
			else if (routes[i][0] == 'S' && h + (routes[i][2] - '0') <= park.Length - 1)
			{
				bool chk = false;
				for (int j = h; j <= h + (routes[i][2] - '0'); j++)
				{
					if (park[j][w] == 'X')
					{
						chk = true;
						break;
					}
				}
				if (!chk)
				{
					h += routes[i][2] - '0';
				}
			}
			else if (routes[i][0] == 'N' && h - (routes[i][2] - '0') >= 0)
			{
				bool chk = false;
				for (int j = h; j >= h - (routes[i][2] - '0'); j--)
				{
					if (park[j][w] == 'X')
					{
						chk = true;
						break;
					}
				}
				if (!chk)
				{
					h -= routes[i][2] - '0';
				}
			}
		}
		answer[0] = h; 
		answer[1] = w;

        return answer;
    }
}