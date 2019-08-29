//
//  1671.cpp
//  BOJ
//
//  Created by 김경준 on 29/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct shark{
    int size;
    int speed;
    int smart;
}Object;

void func(int n, Object * shark){
    
}

int main(){
    int n;
    cin >> n;
    Object shark[n];
    for(int i = 0 ; i < n ; i++)
        cin >> shark[i].size >> shark[i].speed >> shark[i]. smart;
    func(n, shark);
}
