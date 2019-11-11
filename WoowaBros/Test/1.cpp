#include <string>
#include <vector>
#include <cmath>

using namespace std;

double getDistance(vector<int> p1, vector<int> p2) {
    double res;
    int x1, y1, x2, y2
    x1 = p1[0];
    y1 = p1[1];
    x2 = p2[0];
    y2 = p2[1];
    
    res = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    return res;
}

int solution(vector<int> restaurant, vector<vector<int>> riders, int k) {
    int answer = 0;
    double dist;
    
    for(int i = 0 ; i < riders.size() ; i++) {
        dist = getDistance(restaurant, riders[i]);
        if(dist <= (double)k)
            answer++;
    }
    
    return answer;
}
