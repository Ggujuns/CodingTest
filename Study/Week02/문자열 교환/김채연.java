import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    /*
    a를 모두 연속으로 만들기 위해서 필요한 교환의 횟수 최소
    원형큐 -> 배열 두배
    N= 10^3 -> O(N^2)까지만 가능할듯 근데 시간 2초? N^3도 널널할지도
    a 갯수만큼 윈도우 크기를 잡고, 그 안에 있는 b를 없애는 문제
    전체 문자열에 a가 n개 있으면 그 n개를 연속시키면 되기 때문, 그 안에 있는
    b를 a로 바꾸면 그 구간이 전부 a가 된다.

     */
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] split = br.readLine().toCharArray();
        char[] arr = new char[split.length * 2];
        int size = arr.length;
        int slide = 0;
        for (int i = 0; i < size; i++) {
            char c = split[i % split.length];
            if (c == 'a') {
                slide++;
            }
            arr[i] = c;
        }
        slide /= 2;
        if (slide == 0 || slide == split.length) { //a가 아예 없거나, 이미 다 a일 경우
            System.out.println(0);
            return;
        }

        //슬라이딩 윈도우
        int cnt = 0; //b의 최소 갯수 초기값
        //먼저 첫번째 슬라이드의 b갯수를 셈.
        for (int i = 0; i < slide; i++) {
            char c = arr[i];
            if (c == 'b') {
                cnt++;
            }
        }

        int min = cnt;

        //슬라이딩 시작
        for (int i = 1; i < size - slide; i++) {
            if (arr[i - 1] == 'b') { //만약빼려고 하는게 b였음 --를 해
                cnt--;
            }
            if (arr[i - 1 + slide] == 'b') { // 넣으려고 하는게 b였음 ++을 해
                cnt++;
            }
            min = Math.min(cnt, min);
        }
        System.out.println(min);
    }
}
