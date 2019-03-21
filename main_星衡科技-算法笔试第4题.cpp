#include<iostream>
#include<vector>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

// solve this eq: a＊x + b * sin x = 0
// 这题出的有问题，当 a = 0的时候有无穷个解，vector根本装不下。
// 经过验证，这份解答的精度比mathematica(一个专业的数学软件)还要高。

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
	
	//cout << "sol.size(): " << sol.size() << endl;
	//cout << "PI, sin(PI): " << PI << "," << sin(PI) << endl;
	//system("pause");
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

