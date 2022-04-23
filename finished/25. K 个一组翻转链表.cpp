/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：


输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
示例 3：

输入：head = [1,2,3,4,5], k = 1
输出：[1,2,3,4,5]
示例 4：

输入：head = [1], k = 1
输出：[1]
提示：

列表中节点的数量在范围 sz 内
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) return head;
    ListNode* pre_head = new (ListNode);
    ListNode *cur = head, *prev = pre_head, *next;
    ListNode* tail;
    // 获取链表长度
    int len = 0;
    while (cur) {
      len++;
      cur = cur->next;
    }
    cur = head;
    int cnt_k = 0;                   // k个节点的内部序号
    int cnt = 0, cnt_max = len / k;  // 最多划分段数目
    
    while (cur && cnt < cnt_max) {
      // 保存每段的尾部
      if (cnt_k == 0) {
        tail = cur;
      }
      // 头插法
      next = cur->next;
      cur->next = prev->next;
      prev->next = cur;
      cnt_k++;
      cur = next;
      // 结束每一段的翻转
      if (cnt_k == k) {
        cnt_k = 0;
        prev = tail;
        cnt++;
      }
    }
    prev->next = cur;  // 不足k个不翻转，bullshit

    head = pre_head->next;
    delete pre_head;
    return head;
  }
};