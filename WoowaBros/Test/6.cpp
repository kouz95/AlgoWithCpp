#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isDuplicatedWith(string compareStr, string currStr) {
    bool res = false;
    for(int i = 0 ; i < (compareStr.length()/sizeof("제") - 1) ; i++) {
        string firstStr = compareStr.substr(i, 2);
        for(int j = 0 ; j < (currStr.length()/sizeof("제") - 1) ; j++) {
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

int main() {
    vector<string> tmpInputs;
    vector<vector<string>> forms;
    tmpInputs.push_back("jm@email.com");
    tmpInputs.push_back("제이엠");
    forms.push_back(tmpInputs);
    tmpInputs.clear();
    tmpInputs.push_back("jason@email.com");
    tmpInputs.push_back("제이슨");
    forms.push_back(tmpInputs);
    tmpInputs.clear();
    tmpInputs.push_back("woniee@email.com");
    tmpInputs.push_back("워니");
    forms.push_back(tmpInputs);
    tmpInputs.clear();
    tmpInputs.push_back("mj@email.com");
    tmpInputs.push_back("엠제이");
    forms.push_back(tmpInputs);
    tmpInputs.clear();
    tmpInputs.push_back("nowm@email.com");
    tmpInputs.push_back("이제엠");
    forms.push_back(tmpInputs);
    tmpInputs.clear();
    
    vector<string> sol = solution(forms);
    for(int i = 0 ; i < sol.size(); i++)
        cout << sol[i] <<endl;
    cout << sizeof("라") << endl;
    
}
