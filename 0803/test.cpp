#include<iostream>
using namespace std;

class Date
{
public:


	friend ostream& operator<<(ostream& _cout, const Date& d);

	Date(int y, int m, int d)
		: _y(y)
		, _m(m)
		, _d(d)
	{

	}
private:
	int _y;
	int _m;
	int _d;

};

ostream& operator<<(ostream& _cout, const Date& d)

{
	_cout << d._y << "-" << d._m << "-" << d._d << endl;
	return _cout;
}

void test()
{
	Date d(2001, 01, 26);
	cout << d;
}

int main()
{
	test();
	return 0;
}