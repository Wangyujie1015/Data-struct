#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int main() {
	srand(time(0));
	int n = rand() % 1000;
	int c = -1, ans = 0;
	cout << "��Ҫ�µ�����Ϊ��***" << endl << endl;
	while (c != n) {
		cout << "��µ����ǣ�";
		cin >> c;
		ans++;
		if (c > n) {
			Sleep(500);
			cout << "���ˣ�" << endl << endl;
		}
		else if (c < n) {
			Sleep(500);
			cout << "С�ˣ�" << endl << endl;
		}
	}
	cout << "��ϲ���У�����" << endl << "������" << ans << "�Σ�����" << endl;
	system("pause");
	return 0;
}




get������getline����

#include<iostream>

using namespace std;

int main()
{
	char s1, s2, s3[50], s4[50];
	cout << "������һ���ַ���";
	cout << cin.get() << endl;//��ȡһ���ַ���ASCII��ֵ
	cin.get();//��ȡ���з�
	cout << "�����������ַ���";
	cin.get(s1).get(s2);
	cout << s1 << s2 << endl;
	cin.get();
	cout << "������һ���ַ�����";
	cin.get(s3, 50);
	cout << s3 << endl;
	cin.get();
	cout << "������һ���ַ�����";
	cin.getline(s4, 50);
	cout << s4 << endl;
	return 0;
}
