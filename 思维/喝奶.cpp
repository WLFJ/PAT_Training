#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1100;
int ver[MAXN], Next[MAXN], head[MAXN], tot;
pair<int, int> edge[MAXN];

void addedge(int x, int y, pair<int, int> z){
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

int N;

int path[MAXN], p, minPath[MAXN], minP, minLen = 0x3f3f3f3f, maxCost, endP;

void dfs(int curP, int l, int c){
    if(l > minLen) return;
    if(curP == endP){
       if(minLen > l || (minLen == l && maxCost < c)){
            minLen = l;
            maxCost = c;
            for(int i = 0; i < p; i ++){
                minPath[i] = path[i];
            }
            minP = p;
       }
    }else{
        for(int i = head[curP]; i; i = Next[i]){
            int y = ver[i];
            pair<int, int> z = edge[i];
            path[p ++] = y;
            dfs(y, l + z.first, c + z.second);
            p --;
        }
    }
}

bool topo(vector<int> in_deg){
    queue<int> bfs;
    for(int i = 1; i <= N; i ++){
        if(in_deg[i] == 0){
            bfs.push(i);
        }
    }
    int cnt = 0;
    while(bfs.size()){
        int curP = bfs.front();bfs.pop();
        cnt ++;
        for(int i = head[curP]; i; i = Next[i]){
            int y = ver[i];
            in_deg[y] --;
            if(!in_deg[y])
                bfs.push(y);
        }
    }
    return cnt == N;
}

int main(void){
    int M;
    cin >> N >> M;
    vector<int> in_deg(N + 1);
    for(int i = 0; i < M; i ++){
        int x, y;
        cin >> x >> y;
        x ++, y ++;
        in_deg[y] ++;
        pair<int, int> p;
        cin >> p.first >> p.second;
        addedge(x, y, p);
    }
    
    bool solveNeeded = topo(in_deg);
    
    if(solveNeeded){
        cout << "Okay." << endl;
    }else{
        cout << "Impossible." << endl;
    }

    int query;
    cin >> query;
    for(int j = 0; j < query; j ++){
        cin >> endP;
        endP ++;
        if(in_deg[endP] == 0){
            cout << "You may take test "<< endP - 1 <<" directly." << endl;
        }
        if(solveNeeded){
            for(int i = 1; i <= N; i ++){
                if(in_deg[i] == 0){
                    minP = 0, minLen = 0x3f3f3f3f, maxCost = 0, endP = 0;
                    path[p ++] = i;
                    dfs(i, 0, 0);
                    p --;
                }
            }
            for(int i = 0; i < minP; i ++){
                if(i) cout << "->";
                cout << minPath[i] - 1;
            }
            cout << endl;
        }else{
            cout << "Error." << endl;
        }
    }
    return 0;
}
