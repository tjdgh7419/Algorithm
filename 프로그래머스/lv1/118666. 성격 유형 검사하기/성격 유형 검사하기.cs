using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

public class Solution {
    public string solution(string[] survey, int[] choices) {
       string answer = "";
		int[] score = new int[] { 3, 2, 1, 0, 1, 2, 3 };
		string[] type = new string[] { "RT", "CF", "JM", "AN"};
		var dc = new Dictionary<char, int>();
		dc.Add('R', 0);
		dc.Add('T', 0);
		dc.Add('C', 0);
		dc.Add('F', 0);
		dc.Add('J', 0);
		dc.Add('M', 0);
		dc.Add('A', 0);
		dc.Add('N', 0);


		for (int i = 0; i < survey.Length; i++)
		{
			if (choices[i] < 4)
			{
				dc[survey[i][0]] += score[choices[i] - 1];
			}
			else if (choices[i] > 4)
			{
				dc[survey[i][1]] += score[choices[i] - 1];
			}
		}

		for (int i = 0; i < type.Length; i++)
		{
			if (dc[type[i][0]] > dc[type[i][1]])
			{
				answer += type[i][0].ToString();
			}
			else if (dc[type[i][0]] < dc[type[i][1]])
			{
				answer += type[i][1].ToString();
			}
			else
			{
				if (type[i][0] > type[i][1])
				{
					answer += type[i][1].ToString();
				}
				else
				{
					answer += type[i][0].ToString();
				}
			}
		}

		return answer;
    }
}