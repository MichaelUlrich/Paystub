#pragma once

#include <iostream>
using namespace std;
class Employee
{
public:
	Employee();
	Employee(string newName, string newEployeeNum);
	~Employee();
	string getName();
	void setName(string newName);
	string getNum();
	void setNum(string newNum);
	void setNetPay(double newPay);
	double getNetPay();



	/*
	

	FUCKING BROKE THE PRINT TO FILE THING SOMEHOW

	*/


private:
	string employee_name;
	string employee_num;
	double net_pay;
};
Employee::Employee() { employee_name = "NO NAME", employee_num = "NO NUM"; }
	//Default Constructor - Initialized name, employee_num, netPay
Employee::Employee(string newName, string newEmployeeNum) { employee_name = newName, employee_num = newEmployeeNum; }
	//Secondary Constructor - Assigns values to employee_name, employee_num, netPay
string Employee::getName() { return employee_name; }
	//Returns employee_name
void Employee::setName(string newName) { employee_name = newName; }
	//Sets employee_name from outside the class
string Employee::getNum() { return employee_num; }
	//Returns employee_num
void Employee::setNum(string newNum) { employee_num = newNum; }
	//Sets employee_num from outside the class
void Employee::setNetPay(double newPay) { net_pay = newPay; }
	//Sets net_pay from outside the class
double Employee::getNetPay() { return net_pay; }
	//Returns net_pay
Employee::~Employee() { /*empty*/ }
	//Default Destructor - Not used