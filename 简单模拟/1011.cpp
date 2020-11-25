#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(void){
    double res = 1;
    for(int i = 0; i < 3; i ++){
        if(i) cout << " ";
        double a, b, c;
        cin >> a >> b >> c;
        // 求三个数的最大数，关键想到这个小技巧
        double maxx = max(a, max(b, c));
        res *= maxx;
        if(maxx == a) cout << "W";
        else if(maxx == b) cout << "T";
        else if(maxx == c) cout << "L";
    }
    printf(" %.2f\n", (res * 0.65 - 1) * 2);
    return 0;
}
