//
//  14501.cpp
//  BOJ
//
//  Created by 김경준 on 21/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void getMaxProfit(int * arr,vector <pair <int, int> > profit, int n){
    for(int i = n-1 ; i >=0 ; i--){
        int nextIdx = profit[i].first + i;
        if(nextIdx > n)
            profit[i].second = 0;
        if(nextIdx <= n){
            int val = 0;
            for(int j = nextIdx ; j <= n; j++){
                if(!val || val < profit[i].second + arr[j])
                    val = profit[i].second + arr[j];
            }
            arr[i] = val;
        }
    }
    int maxProfit = 0;
    for(int i = 0 ; i < n; i++)
        if (!maxProfit || maxProfit < arr[i])
            maxProfit = arr[i];
    cout << maxProfit << endl;
}

int main(){
    int n;
    cin >> n;
    vector <pair <int, int> > profit;
    for(int i = 0 ; i < n; i++){
        int t, p;
        cin >> t >> p;
        profit.push_back({t,p});
    }
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    getMaxProfit(arr, profit, n);
}
