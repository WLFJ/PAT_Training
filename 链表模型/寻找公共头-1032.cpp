// 注意模型遍历的时候，我们传递的是值还是tot
// 能通过简单的办法解决，就不要想太多。
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int MAXN = 100000 + 10;
int ver[MAXN], Next[MAXN], head[MAXN], tot;
void addedge(int a, int b){
    ver[++tot] = b, Next[tot] = head[a], head[a] = tot;
}
int main(void){
    int a, b, n;
    cin >> a >> b >> n;
    while(n --){
        int x; char z; int y;
        cin >> x >> z >> y;
        if(y == -1) continue;
        addedge(x, y);
    }
    // 下面开始两个遍历 我们看看哪个最后分叉
    set<int> mem;
    mem.insert(a);
    for(int i = head[a]; i; i = head[ver[i]]){
        mem.insert(ver[i]);
    }
    int ans = -1;
    if(mem.count(b)){
        ans = b;
        printf("%05d\n", ans);
        return 0;
    }
    mem.insert(b);
    for(int i = head[b]; i; i = head[ver[i]]){
        if(mem.count(ver[i])){
            ans = ver[i];
            break;
        }else{
            mem.insert(ver[i]);
        }
    }
    if(ans == -1) cout << -1 << endl;
    else printf("%05d\n", ans);
    return 0;
}
