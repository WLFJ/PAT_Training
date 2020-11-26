/*
 * 关键在于厘清逻辑关系
 *
 */
#include <iostream>
#include <cstring>
using namespace std;
int arr[100];

int isPa(int arr[], int p){
    for(int i = 0; i <= p; i ++){
        if(arr[i] != arr[p - i]) return false;
    }
    return true;
}

int main(void){
    string N; int k;
    cin >> N >> k;
    for(int i = 0; i < N.length(); i ++){
        arr[N.length() - i - 1] = N[i] - '0';
    } 
    int i = 0;
    while(true){
        int p = 100;
        while(!arr[--p]);

        if(isPa(arr, p) || i == k) break;

        int at[100];
        memset(at, 0, sizeof(at));

        for(int j = 0; j <= p; j ++){
            at[j] = arr[j] + arr[p - j];
        }

        for(int j = 0; j <= p; j ++){
            at[j + 1] += at[j] / 10;
            at[j] %= 10;
        }

        for(int j = 0; j < 100; j ++){
            arr[j] = at[j];
        }

        i ++;
        p = 100;
        while(!arr[--p]);
        if(isPa(arr, p)) break;
    }
    int p = 100;
    while(!arr[--p]);
    if(p == -1) p ++;
    for(int i = p; i >= 0; i --) cout << arr[i];
    cout << endl;
    cout << i << endl;
    return 0;
}
