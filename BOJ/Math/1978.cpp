//
//  1978.cpp
//  BOJ
//
//  Created by 김경준 on 15/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int num[100];
bool primeNum[1001];
bool isVisit[1001];
int cnt = 0;

void primeNumNet(){
    for(int i = 0 ; i < 2; i++){
        primeNum[i] = false;
        isVisit[i] = true;
    }
    for(int i = 2 ; i <= 1000; i++){
        if (isVisit[i] == false){
            for(int j = i ; j <= 1000; j += i){
                isVisit[j] = true;
            }
            primeNum[i] = true;
        }
    }
}

void func(){
    primeNumNet();
    
    for(int i = 0 ; i < n ; i++){
        if(primeNum[num[i]]==true)
            cnt++;
    }
    cout << cnt << endl;
}

void init(){
    cin >> n;
    for (int i = 0 ; i < n ; i ++)
        cin >> num[i];
    for (int i = 0 ; i < 1001 ; i++){
        primeNum[i] = false;
        isVisit[i] = false;
    }
}

int main(){
    init();
    func();
}
