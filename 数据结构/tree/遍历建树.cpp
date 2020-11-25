#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;
int post[35], in[35];
int R;
struct node{
    node *lc, *rc;
    int val;
};

node* build_tree(int l, int r){
    if(l >= r) return NULL;
    int p;
    for(p = l; p < r; p ++){
        if(in[p] == post[R]) break;
    }
    node* n = new node();
    n->val = post[R];
    R --;// 注意这里只要--一次就行了
    n->rc = build_tree(p + 1, r);
    n->lc = build_tree(l, p);
    return n;
}

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++) cin >> post[i];
    for(int i = 0; i < N; i ++) cin >> in[i];
    R = N - 1;
    node* tree = build_tree(0, N);
    queue<node*> q;
    q.push(tree);
    int cnt = 0;
    while(q.size()){
        node *curp = q.front(); q.pop();
        if(cnt) cout << " ";
        cout << curp->val;
        if(curp->lc != NULL) q.push(curp->lc);
        if(curp->rc != NULL) q.push(curp->rc);
        cnt ++;
    }
    cout << endl;
    return 0;
}
