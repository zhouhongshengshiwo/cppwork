import numpy as np
from PIL import Image
import os
import tensorflow as tf
import matplotlib.pyplot as plt

mnist_mulu = "F:\py\MNIST"
x_xunlian_lujing = os.path.join(mnist_mulu, "train-images.idx3-ubyte")
y_xunlian_lujing = os.path.join(mnist_mulu, "train-labels.idx1-ubyte")
x_ceshi_lujing = os.path.join(mnist_mulu, "t10k-images.idx3-ubyte")
y_ceshi_lujing = os.path.join(mnist_mulu, "t10k-labels.idx1-ubyte")

# 读取MNIST训练集图像
with open(x_xunlian_lujing, 'rb') as f:
    moshu = int.from_bytes(f.read(4), 'big')  # 读取魔术数
    tupian_shuliang = int.from_bytes(f.read(4), 'big')  # 图像数量
    gao = int.from_bytes(f.read(4), 'big')  # 图像高度
    kuan = int.from_bytes(f.read(4), 'big')  # 图像宽度
    buf = f.read(tupian_shuliang * gao * kuan)  # 读取图像数据
    x_xunlian = np.frombuffer(buf, dtype=np.uint8).reshape(tupian_shuliang, gao, kuan)  # 转换为numpy数组

# 读取MNIST训练集标签
with open(y_xunlian_lujing, 'rb') as f:
    moshu = int.from_bytes(f.read(4), 'big')  # 读取魔术数
    biaoqian_shuliang = int.from_bytes(f.read(4), 'big')  # 标签数量
    y_xunlian = np.frombuffer(f.read(biaoqian_shuliang), dtype=np.uint8)  # 转换为numpy数组

# 读取MNIST测试集图像
with open(x_ceshi_lujing, 'rb') as f:
    moshu = int.from_bytes(f.read(4), 'big')  # 读取魔术数
    tupian_shuliang = int.from_bytes(f.read(4), 'big')  # 图像数量
    gao = int.from_bytes(f.read(4), 'big')  # 图像高度
    kuan = int.from_bytes(f.read(4), 'big')  # 图像宽度
    buf = f.read(tupian_shuliang * gao * kuan)  # 读取图像数据
    x_ceshi = np.frombuffer(buf, dtype=np.uint8).reshape(tupian_shuliang, gao, kuan)  # 转换为numpy数组

# 读取MNIST测试集标签
with open(y_ceshi_lujing, 'rb') as f:
    moshu = int.from_bytes(f.read(4), 'big')  # 读取魔术数
    biaoqian_shuliang = int.from_bytes(f.read(4), 'big')  # 标签数量
    y_ceshi = np.frombuffer(f.read(biaoqian_shuliang), dtype=np.uint8)  # 转换为numpy数组

# 构建BP神经网络模型
model = tf.keras.models.Sequential([
    tf.keras.layers.Flatten(input_shape=(28, 28)),  # 扁平化层，将28x28的图像转换为一维向量
    tf.keras.layers.Dense(128, activation='relu'),  # 全连接层，128个神经元，激活函数为ReLU
    tf.keras.layers.Dense(10)  # 输出层，10个神经元对应10个类别
])

def chuangjian_bing_bianyi_moxing(xuexi_lv):
    model = tf.keras.models.Sequential([
        tf.keras.layers.Flatten(input_shape=(28, 28)),
        tf.keras.layers.Dense(128, activation='relu'),
        tf.keras.layers.Dense(10)
    ])
    youhuaqi = tf.keras.optimizers.Adam(learning_rate=xuexi_lv)
    model.compile(optimizer=youhuaqi,
                  loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
                  metrics=['accuracy'])
    return model

# 图像归一化处理
x_xunlian, x_ceshi = x_xunlian / 255.0, x_ceshi / 255.0

# 定义不同的学习率
xuexi_lvs = [0.001, 0.01, 0.1]

# 字典来存储不同学习率的历史记录
lishi = {}

# 对每个学习率训练模型，并记录历史
for xuexi_lv in xuexi_lvs:
    print(f"Training with learning rate: {xuexi_lv}")
    model = chuangjian_bing_bianyi_moxing(xuexi_lv)
    history = model.fit(x_xunlian, y_xunlian, epochs=10, validation_data=(x_ceshi, y_ceshi), verbose=1)
    lishi[xuexi_lv] = history

# 绘制对比图
plt.figure(figsize=(14, 6))
for xuexi_lv, history in lishi.items():
    plt.plot(history.history['accuracy'], label=f'Accuracy LR={xuexi_lv}')
    plt.plot(history.history['loss'], label=f'Loss LR={xuexi_lv}', linestyle='--')
plt.title('Comparison of different learning rates')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.legend()
plt.grid(True)
plt.show()

def huatu(tuijian, x_ceshi, y_ceshi, xuexi_lv):
    plt.figure(figsize=(15, 12))
    plt.suptitle(f'Predictions with Learning Rate: {xuexi_lv}', fontsize=16)  # 在顶部添加包含学习率的标题
    for i in range(25):  # 假设我们要绘制25张图像
        plt.subplot(5, 5, i + 1)
        plt.xticks([])
        plt.yticks([])
        plt.grid(False)
        plt.imshow(x_ceshi[i], cmap=plt.cm.binary)
        yuce_biaoqian = np.argmax(tuijian[i])
        zhenshi_biaoqian = y_ceshi[i]
        yanse = 'blue' if yuce_biaoqian == zhenshi_biaoqian else 'red'
        # 在每个图像下方显示预测和真实标签以及学习率
        plt.xlabel(f'Pred: {yuce_biaoqian}, True: {zhenshi_biaoqian}\nLR: {xuexi_lv}', color=yanse)
    plt.subplots_adjust(top=0.9)  # 留出空间显示标题
    plt.show()

# 在模型训练和预测的代码中，我们需要确保学习率信息传递正确
for xuexi_lv in xuexi_lvs:
    print(f"Training and predicting with learning rate: {xuexi_lv}")
    model = chuangjian_bing_bianyi_moxing(xuexi_lv)
    model.fit(x_xunlian, y_xunlian, epochs=10, validation_data=(x_ceshi, y_ceshi), verbose=0)  # 训练模型
    tuijian = model.predict(x_ceshi[:25])  # 对前25张图像进行预测
    huatu(tuijian, x_ceshi[:25], y_ceshi[:25], xuexi_lv)
