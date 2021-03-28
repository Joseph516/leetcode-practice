#!/usr/bin/env python
# coding=UTF-8
'''
@Description: Simple example of pca.
@Author: Joe
@Verdion: 1.0
'''
import numpy as np

# 每一列代表一个特征
x = np.array([[1,3,-7],[2,5,-14],[-3,-7,2]])

# 1. normalization
x_mean = np.mean(x, axis=0)
x_std = np.std(x, axis=0)

x = x - x_mean
x_norm = x / x_std
# array([[ 0.46291005,  0.50800051, -0.10179732],
#        [ 0.9258201 ,  0.88900089, -1.17066918],
#        [-1.38873015, -1.3970014 ,  1.2724665 ]])

# 2. compute variance matrix
# cov默认是按照行计算协方差，这里分析是按列需要设置rowvar
x_cov = np.cov(x_norm, rowvar=False)
# array([[ 0.11546349,  0.40637085, -0.52183434],
#        [ 0.40637085,  1.43981062, -1.84618147],
#        [-0.52183434, -1.84618147,  2.36801581]])

# 3. compute feature value and matrix
feature_value, feature_vector = np.linalg.eig(x_cov)
print("feature_value:\n", feature_value)
# feature_value:                                                                                                                                                                         
# array([4.42231151e+00, 2.43596756e-16, 7.76884923e-02])
# feature_vector:
# 每一列对应特征矩阵，不是每一行。
# array([[-0.1711692 , -0.79835316,  0.57735027],
#        [-0.60580952,  0.54741346,  0.57735027],
#        [ 0.77697872,  0.25093971,  0.57735027]])

# 4. 按特征值大小排列并获得对应的特征向量, 这里取2维pca
x_pca = np.vstack(([feature_vector[:,0], feature_vector[:, 2]]))
x_pca = np.transpose(x_pca)
# array([[-0.58077228,  0.3282358 ],
#        [-0.57896098,  0.47677453],
#        [ 0.57228292,  0.81544301]])

# 5. 第1步归一化矩阵，点乘x_pca矩阵实现降维
x_norm_pca = np.dot(x_norm, x_pca)
print(x_norm_pca)
# array([[-0.62121467,  0.31113544],
#        [-1.72234145, -0.22687371],
#        [ 2.34355612, -0.08426173]])