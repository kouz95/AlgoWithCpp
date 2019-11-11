#include <string>
#include <vector>
#include <iostream>

using namespace std;

void pushTimeToAns(string time, vector<int> &answer) {
    int timeIdx = time[1] - '0';
    if(time[0] == '1')
        timeIdx += 10;
    if(time[0] == '2')
        timeIdx += 20;
    timeIdx += 9;
    timeIdx = timeIdx >= 24 ? timeIdx-24 : timeIdx;
    answer[timeIdx]++;
}

string getTimeOfLog(string logs, int logIdx, int logLen) {
    string logTime = "error";
    int startIdx = logIdx * logLen;
    for(int i = startIdx; i < startIdx + logLen ; i++) {
        if(logs[i] == ':') {
            char firstNum = logs[i-2];
            char secondNum = logs[i-1];
            logTime.clear();
            logTime.push_back(firstNum);
            logTime.push_back(secondNum);
            break;
        }
    }
   return logTime;
}

int getLogLen(string logs) {
    int cnt = 0;
    while(logs[cnt] != '\n') {
        cnt++;
    }
    return cnt + 1;
}

vector<int> solution(string logs) {
    vector<int> answer(24, 0);
    int logLen = getLogLen(logs);
    int logNum = logs.length()/logLen;
    for(int i = 0 ; i <= logNum; i++) {
        string time = getTimeOfLog(logs, i, logLen);
        pushTimeToAns(time, answer);
    }
    return answer;
}
