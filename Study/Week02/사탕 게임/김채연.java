import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    /*
    고른 칸에 들어있는 인접하고, 색깔이 다른 사탕을 서로 교환함.
    모두 같은 색으로 이뤄져있는 가장 긴 연속 부분을 고른 다음, 그 사탕을 모두 먹음.(행또는 열)
    시간제한 1초 -> 10^8
    o(N^3)까지 가능.
    배열 탐색하다가 -> 만약 인접(bfs) 한거랑  색깔이 다르면 바꿔보고
    행, 열 -> 각각 색깔 다른거 세보기
    만약 바로 다른 색깔이 나오면 return;
     */
    static char[][] arr;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int N;
    static int MAX = Integer.MIN_VALUE;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new char[N][N];
        //입력받기
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                arr[i][j] = line.charAt(j);
            }
        }
        //순회전에 바꾸지않아도 MAX값이 있는지를 봄
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                MAX = Math.max(MAX, Math.max(getRowCnt(i), getColCnt(j)));
            }
        }
        //배열 순회
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                circut(i, j);
            }
        }
        System.out.println(MAX);
    }

    private static boolean isValid(int i, int j) {
        return (i >= 0 && i < N) && (j >= 0 && j < N);
    }

    private static void circut(int i, int j) {
        for (int n = 0; n < 4; n++) {
            int nr = dx[n] + i;
            int nc = dy[n] + j;

            if (isValid(nr, nc) && arr[nr][nc] != arr[i][j]) { //다르면
                swap(i, j, nr, nc);
                MAX = Math.max(MAX, Math.max(getRowCnt(i), getColCnt(j)));
                swap(i, j, nr, nc); //다시 돌리기.
            }
        }
    }

    private static int getRowCnt(int row) { //특정 행 i
        int cnt = 1;
        int best = 1;
        for (int j = 1; j < N; j++) {
            if (arr[row][j] == arr[row][j - 1]) { //그 이전꺼랑 같으면
                cnt++; //현재 이어지는 구간의 길이
            } else {//다른게 나오면
                best = Math.max(best, cnt); // 연속값이 끊겼으므로 최댓값을 갱신한다.
                cnt = 1; //현재 연속 길이를 초기화한다.
            }
        }
        return Math.max(best, cnt);
    }

    private static int getColCnt(int column) {
        int cnt = 1;
        int best = 1;
        for (int j = 1; j < N; j++) {
            if (arr[j][column] == arr[j - 1][column]) {
                cnt++; //현재 길이를 갱신한다.
            } else {
                best = Math.max(cnt, best); // 최댓값을 갱신한다.
                cnt = 1; //연속이 끊겼으므로 1로 초기화
            }
        }
        return Math.max(best, cnt);
    }

    private static void swap(int r1, int c1, int r2, int c2) {
        char t = arr[r1][c1];
        arr[r1][c1] = arr[r2][c2];
        arr[r2][c2] = t;
    }
}