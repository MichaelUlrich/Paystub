#pragma once
using namespace std;
#include <string>
#include <iostream>
#include "Employee.h"
class Hourly_Employee : public Employee
{
public:
	Hourly_Employee();
		//Default Constructor - Initialized hours, hourly_rate	
	Hourly_Employee(int newHours, double newHourlyRate, string newName, string newEmployeeNum);
		//Secondary Constructor - Assigns values to hours, hourly_rate, employee_name, employee_num
	void print();
		//Prints Hourly_Employee pay stub
	void print_to_file();

	void input();
		//Allows user to input name, employee_num, hourly_rate, hours
	~Hourly_Employee();
		//Default Destructor - Not used
	void setNetPay(int hours, double hourly_rate);
		//Calculates hourly_net_pay
	double getNetPay();
		//Returns hourly_net_pay
private:
	int hours;
	double hourly_rate;
	double hourly_net_pay;
};
Hourly_Employee::Hourly_Employee() { hours = 0; hourly_rate = 0.0; }											 
Hourly_Employee::Hourly_Employee(int newHours, double newHourlyRate, string newName, string newEmployeeNum)
	: Employee(newName, newEmployeeNum) //Needed to pass to base class
	{ hours = newHours, hourly_rate = newHourlyRate;}	
void Hourly_Employee::input() {
	string name, num;
	cin.ignore(); //Needed to avoid skipping due to alternating between 'cin' and 'getline'
	cout << "Please enter your first name and hit [ENTER]: ";
	getline(cin, name); //Need to include white spaces
	cout << "Please enter your employee number and hit [ENTER]: ";
	cin >> num;
	cout << "Please enter your hourly rate and hit [ENTER]: $";
	cin >> hourly_rate;
	cout << "Please enter your total hours and hit [ENTER]: ";
	cin >> hours;
	this->setName(name);
	this->setNum(num);
	setNetPay(hours, hourly_rate);
	
}
void Hourly_Employee::print() { //formated
	cout << "----------------------------------------" << endl;
	cout << "           Name     " << getName() << endl;
	cout << "Employee Number   " << "# " << getNum() << endl;
	cout << setw(15) << "Hours" << setw(6) << hours << endl;
	cout << setw(15) << "Rate" <<  setw(5) <<  fixed << setprecision(2) << "$ " <<  hourly_rate << endl;
	cout << setw(15) << "Total Pay" << setw(5) << fixed << setprecision(2) <<"$ " << getNetPay() << endl;
}
void Hourly_Employee::print_to_file() {
	ofstream myfile;

	myfile.open("example.txt");

	if (myfile.fail())
	{
		cout << "Failed to open file" << endl;
		exit(1);
	}

	myfile << "----------------------------------------" << endl
		<< "           Name     " << getName() << endl
		<< "Employee Number   " << "# " << getNum() << endl
		<< setw(15) << "Hours" << setw(6) << hours << endl
		<< setw(15) << "Rate" << setw(5) << fixed << setprecision(2) << "$ " << hourly_rate << endl
		<< setw(15) << "Total Pay" << setw(5) << fixed << setprecision(2) << "$ " << getNetPay() << endl;
	myfile.close();
}
void Hourly_Employee::setNetPay(int hours, double hourly_rate) { hourly_net_pay = hours * hourly_rate; }	
double Hourly_Employee::getNetPay() { return hourly_net_pay; }
Hourly_Employee::~Hourly_Employee() { /*empty*/ }
	