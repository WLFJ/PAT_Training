#include <iostream>
#include <cstdio>
using namespace std;
int mem[100000];
int main(void){
    int a, b;int n;
    cin >> a >> b >> n;
    mem[a] ++;
    if(mem[b]){
        printf("%05d\n", a);
        return 0;
    }
    mem[b] ++;
    int ans = -1;
    int cc = 4;
    while(n --){
        int a, c;
        char b;
        cin >> a >> b >> c;
        // 我们只要看哪个c出现两次就行了
        if(mem[c]){
            ans = c;
            cc --;
            if(!cc) break;
        }else{
            mem[c] ++;
        }
    }
    if(ans != -1)
        printf("%05d\n", ans);
    else
        puts("-1");
    return 0;
}
