#ifndef _WAGEDEMPLOYEE_H_
#define _WAGEDEMPLOYEE_H_

#include <iostream>

using namespace std;

#include "SalesEmployee.h"

class WagedEmployee : public Employee
{
	private:
		double wage;
		double hours;

	public:
		WagedEmployee(string a_name, int a_year, int a_month, int a_day, double a_wage, double a_hours)
			: Employee(a_name, a_year, a_month, a_day), wage(a_wage), hours(a_hours) {}


		virtual double calcPay()
		{
			return wage * hours;
		}


		virtual void dislpay()  //  ************ should this only be printing out calcPay()??
		{
			Employee::display();
			cout << "Wage: " << wage << " Hours: " << hours << " Total Wage: " << calcPay() << endl;
			cout << endl;
		}


		friend ostream& operator<<(ostream& out, WagedEmployee& me)
		{
			out << (Employee &)me << " Wage: " << me.wage << " Hours: " << me.hours << endl;
			return out;
		}
};

#endif 

