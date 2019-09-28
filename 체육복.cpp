#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> student(n,1);
    
    for(int i=0; i<(int)lost.size(); i++) {
        student[ lost[i]-1 ]--;
    }
    
    for(int i=0; i<(int)reserve.size(); i++) {
        student[ reserve[i]-1 ]++;
    }
    
    for(int i=0; i<(int)student.size(); i++) {
        if(i != 0 && student[i] == 0) {
            if(student[i-1] == 2) {
                student[i-1]--;
                student[i]++;
            }
        }
        
        if(i != student.size()-1 && student[i] == 0) {
            if(student[i+1] == 2) {
                student[i+1]--;
                student[i]++;
            }
        }
    }
    
    int answer=0;
    for(int i=0; i<(int)student.size(); i++) {
        if(student[i] > 0) answer++;
    }
    return answer;
}
