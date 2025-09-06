import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static int[] dx = {-1, -1, -1};
    static int[] dy = {-1, 0, 1};
    static int N, cnt;
    static int[][] arr;
    static boolean[][] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        visited = new boolean[N][N];
        backtracking(0);
        System.out.println(cnt);
    }

    private static void backtracking(int depth) { // depth를 깊이 또는 행으로 봄. 퀸은 한 행에 하나만 놓을 수 있기 때문이다.
        if (depth == N) {
            cnt++;
            return;
        }
        for (int c = 0; c < N; c++) {
            if (isValid(depth, c)) {
                visited[depth][c] = true;
                backtracking(depth + 1);
                visited[depth][c] = false; //다시 되돌린다.(다음 선택지 탐색)
            }
        }
    }

    private static boolean isValid(int r, int c) {
        for (int i = 1; i <= r; i++) { //1부터 위쪽 모든 행을 탐색
            for (int j = 0; j < 3; j++) {
                int nr = r + dx[j] * i;
                int nc = c + dy[j] * i;
                if (nc < N && nc >= 0 && visited[nr][nc]) { //이미 방문한 선택지면 false
                    return false;
                }
            }
        }
        return true;
    }
}