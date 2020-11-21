#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(void){
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> mem;
    for(int i = 0; i < s2.length(); i ++){
        char c = s2[i];
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        mem[c] = 1;
    } 
    set<char> ss;
    for(int i = 0; i < s1.length(); i ++){
        char c = s1[i];
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if(mem[c] == 0){
            if(ss.count(c)){
                
            }else{
                ss.insert(c);
                if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
                cout << c;
            }
        }
    }
    cout << endl;
    
    return 0;
}
