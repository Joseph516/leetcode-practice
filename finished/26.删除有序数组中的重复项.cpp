/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (53.03%)
 * Likes:    1999
 * Dislikes: 0
 * Total Accepted:    626.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,2]'
 *
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次
 * ，返回删除后数组的新长度。
 *
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1)
 * 额外空间的条件下完成。
 *
 *
 *
 * 说明:
 *
 * 为什么返回数值是整数，但输出的答案是数组呢?
 *
 * 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 *
 * 你可以想象内部操作如下:
 *
 *
 * // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 * int len = removeDuplicates(nums);
 *
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,2]
 * 输出：2, nums = [1,2]
 * 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2
 * 。不需要考虑数组中超出新长度后面的元素。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,0,1,1,1,2,2,3,3,4]
 * 输出：5, nums = [0,1,2,3,4]
 * 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2,
 * 3, 4 。不需要考虑数组中超出新长度后面的元素。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^4
 * nums 已按升序排列
 *
 *
 *
 *
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // 针对有序数组的方法
  int removeDuplicates(vector<int>& nums) {
    vector<int>::size_type indx = -1;  // 修改后数组下标
    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
      if (indx == -1 || nums[i] != nums[indx]) {
        indx++;
        nums[indx] = nums[i];
      }
    }
    return indx + 1;
  }

  // 该方法适用于无序，但是在本题中不够高效
  int removeDuplicates2(vector<int>& nums) {
    vector<int>::size_type indx = 0;  // 修改后数组下标
    unordered_set<int> duplicates;

    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
      auto search = duplicates.find(nums[i]);
      if (search == duplicates.end()) {
        // 没找到
        nums[indx++] = nums[i];
        duplicates.insert(nums[i]);
      }
    }
    return indx;
  }
};
// @lc code=end
