//
//  11047.cpp
//  BOJ
//
//  Created by 김경준 on 29/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

using namespace std;

int func(int n, int k, int * worth){
    int res = 0;
    for(int i = n-1 ; i >= 0 ; i--)
        while(k >= worth[i]){
            k -= worth[i];
            res++;
        }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    int worth[n];
    for(int i = 0 ; i < n ; i++)
        cin >> worth[i];
    cout << func(n,k,worth) << "\n";
}
