import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class 유기농_배추 {
    /*상하좌우 큐에 계속 넣고 체크 만약 0이나오면 넣지않고 ->
    큐가 비게되면 배추가 잇는 다른 좌표를 넣음.
     필요한것: Deque, Boolean [][] 배열 -> true이면 배추가 있는거임
     그리고 count 증가
     */
    static int count;
    static boolean[][] arr;
    static int T, M, N, K, X, Y;
    static Deque<int[]> dq = new ArrayDeque<>();
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken()); //가로
            N = Integer.parseInt(st.nextToken()); //세로
            K = Integer.parseInt(st.nextToken()); //위치의 갯수
            arr = new boolean[M][N];
            count = 0;
            dq = new ArrayDeque<>();
            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                X = Integer.parseInt(st.nextToken());
                Y = Integer.parseInt(st.nextToken());
                arr[X][Y] = true;
            }
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (arr[i][j]) {
                        dfs(i, j);
                    }
                }
            }
            sb.append(count).append("\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int x, int y) {
        dq.add(new int[]{x, y});
        count++;
        while (!dq.isEmpty()) {
            int[] ar = dq.poll();
            int cx = ar[0];
            int cy = ar[1];
            arr[cx][cy] = false;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (isValid(nx, ny) && arr[nx][ny]) {
                    arr[nx][ny] = false;
                    dq.add(new int[]{nx, ny});
                }
            }
        }
    }

    private static boolean isValid(int x, int y) {
        return (x >= 0 && x < M) && (y >= 0 && y < N);
    }
}