#include <string>
#include <vector>

using namespace std;

bool isMatch(string word, string query){
    bool res = true;
    int qLen = query.length();
    if(word.length() != qLen)
        return false;
    for(int i = 0; i < qLen ; i++){
        if(query[i] == '?')
            continue;
        if(query[i] == word[i])
            continue;
        else{
            res = false;
            break;
        }
        
    }
    
    
    return res;
}

int solNum(vector<string> words, string query){
    int res = 0;
    for(int i = 0 ; i < words.size(); i++){
        if(isMatch(words[i],query))
            res++;
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i = 0 ; i < queries.size(); i++){
        int res = solNum(words, queries[i]);
        
        answer.push_back(res);
    }
    return answer;
}
