#include <iostream>
using namespace std;

int width, height;

int map[52][52];
bool isvisit[52][52];
int res;
void visit(int x, int y);
void init(){
    for (int i = 0 ; i < 52 ; i++)
        for (int j = 0 ; j < 52 ; j++){
            map[i][j] = -1;
            isvisit[i][j] = false;
            res = 0;
        }
}
void fillmap(int w, int h){
    for (int i = 1 ; i <= height ; i++)
        for (int j = 1 ; j <= width ; j++){
            cin >> map[j][i];
        }
}
void grouping(int x, int y){
    if (map[x][y+1]==1 && !isvisit[x][y+1])
        visit(x,y+1);
    if (map[x+1][y+1]==1 && !isvisit[x+1][y+1])
        visit(x+1,y+1);
    if (map[x+1][y]==1 && !isvisit[x+1][y])
        visit(x+1,y);
    if (map[x+1][y-1]==1 && !isvisit[x+1][y-1])
        visit(x+1,y-1);
    if (map[x][y-1]==1 && !isvisit[x][y-1])
        visit(x,y-1);
    if (map[x-1][y-1]==1 && !isvisit[x-1][y-1])
        visit(x-1,y-1);
    if (map[x-1][y]==1 && !isvisit[x-1][y])
        visit(x-1,y);
    if (map[x-1][y+1]==1 && !isvisit[x-1][y+1])
        visit(x-1,y+1);
    
    
}
void visit(int x, int y){
    isvisit[x][y] = true;
    if(map[x][y] == 1){
        grouping(x,y);
    }
        
}
int main(){
    while(1){
        cin >> width >> height;
        if (width == 0 || height == 0)
            break;
        init();
        fillmap(width,height);
        for (int i = 1 ; i <= width ; i++)
            for (int j = 1 ; j <= height ; j++){
                if(!isvisit[i][j]){
                    visit(i,j);
                    if(map[i][j] == 1){
                        res ++;
                    }
                }
            }
        cout << res << endl;
    }
    
}



