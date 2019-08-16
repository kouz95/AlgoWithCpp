//
//  1085.cpp
//  BOJ
//
//  Created by 김경준 on 16/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;

int x , y , w , h;

void func(){
    int minW= min(x,w-x);
    int minH= min(y,h-y);
    
    cout << min(minW,minH) << endl;
}

void init(){
    cin >> x >> y >> w >> h;
}

int main(){
    init();
    func();
}
