#include <iostream>
#include <vector>
using namespace std;

void Flag_Arrange(vector<int>& nums) {
  int n = nums.size();
  int i = 0, j = 0, k = n - 1;
  while (j <= k) {
    switch (nums[j]) {
      case 0:
        swap(nums[j], nums[i]);
        ++i;
        ++j;
        break;
      case 1:
        ++j;
        break;
      case 2:
        swap(nums[j], nums[k]);
        --k;
        break;
    }
  }
}

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Flag_Arrange(nums);
  for (auto& num : nums) {
    cout << num << " ";
  }
}