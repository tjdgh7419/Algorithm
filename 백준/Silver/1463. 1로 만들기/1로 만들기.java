import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

       System.out.println(recur(N, 0));
    }

    static int recur(int N, int cnt) {
        if(N < 2) {
            return cnt;
        }

        return Math.min(recur(N/2, cnt + 1 + (N % 2)), recur(N/3, cnt + 1 + (N % 3)));
    }

}