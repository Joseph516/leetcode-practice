/*
https://bytedance.feishu.cn/file/boxcn0VhRhQ1TfRPJMdv2L6wWjd
*/

package main

import (
	"bufio"
	"fmt"
	"sort"
	"strings"
)

// C++没有内置的Split函数
// C++map处理不太方便
func main() {
	var n, m, k int

	for {
		fmt.Scan(&n, &m, &k)
		prefixMap := make(map[string]map[string]int)
		reader := bufio.Reader{}
		for i := 0; i < n; i++ {
			line, _ := reader.ReadString('\n')
			strArr := strings.Split(strings.TrimSpace(line), " ")
			for idx := 0; idx < len(strArr)-1; idx++ {
				prefix := strings.Join(strArr[:idx+1], " ")
				if _, ok := prefixMap[prefix]; !ok {
					prefixMap[prefix] = make(map[string]int)
				}
				nextWord := strArr[idx+1]
				if _, ok2 := prefixMap[prefix][nextWord]; !ok2 {
					prefixMap[prefix][nextWord] = 1
				} else {
					prefixMap[prefix][nextWord] += 1
				}
			}
		}

		// query
		for i := 0; i < m; i++ {
			line, _ := reader.ReadString('\n')
			queryRes := prefixMap[line]
			// sort
			keys := make([]string, 0, len(queryRes))
			for key := range queryRes {
				keys = append(keys, key)
			}
			sort.Slice(keys, func(i, j int) bool {
				return queryRes[keys[i]] > queryRes[keys[j]]
			})
			// output
			out := []string{}
			for j := 0; j < k && j < len(keys); j++ {
				out = append(out, keys[j])
			}
			fmt.Println(strings.Join(out, " "))
		}
	}
}
