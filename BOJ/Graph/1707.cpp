//
//  1707.cpp
//  BOJ
//
//  Created by 김경준 on 01/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void func(vector<int> * adjacent){
    vector<int> Group1;
    vector<int> Group2;
    
    
}

int main(){
    int k;
    cin >> k;
    while(k--){
        int vertex, edge;
        cin >> vertex, edge;
        vector<int> adjacent[vertex+1];
        for(int i = 0 ; i < edge ; i++){
            int from, to;
            cin >> from >> to;
            adjacent[from].push_back(to);
        }
        func(adjacent);
    }
}

