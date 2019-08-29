//
//  1931.cpp
//  BOJ
//
//  Created by 김경준 on 29/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int func(int n, vector<pair<int, int> > meeting, int firstTime, int lastTime){
    int res = 0;
    sort(meeting.begin(), meeting.end());
    int curr = 0;
    for(int i = 0 ; i < meeting.size(); i++){
        int startTime = meeting[i].second;
        int endTime = meeting[i].first;
        if(startTime >= curr){
            curr = endTime;
            res++;
        }
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int> > meeting;
    int firstTime = (int)pow(2.0,31.0)-1;
    int lastTime = 0;
    for(int i = 0 ; i < n ; i++){
        int startTime, endTime;
        cin >> startTime >> endTime;
        meeting.push_back({endTime,startTime});
        firstTime = firstTime > startTime ? startTime : firstTime;
        lastTime = lastTime < endTime ? endTime : lastTime;
    }
    
    cout << func(n,meeting,firstTime,lastTime) << "\n";
}
