import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[][] paper;
    static int whiteCount = 0;  // 하얀색 색종이 개수
    static int blueCount = 0;   // 파란색 색종이 개수

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        paper = new int[N][N];

        // 색종이 정보 입력
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 분할 정복 시작
        divideAndConquer(0, 0, N);

        System.out.println(whiteCount);
        System.out.println(blueCount);
    }

    static void divideAndConquer(int startRow, int startCol, int size) {
        // 현재 영역이 모두 같은 색인지 확인
        if (isSameColor(startRow, startCol, size)) {
            // 같은 색이면 해당 색종이 개수 증가
            if (paper[startRow][startCol] == 0) {
                whiteCount++;
            } else {
                blueCount++;
            }
            return;
        }

        // 같은 색이 아니면 4분할
        int halfSize = size / 2;

        // 1사분면 (왼쪽 위)
        divideAndConquer(startRow, startCol, halfSize);

        // 2사분면 (오른쪽 위)
        divideAndConquer(startRow, startCol + halfSize, halfSize);

        // 3사분면 (왼쪽 아래)
        divideAndConquer(startRow + halfSize, startCol, halfSize);

        // 4사분면 (오른쪽 아래)
        divideAndConquer(startRow + halfSize, startCol + halfSize, halfSize);
    }

    static boolean isSameColor(int startRow, int startCol, int size) {
        int firstColor = paper[startRow][startCol];

        for (int i = startRow; i < startRow + size; i++) {
            for (int j = startCol; j < startCol + size; j++) {
                if (paper[i][j] != firstColor) {
                    return false;
                }
            }
        }
        return true;
    }
}