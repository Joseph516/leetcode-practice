#!/usr/bin/env python
# coding=UTF-8
'''
@Description: page rank 算法，算法根据<程序员的算法课>改写
@Author: 
@Verdion: 1.0
'''
import numpy as np

# 1. 初始化PR， 网络结点，邻接矩阵和随机跳转概率
alpha = 0.9
N = 5
# 邻阶矩阵
adj = np.full([5, 5], [[0, 0, 1, 0, 0], [1, 0, 1, 0, 0], [1, 0, 0, 0, 0], [
              0, 0, 0, 0, 0], [0, 1, 0, 0, 0]], dtype=float)

# 归一化邻阶矩阵
# row_sums = [sum(adj[i]) for i in range(len(adj))]
row_sums = adj.sum(axis=1)      # 对每一行求和
row_sums[row_sums == 0] = 0.1   # 防止由于分母出现 0 而导致的 Nan
adj = adj / row_sums[:, np.newaxis]  # 除以每行之和的归一化

# 初始化随机跳转的概率计算矩阵
jump = np.full([2, 1], [[alpha], [1-alpha]], dtype=float)

# 初始的 PageRank 值，通常是设置所有值为 1.0
pr = np.full([1, N], 1, dtype=float)  # [1,1,1,1,1]

# 2. 计算PR
# PageRank 算法本身是采样迭代方式进行的，当最终的取值趋于稳定后结束。
epochs = 20
pr_old = pr.copy()
for i in range(0, epochs):

    # 进行点乘，计算Σ(PR(pj)/L(pj))
    pr = np.dot(pr, adj)

    # 转置保存Σ(PR(pj)/L(pj)) 结果的矩阵，并增加长度为 N 的列向量，其中每个元素的值为 1/N，便于下一步的点乘。
    pr_jump = np.full([N, 2], [[0, 1/N]])
    pr_jump[:, 0] = pr

    # 进行点乘，计算α(Σ(PR(pj)/L(pj))) + (1-α)/N)
    pr = np.dot(pr_jump, jump)

    # 归一化 PageRank 得分
    pr = pr.transpose()
    pr = pr / pr.sum()

    # 根据平均偏差判断是否结束
    diff = np.linalg.norm(pr-pr_old) / np.sqrt(N)
    if (diff < 1e-10):
        break
    pr_old = pr.copy()

    print("round", i + 1, pr)
