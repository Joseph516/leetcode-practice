/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个
next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：

输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：

输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 
提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。
 

注意：本题与主站 138
题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  // 空间换时间
  // 更优的方法：参考《剑指offer》，将新的节点连在旧节点后面，复杂度O(n)，不需要辅助空间
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // 保存节点序号与节点指针之间的位置关系
    // 优化方式：可以建立map<Node*, Node*>，从而去除i
    map<Node*, int> pos;
    map<int, Node*> pos_new;
    int i = 0;

    // 遍历next
    Node *head_new, *cur_new;
    Node* cur = head;
    while (cur) {
      Node* tmp = new Node(cur->val);
      if (i == 0) {
        head_new = tmp;
        cur_new = head_new;
      } else {
        cur_new->next = tmp;
        cur_new = cur_new->next;
      }

      pos.insert(pair<Node*, int>(cur, i));
      pos_new.insert(pair<int, Node*>(i, tmp));
      i++;
      cur = cur->next;
    }
    cur_new->next = nullptr;
    pos.insert(pair<Node*, int>(nullptr, i));
    pos_new.insert(pair<int, Node*>(i, nullptr));

    // 遍历rondom
    cur = head;
    cur_new = head_new;
    while (cur) {
      int idx = pos[cur->random];
      cur_new->random = pos_new[idx];
      cur = cur->next;
      cur_new = cur_new->next;
    }
    return head_new;
  }
};