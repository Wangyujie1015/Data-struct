class Date
{
public:
	/*
	// 如果用户显式定义了构造函数，编译器将不再生成
	Date (int year, int month, int day)
	{
	_year = year;
	_month = month;
	_day = day;
	}
	*/
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{

		Date d;
}

class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
}