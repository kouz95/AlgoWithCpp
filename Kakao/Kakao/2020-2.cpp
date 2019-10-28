#include <string>
#include <vector>

using namespace std;

string res = "";

string reverseStr(string s){
    string res = "";
    for(int i = 1 ; i < s.length()-1 ; i++){
        if(s[i] == '(')
            res+= ')';
        if(s[i] == ')')
        res+= '(';
    }
    return res;
    
}

bool isNiceStr(string s){
    bool res = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')'){
            s[i-1] = 'C', s[i] = 'C';
            i = -1;
            continue;
        }
        if(s[i] != 'C'){
            res = false;
            break;
        }
    }
    return res;
}

bool isValid(string u, string v){
    bool res = false;

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    for(int i = 0 ; i < u.length(); i++){
        if(u[i] == '(')
            cnt1++;
        if(u[i] == ')')
            cnt2++;
        if(v[i] == '(')
            cnt3++;
        if(v[i] == ')')
            cnt4++;
    }
    if(cnt1 == cnt2 && cnt3 == cnt4)
        res = true;
    return res;
}

string sliceStr(string p){
    string u ="";
    string v ="";
    string tmp = "";
    for(int i = 1 ; i <= p.length(); i++){
        u = p.substr(0,i);
        if(i == p.length())
            v = "";
        else
            v = p.substr(i);
        if(!isValid(u,v)){
            u = "";
            v = "";
            continue;
        }
        if(isNiceStr(u)){
            sliceStr(v);
            res += u + v;
            return res;
        }
        tmp += '(' + sliceStr(v) + ')' + reverseStr(u);
        return tmp;
    }
}

string solution(string p) {
    string answer = "";
    if(answer.length() == 0)
        return "";
    answer = sliceStr(p);
    return answer;
}
