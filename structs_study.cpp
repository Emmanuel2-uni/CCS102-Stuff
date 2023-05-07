#include <iostream>
#include <iomanip>
#include <string>
#include <vector> 


//
//My own demonstration and study of structs (also called objects) for better data containers and emplace_back
//
// source and reading material:
// https://en.cppreference.com/w/cpp/container/vector/emplace_back
//
// https://stackoverflow.com/questions/60473710/c-emplace-back-vs-push-back-vector
//


//structs are public instances by default, classes are not.
struct employee{
	std::string employee_name;
	std::string employee_position;
	float employee_salary;
	
};

employee employee1;



int main(){
	employee1.employee_name = "Yo";
	std::cout << employee1.employee_name;
	

	return 0;
	
}