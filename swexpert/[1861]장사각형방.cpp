#include <stdio.h>
const int MAXN = 1000;
int map[MAXN][MAXN];
int visit[MAXN][MAXN];
int N;
int dx[] = {0 ,0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dfs(int x, int y){
    
    visit[x][y] = 1;
    int max = 0;
    for(int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 0 || ty < 0 || tx == N || ty == N) continue;
        if(visit[tx][ty]) continue;
        if(map[x][y] + 1 == map[tx][ty])
        {
            int ret = dfs(tx , ty);
            if(ret > max) max = ret;
        }
    }                
    visit[x][y] = 0;
    return max + 1;
}
int main()
{
    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                scanf("%d", &map[i][j]);
        }
        int ans = 0xfffffff, max = 0;
        for(int x = 0; x < N; x++)
        {
            for(int y = 0; y < N; y++)
            {
                int ret = dfs(x, y);
                if(ret > max){
                    max = ret;
                    ans = map[x][y];
                }else if(ret == max && map[x][y])
            }
        }
        printf("#%d %d %d\n", tc, ans, max);
    }
    return 0;
}