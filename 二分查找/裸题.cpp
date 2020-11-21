#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max(int a, int b){
    return a > b ? a : b;
}
int main(void){
    int N, p;
    cin >> N >> p;
    vector<int> arr(N);
    for(int i = 0; i < N; i ++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 0; i < N; i ++){
        ans = max(ans, upper_bound(arr.begin(), arr.end(), arr[i] * p) - arr.begin() - i);
    }    
    cout << ans << endl;
    
    return 0;
}
