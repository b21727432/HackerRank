#include<iostream>
#include<string>

using namespace std;

class Student{
	int id;
	string name;
	double gpa;
	int year;
	char gender;
	public:
		Student(int id, string name, double gpa, int year, char gender){
			this->id = id;
			this->name = name;
			this->gpa = gpa;
			this->year = year;
			this->gender = gender;
		}
		Student(){
			
		}
		void setId(int id){
			this->id = id;	
		}
		int getId(){
			return this->id;
		}
		void setName(string name){
			this->name = name;	
		}
		string getName(){
			return this->name;
		}
		void setGpa(double gpa){
			this->gpa = gpa;	
		}
		double getGpa(){
			return this->gpa;
		}
		void setYear(int year){
			this->year = year;	
		}
		int getYear(){
			return this->year;
		}
		void setGender(char gender){
			this->gender = gender;	
		}
		char getGender(){
			return this->gender;
		}
		friend istream &operator>>(istream  &input, Student &s) {
			cout << "enter student information (ID, name, gpa, year, gender)" << endl;
	
			input >> s.id;
			input >> s.name;
			input >> s.gpa;
			input >> s.year;
			input >> s.gender;
			
        	return input;
      	}
      	friend ostream &operator<<(ostream& output, const Student &s) {
        	output << "Student ID: " << s.id << ", Name: " << s.name << endl;
      	}
      	Student operator >=(const Student& s){
      		if(this->getGpa() > s.gpa){
      			return *this;
			} else {
				return s;
			}	
		}
		void topOfClass(Student s1, Student s2, Student s3, Student s4, Student s5);
      	
};

void Student::topOfClass(Student s1, Student s2, Student s3, Student s4, Student s5){
	Student winner = s1>=s2;
	winner = winner>=s3;
	winner = winner>=s4;
	winner = winner>=s5;
	cout << "Highest GPA belongs to " << winner.getName() << ": " << winner.getGpa();
}


int main(){
	
	Student s1(1, "Harry Potter", 3.4, 2, 'm');
	Student s2(2, "Hermione Granger", 3.8, 2, 'f');
	Student s3(3, "Ron Weasley", 3.1, 2, 'm');
	Student s4(4, "Draco Malfoy", 2.9, 2, 'm');
	
	
	Student newStudent;
	cin >> newStudent;
	
	cout << s1;
	cout << s2;
	cout << s3;
	cout << s4;
	cout << newStudent;
	
	newStudent.topOfClass(s1, s2, s3, s4, newStudent);
	
	
	return 0;
}
