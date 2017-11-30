#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using namespace std;

class Date
{
	private:
		int year;
		int month;
		int day;

	public:
		//Date();
		Date(int a_year, int a_month, int a_day) 
			: year(a_year), month(a_month), day(a_day) {}

		void display()
		{
			cout << year << "/" << month << "/" << day << endl;
		}

		friend ostream& operator<<(ostream& out, Date& me)
		{
			out << me.year << "/" << me.month << "/" << me.day << endl;
			return out;
		}
};

#endif 

