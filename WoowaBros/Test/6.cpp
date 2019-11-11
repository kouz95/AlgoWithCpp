#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isDuplicatedWith(string compareStr, string currStr) {
    bool res = false;
    for(int i = 0 ; i < (compareStr.length()/sizeof(compareStr[0])) - 1 ; i++) {
        string firstStr = compareStr.substr(i, 2);
        for(int j = 0 ; j < (currStr.length()/sizeof(currStr[0])) - 1 ; j++) {
            string secondStr = currStr.substr(j, 2);
            if(firstStr == secondStr)
                return true;
            
        }
    }
    return res;
}

bool isDuplicated(vector<string> requestedNicknames, string currNickname, int currIdx) {
    bool res = false;
    for(int i = 0 ; i < requestedNicknames.size(); i++) {
        if(i != currIdx && isDuplicatedWith(requestedNicknames[i], currNickname))
            return true;
    }
    return res;
}

vector<string> solution(vector<vector<string>> forms) {
    vector<string> answer;
    vector<string> requestedNicknames;
    for(int i = 0 ; i < forms.size(); i++) {
        requestedNicknames.push_back(forms[i][1]);
    }
    for(int i = 0 ; i < forms.size(); i++) {
        if(isDuplicated(requestedNicknames, forms[i][1], i)){
            answer.push_back(forms[i][0]);
        }
    }
    return answer;
}
