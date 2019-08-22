//
//  5567.cpp
//  BOJ
//
//  Created by 김경준 on 22/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 500;

pair<int,int> list[10000];
vector<int> nearFriends;
bool isInvited[MAX+1];
int n;
int m;
int cnt = 0;

void findFriends(){
    for (int i = 0 ; i < m; i++){
        if(list[i].first == 1){
            isInvited[list[i].second] = true;
            nearFriends.push_back(list[i].second);
        }
    }
    for (int i = 0; i < m ; i++){
        for (int j = 0 ; j < nearFriends.size() ; j++){
            if(list[i].first == nearFriends[j])
                isInvited[list[i].second] = true;
            if(list[i].second == nearFriends[j])
                isInvited[list[i].first] = true;
        }
    }
    
}

void func(){
    findFriends();
    for(int i = 2 ; i <= n ; i++){
        if(isInvited[i])
            cnt++;
    }
    cout << cnt << endl;
}

void init(){
    cin >> n;
    cin >> m;
    for (int i = 0 ; i <= MAX ; i++)
        isInvited[i]= false;
    for (int i = 0 ; i < m ; i++){
        cin >> list[i].first >> list[i].second;
    }
}

int main(){
    init();
    func();
}
