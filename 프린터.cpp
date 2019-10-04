#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i=0; i<priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }

    int answer = 0;
    int cnt = 0;
    while(!q.empty()) {
        if(q.front().second == pq.top()) {
            if(q.front().first==location) {
                answer++;
                break;
            }
            q.pop();
            pq.pop();
            answer++;
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}
