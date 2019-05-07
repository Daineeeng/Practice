#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums) {   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    int len = nums.size();	
	set<int> s;
    
    for(int i=0;i<len;i++){
		s.insert(nums[i]);
	}
	
	int s_size = s.size();
	if(s_size > len/2) {
		answer = len/2;
	} else {
		answer = s_size();
	}
	return answer;
}
