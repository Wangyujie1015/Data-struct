#include<iostream>
#include<vector> 
#include<string>
using namespace std;


int main()
{
	int x, i, j, k, m, n;             // 定义变量 
	double y(0), z, c(0);
	vector<double> num;      //无初始化，可能会有歧义 
	vector<char> ope;        //无初始化，可能会有歧义 
	char a;


	while (2 > 1)              //死循环，将运算式中的数字和运算符分开 
	{
		cin >> x;
		num.push_back(x);
		cin >> a;
		if (a == '=')
		{
			ope.push_back(a);
			break;
		}
		else
		{
			ope.push_back(a);
		}
		c++;
	}


	switch (ope[0])
	{
	case '*':
		num[1] = num[0] * num[1];
		num[0] = 0;
		ope[0] = '+';
		break;
	case '/':
		num[1] = num[0] / num[1];
		num[0] = 0;
		ope[0] = '+';
		break;
	default:
		break;
	}


	for (i = 1; i <= c; i++)                  //计算乘除运算，化成加减运算 
	{
		if (ope[i] == '*' || ope[i] == '/')
		{
			if (ope[i] == '*')
			{
				num[i + 1] = num[i] * num[i + 1];
				num[i] = 0;
			}
			else
			{
				num[i + 1] = num[i] / num[i + 1];
				num[i] = 0;
			}
		}
	}


	for (j = 0; j <= c; j++)         //将减法运算转化成加法运算 
	{
		if (ope[j] == '-')
		{
			num[j + 1] = -num[j + 1];
			ope[j] = '+';        // 考虑两种情况 
		}
	}


	for (k = 0; k <= c; k++)          //将所有元素相加，得到最终结果 
	{
		y = y + num[k];
	}


	cout << y << endl;             //输出最终结果 
	system("pause");
	return 0;

}
