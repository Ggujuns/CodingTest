import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static int N;
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, -1, 0, 1};
    static int MAX = Integer.MIN_VALUE
    static int[][] arr;
    static boolean[][] visited;
    static boolean[][] water;
    static Set<Integer> set = new TreeSet<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        arr = new int[N][N];
        visited = new boolean[N][N];
        water = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int num = Integer.parseInt(st.nextToken());
                set.add(num);
                arr[i][j] = num;
            }
        }
        Integer[] heights = set.toArray(new Integer[0]);

        for (int i = 0; i <= heights[heights.length - 1]; i++) {
            MAX = Math.max(bfs(i), MAX);
        }
        System.out.println(MAX);
    }

    private static int bfs(int height) {
        int count = 0;
        visited = new boolean[N][N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (!visited[r][c] && arr[r][c] > height) {
                    count++;
                    Deque<int[]> dq = new ArrayDeque<>();
                    dq.add(new int[]{r, c});
                    while (!dq.isEmpty()) {
                        int[] carr = dq.poll();
                        int cr = carr[0];
                        int cc = carr[1];
                        for (int i = 0; i < 4; i++) {
                            int nr = cr + dr[i];
                            int nc = cc + dc[i];
                            if (isValid(nr, nc) && !visited[nr][nc] && height < arr[nr][nc]) {
                                visited[nr][nc] = true;
                                dq.add(new int[]{nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }

    private static boolean isValid(int nr, int nc) {
        return (0 <= nr && N > nr) && (0 <= nc && N > nc);
    }
}