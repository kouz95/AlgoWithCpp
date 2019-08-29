//
//  11399.cpp
//  BOJ
//
//  Created by 김경준 on 29/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> time){
    int res = 0;
    for(int i = 1 ; i <= time.size(); i++)
        for (int j = 0 ; j < i ; j++)
            res += time[j];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> time;
    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        time.push_back(input);
    }
    sort(time.begin(),time.end());
    cout << func(time) << "\n";
}
