/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (54.62%)
 * Likes:    1267
 * Dislikes: 0
 * Total Accepted:    245K
 * Total Submissions: 446.5K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */

#include <limits>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // Hint: 可以使用优先级队列加速选择最小值节点，但是会增加空间复杂度。
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // 已经合并列表的头指针和尾指针
    ListNode* head = new ListNode(0, nullptr);
    ListNode* tail = head;

    while (true) {
      // 在所有未合并的k个列表中，选择值最小的节点
      int min_tmp = numeric_limits<int>::max();
      vector<ListNode*>::size_type min_ind = -1;
      for (vector<ListNode*>::size_type i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr && lists[i]->val < min_tmp) {
          min_tmp = lists[i]->val;
          min_ind = i;
        }
      }
      // 全部链表已经合并
      if (min_ind == -1) {
        ListNode* res = head->next;
        delete head;  // 清除内存
        head = nullptr;
        return res;
      }
      // 尾插法插入已经合并列表
      tail->next = lists[min_ind];
      tail = tail->next;
      lists[min_ind] = lists[min_ind]->next;
    }
  }

  /* 使用分治方法进行合并 */
  // 合并两个链表的方法
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
      if (aPtr->val < bPtr->val) {
        tail->next = aPtr;
        aPtr = aPtr->next;
      } else {
        tail->next = bPtr;
        bPtr = bPtr->next;
      }
      tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
  }
  // 合并左右两个链表
  ListNode* mergeLRLists(vector<ListNode*>& lists, int l, int r) {
    if (l == r) {
      return lists[l];
    }
    if (l > r) {
      return nullptr;
    }
    int mid = l + ((r - l) >> 1);
    return mergeTwoLists(mergeLRLists(lists, l, mid),
                         mergeLRLists(lists, mid + 1, r));
  }
  // 使用分治方法进行合并
  ListNode* mergeKLists2(vector<ListNode*>& lists) {
    return mergeLRLists(lists, 0, lists.size() - 1);
  }
};
// @lc code=end
