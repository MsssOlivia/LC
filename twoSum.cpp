#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> sum;
	void twoSum(vector<int>&, int);
};

void Solution::twoSum(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target){
				sum.push_back(i);
				sum.push_back(j);
			}
		}
	}
}

int main() {
	Solution mySolution;
	vector<int> A;
	A = { 1,3,5,7,88,21,34,54,76,12,65 };
	int target = 12;
	mySolution.twoSum(A, target);
	cout << "The two numers in array A whose sum is " << target << " are " << A[mySolution.sum[0]] << " and " << A[mySolution.sum[1]] << endl;
	system("pause");
	return 0;
}
