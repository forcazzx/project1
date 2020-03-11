import numpy as np
import matplotlib.pyplot as plt

# a = 1
# name = input('输入名字：')
# print('hello %d' % a, name)

b = np.loadtxt('/media/zzx/STORAGE/FileRecv/Navigation/组合导航数据处理/20191229车载/A15-D/odostd.txt')
b = np.reshape(b, (-1, 2))
plt.plot(b[:, 0], b[:, 1])
plt.show()

# with open('/media/zzx/STORAGE/FileRecv/Navigation/组合导航数据处理/20191009车载POS320B/test.txt', 'r') as f:
#     data = f.readlines()  # txt中所有字符串读入data
#
#     for line in data:
#         odom = line.split()  # 将单个数据分隔开存好
#         # numbers_float = map(float, odom)  # 转化为浮点数
#         print(odom[0], odom[1])

# tx = np.linspace(-100, 100, 1000)
# y = np.sin(tx) * tx ** 2
# plt.plot(tx, y)
# plt.show()
