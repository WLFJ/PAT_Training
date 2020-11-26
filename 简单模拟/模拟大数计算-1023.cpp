#include <iostream>
#include <vector>
using namespace std;
int arr[100];
int main(void){
    string num;
    cin >> num;
    int p = num.length();
    for(int i = 0; i < num.length(); i ++){
        arr[num.length() - i - 1] = (num[i] - '0') << 1;
    } 
    // 下面维护性质
    for(int i = 0; i < num.length(); i ++){
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
    }  
    if(arr[num.length()]) p ++;
    vector<int> cnt1(10);
    vector<int> cnt2(10);
    for(int i = 0; i < num.length(); i ++){
        cnt1[num[i] - '0'] ++;
    }
    for(int i = 0; i < p; i ++){
        cnt2[arr[i]] ++;
    }
    bool isOK = true;
    for(int i = 0; i <= 9; i ++){
        if(cnt1[i] != cnt2[i]){
            isOK = false;
        }
    }
    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = p - 1; i >= 0; i --) cout << arr[i];
    cout << endl;
    return 0;
}
