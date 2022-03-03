/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    // 归并排序解法
    int cnt = 0;
    mergeSort(nums, 0, nums.size() - 1, cnt);
    return cnt;
  }

  void mergeSort(vector<int>& nums, int left, int right, int& cnt) {
    if (left >= right) return;

    // 递归
    int mid = left + ((right - left) >> 1);
    mergeSort(nums, left, mid, cnt);
    mergeSort(nums, mid + 1, right, cnt);

    // 合并，Tips: 从后向前合并
    vector<int> tmp(right - left + 1);
    int i = mid, j = right, k = tmp.size()-1;
    while (i >= left && j >= mid+1) {
      if (nums[i] > nums[j]) {
        tmp[k] = nums[i];
        // 位置j及前面的数都是逆序
        cnt += (j - mid);
        i--;
      } else {
        tmp[k] = nums[j];
        j--;
      }
      k--;
    }
    while (i >= left) {
      tmp[k] = nums[i];
      i--;
      k--;
    }
    while (j >= mid+1) {
      tmp[k] = nums[j];
      j--;
      k--;
    }

    for (int i = left; i <= right; i++) {
        nums[i] = tmp[i-left];
    }
  }
};

int main() {
    Solution s;
    vector<int> in{7,5,6,4};
    int res = s.reversePairs(in);
}