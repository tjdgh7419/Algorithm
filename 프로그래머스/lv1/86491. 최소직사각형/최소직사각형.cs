
using System;

public class Solution {
    public int solution(int[,] sizes) {
        int answer = 0;
            int rmax = 0;
            int cmax = 0;
            for(int i = 0; i < sizes.GetLength(0); i++)
            {
                int row = sizes[i, 1];
                int col = sizes[i, 0];

                if(col < row)
                {
                    row = sizes[i, 0];
                    col = sizes[i, 1];
                }
                rmax = Math.Max(rmax, row);
                cmax = Math.Max(cmax, col);
            }
            answer = rmax * cmax;
            return answer;
    }
}