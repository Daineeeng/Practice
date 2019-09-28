#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    for(int i=0; i<(int)arr.size(); i++) {
        if(arr[i]%divisor == 0) answer.push_back(arr[i]);
    }
    int a_size = answer.size();
    if (a_size == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}
