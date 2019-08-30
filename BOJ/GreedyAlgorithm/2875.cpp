//
//  2875.cpp
//  BOJ
//
//  Created by 김경준 on 30/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

using namespace std;

int func(int n, int m, int k){
    int res;
    
    while(k!=0){
        if ( n > 2 * m )
            n--,k--;
        if ( n == 2 * m && k > 1)
            n--,m--,k-=2;
        if (n < 2 * m)
            m--,k--;
        if ( n == 2 * m && k == 1)
            m--,k--;
    }
    res = min(n/2,m);
    
    return res;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    cout << func(n,m,k) << endl;
}
