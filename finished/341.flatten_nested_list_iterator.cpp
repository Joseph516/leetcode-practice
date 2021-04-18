/*
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是:
[1,1,2,1,1]。 示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是:
[1,4,6]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-nested-list-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer. The result is undefined if this NestedInteger holds a
  // nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list. The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

#include <bits/stdc++.h>
using namespace std;

// 想复杂了！
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    _integers = nestedList;
    _iter = _integers.begin();
  }

  int next() {
    // 如果当前位置是整数，不是列表
    if ((*_iter).isInteger()) {
      _iter++;
      return (*_iter).getInteger();
    }

    // 当前位置是列表
    vector<NestedInteger> nested_list = (*_iter).getList();
    // 保存list第一个位置
    auto iter_tmp = nested_list.begin();
    NestedInteger nested_integer_first = *iter_tmp;

    // 删除list第一个位置
    iter_tmp++;
    if (iter_tmp != nested_list.end()) {
      vector<NestedInteger> new_list;
      new_list.assign(iter_tmp, nested_list.end());
      NestedIterator j(new_list);
      *_iter = *(j._iter);  // 无法将_iter对应的值赋值为vector形式，需要重载=运算符。
    } else {
      _iter++;
    }

    // 对list第一个位置递归求解
    vector<NestedInteger> ni{nested_integer_first};
    NestedIterator i(ni);
    return i.next();
  }

  bool hasNext() { return _iter != _integers.end(); }

 private:
  vector<NestedInteger> _integers;
  vector<NestedInteger>::iterator _iter;
};


// 思路：把所有数字全部提取出来，然后在输出。
class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    dfs(nestedList);
    _iter = _integers.begin();
  }

  void dfs(const vector<NestedInteger> &nestedList) {
    for (auto &nest : nestedList) {
      if (nest.isInteger()) {
        _integers.push_back(nest.getInteger());
      } else {
        dfs(nest.getList());
      }
    }
  }

  int next() { return *_iter++; }

  bool hasNext() { return _iter != _integers.end(); }

 private:
  vector<int> _integers;
  vector<int>::iterator _iter;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
