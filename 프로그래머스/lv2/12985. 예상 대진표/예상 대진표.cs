using System;

class Solution
{
    public int solution(int n, int a, int b)
    {
     int answer = 1;
		int tmp = 0;
		if(a > b)
		{
			tmp = a;
			a = b; 
			b = tmp;
		}
		while (Math.Abs(a - b) != 1 || a % 2 != 1 || b % 2 != 0)
		{
			
			if (a % 2 == 0)
			{
				a /= 2;
			}
			else
			{
				a = (a / 2) + 1;
			}

			if(b % 2 == 0)
			{
				b /= 2;
			}
			else
			{
				b = (b / 2) + 1;
			}
			answer++;		
		}	
		return answer;

    }
}