using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public int solution(int[] elements) {
      HashSet<int> hs = new HashSet<int>();

		for(int i = 0; i < elements.Length; i++)
		{
			int n = 1;
			int idx = i;
			int sum = 0;

			while (n <= elements.Length)
			{
				sum += elements[idx++];
				hs.Add(sum);

				if (idx >= elements.Length) idx = 0;

				n++;
			}
		}

        return hs.Count();
    }
}