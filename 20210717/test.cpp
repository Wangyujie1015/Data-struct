#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int main() {
	srand(time(0));
	int n = rand() % 1000;
	int c = -1, ans = 0;
	cout << "你要猜的数字为：***" << endl << endl;
	while (c != n) {
		cout << "你猜的数是：";
		cin >> c;
		ans++;
		if (c > n) {
			Sleep(500);
			cout << "大了！" << endl << endl;
		}
		else if (c < n) {
			Sleep(500);
			cout << "小了！" << endl << endl;
		}
	}
	cout << "恭喜猜中！！！" << endl << "共用了" << ans << "次！！！" << endl;
	system("pause");
	return 0;
}




get函数和getline函数

#include<iostream>

using namespace std;

int main()
{
	char s1, s2, s3[50], s4[50];
	cout << "请输入一个字符：";
	cout << cin.get() << endl;//读取一个字符的ASCII码值
	cin.get();//提取换行符
	cout << "请输入两个字符：";
	cin.get(s1).get(s2);
	cout << s1 << s2 << endl;
	cin.get();
	cout << "请输入一个字符串：";
	cin.get(s3, 50);
	cout << s3 << endl;
	cin.get();
	cout << "请输入一个字符串：";
	cin.getline(s4, 50);
	cout << s4 << endl;
	return 0;
}
