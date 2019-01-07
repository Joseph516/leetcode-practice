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
// 下面的算法理解不是很清楚。
class Solution {
  public:
  bool isIdealPermutation(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
      //
      if (abs(A[i] - i) > 1) return false;
    }
    return true;
  }
  /* 
  // Exceed time.
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
};
