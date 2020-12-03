#include <iostream>
#include <vector>
using namespace std;
struct station{
    double p;
    int d;
};
bool operator < (station s1, station s2){
    if(s1.d != s2.d)
        return s1.d < s2.d;
    else
        return s1.p < s2.p;
}
int main(void){
    int C, D, D_avg, N;
    cin >> C >> D >> D_avg >> N;
    vector<station> arr;
    for(int i = 0; i < N; i ++){
        cin >> arr[i].p >> arr[i].d;
    }
    // 我们可以想象为段，之后比较最优的方案
    double maxLen = 1.0 * C / D_avg;// 最远到哪里
    // todo：这里需要检查d
    int curP = maxLen;
    double sum = arr[0].p * maxLen;
    // 我们要寻找能到范围内价格最低的加油站，这个可能比较难实现
    return 0;
}
