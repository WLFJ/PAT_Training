#include <iostream>
#include <string>
using namespace std;
bool isPrime(string s){
    //cout << s << endl;
    int num = 0;
    for(int i = 0; i < s.length(); i ++){
        num = 10 * num + (s[i] - '0');
    } 
    if(num == 2) return true;
    for(int i = 2; i * i <= num; i ++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
int main(void){
    int L, K;
    cin >> L >> K;
    string s;
    cin >> s;
    int i;
    for(i = 0; i + K <= L; i ++){
        if(isPrime(s.substr(i, K))){
            break;
        }
    }
    // 在跳出循环的时候一定要想想，便捷情况会有什么问题？
    if(i + K <= L && isPrime(s.substr(i, K))) cout << s.substr(i, K) << endl;
    else cout << 404 << endl;
    return 0;
}
