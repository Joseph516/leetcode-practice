/*
输入整数数组 arr ，找出其中最小的 k
个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0] 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    vector<int> ans;
    for (size_t i = 0; i < k; i++) {
      ans.push_back(arr[i]);
    }
    return ans;
  }

  // 其他思路1：找到第k大的数，然后遍历获得值
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> ans;
    if (k <= 0) return ans;

    int k_elem = getKElem(arr, k, 0, arr.size() - 1);

    int cnt = 0; // 题目是说第k个数，而不是第k小的数
    for (int & v: arr) {
        if (v <= k_elem && cnt != k) {
            ans.push_back(v);
            cnt++;
        }
    }
    return ans;
  }

  int getKElem(vector<int>& arr, int k, int low, int high) {
    int pos = partition(arr, low, high);
    if (pos == k - 1) {
      return arr[pos];
    } else if (pos < k - 1) {
      return getKElem(arr, k, pos + 1, high);
    } else {
      return getKElem(arr, k, low, pos - 1);
    }
  }

  int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    while (low < high) {
      while (low < high && arr[high] >= pivot) --high;
      arr[low] = arr[high];
      while (low < high && arr[low] <= pivot) ++low;
      arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
  }

  // 其他思路2:用最大堆的方法
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    priority_queue<int> pq;
    for (int& v : arr) {
      if (pq.size() < k) {
        pq.push(v);
      } else {
        if (!pq.empty() && v < pq.top()) {
          pq.pop();
          pq.push(v);
        }
      }
    }

    vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top());
      pq.pop();
    }
    return ans;
  }
};