#include <iostream>
#include <string>
#include <vector>
using namespace std;

int chk[26];

int solution(string skill, vector<string> skill_trees) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    
    int cnt = 1;
    for(int i=0; i<skill.size(); i++) {
        chk[skill[i] - 'A'] = cnt;
        cnt++;
    }
    
    for(int i=0; i<skill_trees.size(); i++) {
        cnt = 1;
        bool asc = true;
        for(int j=0; j<skill_trees[i].size(); j++) {
            int tmp = chk[skill_trees[i][j] - 'A'];
            if(tmp) {
                if(tmp != cnt) {
                    asc = false;
                    break;
                } else {
                    cnt++;
                }
            } 
        }
        if(asc) answer++;
    }    
    return answer;
}
