/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (69.95%)
 * Likes:    713
 * Dislikes: 0
 * Total Accepted:    106.9K
 * Total Submissions: 149.9K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Trie（发音类似 "try"）或者说 前缀树
 * 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
 *
 * 请你实现 Trie 类：
 *
 *
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回
 true（即，在检索之前已经插入）；否则，返回
 * false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为
 prefix ，返回 true
 * ；否则，返回 false 。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 输出
 * [null, null, true, false, true, null, true]
 *
 * 解释
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * word 和 prefix 仅由小写英文字母组成
 * insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
 *
 *
 */

// @lc code=start
#include <limits>
#include <string>
#include <vector>
using namespace std;

const int kmax_nodes = 40000, kcharsets = 26;

// 注意终节点不一定是叶子节点，只要被标记为终点的都是终节点
class Trie {
 private:
  // 树节点，nodes[i][j]=x表示节点i的第j个字符（对应26个英文字母）是第x个节点
  int nodes_[kmax_nodes][kcharsets] = {0};
  bool is_end_[kmax_nodes] = {false};  // 是否是终节点
  int k_ = 1;                          // 当前树的节点个数

 public:
  /** Initialize your data structure here. */
  Trie() {};

  /** Inserts a word into the trie. */
  void insert(string word) {
    int pos = 0;
    for (const auto& w : word) {
      if (nodes_[pos][w - 'a'] == 0) {
        nodes_[pos][w - 'a'] = k_;
        k_++;
      }
      // w字符所在位置
      pos = nodes_[pos][w - 'a'];
    }
    is_end_[pos] = true;  // 记录终点
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    int pos = 0;
    for (const auto& w : word) {
      if (nodes_[pos][w - 'a'] == 0) {
        return false;
      } else {
        pos = nodes_[pos][w - 'a'];
      }
    }
    return is_end_[pos] ? true : false;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    int pos = 0;
    for (const auto& w : prefix) {
      if (nodes_[pos][w - 'a'] == 0) {
        return false;
      } else {
        pos = nodes_[pos][w - 'a'];
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

// int main() { return 0; }
