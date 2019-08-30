//
//  10610.cpp
//  BOJ
//
//  Created by 김경준 on 30/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string func(string n){
    string res;
    int sum = 0;
    bool isThereZero = false;
    for (string::iterator iter = n.begin(); iter != n.end(); iter++){
        if(*iter == '0')
            isThereZero = true;
        sum += (int)*iter - '0';
    }
    if(!isThereZero)
        res = "-1";
    else if (sum % 3 == 0){
        sort(n.begin(),n.end(),greater<int>());
        res = n;
    }
    else res = "-1";
    return res;
}

int main(){
    string n;
    cin >> n;
    cout << func(n) << endl;
}
