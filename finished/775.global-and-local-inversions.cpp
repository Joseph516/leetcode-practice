/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 *
 * https://leetcode.com/problems/global-and-local-inversions/description/
 *
 * algorithms
 * Medium (36.67%)
 * Total Accepted:    10.1K
 * Total Submissions: 27.5K
 * Testcase Example:  '[0]'
 *
 * We have some permutation A of [0, 1, ..., N - 1], where N is the length of
 * A.
 *
 * The number of (global) inversions is the number of i < j with 0 <= i < j < N
 * and A[i] > A[j].
 *
 * The number of local inversions is the number of i with 0 <= i < N and A[i] >
 * A[i+1].
 *
 * Return true if and only if the number of global inversions is equal to the
 * number of local inversions.
 *
 * Example 1:
 *
 *
 * Input: A = [1,0,2]
 * Output: true
 * Explanation: There is 1 global inversion, and 1 local inversion.
 *
 *
 * Example 2:
 *
 *
 * Input: A = [1,2,0]
 * Output: false
 * Explanation: There are 2 global inversions, and 1 local inversion.
 *
 *
 * Note:
 *
 *
 * A will be a permutation of [0, 1, ..., A.length - 1].
 * A will have length in range [1, 5000].
 * The time limit for this problem has been reduced.
 *
 *
 */

// hint: local inversion is the subset of global inversion.
// A of [0, 1, ..., N - 1] is the key.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isIdealPermutation(vector<int>& A) {
    // 局部倒置属于全局倒置，则检查是否存在除了局部倒置的全局倒置即可
    int n = A.size();
    if (n == 0 || n == 1 || n == 2) {
      return true;
    }
    int max_num = A[0];
    for (int i = 2; i < n; i++) {
      // 出现非局部倒置的全局倒置
      if (max_num > A[i]) {
        return false;
      }
      // 找到前面遍历的最大值，只要对于最大值出现非局部倒置的全局倒置，则为false
      // 不需要一个个比
      max_num = max(max_num, A[i - 1]);
    }
    return true;
  }
};
/*
// Exceed time，复杂度O(N^2)
bool isIdealPermutation(vector<int>& A) {
  int localCount = 0;
  int globalCount = 0;
  int len = A.size();
  if (len == 1) {
    return true;
  }
  for (int i = 0; i < len - 1; i++) {
    // local count
    if (A[i] > A[i + 1]) {
      localCount += 1;
    }
    // global count
    for (int j = i; j < len; j++) {
      if (A[i] > A[j]) {
        globalCount += 1;
      }
    }
  }
  return localCount == globalCount;
}
*/

