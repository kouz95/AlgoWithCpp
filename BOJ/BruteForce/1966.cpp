//
//  1966.cpp
//  BOJ
//
//  Created by 김경준 on 25/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

int T, N, M;
deque<pair<int, int> > qu;

int cnt = 1;

void reset(){
    qu.clear();
    cnt = 1;
}

int getHighVal(){
    int res = 0;
    for(int i = 0 ; i < qu.size(); i++)
        if (!res || res < qu[i].first)
            res = qu[i].first;
    return res;
}

void doFunc(){
    while(!qu.empty()){
        int currStatus = qu.front().first;
        int currIdx = qu.front().second;
        int currHighVal = getHighVal();
        if(currStatus < currHighVal){
            qu.pop_front();
            qu.push_back({currStatus,currIdx});
            continue;
        }
        if(qu.front().second == M){
            cout << cnt << endl;
            break;
        }
        qu.pop_front();
        cnt++;
    }
        
}

void init(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        int val;
        cin >> val;
        qu.push_back({val,i});
    }
}

int main(){
    cin >> T;
    while(T--){
        init();
        doFunc();
        reset();
    }
}

