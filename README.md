# Question

## Question1:
关于resnet的结构
![](./img/img0.png)
![](./img/img1.png)


## Question2:

我最近参加了这个比赛，不知道你有没有兴趣啊？
我遇到很多困难，感觉是主办方给了一个无解的题目。

http://www.dcjingsai.com 地球物候的深度学习预测

http://www.dcjingsai.com/common/cmpt/%E5%9C%B0%E7%90%83%E7%89%A9%E5%80%99%E7%9A%84%E6%B7%B1%E5%BA%A6%E5%AD%A6%E4%B9%A0%E9%A2%84%E6%B5%8B_%E7%AB%9E%E8%B5%9B%E4%BF%A1%E6%81%AF.html

这是一个时空序列预测任务，每一个时间点都会给一张卫星灰度图片（1200\*1200\*1），图片表示植被发育情况。给大约200张这样的图片，要预测之后的几张图片的样子。

en，以上是一个地区的情况，每一个地区有大约200张图片，要预测之后的几张图片。现在是初赛，一共有4个地区的数据(也就是说现在有约800张图片)，决赛的话主办方会给更多的数据的。

我的思路是用convlstm[1,2]来做。

>[1] Convolutional LSTM Network: A Machine Learning Approach for Precipitation Nowcasting，http://arxiv.org/abs/1506.04214
>
>这篇2015.06.12的paper提出convlstm结构来预测降水。

>[2] Air Quality Forecasting Using Convolutional LSTM，https://cs230.stanford.edu/projects_spring_2018/reports/8291197.pdf
>
>这是吴恩达的2018年cs230春季课程的一个report，用convlstm来预测空气质量。
