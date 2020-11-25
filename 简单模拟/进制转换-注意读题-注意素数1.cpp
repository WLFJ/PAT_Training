#include <iostream>
#include <sstream>
using namespace std;
bool isPrime(int a){
    if(a == 1) return false;
    if(a == 2) return true;
    for(int i = 2; i * i <= a; i ++){
        if(a % i == 0) return false;
    }
    return true;
}
int arr[100];
int main(void){
    int N, D;
    // 输入的是十进制，我们要将其转换成D进制，之后将其反转，转换回10进制判断是不是素数
    while(cin >> N && N > 0){
        cin >> D;
        if(isPrime(N)){
            int p = 0;
            while(N){
                arr[p ++] = N % D;
                N /= D;
            } 
            int base = 1;
            for(int i = p - 1; i >= 0; i --){
                N += arr[i] * base;
                base *= D;
            }
            if(isPrime(N)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else
            cout << "No" << endl;
    }
    return 0;
}
