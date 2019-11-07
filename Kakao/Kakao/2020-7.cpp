#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int row1;
    int col1;
    int row2;
    int col2;
}Pos;

Pos myRobot;



int solution(vector<vector<int>> board) {
    int answer = 0;
    queue<Pos> qu;
    myRobot.row1 = 1;
    myRobot.col1 = 1;
    myRobot.row2 = 1;
    myRobot.col2 = 2;
    
    
    return answer;
}
