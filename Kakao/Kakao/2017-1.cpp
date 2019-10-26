#include <string>
#include <vector>

using namespace std;

string A, C, F, J, M, N, R, T = "";

void setCondition(char firstName, char lastName, char condition, int num){
    switch(firstName){
        case 'A':
            return;
        default:
            return;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    for(int i = 0; i < n ; i++){
        char firstName = data[i][0];
        char lastName = data[i][2];
        char condition = data[i][3];
        int num = (int)data[i][4] - '0';
        setCondition(firstName,lastName,condition,num);
    }
    
    return answer;
}
