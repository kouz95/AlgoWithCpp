//
//  1222.cpp
//  BOJ
//
//  Created by 김경준 on 16/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stuNum[200001];
int gcdNum;
bool isIn[200001];
int partNum;
int start = 1;

int gcd(int num1, int num2){
    return num1%num2 ? gcd(num2, num1%num2) : num2;
}

int mulGcd(int * arr){
    int res = arr[start];
    for (int i = start + 1; i <= n ; i++)
        res = gcd(res,arr[i]);
    return res;
}

void getIsIn(){
    for (int i = start; i <= n ; i++){
        if (stuNum[i]%gcdNum == 0)
            isIn[i] = true;
    }
}

int isInNum(){
    int res = 0;
    for (int i = start ; i<=n ; i++){
        if (isIn[i] == true)
            res ++;
    }
    return res;
}
int getInNum(){
    int res = 0;
    
    for (int i = start ; i<=n ; i++){
        if (isIn[i] == true){
            res += gcdNum;
        }
    }
    return res;
}
void inItIsIn(){
    for (int i = start ; i <= n ; i++)
        isIn[i] =false;
    
}
void func(){
    int max = 0;
    sort(stuNum,stuNum+n);
    while (start < n){
        gcdNum = mulGcd(stuNum);
        getIsIn();
       
        if(isInNum() < 2)
            continue;
        if(!max|| max < getInNum())
            max = getInNum();
      
        start++;
        inItIsIn();
    }
    cout << max <<endl;
}

void init(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> stuNum[i];
        isIn[i] =false;
    }
    
}

int main(){
    init();
    func();
}

// 3 4 6 8 9
// 
