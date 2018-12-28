/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.28%)
 * Total Accepted:    324.1K
 * Total Submissions: 804.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
#include<stack>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
			int temp = 1;
			int len = digits.size();
			vector<int> res;

			for (int i = len-1; i >= 0; i--) {
				digits[i] += temp;
				if (digits[i] >= 10) {
					digits[i] -= 10;
					temp = 1;
				} else {
					temp = 0;
				}
			}
			if (temp == 1) {
				res.push_back(temp); // top is 1
			}
			
			// output
			for (int i = 0; i < len; i++) {
				res.push_back(digits[i]);
			}
			
			return res;
    }
};




