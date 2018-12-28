#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  // one-paid allocate temp memory
 public:
  void merge(vector<int>& nums, int left, int mid, int right,
             vector<int>& temp) {
    // define pointers
    int leftPtr = 0;
    int rightPtr = mid + 1;
    // comparasion
    int t = 0;
    while (leftPtr <= mid && rightPtr <= right) {
      if (nums[leftPtr] < nums[rightPtr]) {
        temp[t++] = nums[leftPtr++];
      } else if (nums[leftPtr] > nums[rightPtr]) {
        temp[t++] = nums[rightPtr++];
      }
    }
    // merge data to temp
    while (leftPtr <= mid) {
      temp[t++] = nums[leftPtr++];
    }
    while (rightPtr <= right) {
      temp[t++] = nums[rightPtr++];
    }

    t = 0;
    // merge data to original array
    while (left <= right) {
      nums[left++] = temp[t++];
    }
  }

 public:
  void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
    if (left < right) {
      int mid = (left + right) >> 1;
      mergeSort(nums, left, mid, temp);       // merge sort left
      mergeSort(nums, mid + 1, right, temp);  // merge sort right
      merge(nums, left, mid, right, temp);    // merge left and right
    }
  }
};

int main(void) {
  Solution test;
  int a[8] = {2,4,5,1,9,6,7,0};
	vector<int> nums(a, a+8);
  // Allocate temp arrar
  vector<int> temp(nums.size(), 0);
  test.mergeSort(nums, 0, 7, temp);

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << endl;
  }
}
