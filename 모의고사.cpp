#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool go = true;

vector<int> solution(vector<int> answers) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int p1[] = {1,2,3,4,5};
    int p2[] = {2,1,2,3,2,4,2,5};
    int p3[] = {3,3,1,1,2,2,4,4,5,5};
    
    int c1 = 0; int c2 = 0; int c3 = 0;
    int asize = answers.size();
    for(int i=0; i<asize; i++) {
        int i1 = i%5;
        int i2 = i%8;
        int i3 = i%10;
        
        if(p1[i1] == answers[i]) c1++;
        if(p2[i2] == answers[i]) c2++;
        if(p3[i3] == answers[i]) c3++;
    }
    
    vector<int> answer;
    int maxc = max(c1,max(c2,c3));
    if(c1==maxc) answer.push_back(1);
    if(c2==maxc) answer.push_back(2);
    if(c3==maxc) answer.push_back(3);
    return answer;
}
