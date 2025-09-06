import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    /*
    슬라이딩 윈도우를 이용해서 cnt
    윈도우의 크기: k (연속해서 먹는 접시의 수)

     */
    static int[] sushi;
    static int d, k, c, N, cnt;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        arr = new int[N * 2];
        sushi = new int[d + 1];

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for (int i = N; i < arr.length; i++) {
            arr[i] = arr[i % N];
        }

        //슬라이딩 윈도우 초기값 세팅
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < k; i++) {
            int cur = arr[i];
            if (++sushi[cur] == 1) {
                cnt++;
            }
        }
        if (++sushi[c] == 1) {
            cnt++;
        }

        max = cnt;

        for (int i = 1; i <= N + k; i++) {
            int remove = arr[i - 1];
            int add = arr[i - 1 + k];

            if (--sushi[remove] == 0) {
                cnt--;
            }
            if (++sushi[add] == 1) {
                cnt++;
            }
            max = Math.max(cnt, max);
        }
        if (++sushi[c] == 1) {
            cnt++;
        }
        System.out.println(max);
    }
}
