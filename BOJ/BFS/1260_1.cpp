#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int vertexNum;
int edgeNum;
int startVertex;
vector<int> edge[1001];
bool isVisit[1001];
int visitCnt = 0;

void init(){
    cin >> vertexNum >> edgeNum >> startVertex;
    for(int i = 0 ; i < edgeNum ; i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    for(int i = 1; i <= vertexNum ; i++)
        sort(edge[i].begin(),edge[i].end());
}

void visitDFS(int currVertex){
    if(visitCnt == vertexNum)
        return;
    if(isVisit[currVertex])
        return;
    isVisit[currVertex] = true;
    visitCnt++;
    cout << currVertex << " ";
    for(int i = 0; i < edge[currVertex].size() ; i++){
        int nextVertex = edge[currVertex][i];
        visitDFS(nextVertex);
    }
}

void visitBFS(){
    queue<int> qu;
    qu.push(startVertex);
    while(!qu.empty()){
        int currVertex = qu.front();
        qu.pop();
        if(visitCnt == vertexNum)
            break;
        if(isVisit[currVertex])
            continue;
        isVisit[currVertex] = true;
        visitCnt++;
        cout << currVertex << " ";
        for(int i = 0; i < edge[currVertex].size() ; i++){
            int nextVertex = edge[currVertex][i];
            qu.push(nextVertex);
        }
    }
}

int main(){
    init();
    visitDFS(startVertex);
    cout << endl;
    memset(isVisit,false,sizeof(isVisit));
    visitCnt = 0;
    visitBFS();
}
