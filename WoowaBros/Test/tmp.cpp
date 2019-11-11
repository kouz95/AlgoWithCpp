
#include <vector>
using namespace std;

int rooms[200000];

int findNum(int num) {
    int res;
    while(1) {
        if(!rooms[num]){
            rooms[num] += 1;
            break;
        }
        else {
            findNum()
        }
    }
    return res;
}

void solution(int k, vector<int> a) {
    vector<int> res;
    
    for(int i = 0 ; i < a.size(); i++) {
        res.push_back(findNum(a[i]));
    }
}
int main() {
    int k = 10;
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(1);
    a.push_back(3);
    a.push_back(1);
    solution(k,a);
}
