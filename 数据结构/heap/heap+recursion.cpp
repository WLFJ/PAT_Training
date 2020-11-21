// 有没有更简单的写法？
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int hheap[2000 + 10];
int mmem[2000 + 10];
int path[1000 + 10], p = 0;
int AA, BB, CC;
void check(){
    // 专门检查这是个什么玩意
    bool isA = true;
    for(int i = 0; i < p - 1; i ++){
       if(path[i] <= path[i + 1]){

       } else{
            isA = false;
            break;
       }
    }
    bool isB = true;
    for(int i = 0; i < p - 1; i ++){
       if(path[i] >= path[i + 1]){

       } else{
            isB = false;
            break;
       }
    }
    bool isC = !isA && !isB;
    AA += isA, BB += isB, CC += isC;
}
void pprint(int root){
    if(mmem[root << 1] == -1 && mmem[root << 1 | 1] == -1){
        check();
        for(int i = 0; i < p; i ++){
            if(i) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }
}
void print(int root){
    // 我们将创建结果写在数组中就好了
    if(mmem[root] == -1) return;
    path[p ++] = hheap[root];
    // 注意这里暗含的递归哲学
    print(root << 1 | 1);
    print(root << 1);
    pprint(root);
    p --;
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i <= (n << 1 | 1) + 1; i ++) mmem[i] = -1;
    for(int i = 1; i <= n; i ++){
        cin >> hheap[i];
        mmem[i] = 1;
    }
    print(1);
    if(AA && !BB && !CC) cout << "Min Heap" << endl;
    else if(!AA && BB && !CC) cout << "Max Heap" << endl;
    else cout << "Not Heap" << endl;
    return 0;
}
