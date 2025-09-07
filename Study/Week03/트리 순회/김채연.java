import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class BJ_22856 {
    static int N, a, b, c = 0;
    static int[] left;
    static int[] right;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        left = new int[N + 1];
        right = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            left[a] = b;
            right[a] = c;

        }
        // 1) 중위 순회 마지막 노드 찾기
        int lastNode = findLast(1);

        // 2) 루트 → 마지막 노드까지의 거리 구하기
        int depth = findDepth(1, lastNode);

        // 3) 총 이동 횟수 계산
        int result = 2 * (N - 1) - depth;
        System.out.println(result);
    }

    // 중위 순회의 마지막 노드 = 가장 오른쪽 끝 노드
    static int findLast(int root) {
        int cur = root;
        while (right[cur] != -1) {
            cur = right[cur];
        }
        return cur;
    }

    // 루트에서 target까지 거리
    static int findDepth(int root, int target) {
        Deque<int[]> dq = new ArrayDeque<>();
        dq.add(new int[]{root, 0}); // {노드번호, 깊이}

        while (!dq.isEmpty()) {
            int[] cur = dq.poll();
            int node = cur[0], depth = cur[1];
            if (node == target) {
                return depth;
            }

            if (left[node] != -1) {
                dq.add(new int[]{left[node], depth + 1});
            }
            if (right[node] != -1) {
                dq.add(new int[]{right[node], depth + 1});
            }
        }
        return -1;
    }

}
