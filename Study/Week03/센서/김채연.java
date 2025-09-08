import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int N, K, answer = 0;
    static Integer[] arr;
    static Set<Integer> set = new HashSet<>();
    static int[] diff;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            set.add(num);
        }
        arr = set.toArray(new Integer[0]);
        Arrays.sort(arr);
        diff = new int[set.size() - 1];
        for (int i = 0; i < set.size() - 1; i++) {
            diff[i] = arr[i + 1] - arr[i];
        }
        Arrays.sort(diff);
        for (int i = 0; i < set.size() - K; i++) {
            answer += diff[i];
        }
        System.out.println(answer);
    }
}
