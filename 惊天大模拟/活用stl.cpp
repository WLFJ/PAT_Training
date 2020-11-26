// 想好需要使用什么数据结构，不要使用纯暴力，容易翻车
// 一般代码不会超过50行
#include <iostream>
#include <sstream>
#include <set>
#include <map>
using namespace std;

map<string, set<string> > ttitle, aauthor, kkw, ppress, ppressdate;

void q(map<string, set<string> >& db, string& kw){
    if(db.count(kw)){
        for(string id : db[kw]){
            cout << id << endl;
        } 
    }else{
        cout << "Not Found" << endl;
    }
}

int main(void){
    string tt;
    int N;
    cin >> N;
    getline(cin, tt);
    while(N --){
        string id, title, author, kw, press, pressdate;
        getline(cin, id);
        getline(cin, title);
        ttitle[title].insert(id);
        getline(cin, author);
        aauthor[author].insert(id);
        string kwline;
        getline(cin, kwline);
        stringstream ss(kwline);
        while(ss >> kw){
            kkw[kw].insert(id);
        }
        getline(cin, press);
        ppress[press].insert(id);
        getline(cin, pressdate);
        ppressdate[pressdate].insert(id);
    }
    int M;
    cin >> M;
    getline(cin, tt);
    while(M --){
        string line;
        getline(cin, line);
        cout << line << endl;
        string ww = line.substr(3, line.length());
        switch(line[0]){
            case '1':
                q(ttitle, ww);
                break;
            case '2':
                q(aauthor, ww);
                break;
            case '3':
                q(kkw, ww);
                break;
            case '4':
                q(ppress, ww);
                break;
            case '5':
                q(ppressdate, ww);
                break;
        }
    }
    return 0;
}
