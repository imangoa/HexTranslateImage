import numpy as np
import matplotlib
import os

swpfloder = 'swap'
swpname = 'swap'
swpsuffix = 'swp'
dftpath = r'.' + os.sep + swpfloder + os.sep + swpname + '.' + swpsuffix

# 文本分隔符
separator = '\n'

data = np.arange(1, 121).reshape((8, 3, 5))


def write(data, path=dftpath):
    with open(path, 'w') as file:
        # 写入维度
        file.write(str(data.ndim) + separator)
        # 写入形状
        for i in data.shape:
            file.write(str(i) + separator)
        # 写入一维数据
        for i in data.flat:
            file.write(str(i) + separator)

def read(sprt=separator, path=dftpath):
    with open(path, 'r') as file:
        temp = np.array(file.readlines())
        # 去除'\n'
        for i in range(0, len(temp)):
            temp[i] = temp[i].rstrip('\n')
        # 字符列表 -> 数值列表
        temp = np.array(list(map(int, temp)))
        # 提取维度与形状
        ndim = temp[0]
        shape = temp[1:ndim + 1]
    # 组合成数据
    return temp[ndim + 1:].reshape(shape)


if __name__ == '__main__':
    #write(data)
    print(read())
