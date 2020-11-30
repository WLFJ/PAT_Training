#include <iostream>
using namespace std;
int mx[510][510];
int cost[510][510];
int minLen = 0x3f3f3f3f;
int N, M, S, D;
int path[100000], pp;
int minPath[100000], minPP;
int mem[510];
int minCost = 0x3f3f3f3f;
void dfs(int curP, int len, int c){
    if(len > minLen) return; 
    if(curP == D){
        minLen = len;
        if(minCost < c){
            return ;
        }
        minCost = c;
        // 我们要保存最小的结果
        minPP = 0;
        for(int i = 0; i < pp; i ++){
            minPath[minPP ++] = path[i];
        }
        return;
    }
    for(int i = 0; i < N; i ++){
        if(mx[curP][i] != -1 && !mem[i]){
            path[pp ++] = i;
            mem[i] ++;
            dfs(i, len + mx[curP][i], c + cost[curP][i]);
            mem[i] --;
            pp --;
        }
    }
    return;
}
int main(void){
    cin >> N >> M >> S >> D;
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            mx[i][j] = -1;
    for(int i = 0; i < M; i ++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mx[a][b] = mx[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    mem[S] ++;
    dfs(S, 0, 0);
    mem[S] --;
    cout << S << " ";
    for(int i = 0; i < minPP; i ++){
        cout << minPath[i] << " ";
    }
    cout << minLen << " ";
    cout << minCost << endl;
    return 0;
}
