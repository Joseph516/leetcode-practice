import matplotlib.pyplot as plt
import random
from sklearn.cluster import KMeans
import numpy as np

#--------------------custom-kemeans------------------------#


def customKmeans(vec_array, n_clusters=3, epochs=500):
    '''
    @description: 手动实现kmeans，以向量间的夹角余弦作为相似度
                 根据上述tf-idf得到的7条文本向量vec_array，进行聚类算法
    @param {type} vec_array- 向量组, n_clusters-聚类数目, epochs- 训练次数
    @return: cluster_labels- 分类标签
    '''

    # 初始化质心的位置
    cluster_centers = []
    cluster_centers_indx = []
    while (len(cluster_centers_indx) < n_clusters):
        indx = random.randint(0, len(vec_array)-1)
        if indx not in cluster_centers_indx:
            cluster_centers_indx.append(indx)
            cluster_centers.append(vec_array[indx])

    # 初始化向量类别
    cluster_centers = np.array(cluster_centers)
    cluster_labels = [0] * len(vec_array)
    epoch = 0
    while(epoch < epochs):
        # 计算每个向量与质心的相似性，并将其归纳到最近的质心集群中
        for i in range(0, len(vec_array)):
            # max_similarity = computeCosine(vec_array[i], cluster_centers[0])
            min_similarity = computeEuDistance(
                vec_array[i], cluster_centers[0])
            cluster_labels[i] = 0
            for j in range(1, n_clusters):
                temp = computeEuDistance(vec_array[i], cluster_centers[j])
                if (temp < min_similarity):
                    min_similarity = temp
                    cluster_labels[i] = j

        # 更新质心位置
        cluster_centers_old = np.copy(cluster_centers)
        for i in range(0, n_clusters):
            # 找到集群对应原向量的下标
            indxs = [indx for indx, cluster in enumerate(
                cluster_labels) if cluster == i]
            # 根据集群向量的平均值更新质点位置
            cluster_centers[i] = np.average(
                [vec_array[indx] for indx in indxs], axis=0)

        # 当满足迭代次数或质心位置几乎不变时退出算法
        diff = cluster_centers - cluster_centers_old
        if (max(np.linalg.norm(x) for x in diff) < 1e-10):
            break
        epoch += 1
    return cluster_labels


def computeCosine(vec1, vec2):
    # 计算向量间的余弦值
    vecCosine = np.dot(vec1, vec2) / \
        (np.linalg.norm(vec1) * np.linalg.norm(vec2))
    return vecCosine


def computeEuDistance(vec1, vec2):
    # 计算向量间的欧式距离
    dist = [vec1[i] - vec2[i] for i in range(len(vec1))]
    dist = np.linalg.norm(dist)
    return dist


# 生成随机数
x = []
y = []
for i in range(50):
    temp1 = random.random()*10
    temp2 = random.random()*10
    x.append(temp1)
    y.append(temp2)
for i in range(50):
    temp1 = 10+random.random()*10
    temp2 = 10+random.random()*10
    x.append(temp1)
    y.append(temp2)
# plt.scatter(x, y)

# 待分类的向量集群
vec_array = np.array([[x[i], y[i]] for i in range(len(x))])

# 应用customkmeans
n_clusters = 2
labels = customKmeans(vec_array, n_clusters=n_clusters, epochs=10000)
# print(labels)

# 可视化
res = [[] for i in range(n_clusters)]
for i in range(len(vec_array)):
    res[labels[i]].append(vec_array[i])
for i in range(n_clusters):
    plt.scatter([res_s[0] for res_s in res[i]], [res_s[1] for res_s in res[i]])

plt.show()
