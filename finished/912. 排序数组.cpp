/*
给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
 public:
  int partition(vector<int>& nums, int low, int high) {
    // 随机挑选数防止快排出现最差性能
    int indx = rand() % (high - low + 1) + low;
    swap(nums[low], nums[indx]);
    int p = nums[low];
    while (low < high) {
      while (low < high && nums[high] >= p) {
        --high;
      }
      nums[low] = nums[high];
      while (low < high && nums[low] <= p) {
        ++low;
      }
      nums[high] = nums[low];
    }
    nums[low] = p;
    return low;
  }

  void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
      int pivot = partition(nums, low, high);
      quickSort(nums, low, pivot - 1);
      quickSort(nums, pivot + 1, high);
    }
  }

  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};