#include <iostream>
#include <stack>
using namespace std;
char dic[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
void print(int a){
    stack<char> ans;
    while(a){
        ans.push(dic[a % 13]);
        a /= 13;
    }
    if(ans.size() == 1) cout << "0";
    else if(ans.size() == 0) cout << "00";
    while(ans.size()) cout << ans.top(), ans.pop();
}
int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    cout << "#";
    print(a);print(b);print(c);
    cout << endl;
    return 0;
}
