#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int id;
    string name;
    int grade;
};
bool cmp1(node n1, node n2){
    return n1.id < n2.id;
}
bool cmp2(node n1, node n2){
    if(n1.name != n2.name)
        return n1.name <= n2.name;
    else
        return cmp1(n1, n2);
}
bool cmp3(node n1, node n2){
    if(n1.grade != n2.grade)
        return n1.grade <= n2.grade;
    else
        return cmp1(n1, n2);
}
node arr[100000 + 10];
int main(void){
    int N, C;
    cin >> N >> C;
    for(int i = 0; i < N; i ++){
        cin >> arr[i].id >> arr[i].name >> arr[i].grade;
    }
    switch(C){
        case 1:
            // ID上升序列
            sort(arr, arr + N, cmp1);
            for(int i = 0; i < N; i ++){
                node n = arr[i];
                printf("%06d ", n.id);
                cout << n.name << " " << n.grade << endl;
            }
            break;
        case 2:
            sort(arr, arr + N, cmp2);
            for(int i = 0; i < N; i ++){
                node n = arr[i];
                printf("%06d ", n.id);
                cout << n.name << " " << n.grade << endl;
            }
            break;
        case 3:
            sort(arr, arr + N, cmp3);
            for(int i = 0; i < N; i ++){
                node n = arr[i];
                printf("%06d ", n.id);
                cout << n.name << " " << n.grade << endl;
            }
            break;
    }
    return 0;
}
