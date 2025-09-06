/*
 * bfs, 멀티 소스(시작점이 여러개) bfs?
 * dist 배열을 -1로 초기화 시켜놓고, 상어가 있는 위치만 0
 * dist 배열의 값이 -1이 아니면, 이미 최단거리 이므로 넘어감(방문 처리, 다른 곳에서 들렀음)
 * 8방향을 돌면서, -1인 것만 원래 상어 위치+1
 * 전체 dist배열에서 최댓값을 구한다.
 */
import java.io.*;
import java.util.*;

public class Main {
    static int n,m,max;
    static int [][]map;
    static int [][] dist;
    static int [] dx = {-1,-1,-1,0,0,1,1,1};
    static int [] dy={-1,0,1,-1,1,-1,0,1};
    static Deque<int[]> dq = new ArrayDeque<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        dist = new int[n][m];

        for(int i=0; i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                dist[i][j] = -1;
                if(map[i][j]==1){
                    dist[i][j] = 0;
                    dq.add(new int []{i,j});
                }
            }
        }
        bfs();
        max = 0;
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(dist[i][j] > max){
                    max = dist[i][j];
                }
            }
        }

        System.out.print(max);
    }
    private static void bfs(){
        while(!dq.isEmpty()){
            int [] arr= dq.poll();
            int x = arr[0];
            int y = arr[1];
            for(int s=0;s<8;s++){
                int nx = x+dx[s];
                int ny = y+dy[s];
                if((nx >= 0 && nx < n )&&(ny>= 0 && ny< m)){
                    if(dist[nx][ny]!=-1){
                        continue;
                    }
                    dist[nx][ny] = dist[x][y]+1;
                    dq.add(new int[]{nx,ny});
                }
            }
        }
    }
}