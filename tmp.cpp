#include<iostream>
#include<queue>
using namespace std;


int N;
#define MAX 101
int map[MAX][MAX];
int visited[MAX][MAX];
queue<pair <int,int >>q;

void check(int x, int y) {
   visited[x][y] = 1;
   q.push(make_pair(x, y));

   while (!q.empty()) {
      for (int i = 0; i < N;i++) {
         if (map[q.front().second][i] && !visited[x][i]) {
            visited[x][i] == 1;
            q.push(make_pair(q.front().second, i));
         }
      }
      q.pop();
   }

}

int main() {
   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> map[i][j];
      }
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (map[i][j] == 1) {
            check(i, j);
         }
      }
   }

   for (int i = 0; i < N;i++) {
      for (int j = 0; j < N; j++) {
         cout << visited[i][j]<<' ';
      }
      cout << '\n';
   }
}
