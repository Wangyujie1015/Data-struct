#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char s1[100], s2[50] = "Happy new year";
	cout << "put �� writer������Ӧ��!" << endl;
	cout << 'M' << endl;
	cout.put('M');
	cout.put('\n');
	cout << "������һ���ַ���";
	cin.read(s1, 100);
	cout.write(s1, 5) << endl;
	cout.write(s2, strlen(s2)) << endl;
	return 0;
}



int main()
{
	char str[100];
	ofstream myFout("F:\\ٻٻ\\c++����\\example.txt.txt", ios::out);
	cout << "�ļ��������Ӧ�ã�" << endl;
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
	ifstream myFin("F:\\ٻٻ\\c++����\\example.txt.txt", ios::in);
	cout << "�ļ���������Ӧ�ã�";
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
