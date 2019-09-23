//
//  6603.cpp
//  BOJ
//
//  Created by 김경준 on 23/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printSet(vector <int> numSet){
    vector<int> printContainer;
    for(int i = 0 ; i < numSet.size()-5 ; i++){
        printContainer.push_back(numSet[i]);
        for(int j = i+1 ; j < numSet.size()-4 ; j++){
            printContainer.push_back(numSet[j]);
            for(int k = j+1 ; k < numSet.size()-3 ; k++){
                printContainer.push_back(numSet[k]);
                for(int l = k+1 ; l < numSet.size()-2 ; l++){
                    printContainer.push_back(numSet[l]);
                    for(int m = l+1 ; m < numSet.size()-1 ; m++){
                        printContainer.push_back(numSet[m]);
                        for(int n = m+1 ; n < numSet.size() ; n++){
                            printContainer.push_back(numSet[n]);
                            for(int o = 0 ; o < 6 ; o++)
                                cout << printContainer[o] << " ";
                            cout << endl;
                            printContainer.pop_back();
                        }
                        printContainer.pop_back();
                    }
                    printContainer.pop_back();
                }
                printContainer.pop_back();
            }
            printContainer.pop_back();
        }
        printContainer.pop_back();
    }
}

int main(){
    int t = 1;
    while(t){
        cin >> t;
        if(t == 0)
             break;
        vector <int> numSet;
        for(int i = 0 ; i < t ; i++){
            int val;
            cin >> val;
            numSet.push_back(val);
        }
        printSet(numSet);
        cout << endl;
    }
}
