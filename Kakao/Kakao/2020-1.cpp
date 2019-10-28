#include <string>
#include <vector>

using namespace std;

int slice(string s, int step){
    int cnt = 1;
    string resStr = "";
    for(int i = 0 ; i < s.length(); i+=step){
        if(i + 2 * step > s.length()){
            if(cnt > 1)
                resStr += to_string(cnt) + s.substr(i);
            else resStr += s.substr(i);
            break;
        }
        string currStr = s.substr(i,step);
        string nextStr = s.substr(i+step,step);
        if(currStr == nextStr){
            cnt++;
            continue;
        }
        if(cnt > 1){
            resStr += to_string(cnt) + currStr;
            cnt = 1;
            continue;
        }
        resStr += currStr;
    }
    return resStr.length();
}

int solution(string s){
    int answer = s.length();
    
    for(int i = 1 ; i <= s.length()/2; i++){
        if(answer > slice(s, i)){
            answer = slice(s, i);
        }
    }
    return answer;
}
