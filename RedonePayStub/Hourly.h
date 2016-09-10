#pragma once
#pragma warning (disable : 4996) //Kept getting unsafe error
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
		//Prints Hourly_Employee pay stub to file
	void input();
		//Allows user to input name, employee_num, hourly_rate, hours
	~Hourly_Employee();
		//Default Destructor - Not used
	void setNetPay(int hours, double hourly_rate);
		//Calculates hourly_net_pay
	double getNetPay();
		//Returns hourly_net_pay
	void current_date_time();
		//Displays date and 24hr time format
	void print_current_date_time();
		//Allows for date and time to print to file
private:
	int hours;
	double hourly_rate;
	double hourly_net_pay;
};

double Hourly_Employee::getNetPay() { return hourly_net_pay; }

Hourly_Employee::~Hourly_Employee() { /*empty*/ }

Hourly_Employee::Hourly_Employee() { hours = 0; hourly_rate = 0.0; }

void Hourly_Employee::setNetPay(int hours, double hourly_rate) { hourly_net_pay = hours * hourly_rate; }

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
	cout << "---------------------------------------------------------------" << endl;
	current_date_time();
	cout << "           Name     " << getName() << endl;
	cout << "Employee Number   " << "# " << getNum() << endl;
	cout << setw(15) << "Hours " << setw(6) << hours << endl;
	cout << setw(15) << "Rate" <<  setw(5) <<  fixed << setprecision(2) << "$ " <<  hourly_rate << endl;
	cout << setw(15) << "Total Pay" << setw(5) << fixed << setprecision(2) <<"$ " << getNetPay() << endl;
	cout << "---------------------------------------------------------------" << endl;
}

void Hourly_Employee::print_to_file() {
	ofstream myfile;

	string temp_path = "C:\\Users\\Mike\\Desktop\\Test_Folder\\Hourly_Stubs.txt"; //Only used as temp directory 

	myfile.open(temp_path, ios::app);


	if (myfile.fail())
	{
		cout << "Failed to open file" << endl;
		exit(1);
	}

	myfile << "---------------------------------------------------------------" << endl;
	print_current_date_time();
	myfile	<< "           Name     " << getName() << endl
		<< "Employee Number   " << "# " << getNum() << endl
		<< setw(15) << "Hours" << setw(6) << hours << endl
		<< setw(15) << "Rate" << setw(5) << fixed << setprecision(2) << "$ " << hourly_rate << endl
		<< setw(15) << "Total Pay" << setw(5) << fixed << setprecision(2) << "$ " << getNetPay() << endl
		<< "---------------------------------------------------------------" << endl;
	myfile.close();
}

void Hourly_Employee::current_date_time() {

	time_t date_and_time; //declares time_t variable
	date_and_time = time(0); //seeds the variable

	struct tm current_date_time; //creates time struct
	current_date_time = *localtime(&date_and_time); //passes values from seeded time_t variable to struct
													/*
													cout << current_date_time.tm_mday << endl; - Produces day
													cout << current_date_time.tm_wday << endl; - Produces which number of day of the week it is
													*/

													//Maybe make prettier 8-10-16
	cout << "***************" <<
		setw(38) << "Date - "  << current_date_time.tm_mon << "/" <<  current_date_time.tm_mday << "/" << current_date_time.tm_year + 1900 << endl; //Outputs 'Month'/'Day'/'Year' ex. 8/10/2016
	cout << "* Hourly Stub *" <<
		setw(38) << "Time - "   << current_date_time.tm_hour << ":"   << current_date_time.tm_min << ":" << current_date_time.tm_sec << endl;
	cout << "***************" << endl;
}

void Hourly_Employee::print_current_date_time() {

	ofstream myfile;

	string temp_path = "C:\\Users\\Mike\\Desktop\\Test_Folder\\Hourly_Stubs.txt"; //Only used as temp directory 

	myfile.open(temp_path, ios::app);

	if (myfile.fail())
	{
		cout << "Failed to open file" << endl;
		exit(1);
	}

	time_t date_and_time; //declares time_t variable
	date_and_time = time(0); //seeds the variable

	struct tm current_date_time; //creates time struct
	current_date_time = *localtime(&date_and_time); 
	myfile << "***************" <<
		setw(38) << "Date - " << current_date_time.tm_mon << "/" << current_date_time.tm_mday << "/" << current_date_time.tm_year + 1900 << endl; //Outputs 'Month'/'Day'/'Year' ex. 8/10/2016
	myfile << "* Hourly Stub *" <<
		setw(38) << "Time - " << current_date_time.tm_hour << ":" << current_date_time.tm_min << ":" << current_date_time.tm_sec << endl;
	myfile << "***************" << endl;
	myfile.close();
}