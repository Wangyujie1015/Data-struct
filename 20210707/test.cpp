#include<iostream>

using namespace std;

class Date
{
public:


};

//������֮��           ��������ע�ͣ�
#include <iostream>		//Ԥ��������
using namespace std;	//ʹ�������ռ�std
int main()				//�������ײ�
{						//�����忪ʼ
	int a, b, sum;			//�������
	cin >> a >> b;				//�������
	sum = a + b;				//��ֵ���
	cout << "a+b=" << sum << endl;	//�����䣨endl��end line����д����ʾ�н������롰\n��������ͬ��
	system("pause");
	return 0;				//��������������������ϵͳ����һ����ֵ
}


int main()
{
	int max(int x, int y);					//��max����������
	int a, b, c;
	cin >> a >> b;
	c = max(a, b);								//����max����
	cout << "max=" << c << endl;
	system("pause");
	return 0;
}
int max(int x, int y)					//����max����
{
	int z;
	if (x > y)z = x;
	else z = y;
	return(z);
}


class Student						//����һ���࣬����ΪStudent
{
private:							//����Ϊ���˽������
	int num;						//˽�б���num
	int score;						//˽�б���score
public:							//����Ϊ���й��ò���
	void setdata()					//���幫�ú���setdata
	{
		cin >> num;						//����num��ֵ
		cin >> score;					//����score��ֵ
	}
	void display()					//���幫�ú���diaplay
	{
		cout << "num=" << num << endl;		//���num��ֵ
		cout << "score=" << score << endl;	//���score��ֵ
	};
};									//�����������
Student stud1, stud2;				//����stud1��stud2ΪStudent��ı�������Ϊ����
int main()							//�������ײ�
{
	stud1.setdata();					//���ö���stud1��setdata����
	stud1.display();
	stud2.setdata();
	stud2.display();
	system("pause");
	return 0;
}
