#include<iostream>
#include<vector> 
#include<string>
using namespace std;


int main()
{
	int x, i, j, k, m, n;             // ������� 
	double y(0), z, c(0);
	vector<double> num;      //�޳�ʼ�������ܻ������� 
	vector<char> ope;        //�޳�ʼ�������ܻ������� 
	char a;


	while (2 > 1)              //��ѭ����������ʽ�е����ֺ�������ֿ� 
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


	for (i = 1; i <= c; i++)                  //����˳����㣬���ɼӼ����� 
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


	for (j = 0; j <= c; j++)         //����������ת���ɼӷ����� 
	{
		if (ope[j] == '-')
		{
			num[j + 1] = -num[j + 1];
			ope[j] = '+';        // ����������� 
		}
	}


	for (k = 0; k <= c; k++)          //������Ԫ����ӣ��õ����ս�� 
	{
		y = y + num[k];
	}


	cout << y << endl;             //������ս�� 
	system("pause");
	return 0;

}
