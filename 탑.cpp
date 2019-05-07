#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int len = heights.size();
    vector<int> answer(len, 0);
	
	for (int from = len - 1; from > 0; from--) {
		for (int to = from - 1; from >= 0; to--) {
			if (heights[to] > heights[from]) {
				answer[from] = to + 1;
                break;
			}
			else {
				answer[from] = 0;
			}
			if (to == 0 && heights[from] >= heights[to]) {
				answer[from] = 0;
			    break;
			}
		}
	}
	answer[0] = 0;
	return answer;
}
