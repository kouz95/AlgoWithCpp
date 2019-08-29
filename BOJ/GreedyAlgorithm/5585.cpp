//
//  5585.cpp
//  BOJ
//
//  Created by 김경준 on 29/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

using namespace std;

int func(int target){
    int res = 0 ;
    int cost[6] = {500, 100, 50, 10 ,5 ,1};
    while(target!=0){
        for(int i = 0 ; i < 6 ; i++){
            if(target-cost[i] >= 0){
                target -= cost[i];
                res++;
                break;
            }
        }
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cost;
    cin >> cost;
    int target = 1000-cost;
    cout << func(target) << "\n";
}
