import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] cnt = new int[295246];
    static int P, V;
    static String A;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = st.nextToken();
        P = Integer.parseInt(st.nextToken());
        cnt[Integer.parseInt(A)]++;
        for (int i = 0; i < cnt.length; i++) {
            char[] carr = A.toCharArray();
            for (char c : carr) {
                V += Math.pow(c - '0', P);
            }
            cnt[V]++;
            A = String.valueOf(V);
            V = 0;
        }
        int count = 0;
        for (int i = 0; i < cnt.length; i++) {
//            if (cnt[i] == 0) {
//                continue;
//            }
//            System.out.println(i + " " + cnt[i] + "\n");
            if (cnt[i] == 1) {
                count++;
            }
        }
        System.out.println(count);

    }
}