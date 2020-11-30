#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
vector<set<pair<string, int>>> v(100 + 1);
int main(void){
    int N;
    cin >> N;
    int grd[N + 1];
    memset(grd, 0, sizeof(grd));
    int ccnt = 0;
    for(int i = 1; i <= N; i ++){
        int K;
        cin >> K;
        ccnt += K;
        for(int j = 0; j < K; j ++){
            string id; int grade;
            cin >> id >> grade;
            v[grade].insert(make_pair(id, i)); 
        }
    }
    cout << ccnt << endl;
    int mem[101];
    for(int i = 100; i >= 0; i --){
        memset(mem, 0, sizeof(mem));
        set<pair<string, int>> &ss = v[i];
        for(auto it : ss){
            cout << it.first << " " << grd[0] + 1 << " " << it.second << " " << grd[it.second] + 1 << endl;
            mem[0] ++, mem[it.second] ++;
        }
        for(int i = 0; i <= 100; i ++){
            if(mem[i]) grd[i] += mem[i];
        }
    }
    return 0;
}
