#include<iostream>
using namespace std;

class Solution {
public:
	class sum{
	public:
		sum()
		{
			_sum += _i;
			++_i;
	    }
	};
	int Sum_Solution(int n) {
		_sum = 0;
		_i = 1;
		sum array[n];
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};

int Solution::_i = 1;
int Solution::_sum = 0;