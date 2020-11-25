#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
int mx[10000 + 10][10000 + 10];
int K;
int mem[10000 + 10];
int hh[10000 + 10];
void dfs(int p, int h){
    mem[p] = 1;
    hh[p] = max(hh[p], h);
    for(int i = 1; i <= K; i ++){
        if(mx[p][i] && mem[i] == 0){
            dfs(i, h + 1);
        }
    }
}
int main(void){
    scanf("%d", &K);
    for(int i = 1; i < K; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        mx[a][b] = mx[b][a] = 1;
    }
    int ccnt = 0;
    while(true){
        bool found = false;
        for(int i = 1; i <= K; i ++){
            if(mem[i] == 0){
                dfs(i, 1);
                ccnt ++;
                found = true;
            }
        }
        if(found == false) break;
    }
    vector<int> ans;
    if(ccnt == 1){
        // 现在要求解树的高度
        // 我们只要搜索两次就好了
        memset(mem, 0, sizeof(mem));
        memset(hh, 0, sizeof(hh));
        dfs(1, 1);
        int maxx = 0;
        for(int i = 1; i <= K; i ++) maxx = max(maxx, hh[i]);
        for(int i = 1; i <= K; i ++){
            if(hh[i] == maxx){
                ans.push_back(i);
            }
        }
        memset(mem, 0, sizeof(mem));
        memset(hh, 0, sizeof(hh));
        dfs(ans.front(), 1);
        for(int i = 1; i <= K; i ++) maxx = max(maxx, hh[i]);
        for(int i = 1; i <= K; i ++){
            if(hh[i] == maxx){
                ans.push_back(i);
            }
        }
        // 下面记录最大高度的节点们
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        for(int a : ans){
            cout << a << endl;
        }
        
    }else{
        cout << "Error: " << ccnt << " components" << endl;
    }
    return 0;
}
