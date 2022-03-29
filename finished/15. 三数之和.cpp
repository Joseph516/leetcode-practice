/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                // k需要放在外面，因为是有序的，所以k不需要每次都从最右侧开始遍历
                size_t k = nums.size()-1;
                for (size_t j = i+1; j < nums.size(); j++) {
                    if (j == i+1 || nums[j] != nums[j-1]) {
                        // 需要保证k在j的右边
                        while(j < k && nums[i] + nums[j] + nums[k] > 0) {
                            k--;
                        }
                        if (j == k) {
                            break;
                        }
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        }
        return ans;   
    }
};