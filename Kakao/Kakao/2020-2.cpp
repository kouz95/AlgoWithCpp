#include <string>
#include <vector>

using namespace std;

string cutAndReverse(string s){
    for(int i = 1 ; i < s.length()-1 ; i++){
        if(s[i] == '(')
            s[i] = ')';
        if(s[i] == ')')
            s[i] = '(';
    }
    return s.substr(1,s.length()-2);
}

bool isNiceStr(string s){
    bool isNice = false;
    string tmp;
    for(int i = 0 ; i < s.length(); i++){
        if(s.length() == 0){
            isNice = true;
            break;
        }
        if(i == 0 && s[i] == ')')
            return isNice;
        if(i == s.length()-1)
            break;
        if(s[i] == '(' && s[i+1] == ')'){
            s = s.substr(0,i) + s.substr(i+2);
            i-=1;
            continue;
        }
    }
    return isNice;
}

int separateStr(string s){
    int sepIdx = 0;
    int leftCnt = 0;
    int rightCnt = 0;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == '('){
            leftCnt++;
        }
        if(s[i] == ')'){
            rightCnt++;
        }
        if(leftCnt != 0 && rightCnt != 0 && leftCnt == rightCnt){
            sepIdx = i;
            break;
        }
    }
    return sepIdx;
}

string solution(string p) {
    string answer = "";
    int loopCnt = 0;
    bool goLoop = false;
    if(p.length() == 0)
        return answer;
    int sepIdx = separateStr(p);
    string u = p.substr(0,sepIdx+1);
    string v;
    if(sepIdx + 1 >= p.length())
        v = "";
    else
        string v = p.substr(sepIdx+1);
    if(goLoop)
        return u;
    if(isNiceStr(u) && loopCnt == 0){
        goLoop = true;
        u += solution(v);
        goLoop = false;
        loopCnt++;
    }
    else{
        answer = '(' + solution(v) + ')' + cutAndReverse(u);
    }
        
    return answer;
}
//(()())()

// u (()()), v()
