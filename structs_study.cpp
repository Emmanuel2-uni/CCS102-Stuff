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
	
	employee(std::string name, std::string position, float salary):	
		employee_name(name),
		employee_position(position),
		employee_salary(salary)
	{}
	//these declarations allow the constructor to "construct" the object as this can be seen as a *function* inside the struct/class.
	//{} the brackets at the end are needed.
};

std::vector<employee> employee_Details;




int main(){
	
	employee_Details.emplace_back("Emmanuel", "Entry", 100); //0
	employee_Details.emplace_back("Jake", "Entry", 200); //1
	employee_Details.emplace_back("Max", "Entry", 400); //2
	
	if(employee_Details[0].employee_salary < employee_Details[2].employee_salary){
		employee_Details[0] = employee_Details[2];
	}
	
	//employee_Details[0] = employee_Details[1];
	
	std::cout << employee_Details[0].employee_name << "      " << employee_Details[0].employee_salary;
	return 0;
	
}