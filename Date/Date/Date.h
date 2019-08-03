#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
		if (month == 2 && ((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0) )
		{
			return 29;
		}
		else
		{
			return monthDays[month];
		}
	}

	// Date d1(2018, 2, 29);
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		if (year < 1900
			&& month <= 0 && month >= 13
			&& day <= 0 && day > GetMonthDay(year, month))
		{
			cout << "非法日期" << endl;
		}
	}

	// 拷贝 赋值 析构 / 都要去练习写一下

	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		if (_year > d._year)
		{
			return false;
		}
		if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			if (_month > d._month)
			{
				return false;
			}
			if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		if (_year < d._year)
		{
			return false;
		}
		if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			if (_month < d._month)
			{
				return false;
			}
			if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool operator!=(const Date& d)
	{
		if (_year != d._year && _month != d._month && _day != d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// d + 100
	Date operator+(int day)
	{
		Date x = *this;
		x._day += day;
		while (x._day > GetMonthDay(_year, _month))
		{
			x._day -= GetMonthDay(_year, _month);
			if (x._month == 12)
			{
				x._year++;
				x._month = 1;
			}
			else
			{
				x._month++;
			}			
		}
		return x;
	}
	
	Date& operator+=(int day)
	{
		int Monthday = GetMonthDay(_year, _month);
		while (day > Monthday)
		{
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
			_month++;
			day -= Monthday;
		}
		_day = day;
		return *this;
	}
	Date operator-=(int day)
	{
		_day = day;
		while (_day < 1)
		{
			if (_month == 1)
			{
				--_year;
				_month = 12;
			}
			else
			{
				--_month;
			}
			_month--;
			_day += GetMonthDay(_year, _month);
		}
	}
	Date operator-(int day)
	{
		Date x = *this;
		x -=  ;
	}
	int operator-(const Date& d)
	{
		int Monthday = GetMonthDay(_year, _month);
		int day = 0;	
		if (_day < d._day)
		{
			_month--;
			_day += Monthday;
		}
		if (_month < 1)
		{
			_year--;
			_month = 12;
		}
	}

	// ++d d.operator++(&d)
	Date operator++()
	{
		*this += 1;
		return *this;
	}
	// d++ d.operator++(&d, 0)
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
private:
	int _year;
	int _month;
	int _day;
};