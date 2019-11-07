//
//  14499.cpp
//  BOJ
//
//  Created by 김경준 on 2019/11/06.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAX_MAP_SIZE 20

int height, width;

typedef struct {
    int row;
    int col;
}Pos;

Pos dice;

int map[MAX_MAP_SIZE][MAX_MAP_SIZE];

int dR[4] = { 1, 0, -1, 0 };
int dC[4] = { 0, 1, 0, -1 };


void init() {
    
}

int main() {
    init();
}
