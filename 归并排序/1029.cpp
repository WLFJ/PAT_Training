#include <iostream>
using namespace std;
int arr[2][200000 + 10];
/*
 * 注意归并排序的写法，可以通过比较++的方式动态过度，
 * 同时我们需要看看剩下部分的处理方法
 */
int main(void){
    for(int i = 0; i < 2; i ++){
        cin >> arr[i][0];
        for(int j = 1; j <= arr[i][0]; j ++){
            cin >> arr[i][j];
        }
    }
    int i = 1, j = 1;
    int mid = (arr[0][0] + arr[1][0] + 1) / 2;
    int ans, cnt = 0;
    while(i <= arr[0][0] && j <= arr[1][0] && cnt ++ != mid){
       ans = arr[0][i] <= arr[1][j] ? arr[0][i ++] : arr[1][j ++]; 
    }
    if(i <= arr[0][0] && cnt < mid)
    ans = arr[0][i + mid - cnt - 1]; 
    else if(j <= arr[1][0] && cnt < mid)
       ans = arr[1][j + mid - cnt - 1];
    cout << ans << endl;
    return 0;
}
