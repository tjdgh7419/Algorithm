using System;
using System.Buffers;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

public class Solution {
    public int[] solution(string today, string[] terms, string[] privacies) {
      int[] answer = new int[] { };
		string[] infor = today.Split('.');
		
		var term = new Dictionary<string, string>();
		int eYear = int.Parse(infor[0]);
		int eMonth = int.Parse(infor[1]);
		int eDay = int.Parse(infor[2]);
		List<int> ls  = new List<int>();

		for (int i = 0; i < terms.Length; i++)
		{
			string[] dic = terms[i].Split(' ');
			term.Add(dic[0], dic[1]);
        }


        for (int i = 0; i < privacies.Length; i++)
        {
            string[] priv = privacies[i].Split(".");
            string[] kDay = priv[2].Split(" ");

            int year = int.Parse(priv[0]);
            int month = int.Parse(priv[1]) + int.Parse(term[kDay[1]]);
            int day = int.Parse(kDay[0]);
            if (month > 12)
            {
                int n = month / 12;
                
                if(month % 12 == 0)
                {
					year += n - 1;
					month = 12;
                }
                else
                {
					year += n;
					month = month % 12;
                }
            }

            if (eYear > year)
            {
				ls.Add(i + 1);
				continue;
            }
            else if(eYear == year && eMonth > month)
            {
                ls.Add(i + 1);
                continue;
            }
            else if(eYear == year && eMonth == month && eDay >= day)
            {
                ls.Add(i + 1);
                continue;
            }
           
        }

        ls.Sort();
        return ls.ToArray();
    }
}