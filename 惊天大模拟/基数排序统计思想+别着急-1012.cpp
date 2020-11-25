#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
struct node{
    string id;
    int arr[4];
};
string dix = "ACME" ;
int main(void){
    int n, m;
    cin >> n >> m;
    vector<node> arr(n);
    map<string, int> mem;
    for(int i = 0; i < n; i ++){
        cin >> arr[i].id >> arr[i].arr[1] >> arr[i].arr[2] >> arr[i].arr[3];
        for(int j = 1; j <= 3; j ++){
            arr[i].arr[0] += arr[i].arr[j];
        }
        mem[arr[i].id] = i;
    }
    for(int j = 0; j < 4; j ++){
        int scr[333];
        memset(scr, 0, sizeof(scr));
        for(int i = 0; i < n; i ++){
            scr[arr[i].arr[j]] ++;
        }
        for(int i = 310; i >= 0; i --){
            scr[i] += scr[i + 1];
        }
        for(int i = 0; i < n; i ++){
            arr[i].arr[j] = scr[arr[i].arr[j] + 1] + 1;
        }
    }
    for(int i = 0; i < m; i ++){
        // 现在我们要通过查找的办法确定是否存在id
        string s;
        cin >> s;
        if(mem.count(s)){
            // 输出结果
            int i = mem[s];
            int x = 0;
            for(int j = 1; j < 4; j ++){
                if(arr[i].arr[j] < arr[i].arr[x]){
                    x = j;
                }
            }
            cout << arr[i].arr[x] << " " << dix[x] << endl;
        }else{
            cout << "N/A" << endl;
        }
    }
    return 0;
}
