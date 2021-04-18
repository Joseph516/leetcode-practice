package main

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
	for pn < n-m+1 {
		for pn < n-m+1 && haystack[pn] != needle[0] {
			pn++
		}
		currLen := 0
		for pn < n && pm < m && haystack[pn] == needle[pm] {
			pm++
			pn++
			currLen++
		}
		if currLen == m {
			return pn - pm
		} else {
			pn = pn - currLen + 1
			pm = 0
		}
	}
	return -1
}
