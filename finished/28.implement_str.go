package main

/*
实现strStr()函数。

给定一个haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回-1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

func strStr(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	for i := 0; i < n-m+1; i++ {
		if haystack[i:i+m] == needle {
			return i
		}
	}
	return -1
}

func strStr1(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	if m == 0 {
		return 0
	}
	pn, pm := 0, 0
	for ; pn < n-m+1; {
    for ; pn < n-m+1 && haystack[pn] != needle[0]; {
    	pn++
		}
		currLen := 0
		for ; pn < n && pm < m && haystack[pn] == needle[pm]; {
			pm++
			pn++
			currLen++
		}
		if currLen == m{
			return pn-pm
		} else {
			pn = pn-currLen+1
			pm = 0
		}
	}
	return -1
}
