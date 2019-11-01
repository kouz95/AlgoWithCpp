#include <string>
#include <vector>
#include <iostream>

using namespace std;
int keySize;
int lockSize;
int mapSize;

vector<vector<int>> rotate(vector<vector<int>> key){
    vector<vector<int>> result;
    int n = key[0].size();
    for(int i = n-1; i >= 0; i--){
        vector<int> tmp;
        for(int j = 0; j < n; j++){
            tmp.push_back(key[j][i]);
        }
        result.push_back(tmp);
    }
    return result;
}

bool isValid(vector<vector<int>> map){
    bool res = true;
    for(int i = keySize - 1 ; i < keySize + lockSize - 1 ; i++){
        for(int j = keySize - 1 ; j < keySize + lockSize - 1 ; j++){
            if(map[i][j] == 1)
                continue;
            res = false;
            break;
        }
    }
    return res;
}


vector<vector<int>> pushKey(int row, int col, vector<vector<int>> map, vector<vector<int>> key){
    
    vector<vector<int>> res(map);
    vector<vector<int>> tmpKey(mapSize,vector<int>(mapSize,0));
    for(int i = 0 ; i < keySize ; i++){
        for(int j = 0 ; j < keySize ; j++){
            tmpKey[i+row][j+col] = key[i][j];
        }
    }

    for(int i = 0 ; i < mapSize ; i++){
        for(int j = 0 ; j < mapSize ; j++){
            res[i][j] += tmpKey[i][j];
        }
    }
    
    return res;
}


vector<vector<int>> makeMap(vector<vector<int>> key, vector<vector<int>> lock){
    
    vector<vector<int>> map(mapSize,vector<int>(mapSize,0));
    
    for(int i = keySize - 1 ; i < keySize + lockSize - 1 ; i++){
        for(int j = keySize - 1 ; j < keySize + lockSize - 1 ; j++){
            map[i][j] = lock[i+1-keySize][j+1-keySize];
        }
    }
    return map;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    keySize = key[0].size();
    lockSize = lock[0].size();
    mapSize = lockSize + 2 * (keySize - 1);
    
    vector<vector<int>> map = makeMap(key, lock);
    vector<vector<int>> tmpMap(mapSize,vector<int>(mapSize,0));
    
    int row, col;
    
    for(int i = 0 ; i < keySize + lockSize - 1 ; i++){
        for(int j = 0 ; j < keySize + lockSize - 1 ; j++){
            row = i;
            col = j;
            tmpMap = pushKey(row,col,map,key);
            if(isValid(tmpMap)){
                return true;
            }
            for(int k = 0 ; k < 3 ; k++){
                key = rotate(key);
                tmpMap = pushKey(row,col,map,key);
                if(isValid(tmpMap)){
                    return true;
                }
                
            }
            key = rotate(key);
        }
    }
    return answer;
}
