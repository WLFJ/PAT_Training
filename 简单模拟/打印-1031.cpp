// 使用哨兵+Next数组可以解决大多数画图问题
#include <iostream>
#include <string>
using namespace std;
char cc[1000][1000];
int Next[][2] = {1, 0, 0, 1, -1, 0};
int main(void){
    string line;
    cin >> line;
    int l = line.length();
    int mx = (l + 2) / 3;
    int my = l - mx * 2 + 2;
    for(int i = 0; i < mx; i ++){
        for(int j = 0; j < my; j ++){
            cc[i][j] = ' ';
        }
    }
    cc[mx][0] = -1;
    cc[mx - 1][my] = -1;
    int d = 0;
    int x = 0, y = 0;
    int p = 0;
    while(x >= 0){
        cc[x][y] = line[p ++];
        if(cc[x + Next[d][0]][y + Next[d][1]] == -1){
            d ++;
        }
        x += Next[d][0], y += Next[d][1];
    }
    for(int i = 0; i < mx; i ++){
        for(int j = 0; j < my; j ++){
            cout << cc[i][j];
        }
        cout << endl;
    }
    return 0;
}
