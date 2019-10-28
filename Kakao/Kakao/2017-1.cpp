#include <string>
#include <vector>
#include <iostream>

using namespace std;

string A, C, F, J, M, N, R, T = "";

void getSet(){
    for(int i = 0 ; i < A.length(); i++)
        cout << A[i];
}

void setCondition(char firstName, char lastName, char condition, int num){
    switch(firstName){
        case 'A':
            A += lastName + condition + num;
            return;
        case 'C':
            C += lastName + condition + num;
            return;
        case 'F':
            F += lastName + condition + num;
            return;
        case 'J':
            J += lastName + condition + num;
            return;
        case 'M':
            M += lastName + condition + num;
            return;
        case 'N':
            N += lastName + condition + num;
            return;
        case 'R':
            R += lastName + condition + num;
            return;
        case 'T':
            T += lastName + condition + num;
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
    getSet();
    
    return answer;
}
