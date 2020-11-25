#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int N, b;
    cin >> N >> b;
    vector<int> arr;
    while(N){
        arr.push_back(N % b);
        N /= b;
    }
    bool isOK = true;
    for(int i = 0; i < arr.size(); i ++){
       if(arr[i] != arr[arr.size() - i - 1]){
            isOK = false;
            break;
       } 
    }
    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i ++){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
