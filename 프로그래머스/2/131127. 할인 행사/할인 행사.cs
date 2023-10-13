using System;

public class Solution {
    public int solution(string[] want, int[] number, string[] discount) {
        int answer = 0;

		for(int i = 0; i <discount.Length - 9; i++)
		{
			int j;
			for(j = 0; j <want.Length; j++)
			{
				int chk = 0;
				for (int k = i; k < i + 10; k++)
				{
					if (discount[k].Equals(want[j])) chk++;
				}
				if(chk < number[j])
				{
					break;
				}
			}
			if (j == want.Length) answer++;
		}
		return answer;
    }
}