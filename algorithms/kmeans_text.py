import matplotlib.pyplot as plt
import random
from sklearn.cluster import KMeans
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer
import numpy as np

# 模拟文档集合
corpus = ['I like great basketball game',
          'This video game is the best action game I have ever played',
          'I really really like basketball',
          'How about this movie? Is the plot great?',
          'Do you like RPG game?',
          'You can try this FPS game',
          'The movie is really great, so great! I enjoy the plot']
#----------------词频方法-------------------#
# 把文本中的词语转换为词典和相应的向量
vectorizer = CountVectorizer()
vectors = vectorizer.fit_transform(corpus)


# 输出所有的词条（所有维度的特征）
print('所有的词条（所有维度的特征）')
print(vectorizer.get_feature_names())  # 去除一些无用词，并按照字母顺序排列
print('\n')

# 输出 (文章 ID, 词条 ID) 词频
print('(文章 ID, 词条 ID) 词频')
print(vectors)
print('\n')

#----------------tf-idf----------------------#
# 构建 tfidf 的值
transformer = TfidfTransformer()
tfidf = transformer.fit_transform(vectorizer.fit_transform(corpus))

# 输出每个文档的向量
# tfidf_array是每个文章中的词条概率组成的向量，概率通过tf-idf计算而来。从而得到corpus的7条向量。
# 如第一篇文章：array([0., 0., 0.57620019, 0., 0.,0., 0., 0., 0., 0.42760696,0.49251682, 0., 0., 0., 0.49251682,0., 0., 0., 0., 0.,0., 0., 0., 0., 0., 0.])
# 对应['about', 'action', 'basketball', 'best', 'can', 'do', 'enjoy', 'ever', 'fps', 'game', 'great', 'have', 'how', 'is', 'like', 'movie', 'played', 'plot', 'really', 'rpg', 'so', 'the', 'this', 'try',
# 'video', 'you']
tfidf_array = tfidf.toarray()
words = vectorizer.get_feature_names()

"""
for i in range(len(tfidf_array)):
    print("********* 第 ", i + 1, " 个文档中，所有词语的 tf-idf*********")
    # 输出向量中每个维度的取值
    for j in range(len(words)):
        print(words[j], ' ', tfidf_array[i][j])
    print('\n')
"""

"""
#------------------k-means--------------------------#
# 进行聚类，在我这个版本里默认使用的是欧氏距离
clusters = KMeans(n_clusters=3)
s = clusters.fit(tfidf_array)

# 输出所有质心点，可以看到质心点的向量是组内成员向量的平均值
print('所有质心点的向量')
print(clusters.cluster_centers_)
print('\n')

# 输出每个文档所属的分组
print('每个文档所属的分组')
print(clusters.labels_)

# 输出每个分组内的文档
dict = {}
for i in range(len(clusters.labels_)):
    label = clusters.labels_[i]
    if label not in dict.keys():
        dict[label] = []
        dict[label].append(corpus[i])
    else:
        dict[label].append(corpus[i])
print(dict)
"""

#--------------------custom-kemeans------------------------#


def customKmeans(vec_array, n_clusters=3, epochs=500):
    '''
    @description: 手动实现kmeans，以向量间的夹角余弦作为相似度
                 根据上述tf-idf得到的7条文本向量tfidf_array，进行聚类算法
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
            max_similarity = computeCosine(vec_array[i], cluster_centers[0])
            cluster_labels[i] = 0
            for j in range(1, n_clusters):
                temp = computeCosine(vec_array[i], cluster_centers[j])
                if (temp < max_similarity):
                    max_similarity = temp
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


# 应用customkmeans
n_clusters = 3
labels = customKmeans(tfidf_array, n_clusters=n_clusters, epochs=10000)
print(labels)

# 输出每个分组内的文档
dict = {}
for i in range(len(labels)):
    label = labels[i]
    if label not in dict.keys():
        dict[label] = []
        dict[label].append(corpus[i])
    else:
        dict[label].append(corpus[i])
print(dict)
