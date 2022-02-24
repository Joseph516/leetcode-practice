/**
 * 查找升序数组中满足元素的下标，当存在多个满足条件的元素时候，返回最有一个元素的下标，否则返回-1。
 */

#include <iostream>
#include <vector>

using namespace std;

int BSMAX(const std::vector<int>& data, int target) {
  int left = 0;
  int right = data.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (data[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  if (right >= 0 && data[right] == target) {
    return right;
  }
  return -1;
}

int main() {
  std::vector<int> data{1, 5, 5, 7, 8, 9};
  std::cout << BSMAX(data, 5) << std::endl;
  return 0;
}