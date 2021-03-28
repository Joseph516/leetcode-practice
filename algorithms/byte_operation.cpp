#include <iostream>
#include <vector>

using namespace std;

class ByteOperation {
 public:
  /**
   * Description: 检测连续不间断数字中出现重复偶数次。
   * params: nums- 被测数字集合
   * return：重复数字。
   */
  int findRepeatNum(vector<int> nums) {
    int len = nums.size();
    int temp = nums[0];
    int max = nums[0];

    // 将出现偶数次重复数字去除
    for (int i = 1; i < len; i++) {
      temp ^= nums[i];
      max = (nums[i] > max) ? nums[i] : max;
    }

    // 依次与1-max异或，相同的数去除，剩下的为前面去除的重复数字。
    for (int i = 1; i <= max; i++) {
      temp ^= i;
    }

    return temp;
  }
};

int main(void) {
  vector<int> nums = {7, 2, 3, 3, 4, 5, 6, 1};
  ByteOperation test;
  cout << test.findRepeatNum(nums) << endl;
}
