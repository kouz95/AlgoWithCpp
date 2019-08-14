//
//  2839.cpp
//  BOJ
//
//  Created by 김경준 on 14/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int res;

int div5(int n){
    return n % 5;
}

void func(){
    if(n == 4 || n == 7)
        res = -1;
    else{
        switch (div5(n)) {
            case 3:
                res = n / 5 + 1;
                break;
            case 4:
                res = n / 5 + 2;
                break;
            case 0:
                res = n / 5;
                break;
            case 1:
                res = n / 5 + 1;
                break;
            case 2:
                res = n / 5 + 2;
                break;
            default:
                break;
        }
    }
    cout << res <<endl;
}

void input(){
    cin >> n;
}

int main(){
    input();
    func();
   
}

/*
 3  4   5   6   7
 1  -1  1   2   -1
 
 8  9   10  11  12
 2  3   2   3   4
 
 13 14  15  16  17
 3  4   3   4   5
 
 */
