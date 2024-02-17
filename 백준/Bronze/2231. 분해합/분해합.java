import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;


public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int result = 0;
        String a = br.readLine();
        
        int N_len = a.length();
        int N = Integer.parseInt(a);
        
        for(int i = (N - (N_len * 9)); i < N; i++) {
            int num = i;
            int sum = 0;

            while(num != 0) {
                sum += num % 10;
                num /= 10;
            }

            if(sum + i == N) {
                result = i;
                break;
            }
            
        }
        System.out.println(result);
    }
}