#include <iostream>
#include <vector>
using namespace std;
int main(void){
    string line;
    cin >> line;
    bool isNeg = line[0] == '-';
    int i;
    int have = 0;
    vector<char> vc;
   char c;
    for(i = 1; line[i] != '.'; i ++){
        char c = line[i];
       vc.push_back(c);
    }
    i ++;
    for(; line[i] != 'E'; i ++){
        char c = line[i];
       vc.push_back(c);
       have --;
    }
    i ++;
    int ek = line[i] == '-' ? -1 : 1;
    i ++;
    int ee = 0;
    for(; i < line.length(); i ++){
       ee = 10 * ee + (line[i] - '0'); 
    }
    ee *= ek;
    int zeros = have + ee;
    if(isNeg) cout << "-";
    if(zeros < 0){
        if( -zeros >= vc.size() ){
           cout << "0.";
           for(int j = 0; j < -zeros - vc.size(); j ++) cout << "0";
           for(int j = 0; j < vc.size(); j ++) cout << vc[j];
           cout << endl;
        }else{
            for(int j = 0; j < vc.size(); j ++){
                if(j == vc.size() + zeros) cout << ".";
                cout << vc[j];
            }
            cout << endl;
        }
    }else if(zeros >= 0){
        for(int j = 0; j < vc.size(); j ++){
            cout << vc[j];
        }
        for(int j = 0; j < zeros; j ++) cout << "0";
        cout << endl;
    }
    return 0;
}
