/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right
。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。 示例 1:
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]

示例 2：
输入：head = [5], left = 1, right = 1
输出：[5]
*/

#include <bits/stdc++.h>

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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    // 注意：这里的单链表没有头节点，head直接指向第一个节点。
    if (left == right) {
      return head;
    }
    ListNode *p = new ListNode();
    // 获取left前一位置的指针
    if (left == 1) {
      p->next = head;
    } else {
      p = head;
      for (int i = 1; i < left - 1; i++) {
        p = p->next;
      }
    }
    // 保存尾节点
    ListNode *q = p->next, *tail = p->next;
    p->next = NULL;
    // 头插入方法
    for (int i = left; i <= right; i++) {
      ListNode *tmp = q;
      q = q->next;
      tmp->next = p->next;
      p->next = tmp;
    }
    // 连接right后的链表
    tail->next = q;
    return left == 1 ? p->next : head;
  }
};