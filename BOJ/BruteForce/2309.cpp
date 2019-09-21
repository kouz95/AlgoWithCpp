//
//  2309.cpp
//  BOJ
//
//  Created by 김경준 on 20/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define N 9

void PrintRes(int * arr , int num1, int num2){
    for(int i = 0 ; i < N ; i++){
        if (i != num1 && i != num2)
            cout << arr[i] << "\n";
    }
}

int SumWithOut(int * arr , int i, int j){
    int res = 0;
    for(int k = 0 ; k < N ; k++){
        if (k != i && k != j){
            res += arr[k];
        }
    }
    return res;
}

int main(){
    int height[N];
    int num1, num2;
    for(int i = 0 ; i < N ; i++)
        cin >> height[i];
    sort(height,height+N);
    for(int i = 0 ; i < N-1 ; i++)
        for(int j = i+1 ; j < N ; j++)
            if(SumWithOut(height, i, j) == 100){
                num1 = i;
                num2 = j;
                goto EXIT;
            }

    
EXIT:
    PrintRes(height,num1,num2);
}

