//
//  2188.cpp
//  BOJ
//
//  Created by 김경준 on 30/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> want[n];
    for (int i = 1 ; i <= n ; i++){
        int num;
        cin >> num;
        for(int j = 0 ; j < num ; j++){
            int room;
            cin >> room;
            want[i].push_back(room);
        }
    }
}
