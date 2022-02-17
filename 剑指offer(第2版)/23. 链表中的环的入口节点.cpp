/*
如果链表中存在环，如何找到环的入口节点

https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=265&tqId=39225&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D13&difficulty=undefined&judgeStatus=undefined&tags=&title=

*/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  // 先计算环中的节点，再设定前后指针获得
  ListNode* EntryNodeOfLoop(ListNode* head) {
    ListNode* mn = meetingNode(head);
    if (!mn) {
      return nullptr;
    }

    // 计算环节点数目
    ListNode* origin = mn;
    int cnt = 1;
    while (mn->next != origin) {
      mn = mn->next;
      cnt++;
    }

    // 双指针
    ListNode *left = head, *right = head;
    while (cnt > 1) {
      right = right->next;
      cnt--;
    }
    while (right->next != left) {
      left = left->next;
      right = right->next;
    }
    return left;
  }

  // 判断是否有环，若有环返回环中的某一个节点
  // 通过快慢指针实现
  ListNode* meetingNode(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    ListNode *ps = head, *pf = head->next;
    while (ps && pf) {
      if (pf == ps) {
        return pf;
      }
      ps = ps->next;
      pf = pf->next;
      if (pf) {
        pf = pf->next;
      }
    }
    return nullptr;
  }
};