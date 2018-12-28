/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (44.04%)
 * Total Accepted:    33.1K
 * Total Submissions: 75K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<stack>

class Solution {
public:
    bool backspaceCompare(string S, string T) {
			stack<int> ss;
			stack<int> st;

			for (int i = 0; i < S.size(); i++) {
				if (S[i] != '#') {
						ss.push(S[i]);
				} else if ((S[i] == '#')&&(!ss.empty())) {
						ss.pop();
				}
			}
        
			for (int i = 0; i < T.size(); i++) {
				if (T[i] != '#') {
						st.push(T[i]);
				} else if ((T[i] == '#')&&(!st.empty())) {
						st.pop();
				}
			}
			
			return ss==st;
		
    }
};



