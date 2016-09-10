#pragma once
#pragma warning (disable : 4996) //Kept getting unsafe error
#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"
//#include <ios>
using namespace std;

class Commissioned_Employee: public Employee
{
public:
	Commissioned_Employee();
		//Default Constructor - Initializes commision_rate
	~Commissioned_Employee();
		//Default Destructor - Unused 
	void setCommisionRate(double newRate);
		//Assigns value to commission_rate
	void setTotalSales(double newSales);
		//Assigns value to total_sales
	void setNetPay(double newPay);
		//Assigns value to net_pay
	double getCommisionRate();
		//Returns commission_rate
	double getTotalSales();
		//Returns total_sales
	double getNetPay();
		//Returns net_pay
	void input();
		//User enters info of commissioned employee
	void print();
		//Displays pay-stub on screen
	void print_to_file();
		//Prints pay-stub to file
	void current_date_time();
		//Displays date and 24hr time format
	void print_current_date_time();
		//Allows for date and time to print to file

private:
	double commision_rate; //Percentage 
	double total_sales;
	double net_pay;
};
Commissioned_Employee::Commissioned_Employee() { commision_rate = 0.0; }	
Commissioned_Employee::~Commissioned_Employee() { /*empty*/ }	
void Commissioned_Employee::setCommisionRate(double newRate) { commision_rate = newRate; }
void Commissioned_Employee::setTotalSales(double newSales) { total_sales = newSales; }	
void Commissioned_Employee::setNetPay(double newPay) { net_pay = newPay; }	
double Commissioned_Employee::getCommisionRate() { return commision_rate; }	
double Commissioned_Employee::getTotalSales() { return total_sales; }
double Commissioned_Employee::getNetPay() { return net_pay; }
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
void Commissioned_Employee::current_date_time() {

	time_t date_and_time; //declares time_t variable
	date_and_time = time(0); //seeds the variable

	struct tm current_date_time; //creates time struct
	current_date_time = *localtime(&date_and_time); //passes values from seeded time_t variable to struct
	/*
		cout << current_date_time.tm_mday << endl; - Produces day
		cout << current_date_time.tm_wday << endl; - Produces which number of day of the week it is 
	*/

	//Maybe make prettier 8-10-16
	cout << "*********************" <<
		 setw(32) << "Date - "  << current_date_time.tm_mon << "/"  << current_date_time.tm_mday << "/" << current_date_time.tm_year+1900 << endl; //Outputs 'Month'/'Day'/'Year' ex. 8/10/2016
	cout <<"* Commissioned Stub *" << 
		setw(32) << "Time - "  << current_date_time.tm_hour << ":"  << current_date_time.tm_min << ":" << current_date_time.tm_sec << endl;
	cout << "*********************" << endl;
}
void Commissioned_Employee::print() { //formated 
	cout << "---------------------------------------------------------------" << endl;
		current_date_time();
	cout << "           Name     " << getName() << endl
	 	 << "Employee Number   " << "# " << getNum() << endl
		 << setw(15) << "Commission" << setw(6) << commision_rate * 100 << " %" << endl
		 << setw(15) << "Total Sales" << setw(5) << "$ " << fixed << setprecision(2) << total_sales << endl
		 << setw(15) << "Net Pay" << setw(5) << "$ " << fixed << setprecision(2) << net_pay << endl
	     << "---------------------------------------------------------------" << endl << endl;
}
void Commissioned_Employee::print_to_file() { //formated 
	ofstream myfile; //prints to file, make display or new function?

	string temp_path = "C:\\Users\\Mike\\Desktop\\Test_Folder\\Commisioned_Stubs.txt"; //Only used as temp directory 

	myfile.open(temp_path, ios::app); //Saves to specific directory.  
	if (myfile.fail())
	{
		cout << "Failed to write to file" << endl;
		exit(1);
	}

	myfile << "---------------------------------------------------------------" << endl;
		print_current_date_time();
	myfile << "           Name     " << getName() << endl
		<< "Employee Number   " << "# " << getNum() << endl
		<< setw(15) << "Commission" << setw(6) << commision_rate * 100 << " %" << endl
		<< setw(15) << "Total Sales" << setw(5) << "$ " << fixed << setprecision(2) << total_sales << endl
		<< setw(15) << "Net Pay" << setw(5) << "$ " << fixed << setprecision(2) << net_pay << endl
		<< "---------------------------------------------------------------" << endl << endl;
	myfile.close();

}
void Commissioned_Employee::print_current_date_time() {
	time_t date_and_time; //declares time_t variable
	date_and_time = time(0); //seeds the variable

	struct tm current_date_time; 
	current_date_time = *localtime(&date_and_time); 
	string temp_path = "C:\\Users\\Mike\\Desktop\\Test_Folder\\Commisioned_Stubs.txt"; //Only used as temp directory
	ofstream myfile;
	myfile.open(temp_path, ios::app); //Saves to specific directory.  
	if (myfile.fail())
	{
		cout << "Failed to write to file" << endl;
		exit(1);
	}

	myfile << "*********************" <<
		setw(32) << "Date - "  << current_date_time.tm_mon << "/"  << current_date_time.tm_mday << "/"  << current_date_time.tm_year + 1900 << endl;
	myfile << "* Commissioned Stub *" <<
		setw(32) << "Time - "  << current_date_time.tm_hour << ":" <<  current_date_time.tm_min << ":"  << current_date_time.tm_sec << endl;
	myfile << "*********************" << endl;
	myfile.close();
}