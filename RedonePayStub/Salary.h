#pragma once
#include <iostream>
#include <iomanip>
#include "Employee.h"

class Salary_Employee : public Employee
{
public:
	Salary_Employee();
	Salary_Employee(double, string, string);
	~Salary_Employee();
	void setSalary(double newSalary);
	double getSalary();
	void input();
	void print();
	

private:
	double salary;
};
Salary_Employee::Salary_Employee() { salary = 0; }
	//Default Constructor - Initializes salary
Salary_Employee::Salary_Employee(double newSalary, string newName, string newNum): Employee(newName, newNum) { salary = newSalary; } 
	//Secondary Constructor  
Salary_Employee::~Salary_Employee() { /*empty*/ }
	//Default Destructor - Unused 
void Salary_Employee::setSalary(double newSalary) { salary = newSalary; }
	//Assigns new value to salary
double Salary_Employee::getSalary() { return salary; }
	//Returns salary
void Salary_Employee::input() {
	string name, num;
	cin.ignore(); //Needed to avoid skipping due to alternating between 'cin' and 'getline'
	cout << "Please enter your first name and hit [ENTER]: ";
	getline(cin,name); //Needed to include white spaces
	cout << "Please enter your employee number and hit [ENTER]: ";
	cin >> num;
	cout << "Please enter your salary and hit [ENTER]: $";
	cin >> salary;
	this->setName(name);
	this->setNum(num);
}
void Salary_Employee::print() { //formated
	cout << "----------------------------------------" << endl;
	cout << "           Name     " << getName() << endl;
	cout << "Employee Number   " << "# " << getNum() << endl;
	cout << setw(15) << "Salary" << setw(5) << "$ " <<fixed << setprecision(2)  << salary << endl;
}