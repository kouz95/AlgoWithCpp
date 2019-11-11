#include <string>
#include <vector>

using namespace std;

#define MATERIAL_NUM 5
// 현재 냉장고 상태: 돼지 족 5kg, 양파 100g, 대파 10cm, 마늘 5g, 고추 2g
//레시피: 돼지 족 4kg, 양파 50g, 대파 10cm, 마늘 10g, 고추 4g
int currStored[MATERIAL_NUM] = {5, 100, 10, 5, 2};
int requiredAmountOfMan[MATERIAL_NUM] = {4, 50, 10, 10, 4};
int requiredAmountOfWoman[MATERIAL_NUM] = {4, 50, 10, 10, 2};

void heEat() {
    for(int i = 0 ; i < MATERIAL_NUM ; i++) {
        currStored[i] -= requiredAmountOfMan[i];
    }
}
void sheEatFirst() {
    for(int i = 0 ; i < MATERIAL_NUM ; i++) {
        currStored[i] -= requiredAmountOfWoman[i];
    }
}

int buyMaterial(int materialIdx) {
    int spending = 0;
    switch (materialIdx) {
        case 0:
            currStored[materialIdx] += 10;
            spending += 10000;
            break;
        case 1:
            currStored[materialIdx] += 100;
            spending += 3000;
            break;
        case 2:
            currStored[materialIdx] += 30;
            spending += 1000;
            break;
        case 3:
            currStored[materialIdx] += 50;
            spending += 2000;
            break;
        case 4:
            currStored[materialIdx] += 10;
            spending += 1000;
            break;
        default:
            break;
    }
    return spending;
}

bool isNeedToBuy(int materialIdx) {
    return currStored[materialIdx] < 0;
}
int getSpending(string amount) {
    int spending = 0;
    int amountStrLen = amount.length();
    if(amount.substr(amountStrLen - 1) == "5")
        sheEatFirst();
    
    int eatingTimes = amount[0] - '0'; // 10인분 이상?
    for(int i = 0 ; i < eatingTimes ; i++){
        heEat();
    }
    for(int i = 0 ; i < MATERIAL_NUM; i++){
        if(isNeedToBuy(i))
            spending += buyMaterial(i);
    }
    return spending;
}

bool isValid(string amount) {
    bool res = true;
    if(amount == "0.0")
        return false;
    if(amount.length() > 3)
        return false;
    return res;
}

vector<int> solution(vector<string> history) {
    vector<int> answer;
    for(int i = 0 ; i < history.size() ; i++) {
        if(!isValid(history[i])) {
            answer.clear();
            answer.push_back(-1);
            return answer;
        }
        answer.push_back(getSpending(history[i]));
    }
    return answer;
}
