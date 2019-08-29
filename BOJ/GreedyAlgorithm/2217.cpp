//
//  2217.cpp
//  BOJ
//
//  Created by 김경준 on 29/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int func(int n,int * rope){
    int cnt = 0;
    int limit = 0;
    sort(rope,rope+n);
    for(int i = n-1 ; i >= 0 ; i--){
        if(limit < rope[i] * (++cnt)){
            limit = rope[i] * cnt;
        }
    }
    return limit;
}

int main(){
    int n;
    cin >> n;
    int rope[n];
    for(int i = 0 ; i < n ; i ++)
        cin >> rope[i];
    cout << func(n,rope) << endl;
}
