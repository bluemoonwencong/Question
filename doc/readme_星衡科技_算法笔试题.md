### 1. 从1到500的500个数，第一次删除奇数位，第二次删除剩下来的奇数位，以此类推，最后剩下的唯一一位数是____256_____

### 2. 简述CNN和FCN的区别
`CNN网络一般用于计算机视觉任务，以其中的卷积层最有特色，但是CNN一般也有其它的层，如pool layer，fc layer，batchnormalize layer，等等。其输入图片(可以是二维也可以是高维)的尺寸是固定的，输出的尺寸也是固定的。FCN网络中没有fc layer，因为fc layer的效果完全可以用卷积层代替。在寻找物体的bounding box时，以前只能用CNN，用不同大小的窗口按一定步长滑动。CNN的输入输出尺寸固定，只能对每一个窗口来检测该窗口是否存在被检测物体，方差耗费时间。用FCN后可以接受任意尺寸的输入图片，一次性输出所有滑动窗口的结果，非常快。另外，FCN可以完全只用卷积层，使得输出和输入尺寸相同，这对pixel-level的任务如分割是很合适的。`

### 3.（编程题）给出了一个n*n的矩形，编程求从左上角到右下角的路径数（n > =2），并返回走的方法，限制只能向右或向下移动，不能回退。向右走此步骤标记为1， 向下走此步骤标记为2。
```python
from itertools import permutations
# itertools是一个数据挖掘工作会经常用到的包
# permutations返回可迭代对象的排列
def pythonic(n):
    ret = set(list(permutations([1]*(n-1) + [2]*(n-1), 2*(n-1))))
    return len(ret), ret
```

### 4.	（编程题）编程求解 a＊x + b * sin x = 0。
Std::vector<double> Solve(double a, double b){
}


`这题有误！！！`

`首先，题干的"Std"应该写成"std"。`

`其次，当 a=0 的时候，有无穷个解，vector这种数据结构装不下，这是最大的错误。`

`其它任意情况，已经编程处理并做完测试。`

`经过验证，这份解答的精度比mathematica(一个专业的数学软件)还要高。验证方法是使得斜率比1小但极度接近1，观察解的个数和解的值，从这个角度，以下解法比mma的精度高。具体验证操作：固定 b = 100，扫描 a = -99.99999999999, ... 99.9999999999999999，观察mathematica和以下程序的输出。`

`**下载本 git repository 文件 "./doc/main_星衡科技-算法笔试第4题.cpp" 运行**`

`**下载本 git repository 文件 "./doc/main_星衡科技-算法笔试第4题.nb" 测试，本文件需要mathematica环境支持**`

```cpp
#include<iostream>
#include<vector>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

// solve this eq: a * x + b * sin x = 0

double two_divide(double left, double right, double k, double is_up);
vector<double> Solve(double a, double b);
double PI = M_PI;

int main() {
	
	// input:
	double a = -80, b = 100;
	
	vector<double> sol = Solve(a, b);
	vector<double>::iterator iter;
	cout << "solution of this problem:" << endl;
	for (iter = sol.begin(); iter != sol.end(); iter++) {
		cout << *iter << endl;
	}
	
	cout << "sol.size(): " << sol.size() << endl;
	//cout << "PI, sin(PI): " << PI << "," << sin(PI) << endl;
	system("pause");
	return 0;
}

vector<double> Solve(double a, double b) {
	vector<double> sol;
	//pre-processing
	if (a == 0 && b == 0) {
		cout << "any real number!!!" << endl;
		return sol;
	}
	if (a == 0 && b != 0) {
		cout << "there are too many answers!!!" << endl;
		cout << "answer is k*pi, k= ... -3, -2, -1, 0, 1, 2, 3, ..." << endl;
		cout << "vector can't representation all answers" << endl;
		return sol;
	}
	if (a != 0 && b == 0) {
		sol.push_back(0);
		return sol;
	}

	// a, b != 0 is extremely hard ...
	// we need change the problem into sin(x) = k*x
	double ans, k = -a / b;
	//cout << "k: " << k << endl;
	
	if (k > 1 || k < -0.25) {
		;
	}
	
	if (2 / PI <= k && k <= 1) {
		ans = two_divide(0, PI/2, k, -1);
		sol.push_back(ans);
		sol.push_back(-ans);
	}

	if (-0.25 <= k && k < 2 / PI) {
		double left, right;
		int count = 0;
		while (1) {
			left = (count + 0.5)*PI;
			right = (count + 1.5)*PI;
			ans = two_divide(left, right, k, 2 * (count % 2) - 1);
			if (ans == 0) {
				break;
			}
			else {
				sol.push_back(ans);
				sol.push_back(-ans);
			}
			count++;
		}
	}
	sol.push_back(0);
	return sol;
}

double two_divide(double left, double right, double k, double is_up) {
	// careful the bounding !!! 不重不漏
	if ((is_up == 1) && (left * k <= -1 || right * k > 1)) {
		return 0;
	}
	// careful the bounding !!! 不重不漏
	if ((is_up == -1) && (left * k >= 1 || right * k < -1)) {
		return 0;
	}
	// careful the bounding !!! 不重不漏
	if (abs(right*k) == -is_up) {
		return right;
	}

	double mid, d=0.0000000000001;
	while (right - left > d) {
		mid = (left + right) / 2;
		if (is_up*(k*mid - sin(mid)) > 0) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return (left + right) / 2;
}

```

### 5. （探索题）你会用什么样的方法提取遥感图像中的道路呢（包括主街道、田埂、小路）。示例如下：白色明显道路是大路，深绿色田埂也属于需要提取的区域。
![](./img/Snipaste_2019-03-19_11-11-58.png)

`首先对大图进行切割，切割成小块的时候，相邻小块之间有一定的overlap。对这些小块样本数据扩充，旋转，对称翻转，镜像。然后人工标注一小部分图像。然后用一种图像分割框架，deeplabv3，来提取道路。`


### 6.（随便聊聊题） 聊聊你认为深度学习中最有用的三个trick和三个创造性的idea，并说一下你的理解，为什么有用，为什么有创造性。

`3个创造性idea：`

- batch normalization 有了这个就不必关心输入图片的值分布了，而且可以使得收敛过程更平滑，有一定的正则化效应。

- resnet的“shortcut连接”，可以训练更深得网络。

- deeplabv3的upsample，从不同深度的层upsample综合考虑以得到输出。从此不必一定要构建“直来直去”得网络架构了。而且deeplapv3的upsample用到了dilated Convolution，这也是很棒的idea。

`3个创造性trick：`

- dropout。有神经网络特色的正则化方法。

- 迁移学习。极大的加快训练速度。

- 多尺度寻训练。对输入图片做不同尺度的放大缩小，然后喂进去。虽然理论上pool层会使得网络模型天然有处理多尺度信息的能力，但是实际上在数据层面就控制好多尺度更好。这可以让模型充分学习到不同尺度的信息，避免过拟合。


