#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int a[110], b[110];
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    // 首先看看从哪个地方开始二者不同了
    int ee, tt;
    for(ee = 0; ee < n - 1 && b[ee] <= b[ee + 1]; ee ++);
    for(tt = ee + 1; tt < n && a[tt] == b[tt]; tt ++);
    if(tt == n){
        cout << "Insertion Sort" << endl;
        sort(a, a + ee + 1 + 1);
    }else{
        cout << "Merge Sort" << endl;
        int flag = 1;
        int k = 1;
        while(flag){
            flag = 0;
            for(int i = 0; i < n; i ++){
                if(a[i] != b[i]){
                    flag ++;
                    break;
                }
            }
            k <<= 1;
            // 注意这里我们只看这里
            // 这里没有取到
            for(int i = 0; i < n / k; i ++){
                sort(a + (i * k), a + ((i + 1) * k));
            }
            sort(a + n / k * k, a + n);
        }
    }
    for(int i = 0; i < n; i ++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    
    return 0;
}

