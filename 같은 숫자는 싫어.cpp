#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    vector<int> answer;
    answer.push_back(arr[0]);   
    for(int i=1; i<(int)arr.size(); i++) {
        if(answer.back() == arr[i]) continue;
        else answer.push_back(arr[i]);
    }
    return answer;
}
