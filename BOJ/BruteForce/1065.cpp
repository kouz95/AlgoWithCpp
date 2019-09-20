//
//  1065.cpp
//  BOJ
//
//  Created by 김경준 on 19/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void printHanNum(int maxNum){
    int res = 0;
    for(int i = 1; i <= maxNum; i++){
        string currNum = to_string(i);
        if(i < 100){
            res++;
            continue;
        }
        int firstGap = currNum[0] - currNum[1];
        bool isHan = true;
        for (int j = 1 ; j < currNum.length() - 1 ; j++){
            int currGap = currNum[j] - currNum[j+1];
            if(firstGap != currGap)
                isHan = false;
        }
        if(isHan)
            res++;
    }
    cout << res << "\n";
}

int main(){
    int n;
    cin >> n;
    printHanNum(n);
}
