#include <iostream>
#include <vector>
using namespace std;

struct Employee
{
	string name;
	short age;
	int salary;
	char gender;
};

// Database -> Vector of Employees
vector<Employee>data;

void addNewEmployee(){
	Employee newE;
	cout<<"Enrter the name\n";
	cin>>newE.name;
	cout<<"Enrter the age\n";
	cin>>newE.age;
	cout<<"Enrter the salary\n";
	cin>>newE.salary;
	cout<<"Enrter the gender (M/F)\n";
	cin>>newE.gender;
	data.push_back(newE);
}

void printAll(){
	if(data.size()==0){
		cout<<"There is no employees in the database\n";
		return;
	}
	cout<<"\nName\t\tAge\t\tSalary\t\tGender\n";
	for(Employee e : data){
		cout<<e.name<<"\t\t"<<e.age<<"\t\t"<<e.salary<<"\t\t"<<e.gender<<"\n";
	}
}

void deleteByAge(){

	if(data.size()==0){
		cout<<"There is no employees in the database\n";
		return;
	}

	int startAge,endAge ;
	cout<<"Enter start age\n";
	cin>>startAge ;
	cout<<"Enter end age\n";
	cin>>endAge;

	for(int i=0;i<data.size();i++){
		if(data[i].age>=startAge && data[i].age<=endAge){
			data.erase(data.begin()+i);
		}
	}

}

void updateSalary(){

	if(data.size()==0){
		cout<<"There is no employees in the database\n";
		return;
	}

	cout<<"Enter the name you want to update his salary\n";
	string name;
	cin>>name;
	bool found = false;
	for(int i=0;i<data.size();i++){
		if(data[i].name == name ){
			int newSalary;
			cout<<"Enter the new salary\n";
			cin>>newSalary;
			data[i].salary = newSalary;
			found = true;
			break;
		}
	}
	if(found ==  false){
		cout<<"The name you entered is not exist\n";
	}
}

void employeesManageSystem(){
	while(true){
		printf("\n\t\t\t----------------------------------------\n");
		printf("\t\t\t This is an employees mangement program\n");
		printf("\t\t\t----------------------------------------\n");
		printf("Enter your choice : \n");
		printf("To add new employee press 1 \n");
		printf("To pint all employees press 2 \n");
		printf("To Delete by age press 3 \n");
		printf("To Update salary by name press 4 \n");
		printf("To Exit press 0 \n");

		int choice ;
		cin>>choice;

		if(!choice>=0 &choice<=4){
			cin.clear();
			cin.ignore(0,10000000);
			cout<<"Invalid input\n";
		}

		switch (choice){
			case 1:
			addNewEmployee();
			break;
			case 2:
			printAll();
			break;
			case 3:
			deleteByAge();
			break;
			case 4:
			updateSalary();
			break;
			case 0:
			return ;
			default :
			cout<<"Invalid Choice \n";
		}
}

}
int main(){

	// This project to manage employees in a factory version 1.0
	/*
		Display Choices 
		Enter your choice
		1- Add new employee
		2- Print all employees
		3- Delete by age
		4- Update salary by name
		0- Exit
	*/

	employeesManageSystem();	

	return 0;
}
