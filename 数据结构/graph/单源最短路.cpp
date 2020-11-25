#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 110000
#define MAXM 110000
using namespace std;
vector<int> ppath;
vector<int> ans_path;
vector<int> have;
int minneed = 0x3f3f3f3f, minback = 0x3f3f3f3f;
vector<vector<int> > shortpathes(MAXN);
// 我们一定要注意这个need和back是分开的
void dfs(int v) {
    ppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = ppath.size() - 1; i >= 0; i--) {
            int id = ppath[i];
            if(have[id] > 0) {
                back += have[id];
            } else {
                if(back > (0 - have[id])) {
                    back += have[id];
                } else {
                    need += ((0 - have[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minneed) {
            minneed = need;
            minback = back;
            ans_path = ppath;
        } else if(need == minneed && back < minback) {
            minback = back;
            ans_path = ppath;
        }
        ppath.pop_back();
        return ;
    }
    for(int i = 0; i < shortpathes[v].size(); i++)
        dfs(shortpathes[v][i]);
    ppath.pop_back();
}

int tot, ver[MAXN], edge[MAXM], Next[MAXM], head[MAXN];
void addedge(int x, int y, int z){
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

int dis[MAXN], v[MAXN];
void dijkstra(int startp){
    memset(dis, 0x3f, sizeof(dis));
    memset(v, 0, sizeof(v));
    dis[startp] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, startp));
    while(pq.size()){
        int u = pq.top().second; pq.pop();
        if(v[u]) continue;
        v[u] ++;
        for(int i = head[u]; i; i = Next[i]){
            int y = ver[i], z = edge[i];
            if(dis[y] > dis[u] + z){
                dis[y] = dis[u] + z;
                pq.push(make_pair(-dis[y], y));
                shortpathes[y].clear();
                shortpathes[y].push_back(u);
            }else if(dis[y] == dis[u] + z){
                shortpathes[y].push_back(u);
            }
        }
    }
}

int main(void){
    int cmax, N, sp, M;
    cin >> cmax >> N >> sp >> M;
    have = vector<int>(N);
    for(int i = 1; i <= N; i ++){
        cin >> have[i];
        have[i] -= (cmax >> 1);
    }
    for(int i = 0; i < M; i ++){
        int si, sj, tij;
        si ++, sj ++, tij ++;
        cin >> si >> sj >> tij;
        addedge(si, sj, tij);
        addedge(sj, si, tij);
    }
    dijkstra(0);
    dfs(sp);
    cout << minneed << " ";
    for(int i = ans_path.size() - 1; i >= 0; i --){
        if(i < ans_path.size() - 1) cout << "->";
        cout << ans_path[i];
    }
    cout << " " << minback;
    cout << endl;
    return 0;
}
