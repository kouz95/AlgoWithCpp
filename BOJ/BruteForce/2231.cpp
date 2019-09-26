//
//  2231.cpp
//  BOJ
//
//  Created by 김경준 on 26/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int n;
int res;
void findNum(int currNum){
    string currVal = to_string(currNum);
    int sumVal = 0;
    if(currNum >= 10){
        sumVal += currNum;
        for(int i = 0 ; i < currVal.size(); i++)
            sumVal += (int)currVal[i] - '0';
    }
    
    if(sumVal == n){
        res = currNum;
        return;
    }
    if(currNum >= n || n < 10){
        res = 0;
        return;
    }
    
    findNum(currNum+1);
}

void init(){
    cin >> n;
}

int main(){
    init();
    findNum(1);
    cout << res << endl;
}
