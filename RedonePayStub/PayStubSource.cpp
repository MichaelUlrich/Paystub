/*
Michael Ulrich
July 26, 2016
Pay Stub Generator and Printer
*/

#include <iostream>
#include <string>  //string
#include <iomanip> //setw(), fixed, setprecision()
#include <cassert> //assert
#include <fstream> //Read/Write to files
#include "Employee.h"
#include "Hourly.h"
#include "Salary.h"
#include "Commision.h"
using namespace std;
int main()
{
	char payStubSentinel = 'y';
	
	int type; //Determines which type of employee
	
	while (payStubSentinel == 'y' || payStubSentinel == 'Y')
	{
		cout << "---------------------------------------------------------------" << endl;
		cout << "#           Welcome to Mike's Pay-stub Generator              #" << endl;
		cout << "# Please enter the corresponding number to your employee type #" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "(1) Hourly | (2) Salary | (3) Commissioned: ";
		cin >> type;
		cout << "---------------------------------------------------------------" << endl;
		/*while (type != 1 || type != 2 || type != 3)
		{
			cout << "Please enter either (1) hourly, (2) salary, (3) commissioned: ";
			cin >> type;
			cout << "--------------------------------------------" << endl;
		}*/
		Hourly_Employee *hourlyEmployee = new Hourly_Employee;
		Salary_Employee *salaryEmployee = new Salary_Employee;
		Commissioned_Employee *commisionedEmployee = new Commissioned_Employee;
		assert(hourlyEmployee != NULL && salaryEmployee != NULL && commisionedEmployee != NULL); //Emergency abort

		switch (type)
		{
		case 1: //hourly

			/* 7/28
			All input still need fail-safe for entering info
			Still needs print to file for stubs 
			Format output to look nice - DONE
			*/
			hourlyEmployee->input();
			hourlyEmployee->print();
			hourlyEmployee->print_to_file();
			
			delete hourlyEmployee;
			break;
		case 2: //salary
			salaryEmployee->input();
			salaryEmployee->print();
			salaryEmployee->print_to_file();

			delete salaryEmployee;
			break;
		case 3: //commissioned 
			commisionedEmployee->input();
			commisionedEmployee->print();
			commisionedEmployee->print_to_file();

			delete commisionedEmployee;
			break;
		}

		cout << "Would you like to enter another employee? : (Y/N) ";
		
		cin >> payStubSentinel;
		cout << "---------------------------------------------------------------" << endl;
		
		
	} 
	return 0;
}