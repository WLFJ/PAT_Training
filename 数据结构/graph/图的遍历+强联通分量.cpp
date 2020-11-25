#include <iostream>
#include <cstring>
using namespace std;
int mx[1100][1100];
int visit[1100];
int N, M, K;
void dfs(int p){
    if(visit[p]) return;
    visit[p] = 1;
    for(int i = 1; i <= N; i ++){
        if(mx[p][i]) dfs(i);
    }
}
int main(void){
    // 我们直接dfs统计就行了 别想太复杂
    cin >> N >> M >> K;
    for(int i = 0; i < M; i ++){
        int a, b;
        cin >> a >> b;
        mx[a][b] = mx[b][a] = 1;
    }
    for(int i = 0; i < K; i ++){
        int p; cin >> p;
        memset(visit, 0, sizeof(visit));
        visit[p] = 1;
        int ans = 0;
        for(int i = 1; i <= N; i ++){
            if(!visit[i]){
                ans ++;
                dfs(i);
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
