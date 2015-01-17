//(Employee Class) Create a class called Employee that includes three pieces of information as
//data members—a first name (type string), a last name (type string) and a monthly salary (type int).
//[Note: In subsequent chapters, we’ll use numbers that contain decimal points (e.g., 2.75)—
//called floating-point values—to represent dollar amounts.] Your class should have a constructor that
//initializes the three data members. Provide a set and a get function for each data member. If the
//monthly salary is not positive, set it to 0. Write a test program that demonstrates class Employee’s
//capabilities. Create two Employee objects and display each object’s yearly salary. Then give each Employee
//a 10 percent raise and display each Employee’s yearly salary again.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdbool.h>
using namespace std;

class Employee
{
	private:
		string firstname;
		string lastname;
		int salary;
	public:
		Employee(string firstname, string lastname, int salary);
		string getfirstname();
		string getlastname();
		int getsalary();
		void setfirstname(string firstname);
		void setlastname(string lastname);
		void setsalary(int salary);
		int control(int a);
		int salary_raise(int salary);
};

Employee::Employee(string xfirstname, string xlastname, int xsalary)
{
    firstname=xfirstname;
	lastname=xlastname;
	salary=control(xsalary);
}

string Employee::getfirstname()
{
	return firstname;
}

string Employee::getlastname()
{
	return lastname;
}

int Employee::getsalary()
{
	return control(salary);
}

void Employee::setfirstname(string xfirstname)
{
    firstname=xfirstname;
}

void Employee::setlastname(string xlastname)
{
    lastname=xlastname;
}

void Employee::setsalary(int xsalary)
{
    salary=control(xsalary);
}

int Employee::control(int a)
{
	if(a<0)
	{
		return 0;
	}else{
		return a;
	}
}

int Employee::salary_raise(int salary)
{
	salary=salary+(salary*10)/100;
	return salary;
}

void menu()
{
	system("cls");
	cout<<endl;
	cout<<" New Employee ------------------------- 1"<<endl;
	cout<<" Show Employees ----------------------- 2"<<endl;
	cout<<" 10% salary raise to all -------------- 3"<<endl;
	cout<<" Delete Employee ---------------------- 4"<<endl;
	cout<<" Close -------------------------------- 0"<<endl<<endl;
	cout<<" CHOICE: ";
}

Employee newemployee();
void print_employees(vector <Employee> employees);
vector <Employee> delete_employee(vector <Employee> employees);

int main()
{
system("color f1");
	int choose;
	vector <Employee> employees;
	while(true)
	{
		menu();
		cin>>choose;
		cout<<endl;
		
		if (choose==1)
		{
			employees.push_back(newemployee());
			cout<<endl;
		}
		
		if (choose==2)
		{
			print_employees(employees);
		}
		
		if (choose==3)
		{
			for(int i=0; i<employees.size(); ++i)
			{
				employees[i].setsalary(employees[i].salary_raise(employees[i].getsalary()));
			}
			
			if (employees.size()!=0)
			{
				cout<<" *** SALARY RAISE WAS SUCCESSFUL ***"<<endl<<endl;
			}
			print_employees(employees);
		}
		
		if (choose==4)
		{
			employees=delete_employee(employees);
		}
		
		if (choose==0)
		{
			break;
		}
		
		if ((choose!=0)&&(choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4))
		{
			cout<<" @@@ ERROR: WRONG CHOICE @@@ "<<endl<<endl;
		}
		
 	system("pause");
	}
system("pause");
}

Employee newemployee()
{
    string firstname,lastname;
	int salary;
	Employee emp(firstname,lastname,salary);
	
	cout<<" GIVE FIRSTNAME: ";
	cin>>firstname;
	emp.setfirstname(firstname);
	
	cout<<" GIVE LASTNAME: ";
	cin>>lastname;
	emp.setlastname(lastname);
	
	cout<<" GIVE SALARY: ";
	cin>>salary;
	emp.setsalary(salary);
	
	return emp;
}

void print_employees(vector <Employee> employees)
{
	if (employees.size()==0)
	{
		cout<<" @@@ NO EMPLOYEES REGISTERED YET @@@"<<endl<<endl;
	}else{
		for(int i=0; i<employees.size(); ++i)
		{
			cout<<" ---- Employee "<<(i+1)<<" ----"<<endl;
			cout<<" Firstname : "<<employees[i].getfirstname()<<endl;
			cout<<" Lastname  : "<<employees[i].getlastname()<<endl;
			cout<<" Salary    : "<<employees[i].getsalary()<<endl<<endl;
		}
	}
}

vector <Employee> delete_employee(vector <Employee> employees)
{
	int choose,i;
    cout<<" EMPLOYEES: "<<employees.size()<<endl;
	print_employees(employees);
	
	while(true)
	{
		cout<<" CHOOSE EMPLOYEE TO DELETE: ";
		cin>>choose;
		cout<<endl;
		if ((choose>=1)&&(choose<=employees.size()))
		{
			i=choose-1;
			break;
		}else{
            cout<<" @@@ ERROR: WRONG CHOICE @@@ "<<endl<<endl;
		}
	}
	
	employees.erase(employees.begin()+i,employees.begin()+i+1);
	
	print_employees(employees);
	return employees;
}
