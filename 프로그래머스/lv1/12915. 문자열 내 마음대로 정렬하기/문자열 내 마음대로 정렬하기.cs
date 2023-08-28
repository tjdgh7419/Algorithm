using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    public string[] solution(string[] strings, int n) {
        string[] answer = new string[] { };

			answer = strings.OrderBy(s => s).OrderBy(s => s[n]).ToArray();

			return answer;
    }
}