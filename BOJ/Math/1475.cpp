//
//  1475.cpp
//  BOJ
//
//  Created by 김경준 on 15/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string n;
int cnt[10];

void func(){
    for (int j = 0 ; j < 10 ; j++){
        for (int i = 0 ; i < n.size(); i++){
            if((int)n[i] - 48 == j){
                cnt[j]++;
            }
        }
    }
    
    int nMax = 0;
    for (int i = 0 ; i < 10 ; i++){
        if((!nMax || nMax < cnt[i]) && (i!=9 && i!=6))
            nMax = cnt[i];
    }
    nMax = max(nMax , (cnt[6] + cnt[9] + 1)/2 );
    cout << nMax << endl;
}

void init(){
    cin >> n;
    for (int i = 0 ; i < 10 ; i++){
        cnt[i] = 0;
    }
}

int main(){
    init();
    func();
}
