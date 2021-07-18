#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char s1[100], s2[50] = "Happy new year";
	cout << "put 和 writer函数的应用!" << endl;
	cout << 'M' << endl;
	cout.put('M');
	cout.put('\n');
	cout << "请输入一串字符：";
	cin.read(s1, 100);
	cout.write(s1, 5) << endl;
	cout.write(s2, strlen(s2)) << endl;
	return 0;
}



int main()
{
	char str[100];
	ofstream myFout("F:\\倩倩\\c++程序\\example.txt.txt", ios::out);
	cout << "文件输出流的应用！" << endl;
	if (myFout.fail())
	{
		cout << "This file dose not exist!" << endl;
		return 0;
	}
	else
	{
		cout << "Open this file!" << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> str;
		myFout << str << endl;
	}
	myFout.close();
	return 0;
}



int main()
{
	char str[100];
	ifstream myFin("F:\\倩倩\\c++程序\\example.txt.txt", ios::in);
	cout << "文件输入流的应用！";
	if (myFin.fail())
	{
		cout << "This file does not exist!" << endl;
		return 0;
	}
	else
	{
		cout << "Open the file!" << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		myFin >> str;
		cout << str << endl;
	}
	myFin.close();
	return 0;
}
