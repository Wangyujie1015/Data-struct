#include<iostream>

using namespace std;

class Date
{
public:


};

//求两数之和           （本行是注释）
#include <iostream>		//预处理命令
using namespace std;	//使用命名空间std
int main()				//主函数首部
{						//函数体开始
	int a, b, sum;			//定义变量
	cin >> a >> b;				//输入语句
	sum = a + b;				//赋值语句
	cout << "a+b=" << sum << endl;	//输出语句（endl是end line的缩写，表示行结束，与“\n”作用相同）
	system("pause");
	return 0;				//如程序正常结束，向操作系统返回一个零值
}


int main()
{
	int max(int x, int y);					//对max函数作声明
	int a, b, c;
	cin >> a >> b;
	c = max(a, b);								//调用max函数
	cout << "max=" << c << endl;
	system("pause");
	return 0;
}
int max(int x, int y)					//定义max函数
{
	int z;
	if (x > y)z = x;
	else z = y;
	return(z);
}


class Student						//声明一个类，类名为Student
{
private:							//以下为类的私有内容
	int num;						//私有变量num
	int score;						//私有变量score
public:							//以下为类中公用部分
	void setdata()					//定义公用函数setdata
	{
		cin >> num;						//输入num的值
		cin >> score;					//输入score的值
	}
	void display()					//定义公用函数diaplay
	{
		cout << "num=" << num << endl;		//输出num的值
		cout << "score=" << score << endl;	//输出score的值
	};
};									//类的声明结束
Student stud1, stud2;				//定义stud1和stud2为Student类的变量，称为对象
int main()							//主函数首部
{
	stud1.setdata();					//调用对象stud1的setdata函数
	stud1.display();
	stud2.setdata();
	stud2.display();
	system("pause");
	return 0;
}
