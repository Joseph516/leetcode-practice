/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (50.44%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    113.9K
 * Total Submissions: 220.3K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 存在一个按升序排列的链表，给你这个链表的头节点 head
 * ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
 *
 * 返回同样按升序排列的结果链表。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,1,1,2,3]
 * 输出：[2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围 [0, 300] 内
 * -100
 * 题目数据保证链表已经按升序排列
 *
 *
 */

// @lc code=start

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // head指向的就是第一个node
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // 在头节点之前建立辅助节点指向head
    ListNode* pre_head = new ListNode(0, head);
    ListNode *curr_node = head, *next_node = head->next, *tail = pre_head;
    while (next_node) {
      if (curr_node->val != next_node->val) {
        // 尾插法
        tail->next = curr_node;
        tail = curr_node;
      } else {
        // 找到下一个与当前节点值不相等的节点
        while (next_node && curr_node->val == next_node->val) {
          next_node = next_node->next;
        }
      }
      curr_node = next_node;
      if (next_node) {
        next_node = next_node->next;
      }
    }
    if (curr_node != nullptr) {
      tail->next = curr_node;
      tail = curr_node;
    }
    tail->next = nullptr;
    return pre_head->next;
  }

  // 优化版本，这里curr_node同时承担了头节点和尾节点的工作
  // head指向的就是第一个node
  ListNode* deleteDuplicates1(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // 在头节点之前建立辅助节点指向head
    ListNode* pre_head = new ListNode(0, head);
    ListNode* curr_node = pre_head;
    while (curr_node->next && curr_node->next->next) {
      if (curr_node->next->val == curr_node->next->next->val) {
        int x = curr_node->next->val;
        // 找到下一个与当前节点值不相等的节点
        while (curr_node->next && curr_node->next->val == x) {
          curr_node->next = curr_node->next->next;
        }
      } else {
        curr_node = curr_node->next;
      }
    }
    return pre_head->next;
  }
};
// @lc code=end

int main() {
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(1);
  //   ListNode *c = new ListNode(1);
  //   ListNode *d = new ListNode(2);
  //   ListNode *e = new ListNode(3);
  a->next = b;
  //   b->next = c;
  //   c->next = d;
  //   d->next = e;

  Solution test;
  test.deleteDuplicates(a);
}