/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：

0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
      ListNode *prev_head = new(ListNode);
      prev_head->next = nullptr;

      ListNode *cur = head, *tmp;
      // 头插入法
      while(cur) {
          tmp = cur->next;
          cur->next = prev_head->next;
          prev_head->next = cur;
          cur = tmp;
      }
      head = prev_head->next;
      delete prev_head;
      return head;
  }
};