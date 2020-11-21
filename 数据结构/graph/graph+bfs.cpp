#include <iostream>
#include <set>
#include <vector>
using namespace std;
// 我们需要更好的建边方式，这个需要复习了
int coloring[10000 + 10];
int main(void){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > g(N); 
    for(int i = 0; i < M; i ++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int K;
    cin >> K;
    while(K --){
        set<int> ss;
        for(int i = 0; i < N; i ++){
            int c;
            cin >> c;
            coloring[i] = c;
            ss.insert(c);
        }
        bool isOK = true;
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < g[i].size(); j ++){
                if(coloring[i] != coloring[g[i][j]]){

                }else{
                    isOK = false;
                    break;
                }
            }
        }
        if(isOK) cout << ss.size() << "-coloring" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
