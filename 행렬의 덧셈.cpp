#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> answer = arr1;
    for(int i=0; i<(int)arr1.size(); i++) {
        for(int j=0; j<(int)arr1[i].size(); j++) {
            answer[i][j] += arr2[i][j];
        }
    }
    return answer;
}
