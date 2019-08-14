//
//  1110.cpp
//  BOJ
//
//  Created by 김경준 on 14/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int n;
string in;
string newStr;
int cnt = 0;

string makeNewStr(string str){
    int tmpNum = stoi(str);
    int newNum = ( tmpNum % 10 ) * 10 +(tmpNum / 10 + tmpNum % 10) % 10;
    return to_string(newNum);
}

void func(){
    newStr = makeNewStr(in);
    cnt ++;
    while(stoi(newStr) != stoi(in)){
        newStr = makeNewStr(newStr);
        cnt++;
    }
    cout << cnt << endl;
}

void init(){
    if (n < 10){
        in = "0" + to_string(n);
    }
    else in = to_string(n);
}

void input(){
    cin >> n;
}

int main(){
    input();
    init();
    func();
}
