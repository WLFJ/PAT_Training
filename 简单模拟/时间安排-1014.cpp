#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 *  前n*m个很重要，为了保证所有的都能提前结束，我们应该每次放在里面最小的，如果超过之后就只能按照游戏规则玩了
 */
int main(void){
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    queue<pair<int, int> > q[N];
    for(int i = 0; i < K; i ++){
        int time;
        cin >> time;
        q[i % N].push(make_pair(i, time));
    }
    return 0;
}
