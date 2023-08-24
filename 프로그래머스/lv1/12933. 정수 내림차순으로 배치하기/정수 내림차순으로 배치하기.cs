using System;
public class Solution {
    public long solution(long n) {
        string str = n.ToString();
			int[] arr = new int[str.Length];
			long answer = 0;
			
			for(int i = 0; i < arr.Length; i++)
			{
				arr[i] = (int)(n % 10);
				n = n / 10;
			}
			Array.Sort(arr);

			for(int i = 0; i < arr.Length; i++)
			{
				answer += arr[i] * (long)Math.Pow(10, i);
			}

			return answer;
    }
}