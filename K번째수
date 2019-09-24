#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++){
        int a = commands[i][0] - 1;
        int b = commands[i][1] - 1;
        int k = commands[i][2] - 1;

        vector<int> vt;
        for(int idx=a; idx<=b; idx++){
            vt.push_back(array[idx]);
        }            
        sort(vt.begin(), vt.end());
        answer.push_back(vt[k]);   
    }
    
    return answer;
}
