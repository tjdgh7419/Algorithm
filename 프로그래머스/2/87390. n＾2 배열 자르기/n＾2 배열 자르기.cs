using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public int[] solution(int n, long left, long right) {
        List<int> result = new List<int>();
		for (long i = left; i < right + 1; i++)
		{
			long v = Math.Max(i / n, i % n)+1;
			result.Add((int)v);
		}

		return result.ToArray();
    }
}