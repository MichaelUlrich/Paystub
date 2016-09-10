#pragma once
#pragma warning (disable : 4996) //Kept getting unsafe error
#include <iostream>
using namespace std;
class Employee
{
public:
	Employee();
	//Default Constructor - Initialized name, employee_num, netPay
	Employee(string newName, string newEployeeNum);
		//Secondary Constructor - Assigns values to employee_name, employee_num, netPay
	~Employee();
		//Default Destructor - Not used
	string getName();
		//Returns employee_name
	void setName(string newName);
		//Sets employee_name from outside the class
	string getNum();
		//Returns employee_num
	void setNum(string newNum);
		//Sets employee_num from outside the class
	void setNetPay(double newPay);
		//Sets net_pay from outside the class
	double getNetPay();
		//Returns net_pay
private:
	string employee_name;
	string employee_num;
	double net_pay;
};
Employee::Employee() { employee_name = "NO NAME", employee_num = "NO NUM"; }

Employee::Employee(string newName, string newEmployeeNum) { employee_name = newName, employee_num = newEmployeeNum; }
	
string Employee::getName() { return employee_name; }
	
void Employee::setName(string newName) { employee_name = newName; }
	
string Employee::getNum() { return employee_num; }
	
void Employee::setNum(string newNum) { employee_num = newNum; }
	
void Employee::setNetPay(double newPay) { net_pay = newPay; }
	
double Employee::getNetPay() { return net_pay; }
	
Employee::~Employee() { /*empty*/ }
	