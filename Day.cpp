#include"Day.h"
#include<iostream>
#include<cassert>

using namespace std;

Day::Day(int y , int m, int d )
{
	day=d;
	month=m;
	year=y;
	//防止某些小可爱故意找茬
	assert(month>0&&month<13&&year>0&&day>0&&day<=get_month_day(year,month));
}
Day& Day::operator+=(int d)
{
	if (d < 0)day-=d;
	else day=d+day;
	while (day >get_month_day(year, month))
	{
		day-= get_month_day(year, month);
		month+=1;
		if (month == 13)
		{
			year++;month=1;
		}
	}
	return *this;
}
Day Day::operator+(int d)
{
	//重写一遍
	//Day tmp=*this;
	//tmp.day+=d;
	//while (tmp.day > get_month_day(tmp.year, tmp.month))
	//{
	//	tmp.day -= get_month_day(tmp.year, tmp.month);
	//	tmp.month += 1;
	//	if (tmp.month == 13)
	//	{
	//		tmp.year++; tmp.month = 1;
	//	}
	//}
	//代码复用
	Day tmp=*this;
	if (d < 0)tmp-=d;
	else tmp+=d;//报尼玛的错vs2026
	return tmp;
}

Day& Day::operator-=(int d)
{
	if (d < 0)day+=d;
	else day-=d;
	while (day <= 0)
	{
		month--;
		if (month == 0)
		{
			year--;month=12;
		}
		day+=get_month_day(year,month);
	}
	return *this;
}

Day Day::operator-(int d)
{
	Day tmp=*this;
	if(d<0)tmp+=d;
	else tmp-=d;
	return tmp;
}
bool Day:: operator<(const Day& d)
{
	if (year < d.year)return true;
	else if (year == d.year)
	{
		if(month<d.month)return true;
		else if (month = d.month)
		{
			if(day<d.day)return true;
		}
	}
	return false;
}

bool Day::operator ==(const Day& d)
{
	return year==d.year
			&&month==d.month
			&&day==d.day;
}

bool Day::operator !=(const Day& d)
{
	return !(*this==d);
}

bool Day::operator<=(const Day& d)
{
//代码复用的强大之处啊
	return (*this<d)||*this==d;
}

bool Day::operator>(const Day& d)
{
	//代码复用的强大之处啊
	return !(*this <= d);
}

bool Day::operator>=(const Day& d)
{
	//代码复用的强大之处啊
	return !(*this<d);
}

Day Day:: operator++(int)//后置++
{
	//first use
	//second ++
	Day tmp=*this;
	*this+=1;
	return tmp;
}

Day& Day::operator++()
{
	*this+=1;
	return *this;
}

int Day::operator-(const Day& d)
{
	//思路有不少，效率高的有算出相差天数然后再调用+或-等
	//这里就用简单的循环来写了，因为相差天数很难达到1e6级别的，也是秒出
	int flag=1;
	Day max=*this;
	Day min=d;
	if (max < min)
	{
		max=d;
		min=*this;
		flag=-1;
	}
	int cnt=0;
	while (min!=max)
	{
		cnt++;
		min++;
	}
	return cnt*flag;
}


ostream& operator<<(ostream& out, const Day& d)
{
	out<<d.year<<"年"<<d.month<<"月"<<d.day<<"日\n";
	return out;
}

istream& operator>>(istream& in,  Day& d)
{
	in>>d.year>>d.month>>d.day;
	assert(d.year>0&&d.month>0&&d.month<13&&d.day>0&&d.day<=d.get_month_day(d.year,d.month));
	return in;
}