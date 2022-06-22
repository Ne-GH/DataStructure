#include<iostream>
#include<stack>
using namespace std;
int f_yx(char c) {//返回符号的优先级
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	else return 0;//这句话只是为了应付警告信息
}

int main() {
	while (1) {
		int num;
		char ch, T_;
		stack<double>d;
		stack<char>c;

		while (1) {
			cin >> num;//被操作的数字
			d.push(num * 1.0);
			T_ = getchar();

			if (num == 0 && T_ == '\n' && c.empty())
				goto A;//退出的是最外层的循环
			if (T_ == '\n')
				break;

			cin >> ch;//运算符号
			getchar();
		B:
			if (!c.empty() && (f_yx(c.top()) < f_yx(ch))) {
				c.push(ch);
			}
			else if (!c.empty() && (f_yx(c.top()) >= f_yx(ch))) {
				double temp_s;//临时计算的计算结果
				double temp1 = d.top();
				d.pop();
				double temp2 = d.top();
				d.pop();
				if (c.top() == '*')
					temp_s = temp1 * temp2;
				else if (c.top() == '/')
					temp_s = temp2 / temp1;
				else if (c.top() == '+')
					temp_s = temp1 + temp2;
				else if (c.top() == '-')
					temp_s = temp2 - temp1;

				d.push(temp_s);
				c.pop();
				if (c.empty())
					c.push(ch);
				else
					goto B;
			}
			else {
				c.push(ch);//没有进行上述操作说明符号栈为空,将符号入栈
			}




		}
		double temp_ss;
		while (!c.empty()) {
			double temp1, temp2;
			temp1 = d.top();
			d.pop();
			temp2 = d.top();
			d.pop();
			switch (c.top()) {
			case '+':
				temp_ss = temp1 + temp2;
				break;
			case '-':
				temp_ss = temp2 - temp1;
				break;
			case '*':
				temp_ss = temp1 * temp2;
				break;
			case '/':
				temp_ss = temp2 / temp1;
				break;
			}
			c.pop();
			d.push(temp_ss);
		}
		printf("%.2f\n", temp_ss);
	}
A:
	return 0;
}