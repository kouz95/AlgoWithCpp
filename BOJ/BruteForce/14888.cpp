//
//  14888.cpp
//  BOJ
//
//  Created by 김경준 on 2019/11/07.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_NUM 2e9
#define MIN_NUM -2e9

vector<int> nums;
vector<int> operatorNums;
vector<int> operators;

int operationWith(int firstNum, int operatorType, int secondNum) {
    int res = -1;
    
    switch (operatorType) {
        case 0:
            return firstNum + secondNum;
            break;
        case 1:
            return firstNum - secondNum;
            break;
        case 2:
            return firstNum * secondNum;
            break;
        case 3:
            return firstNum / secondNum;
            break;
        default:
            break;
    }
    
    return res;
}

pair<int,int> getMinAndMaxNum() {
    int minNum = MAX_NUM;
    int maxNum = MIN_NUM;
    
    
    sort(operators.begin(), operators.end());
    
    do{
        int varNum = operationWith(nums[0],operators[0],nums[1]);
        for(int i = 1 ; i < operators.size() ; i++)
            varNum = operationWith(varNum,operators[i],nums[i+1]);
        minNum = varNum < minNum ? varNum : minNum;
        maxNum = varNum > maxNum ? varNum : maxNum;

    }while(next_permutation(operators.begin(), operators.end()));
    return {minNum,maxNum};
}

void printSol() {
    int minNum = getMinAndMaxNum().first;
    int maxNum = getMinAndMaxNum().second;
    
    cout << maxNum << "\n";
    cout << minNum << "\n";
}

void getOperators() {
    for(int i = 0 ; i < 4 ; i++) {
        int iterNum = operatorNums[i];
        for(int j = 0 ; j < iterNum ; j++) {
            operators.push_back(i);
        }
    }
}

void init() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        int inputNum;
        cin >> inputNum;
        nums.push_back(inputNum);
    }
    for( int i = 0 ; i < 4 ; i++) {
        int inputNum;
        cin >> inputNum;
        operatorNums.push_back(inputNum);
    }
    getOperators();
}

int main() {
    init();
    printSol();
}

