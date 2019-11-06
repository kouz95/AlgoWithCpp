//
//  1094.cpp
//  BOJ
//
//  Created by 김경준 on 2019/11/06.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int stick = 64;
int targetLen;
vector<int> mySticks;

int getSum(){
    int res = 0;
    for(int i = 0 ; i < mySticks.size(); i++){
        res += mySticks[i];
    }
    return res;
}

void cutStick(int stickIdx, int stickLen){
    vector<int>::iterator iter = mySticks.begin();
    iter += stickIdx;
    mySticks.erase(iter);
    mySticks.insert(iter, stickLen / 2);
    int currSum = getSum();
    if(currSum < targetLen) {
        mySticks.insert(iter, stickLen / 2);
    }
}

void cutShortest(){
    int shortestStickIdx = 0;
    int shortestStickLen = 64;
    for(int i = 0 ; i < mySticks.size() ; i++){
        if(shortestStickLen > mySticks[i] || shortestStickLen == 64) {
            shortestStickLen = mySticks[i];
            shortestStickIdx = i;
        }
    }
    cutStick(shortestStickIdx,shortestStickLen);
}
void simulation() {
    int currSum = 64;
    while(currSum != targetLen){
        if(currSum > targetLen){
            cutShortest();
        }
        currSum = getSum();
    }
}

void init(){
    cin >> targetLen;
    mySticks.push_back(stick);
}

int main(){
    init();
    simulation();
    cout << mySticks.size() << "\n";
}
