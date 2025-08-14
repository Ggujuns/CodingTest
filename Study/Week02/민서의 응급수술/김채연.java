import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] parent;
    static int[] rank;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // Union-Find 초기화
        parent = new int[N + 1];
        rank = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int cyclesToRemove = 0;  // 제거해야 할 사이클 간선 수

        // 간선 처리
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            // 이미 같은 컴포넌트에 속해있으면 사이클을 만드는 간선
            if (find(u) == find(v)) {
                cyclesToRemove++;
            } else {
                // 다른 컴포넌트면 연결
                union(u, v);
            }
        }

        int components = 0;
        for (int i = 1; i <= N; i++) {
            if (find(i) == i) {  // 루트 노드인 경우
                components++;
            }
        }

        // 컴포넌트를 하나로 연결하기 위해 필요한 간선 수
        int edgesToAdd = components - 1;

        // 총 연산 횟수 = 제거할 간선 수 + 추가할 간선 수
        int totalOperations = cyclesToRemove + edgesToAdd;

        System.out.println(totalOperations);
    }

    static int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 경로 압축
        }
        return parent[x];
    }

    static void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // rank가 낮은 트리를 높은 트리 아래에 붙임
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
}