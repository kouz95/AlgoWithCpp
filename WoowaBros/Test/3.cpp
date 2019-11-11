#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getDiscountedPrices(int discountPer, int price) {
    return price * (100-discountPer)/100;
}

int solution(vector<int> prices, vector<int> discounts) {
    int answer = 0;
    sort(prices.begin(), prices.end(), greater<int>());
    sort(discounts.begin(), discounts.end(), greater<int>());
    for(int i = 0 ; i < min(discounts.size(), prices.size()); i++) {
        prices[i] = getDiscountedPrices(discounts[i], prices[i]);
    }
    for(int i = 0 ; i < prices.size(); i++) {
        answer += prices[i];
    }
    return answer;
}
