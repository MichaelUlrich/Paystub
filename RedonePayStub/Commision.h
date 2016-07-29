#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"
using namespace std;

class Commissioned_Employee: public Employee
{
public:
	Commissioned_Employee();
	~Commissioned_Employee();
	void setCommisionRate(double newRate);
	void setTotalSales(double newSales);
	void setNetPay(double newPay);
	double getCommisionRate();
	double getTotalSales();
	double getNetPay();
	void input();
	void print();


private:
	double commision_rate; //Percentage 
	double total_sales;
	double net_pay;
};

Commissioned_Employee::Commissioned_Employee() { commision_rate = 0.0; }
	//Default Constructor - Initializes commision_rate
Commissioned_Employee::~Commissioned_Employee(){ /*empty*/ }
	//Default Destructor - Unused 
void Commissioned_Employee::setCommisionRate(double newRate) { commision_rate = newRate; }
	//Assigns value to commission_rate
void Commissioned_Employee::setTotalSales(double newSales) { total_sales = newSales; }
	//Assigns value to total_sales
void Commissioned_Employee::setNetPay(double newPay) { net_pay = newPay; }
	//Assigns value to net_pay
void Commissioned_Employee::input()
{
	string name, num;
	cin.ignore(); //Needed to avoid skipping due to alternating between 'cin' and 'getline'
				  //Caused by selecting employee type where I used cin >> int
	cout << "Please enter your first and last name and hit [ENTER]: ";
	getline(cin, name); //Needed to include white spaces
	
	cout << "Please enter your employee number and hit [ENTER]: ";
		cin >> num;
	cout << "Please enter your total amount of sales and hit [ENTER]: $";
		cin >> total_sales;
	cout << "Please enter your commission rate: (%)";
		cin >> commision_rate;
	commision_rate *= .01; //converts to decimal
	double newPay = (commision_rate * total_sales) + total_sales;
	setNetPay(newPay);
	this->setName(name);
	this->setNum(num);
}
double Commissioned_Employee::getCommisionRate() { return commision_rate; }
	//Returns commission_rate
double Commissioned_Employee::getTotalSales() { return total_sales; }
	//Returns total_sales
double Commissioned_Employee::getNetPay() { return net_pay; }
	//Returns net_pay

void Commissioned_Employee::print() { //formated 
	ofstream myfile("example.txt"); //prints to file, make display or new function?
	
	 myfile << "----------------------------------------" << endl
			<< "           Name     " << getName() << endl
			<< "Employee Number   " << "# " << getNum() << endl
			<< setw(15) << "Commission" << setw(6) << commision_rate * 100 << " %" << endl
			<< setw(15) << "Total Sales" << setw(5) << "$ " << fixed << setprecision(2) << total_sales << endl
			<< setw(15) << "Net Pay" << setw(5) << "$ " << fixed << setprecision(2) << net_pay << endl
			<< "----------------------------------------" << endl << endl;
		myfile.close();

	
}