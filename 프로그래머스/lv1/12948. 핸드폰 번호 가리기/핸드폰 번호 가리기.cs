using System;
public class Solution {
    public string solution(string phone_number) {
        string answer = "";

			int a = phone_number.Length;
			string str = new string('*', phone_number.Length - 4);
			
			string str2 = phone_number.Substring(phone_number.Length - 4);
			answer = str + str2;
			

			return answer;
    }
}