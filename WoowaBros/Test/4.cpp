#include <string>
#include <vector>

using namespace std;

bool isInInfos(string action, vector<string> infos) {
    bool res = false;
    string inputInfo = action.substr(6);
    for(int i = 0 ; i < infos.size(); i++) {
        if(inputInfo == infos[i])
            return true;
    }
    return res;
}

int getActionNum(string action) {
    int res = -1;
    
    if(action.substr(0,5) == "LOGIN")
        return 0;
    if(action.substr(0,3) == "ADD")
        return 1;
    if(action.substr(0,5) == "ORDER")
        return 2;
    
    return res;
}

bool getAns(vector<string> infos , string action, bool &isLogined, bool &isFoodAdded) {
    bool res = false;
    int actionNum = getActionNum(action);
    switch (actionNum) {
        case 0:
            if(isLogined)
                return false;
            if(isInInfos(action, infos)) {
                isLogined = true;
                return true;
            }
            break;
        case 1:
            if(isLogined) {
                isFoodAdded = true;
                return true;
            }
            break;
        case 2:
            if(isFoodAdded) {
                isFoodAdded = false;
                return true;
            }
            break;
            
        default:
            break;
    }
    return res;
}

vector<bool> solution(vector<string> infos, vector<string> actions) {
    vector<bool> answer;
    int userNum = infos.size();
    bool isLogined = false;
    bool isFoodAdded = false;
    for(int i = 0 ; i < actions.size(); i++) {
        bool isValidAction;
        isValidAction = getAns(infos ,actions[i], isLogined, isFoodAdded);
        answer.push_back(isValidAction);
    }
    
    return answer;
}
