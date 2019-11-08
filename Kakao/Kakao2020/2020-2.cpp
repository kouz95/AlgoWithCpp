#include <string>
#include <vector>

using namespace std;

string cutAndReverse(string s){
    for(int i = 1 ; i < s.length()-1 ; i++){
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }
    return s.substr(1,s.length()-2);
}

bool isNiceStr(string s){
    bool res = false;
    int cnt = 0 ;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')')
            cnt--;
        if(cnt < 0)
            break;
    }
    if(cnt == 0)
        res = true;
    return res;
}

int firstBalanceIdx(string s){
    int res = 0;
    int cnt = 0;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')')
            cnt--;
        if(cnt == 0){
            res = i;
            break;
        }
    }
    
    return res;
}


string solution(string p) {
    string answer = "";
    if(p.length() == 0)
        return "";
    int separateIdx = firstBalanceIdx(p) + 1;
    string u = p.substr(0,separateIdx);
    string v = p.substr(separateIdx);
    if(isNiceStr(u)){
        return u + solution(v);
    }
    answer = '(' + solution(v) + ')' + cutAndReverse(u);
    return answer;
}
