#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		unordered_set<int> seen;
		int slow = 0;
		for(int fast = 0; fast < n; fast++) {
			if (seen.find(nums[fast]) == seen.end()) {
				seen.insert(nums[fast]);
				nums[slow] = nums[fast];
				slow++;
			}
		}
		bubbleSort(nums, slow);
		return slow;
	}
	void bubbleSort(vector<int>& nums,int len) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					swap(nums[j], nums[j + 1]);
				}
			}
		}
	}
};
int main() {
	vector<int> nums = { 1,5,3,2,5,2,4,5 };
	Solution sol;
	int newLength = sol.removeDuplicates(nums);
	cout << "New length: " << newLength << endl;
	cout << "Array after removing duplicates and sorting: ";
	for (int i = 0; i < newLength; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return  0;
}

