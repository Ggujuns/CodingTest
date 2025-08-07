import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class BJ1863 {
    static int N, X, Y, cnt;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        Deque<Integer> stack = new ArrayDeque<>();
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            X = Integer.parseInt(st.nextToken());
            Y = Integer.parseInt(st.nextToken());
            while (!stack.isEmpty() && stack.peekFirst() > Y) {
                stack.pollFirst(); //높이가 이전보다 낮아지면 직사각형 종료
                cnt++;
            }
            if (!stack.isEmpty() && stack.peekFirst() == Y) {
                continue;
            }
            if (Y != 0) {
                stack.addFirst(Y);
            }
        }
        cnt += stack.size();
        System.out.println(cnt);
    }
}
