import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    /*
    상담 완료 걸리는 기간 T
    받을 수 있는 금액 P
     */
    static int N, size;
    static int MAX = Integer.MIN_VALUE;
    static int[][] map;
    static int[] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        map = new int[N + 1][2];
        dp = new int[N + 2];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            int R = i + 1 + T;
            map[i + 1][0] = P;
            map[i + 1][1] = R;
        }

        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            dp[i + 1] = Math.max(dp[i + 1], dp[i]); //상담을 하지 않을떄
            int next = map[i][1];
            if (next <= N + 1) {
                dp[next] = Math.max(dp[next], dp[i] + map[i][0]);
            }
        }

        MAX = Math.max(MAX, dp[N + 1]);

        System.out.println(MAX);

    }
}