//
//  1946.cpp
//  BOJ
//
//  Created by 김경준 on 08/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int func(int n,vector<pair<int, int> > score){
    int res = 0;
    int maxSize = 0;
    int maxIndex;
    for(int i = 0 ; i < n ; i++)
        if(!maxSize || maxSize < abs(score[i].first - score[i].second)){
            maxIndex = i;
            maxSize = abs(score[i].first - score[i].second);
        }
    int firstLimit = score[maxIndex].first;
    int secondLimit = score[maxIndex].second;
    for(int i = 0 ; i < n ; i++){
        if (score[i].first < firstLimit && score[i].second < secondLimit)
            continue;
        if (score[i].first <= firstLimit || score[i].second <= secondLimit)
            res++;
    }
    
    return res;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > score;
        for(int i = 0 ; i < n; i ++){
            int score1, score2;
            cin >> score1 >> score2;
            score.push_back({score1,score2});
        }
        cout << func(n,score) << "\n";
        score.clear();
    }
}
