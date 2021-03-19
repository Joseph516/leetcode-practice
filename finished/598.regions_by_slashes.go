package main

import "fmt"

/*
在由 1 x 1 方格组成的 N x N 网格grid 中，每个 1 x 1方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\"表示。）。

返回区域的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
|------------|
|    \ 0/    |
|     \/     |
| 3   /\  1  |
|    / 2\    |
|------------|
*/
type unionFind struct {
	parent, size []int
	setCount     int // 当前连通分量数目
}

func newUnionFind(n int) *unionFind {
	parent := make([]int, n)
	size := make([]int, n)
	for i := range parent {
		parent[i] = i // 自己作为自己的根节点，单独成为连通图
		size[i] = 1   // 孩子数目
	}
	return &unionFind{parent, size, n}
}

// find 找x的根节点
func (uf *unionFind) find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.find(uf.parent[x])
	}
	return uf.parent[x]
}

// union 将x，y的根节点联合，size大的节点成为新的根节点
func (uf *unionFind) union(x, y int) {
	fx, fy := uf.find(x), uf.find(y)
	if fx == fy {
		return
	}
	if uf.size[fx] < uf.size[fy] {
		fx, fy = fy, fx
	}
	uf.size[fx] += uf.size[fy]
	uf.parent[fy] = fx
	uf.setCount--
}

// regionsBySlashes 获取隔离区域。
func regionsBySlashes(grid []string) int {
	n := len(grid)
	// 将每块正方形划分为4块，每小块单独成为一个作为一个连通图，根据/和\分别
	// 融合最终连通图，最终连通图的个数就是最终的隔离区域。
	uf := newUnionFind(4 * n * n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			idx := i*n + j // 每块正方形的编号
			// 无论是/还是\，都需要向下合并当前块2和下块0，向右合并当前块1和右块3
			if i < n-1 {
				bottom := idx + n
				uf.union(idx*4+2, bottom*4)
			}
			if j < n-1 {
				right := idx + 1
				uf.union(idx*4+1, right*4+3)
			}
			if grid[i][j] == '/' {
				// 合并当前块的0，3和1，2
				uf.union(idx*4, idx*4+3)
				uf.union(idx*4+1, idx*4+2)
			} else if grid[i][j] == '\\' {
				// 合并当前块的0，1和2，3
				uf.union(idx*4, idx*4+1)
				uf.union(idx*4+2, idx*4+3)
			} else {
				// 空格情况，合并当前块0，1，2，3
				uf.union(idx*4, idx*4+1)
				uf.union(idx*4+1, idx*4+2)
				uf.union(idx*4+2, idx*4+3)
			}
		}
	}
	return uf.setCount
}

func main() {
	grid := []string{" /", "/ "}
	fmt.Println(regionsBySlashes(grid))
}
