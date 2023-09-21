using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

public class Solution {
    public int[] solution(string[] id_list, string[] report, int k) {
        int[] answer = new int[id_list.Length];

		report = report.Distinct().ToArray();
        
  
		var r_Value = new Dictionary<string, List<string>>();

		Dictionary<string, int> result = new Dictionary<string, int>();

		for (int i = 0; i < report.Length; i++)
		{
			string[] arr = report[i].Split(' ');

			string fName = arr[0];
			string sName = arr[1];

			if (!r_Value.ContainsKey(sName))
			{
				List<string> rName = new List<string>();
				rName.Add(fName);
				r_Value.Add(sName, rName);
				continue;
			}

			if (!r_Value[sName].Contains(fName))
			{
				r_Value[sName].Add(fName);
			}
		}

		for(int i = 0; i < id_list.Length; i++)
		{
			foreach(KeyValuePair<string, List<string>> item in r_Value)
			{
				if (item.Value.Contains(id_list[i]))
				{
					if(item.Value.Count >= k)
					{
						answer[i] = ++answer[i];
					}
				}
			}
		}
		return answer;
    }
}