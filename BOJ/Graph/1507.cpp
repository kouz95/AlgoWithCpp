//
//  1507.cpp
//  BOJ
//
//  Created by 김경준 on 27/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 20

int dist[MAX+1][MAX+1];
bool isDelete[MAX+1][MAX+1];

void floyd(int vertex){
    int res = 0;
    for(int k = 1; k <= vertex ; k++)
        for(int i = 1; i <= vertex ; i++)
            for(int j = 1; j <= vertex ; j++){
                if (i==j || j==k || k==i)
                    continue;
                else if (dist[i][j] > dist[i][k] + dist[k][j]){
                    res = -1;
                    break;
                }
                else if (dist[i][j] == dist[i][k] + dist[k][j])
                    isDelete[i][j] = true;
            }
    if(res != -1){
        for (int i = 1; i <= vertex ; i++)
            for (int j = 1 ; j <= vertex ; j++)
                if(!isDelete[i][j])
                    res+=dist[i][j];
        res /= 2;
    }

    cout << res << "\n";

}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex;
    cin >> vertex;
    for (int i = 1; i <= vertex ; i++)
        for (int j = 1 ; j <= vertex ; j++)
            cin >> dist[i][j];
    memset(isDelete,false,sizeof(isDelete));
    floyd(vertex);
}
