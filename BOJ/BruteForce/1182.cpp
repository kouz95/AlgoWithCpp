//
//  1182.cpp
//  BOJ
//
//  Created by 김경준 on 24/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int res = 0;

void sumOfSubSet(int idx, int sum, int n, int s, int * num){
    sum += num[idx];
    if(idx >= n)
        return;
    if(sum == s)
        res++;
    sumOfSubSet(idx+1, sum - num[idx], n, s, num);
    sumOfSubSet(idx+1, sum, n, s, num);

}

int main(){
    int n , s;
    cin >> n >> s;
    int num[n];
    for(int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    sumOfSubSet(0, 0, n, s, num);
    cout << res << endl;
}



