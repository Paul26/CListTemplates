#include "Employee.h"
#include "SalariedEmployee.h"
#include "SalesEmployee.h"
#include "WagedEmployee.h"
#include "Date.h"
#include "Address.h"
#include "CList.h"  // Goes here?
#include <iostream>
#include <string>
using namespace std;


void prompt(const char* message, string& variable);
void prompt(const char* message, int& number);
void prompt(const char* message, double& number);


int main()
{
	CList<Employee> employee;

	while (true)
	{
		cout << endl;
		cout << "1. Waged Employee" << endl;
		cout << "2. Salaried Employee" << endl;
		cout << "3. Sales Employee" << endl;
		cout << "4. List" << endl << endl;		
		cout << "5. Exit" << endl << endl;
		cout << "Choose an Employee or an Action: ";

		char	c;
		cin >> c;
		cin.ignore();

		string	name;				// variables used by all employee types
		int	year;
		int	month;
		int	day;
		string	street;
		string	city;

		switch (c)
		{	case '1' :	// waged employee
				{
					double	wage;
					double	hours;
					prompt("Name", name);
					prompt("Wage", wage);
					prompt("Hours", hours);
					prompt("Year", year);
					prompt("Month", month);
					prompt("Day", day);
					prompt("Street", street);
					prompt("City", city);
					WagedEmployee* we = new WagedEmployee(name, year, month, day, wage, hours);
					we->setAddress(street, city);
					cout << *we << endl;
					//we->display();
					employee.insert(we); 
					break;
				}

			case '2' :	// salaried employee
				{
					double	salary;
					prompt("Name", name);
					prompt("Salary", salary);
					prompt("Year", year);
					prompt("Month", month);
					prompt("Day", day);
					prompt("Street", street);
					prompt("City", city);
					SalariedEmployee* se = new SalariedEmployee(name, year, month, day, salary);
					se->setAddress(street, city);
					cout << *se << endl;
					//se->display();
					employee.insert(se);  
					break;
				}

			case '3' :	// sales employee
				{
					double	salary;
					double	commission;
					double	sales;
					prompt("Name", name);
					prompt("Salary", salary);
					prompt("Commission", commission);
					prompt("Sales", sales);
					prompt("Year", year);
					prompt("Month", month);
					prompt("Day", day);
					prompt("Street", street);
					prompt("City", city);
					SalesEmployee* se = new SalesEmployee(name, year, month, day,
							salary, commission, sales);
					se->setAddress(street, city);
					cout << *se << endl;
					//se->display();
					employee.insert(se);  
					break;
				}

			case '4' :
				{
					//string name;
					//prompt("Name", name);    //  ****************  I don't believe I need any of these comments, is this correct?
					//prompt("Year", year);    //  ****************  Because option 4 is to only list what has been inserted into the CList, correct? 
					//prompt("Month", month);  //  **************** plus it goes into an infinite loop if used.
					//prompt("Day", day);
					//prompt("Street", street);
					//prompt("City", city);
					employee.list();
					break;
				}

			case '5' :
				exit(0);
		}
	}

	system("pause");
	return 0;
}


void prompt(const char* message, string& variable)
{
	cout << message << ": ";
	getline(cin, variable);
}


void prompt(const char* message, int& number)
{
	cout << message << ": ";
	cin >> number;
	cin.ignore();		// discard \n following number
}

void prompt(const char* message, double& number)
{
	cout << message << ": ";
	cin >> number;
	cin.ignore();		// discard \n following number
}

