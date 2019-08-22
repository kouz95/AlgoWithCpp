//
//  1068.cpp
//  BOJ
//
//  Created by 김경준 on 22/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int n, out;
pair <int, bool> parent[MAX]; // first : parentNum, Second : is N leaf?
vector<int> ancestor[MAX];
int cnt = 0;

void func(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < ancestor[i].size() ; j++){
            if(ancestor[i][j] == out)
                parent[i].second = false;
        }
    }
    for (int i = 0; i < n; i++)
        if(i != out)
            parent[parent[i].first].second = false;

    for (int i = 0; i < n; i++)
        if (parent[i].second == true)
            cnt++;
    cout << cnt << endl;
}


void init(){
    cin >> n;
    
    for (int i = 0 ; i < n ; i++){
        cin >> parent[i].first;
        parent[i].second = true;

    }
    for (int i = 0 ; i < n ; i++){
            parent[parent[i].first].second = false;
    }
    for (int i = 0 ; i < n ; i++){
        int curParent = parent[i].first;
        while(curParent != -1){
            ancestor[i].push_back(curParent);
            curParent = parent[curParent].first;
        }
    }
    cin >> out;
    parent[out].second = false;
    
    parent[parent[out].first].second = true;
}

int main(){
    init();
    func();
}
