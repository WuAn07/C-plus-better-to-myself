#ifndef DAY_H
#define  DAY_H
#include<iostream>
using namespace std;
class Day
{
public:
	//	打印测试函数
	void print()
	{
		cout<<"year:" << year << "  month:" << month << "  day:" << day << endl;
	}
	Day(int y = 2000,int m=1, int d=1);

	int get_month_day(int y, int m)
	{
		int month_day_arry[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		{
			return 29;
		}
		return month_day_arry[m];
	}
	//日期加天数，求输出日期的变化
	Day& operator+=(int d);
	Day operator+(int d);
	Day& operator-=(int d);
	Day operator-(int d);
	bool operator<(const Day& d);
	bool operator==(const Day& d);
	bool operator!=(const Day& d);
	bool operator<=(const Day& d);
	bool operator>(const Day& d);
	bool operator>=(const Day& d);
	Day operator++(int);
	Day& operator++();
	int operator-(const Day& d);

friend  ostream& operator<<(ostream& out,const Day& d);
friend  istream& operator>>(istream& in, Day& d);//注意这里的Day不需要const，因为输入相当于修改了
private:
	int day;
	int month;
	int year;

};

#endif
