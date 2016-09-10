#pragma once
#pragma warning (disable : 4996) //Kept getting unsafe error
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
	void print_to_file();
	void current_date_time();
		//Displays date and 24hr time format
	void print_current_date_time();
		//Allows for date and time to print to file
	

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
	cout << "---------------------------------------------------------------" << endl;
	current_date_time();
	cout << "           Name     " << getName() << endl;
	cout << "Employee Number   " << "# " << getNum() << endl;
	cout << setw(15) << "Salary" << setw(5) << "$ " <<fixed << setprecision(2)  << salary << endl;
	cout << "---------------------------------------------------------------" << endl;
}
void Salary_Employee::print_to_file() { //formated
	ofstream myfile;

	string temp_path = "C:\\Users\\Mike\\Desktop\\Test_Folder\\Salary_Stubs.txt"; //Only used as temp directory 
	myfile.open(temp_path, ios::app);


	if (myfile.fail())
	{
		cout << "File was unable to open. Terminating program" << endl;
		exit(1);
	}

	myfile << "---------------------------------------------------------------" << endl;
		print_current_date_time();
	myfile	<< "           Name     " << getName() << endl
		<< "Employee Number   " << "# " << getNum() << endl
		<< setw(15) << "Salary" << setw(5) << "$ " << fixed << setprecision(2) << salary << endl
		<< "---------------------------------------------------------------" << endl;
}
void Salary_Employee::current_date_time() {
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
		setw(32) << "Date - " << current_date_time.tm_mon << "/" << current_date_time.tm_mday << "/" << current_date_time.tm_year + 1900 << endl; //Outputs 'Month'/'Day'/'Year' ex. 8/10/2016
	cout << "* Salary Stub *" <<
		setw(32) << "Time - " << current_date_time.tm_hour << ":" << current_date_time.tm_min << ":" << current_date_time.tm_sec << endl;
	cout << "***************" << endl;
}
void Salary_Employee::print_current_date_time() {
	time_t date_and_time; //declares time_t variable
	date_and_time = time(0); //seeds the variable

	struct tm current_date_time; //creates time struct
	current_date_time = *localtime(&date_and_time); 

	string temp_path = "C:\\Users\\Mike\\Desktop\\Test_Folder\\Salary_Stubs.txt"; //Only used as temp directory
	ofstream myfile;
	myfile.open(temp_path, ios::app); //Saves to specific directory.  
	if (myfile.fail())
	{
		cout << "Failed to write to file" << endl;
		exit(1);
	}
	myfile << "***************" <<
		setw(32) << "Date - "  << current_date_time.tm_mon << "/"  << current_date_time.tm_mday << "/" << current_date_time.tm_year + 1900 << endl; //Outputs 'Month'/'Day'/'Year' ex. 8/10/2016
	myfile << "* Salary Stub *" <<
		setw(32) << "Time - "  << current_date_time.tm_hour << ":"  << current_date_time.tm_min << ":" << current_date_time.tm_sec << endl;
	myfile << "***************" << endl;
}
