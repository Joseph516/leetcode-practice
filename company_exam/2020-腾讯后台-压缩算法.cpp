/*
时间限制：C/C++ 1秒，其他语言2秒

空间限制：C/C++ 256M，其他语言512M

小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？




输入例子1:
"HG[3|B[2|CA]]F"

输出例子1:
"HGBCACABCACABCACAF"

例子说明1:
HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
*/

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param str string字符串
   * @return string字符串
   */
  string compress(string str) {
    // write code here
    stack<char> st;
    int i = 0;
    while (i < str.size()) {
      if (str[i] != ']') {
        st.push(str[i]);
      } else {
        // 重复字符
        string tmp = "";
        while (st.top() != '|') {
          tmp += st.top();
          st.pop();
        }
        st.pop();  // 去掉'|'
        // 重复次数
        string cnt_str;
        while (st.top() != '[') {
          cnt_str += st.top();
          st.pop();
        }
        st.pop();  // 去掉'['
        reverse(cnt_str.begin(), cnt_str.end());
        int cnt = stoi(cnt_str);
        // 重新入栈
        for (int j = 0; j < cnt; j++) {
          for (int k = tmp.size() - 1; k >= 0; k--) {
            st.push(tmp[k]);
          }
        }
      }
      i++;
    }
    // 全部出栈再reverse
    string ans;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};