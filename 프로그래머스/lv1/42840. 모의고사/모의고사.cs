using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

 public class Solution
    {
        public int[] solution(int[] answers)
        {
            List<int> answer = new List<int>();
			
            // 반복되는 정답 숫자의 배열
            int[] student_1 = new int[] { 1, 2, 3, 4, 5 };
            int[] student_2 = new int[] { 2, 1, 2, 3, 2, 4, 2, 5 };
            int[] student_3 = new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
			
            // 각 학생의 정답을 카운트하기 위한 배열
            int[] count = new int[3];
			
            // 정답 숫자를 반복적으로 순회하기 위한 열거자
            IEnumerator student1_enum = student_1.GetEnumerator();
            IEnumerator student2_enum = student_2.GetEnumerator();
            IEnumerator student3_enum = student_3.GetEnumerator();

            for(int i = 0; i < answers.Length; ++i)
            {
            	// 열거자의 끝일 경우 요소를 처음으로 리셋
                if (student1_enum.MoveNext() == false)
                {
                    student1_enum.Reset();
                    student1_enum.MoveNext();
                }

                if (student2_enum.MoveNext() == false)
                {
                    student2_enum.Reset();
                    student2_enum.MoveNext();
                }

                if (student3_enum.MoveNext() == false)
                {
                    student3_enum.Reset();
                    student3_enum.MoveNext();
                }
				
                // 현재 정답 요소와 문제의 답이 일치하면 각각을 카운트
                if ((int)student1_enum.Current == answers[i]) count[0]++;
                if ((int)student2_enum.Current == answers[i]) count[1]++;
                if ((int)student3_enum.Current == answers[i]) count[2]++;
            }
			
            // 카운트 배열의 가장 높은 수를 찾고, 정답 리스트에 추가함
            int max = count.Max();
            for (int i = 0; i < count.Length; ++i)
            {
                if (max == count[i])
                {
                    answer.Add(i+1);
                }
            }
			
            // 정답 리스트 정렬
            answer.Sort();

            return answer.ToArray();
        }
    }