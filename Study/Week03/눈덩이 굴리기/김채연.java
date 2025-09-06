import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static boolean[] visited;
    static long MAX;
    static int N, M;

    static int[] snow;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        snow = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            snow[i] = Integer.parseInt(st.nextToken());
        }
        visited = new boolean[N + 1];
        backtrack(0, 1, 0);
        System.out.println(MAX);
    }

    private static void backtrack(int depth, long size, int idx) {
        if (depth == M) {
            MAX = Math.max(MAX, size);
            return;
        }
        if (idx == N) {
            MAX = Math.max(MAX, size);
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (idx + 2 >= i && !visited[i]) {
                visited[i] = true;
                if (idx + 2 == i) {
                    backtrack(depth + 1, (size / 2) + snow[i], i);
                } else if (idx + 1 == i) {
                    backtrack(depth + 1, size + snow[i], i);
                }
                visited[i] = false;
            }
        }
    }
}