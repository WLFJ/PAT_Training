#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
int gcd(int a, int b){
    while(a ^= b ^= a ^= b %= a);
    return b;
}
string pp(int a, int b){
   ostringstream oss;
   int c = gcd(a, b);
   a /= c, b /= c;
   if(b == 1) {
        oss << a;
        return oss.str();
   }
   if(a > 0 && b < 0) a = -a, b = -b;
   if(abs(a) > b){
        oss << a / b << " ";
        a %= b;
        a = abs(a);
   }
   if(b == 1) oss << a;
   oss << a << "/" << b;
   return oss.str();
}
string getFrac(int a, int b){
    ostringstream oss;
    if(a * b < 0){
        oss << "(" << pp(a, b) << ")";
    }else if(a * b == 0){
        if(a == 0) oss << 0;
        else if(b == 0) oss << "Inf";
    }else{
        if(b == 1) oss << a;
        else{
            oss << pp(a, b);
        }
    }
    return oss.str();
}
int main(void){
    int a, b, c, d;
    scanf("%d/%d %d/%d", &a, &b, &c, &d);
    cout << getFrac(a, b) << " + " << getFrac(c, d) << " = " << getFrac(a * d + c * b, b * d) << endl;
    cout << getFrac(a, b) << " - " << getFrac(c, d) << " = " << getFrac(a * d - c * b, b * d) << endl;
    cout << getFrac(a, b) << " * " << getFrac(c, d) << " = " << getFrac(a * c, b * d) << endl;
    cout << getFrac(a, b) << " / " << getFrac(c, d) << " = " << getFrac(a * d, b * c) << endl;

    
    return 0;
}
