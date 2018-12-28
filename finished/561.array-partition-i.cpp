/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 *
 * https://leetcode.com/problems/array-partition-i/description/
 *
 * algorithms
 * Easy (67.67%)
 * Total Accepted:    119.9K
 * Total Submissions: 177.2K
 * Testcase Example:  '[1,4,3,2]'
 *
 * 
 * Given an array of 2n integers, your task is to group these integers into n
 * pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of
 * min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,4,3,2]
 * 
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3,
 * 4).
 * 
 * 
 * 
 * Note:
 * 
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 * 
 * 
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
			// sort
			mergeSort(nums, 0, nums.size()-1);
			// standard sort algorithm.
			//std::sort(nums.begin(), nums.end());
			int sum = 0;
			for (int i = 0; i < nums.size(); i +=2) {
				sum += nums[i];
			}
			return sum;
    }	

		void merge(vector<int>& nums, int left, int mid, int right) {
			// Allocate and assign data to sub left and right array
			// [left, mid]
			vector<int> leftSub(nums.begin() + left, nums.begin() + mid + 1);  
			//[mid+1, right]
			vector<int> rightSub(nums.begin() + mid + 1, nums.begin() + right + 1);  
			// keep comparasion successfully when one sub is totally lower than other,
			// such as [1,2]vs[3,4]. You need to add max<int> to make sure pointers within
			// control, like [1,2,max] vs [3,4, max], then you can get [1,2,3,4]
			leftSub.insert(leftSub.end(), numeric_limits<int>::max());
			rightSub.insert(rightSub.end(), numeric_limits<int>::max());
			// define pointers
			int leftPtr = 0;
			int rightPtr = 0;
			// merger array
			for (int i = left; i <= right; i++) {
				if (leftSub[leftPtr] < rightSub[rightPtr]) {
					nums[i] = leftSub[leftPtr++];
				} else {
					nums[i] = rightSub[rightPtr++];
				}
			}
		}
		// main function
		void mergeSort(vector<int>& nums, int left, int right) {
  		if (left >= right) {
    		return;  // exit function
 			 } else {
			int mid = (left + right) >> 1;
   		 mergeSort(nums, left, mid);       // merge sort left
   		 mergeSort(nums, mid + 1, right);  // merge sort right
			 merge(nums, left, mid, right);    // merge left and right
  		}
		}
};
