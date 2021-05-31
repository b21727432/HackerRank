#include<iostream>
#include "RedBlackTree.h"	

// This is my employee class to store intances of employes i will create
// and store in red black tree. I store the registration number, department id and phone number.
// i have 3 different constructors for every case to find in wanted employee and to insert the employee
// to the tree.
class Employee{
	public:
		int reg_number;
		int department_id;
		int phone_number;
		Employee(int register_number, int derpartment, int phone){
			reg_number = register_number;
			department_id = derpartment;
			phone_number = phone;
		}
		Employee(){
			
		}
		Employee(int number){
			reg_number = number;
		}
};

using namespace std;

int main(){
	// here i am creating the instances of red black tree with template class employee
	RedBlackTree<Employee> rbt;
	
	// here i am creating objects of employee class with their constructor which takes 3 numbers
	Employee employee1(1001, 51, 6467);
	Employee employee2(1002, 43, 2359);
	Employee employee3(1010, 34, 4342);
	Employee employee4(1008, 21, 6761);
	Employee employee5(2001, 45, 2345);
	Employee employee6(2006, 23, 6862);
	
	// i m adding the employee objects i have created above to the red black tree
	rbt.InsertNode(employee1);
	rbt.InsertNode(employee2);
	rbt.InsertNode(employee3);
	rbt.InsertNode(employee4);
	rbt.InsertNode(employee5);
	rbt.InsertNode(employee6);
	
	// this loop works until user says n to the continue question
	while(1){
		cout << "Enter Employee's Registiration Number : ";
		int number;
		cin >> number;
		// here i m searching in the tree, if the search return null it means the employee is not in the system		
		if(rbt.AccessNode(number) == NULL){
			// if not found ask if user wants to add this employee to the tree
			cout << "Employee not found !" << endl;
			cout << "Dou you want to add this employee to the system ? (y/n) : ";
			char ekleme;
			cin >>  ekleme;
			if(ekleme == 'y'){
				// if the answer is yes, add this to the tree
				cout << "What is the department id and internal phone number? : ";
				int id;
				int phone;
				cin >> id >> phone;
				// create the new employee object and add it
				Employee newemployee(number, id, phone);
				rbt.InsertNode(newemployee);
				cout << "Added succesfully" << endl;
			} else if(ekleme == 'n'){
				// if the answer is no simply do nothing and continue
				continue;
			}
			else{
				cout << "Enter valid operation!!!" << endl;
			}
		} else{
			// if the return is not null, that means employee exist, print the attributes of employee
			Employee x = rbt.AccessNode(number)->GetValue();
			cout << "Department id is : " << x.department_id << " Internal phone number is : " << x.phone_number << endl; 
		}
		// ask if user wants to continue, if yes continue , if no simply exit from the program
		char devam;
		cout << "Continue (y/n) : ";
		cin >> devam;
		if(devam == 'y'){
			continue;
		} else if(devam == 'n'){
			cout << "Bye";
			break;
		}
		else{
			cout << "Enter valid operation!!!" << endl;
		}
		
	}
	
	return 0;
}
