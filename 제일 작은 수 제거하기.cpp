#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    int minN = 987654321;
    if(arr.size()==1) answer.push_back(-1);
    else {
        for(int i=0; i<(int)arr.size(); i++) {
            if(arr[i] < minN) {
                minN = arr[i];
            }
        }
        for(int i=0; i<(int)arr.size(); i++) {
            if(arr[i] == minN) continue;
            else answer.push_back(arr[i]);
        }        
    }
    return answer;
}
