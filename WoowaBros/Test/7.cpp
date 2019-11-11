#include <string>
#include <vector>

using namespace std;

vector<pair<string, int> > getUserFriends() {
    
}

vector<string> solution(string user, vector<vector<string>> friends, vector<string> visitors) {
    vector<string> answer;
    vector<pair<string, int> > userFriends = getUserFriends();
    for(int i = 0 ; i < friends.size(); i++) {
        for(int j = 0 ; j < userFriends.size(); j++) {
            if(friends[i][0] == userFriends[j].first || friends[i][1] == userFriends[j].first)
                userFriends[j].second += 10;
        }
    }
    return answer;
}
