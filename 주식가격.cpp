#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer(prices.size());
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size();j++){
            answer[i] = j-i;
            if(prices[i] > prices[j])  break;
        }
    }
    return answer;
}
