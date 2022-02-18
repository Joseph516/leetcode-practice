# Leetcode Note

主要记录leetcode练习过程中需要的题目，数学知识，以及对应的思考与笔记。
## Quick Start

- [finished](finished/)：完成试题代码及部分note文档。
  
- [unfinished](unfinished/)：暂未完成或暂时未理解的试题。

- [剑指offer(第2版)-Go/C++语言实现](剑指offer(第2版))

- [algorithms](algorithms/README.md): 学习笔记及个人代码实现

  - 基础数学知识及数据结构，包括递归与归纳，动态规划，树和图的搜索等。

  - 概率与统计，包括马尔科夫模型，nlp等

  - 线性代数：矩阵，线性回归和pca降维等。

## C++常见库

[C++ Data Structures and Algorithms Cheat Sheet](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md#c-data-structures-and-algorithms-cheat-sheet)

### Vector `std::vector`

```cpp
#include <vector>
std::vector<int> v;

//---------------------------------
// General Operations
//---------------------------------

// Size
unsigned int size = v.size();

// Insert head, index, tail
v.insert(v.begin(), value);             // head
v.insert(v.begin() + index, value);     // index
v.push_back(value);                     // tail

// Access head, index, tail
int head = v.front();       // head
head = v[0];                // or using array style indexing

int value = v.at(index);    // index
value = v[index];           // or using array style indexing

int tail = v.back();        // tail
tail = v[v.size() - 1];     // or using array style indexing

// Iterate
for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
v.erase(v.begin());             // head
v.erase(v.begin() + index);     // index
v.pop_back();                   // tail

// Clear
v.clear();
```

### Deque `std::deque`

双端队列，与vector类似，但`push_front`和`pop_front`效率更高。

```cpp
#include <deque>
std::deque<int> d;

//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
d.push_front(value);                    // head
d.insert(d.begin() + index, value);     // index
d.push_back(value);                     // tail

// Access head, index, tail
int head = d.front();       // head
int value = d.at(index);    // index
int tail = d.back();        // tail

// Size
unsigned int size = d.size();

// Iterate
for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
d.pop_front();                  // head
d.erase(d.begin() + index);     // index
d.pop_back();                   // tail

// Clear
d.clear();
```

### List `std::list` and `std::forward_list`

list为双向链表，forward_list为单向链表，排序高效。

```cpp
#include <list>
#include <forward_list>
std::list<int> l;

//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
l.push_front(value);                    // head
l.insert(l.begin() + index, value);     // index
l.push_back(value);                     // tail

// Access head, index, tail
int head = l.front();                                           // head
int value = std::next(l.begin(), index);		        // index
int tail = l.back();                                            // tail

// Size
unsigned int size = l.size();

// Iterate
for(std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
l.pop_front();                  // head
l.erase(l.begin() + index);     // index
l.pop_back();                   // tail

// Clear
l.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Splice: Transfer elements from list to list
//	splice(iterator pos, list &x)
//  	splice(iterator pos, list &x, iterator i)
//  	splice(iterator pos, list &x, iterator first, iterator last)
l.splice(l.begin() + index, list2);

// Remove: Remove an element by value
l.remove(value);

// Unique: Remove duplicates
l.unique();

// Merge: Merge two sorted lists
l.merge(list2);

// Sort: Sort the list
l.sort();

// Reverse: Reverse the list order
l.reverse();
```

### Map `std::map` and `std::unordered_map`

Maps通常由二叉搜索树（二叉排序树）实现。

```cpp
#include <map>
#include <unordered_map>
std::map<std::string, std::string> m;

//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert(std::pair<std::string, std::string>("key", "value"));

// Access by key
std::string value = m.at("key");

// Size
unsigned int size = m.size();

// Iterate
for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove by key
m.erase("key");

// Clear
m.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool exists = (m.find("key") != m.end());

// Count the number of elements with a certain key
unsigned int count = m.count("key");
```

### Set `std::set`

集合，内部元素不重复，用于元素去重，通常由二叉树实现。

```cpp
#include <set>
std::set<int> s;

//---------------------------------
// General Operations
//---------------------------------

// Insert
s.insert(20);

// Size
unsigned int size = s.size();

// Iterate
for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove
s.erase(20);

// Clear
s.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists
bool exists = (s.find(20) != s.end());

// Count the number of elements with a certain value
unsigned int count = s.count(20);
```

### Stack `std::stack`

```cpp
#include <stack>
std::stack<int> s;

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Push
s.push(20);

// Size
unsigned int size = s.size();

// Pop
s.pop();

// Top
int top = s.top();
```

### Queue `std::queue`

```cpp
#include <queue>
std::queue<int> q;

//---------------------------------
// General Operations
//---------------------------------

// Insert
q.push(value);

// Access head, tail
int head = q.front();       // head
int tail = q.back();        // tail

// Size
unsigned int size = q.size();

// Remove
q.pop();
```

### Priority Queue `std::priority_queue`

优先级队列，可以由vector实现。

```cpp
#include<queue>
std::priority_queue<int> p;

//---------------------------------
// General Operations
//---------------------------------

// Insert
p.push(value);

// Access
int top = p.top();  // 'Top' element

// Size
unsigned int size = p.size();

// Remove
p.pop();
```

### Heap `std::priority_queue`

堆。大顶堆和小顶堆，优先级队列的应用之一。

### String `std::string`

```cpp
// --- transform char using #include <string.h>
toupper(s[i], locale());
tolower(s[i], locale());

// --- initialize a sequence using #include <algorithm>
fill_n(nums, sizeof(nums), true);

// --- transform string using #include <algorithm>
transform(word.begin(), word.end(), word.begin(), ::tolower);   
transform(word.begin(), word.end(), word.begin(), ::toupper);

// --- use ignore after using cin
cin.ignore();   // Extracts chars from the input sequence and discards them.
getline(cin, line);     

// --- use #include <sstream>
getline(cin, line);
stringstream stream(line);
stream >> word;


// --- find using #include <string>
// 2nd param: Position of the 1st char in the string to be searched.
// 3rd param: Length of sequence of chars to match.

string haystack = "There are two needles in this haystack with needles.";
string needle = "needle";

size_t found = haystack.find(needle);
if (found != ::npos) cout << "first needle at: " << found << '\n';

found = haystack.find("needles are small", found+1, 6);
if (found != ::npos) cout << "second needle at: " << found << '\n';


// --- replace using #include <string>
string str1 = "donkey ate the milk";
string str2 = "cat";
str1.replace(str1.begin(), str1.begin()+6, str2); // (from, to, replace)

string str1 = "donkey ate the milk";
string str2 = "012cat";
str1.replace(str1.begin(), str1.begin()+6, str2.begin()+3, str2.end()); // (from, to, from, to)

str.replace(9,5,"hello");       // (from, len, replace) - string
str.replace(9,6,"hello",7,6);   // (from, len, replace, subFrom, subLen) - substring
str.replace(22,1,3,'!');        // (from, len, n, char c)   - fill

// replace the first needle:
str.replace(str.find(needle), needle.length(), "replace");
```

## 参考

### Cheat Sheets

1. cpp: https://hackingcpp.com/cpp/cheat_sheets.html
2. cpp: https://github.com/gibsjose/cpp-cheat-sheet
3. https://quickref.me/
4. [20 Most Useful C and C++ Cheat Sheets | 2022 Edition](https://www.rankred.com/useful-c-cheat-sheets/)

### others

- [leetcode-cli]( https://github.com/skygragon/leetcode-cli) 
- [程序员的数学课](https://time.geekbang.org/column/143)

