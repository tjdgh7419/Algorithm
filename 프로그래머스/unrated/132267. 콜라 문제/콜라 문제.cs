using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int a, int b, int n) {
    int answer = 0;
			int rest = 0;
			while (n >= a)
			{ 
				rest = n % a;
				n = n / a;
				answer += n * b;
				n = n * b + rest;
			}
			
            return answer;
    }
}