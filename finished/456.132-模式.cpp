/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // 超时,O(n^3)
  bool find132pattern1(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        if (nums[j] > nums[i]) {
          for (int k = j + 1; k < n; k++) {
            if (nums[k] > nums[i] && nums[k] < nums[j]) {
              return true;
            }
          }
        }
      }
    }
    return false;
  }
  // O(n^2)， 通过但太慢了。
  bool find132pattern2(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      int max_val = nums[i];
      for (int j = i + 1; j < n; j++) {
        // 只要保证最大值为中间值即可
        if (nums[j] > max_val) {
          max_val = nums[j];
        }
        if (nums[j] < max_val && nums[j] > nums[i]) {
          return true;
        }
      }
    }
    return false;
  }
  // 以空间换时间, O(n)
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return false;
    }
    // 记录每一位之前的最小值
    vector<int> min_nums(n);
    min_nums[0] = nums[0];
    for (int i = 1; i < n; i++) {
      min_nums[i] = min(nums[i], min_nums[i - 1]);
    }
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] > min_nums[i]) {
        // 以i为中心，将右侧小于i左侧最小值的元素出栈
        while (!s.empty() && s.top() <= min_nums[i]) {
          s.pop();
        }
        if (!s.empty() && nums[i] > s.top()) {
          return true;
        }
        s.push(nums[i]);
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  vector<int> nums = {1,-4,2,-1,3,-3,-4,0,-3,-1};
  Solution test;
  test.find132pattern2(nums);
}