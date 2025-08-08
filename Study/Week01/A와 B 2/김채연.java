import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BJ12919 {
    static String S = "";
    static String T = "";
    static boolean flag;

    public static void main(String[] args) throws Exception {
        StringBuilder sb;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        T = br.readLine();

        recursion(T);
        if (!flag) {
            System.out.println(0);
        } else {
            System.out.println(1);
        }
    }

    private static void recursion(String current) {
        char[] carr = current.toCharArray();
        int len = carr.length;
        if (flag) {
            return;
        }
        if (current.length() == S.length()) {
            flag = current.equals(S);
            return;
        }
        if (carr[0] == 'B') {
            StringBuilder sb = new StringBuilder(current.substring(1, len));
            recursion(sb.reverse().toString());
        }
        if (carr[len - 1] == 'A') {
            recursion(current.substring(0, len - 1));
        }
    }
}
