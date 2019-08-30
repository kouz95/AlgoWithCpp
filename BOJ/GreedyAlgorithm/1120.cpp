//
//  1120.cpp
//  BOJ
//
//  Created by 김경준 on 30/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int func(string a,string b){
    int res = 0;
    int len = b.size() - a.size();
    
    int val = 0;
    
    for (int i = 0 ; i <= len ; i++){
        int compare = 0;
        for(int j = 0 ; j < a.size(); j++){
            if(a[j] == b[j+i])
                compare++;
        }
        if (val < compare)
            val = compare;
    }
    res = b.size() - (val + len);
    return res;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << func(a,b) << endl;
}

