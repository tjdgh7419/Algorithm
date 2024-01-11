import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.io.IOException;


public class Main {
    static int N;
    static int dist[];
    static ArrayList<Integer>[]AL;
    static boolean visit[], cycle;
    static StringBuilder sb = new StringBuilder();
    static Queue<Integer>q = new LinkedList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        

        N = Integer.parseInt(br.readLine());

        AL = new ArrayList[N + 1];
        visit = new boolean[N + 1];
        dist = new int[N + 1];
        Arrays.fill(dist, -1);
        for(int i = 0; i < N + 1; i++) {
            AL[i] = new ArrayList<>();
        }

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());

            AL[n1].add(n2);
            AL[n2].add(n1);
        }
        dfs(1, 0);

        bfs();

        for(int i = 1; i <= N; i++) {
            sb.append(dist[i]).append(' ');
        }
        
        dfs(1, 0);
        System.out.println(sb);
    }
    public static void bfs() {
        int cnt = 1;
        while(!q.isEmpty()) {
            int len = q.size();
            for(int j = 0; j < len; j++) {
                int tmp = q.poll();
                for(int i : AL[tmp]) {
                    if(dist[i] != -1) continue;
                    dist[i] = cnt;
                    q.add(i);
                }
            }
            cnt++;
        }
    }

    public static void dfs(int start, int prev) {

        visit[start] = true;
        for(int i : AL[start]) {
            if(visit[i] && prev != i) {
                cycle = true;
                dist[i] = 0;
                q.add(i);
                break;
            }
            else if(!visit[i]) {
                dfs(i, start);
                if(cycle) {
                    if(dist[i] == 0) {
                        cycle = false;
                    }
                    else {
                        dist[i] = 0;
                        q.add(i);
                    }
                    return;
                }
            }
        }
    }
}