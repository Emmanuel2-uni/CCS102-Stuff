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
	//These declarations allow the constructor to "construct" the object as this can be seen as a *function* inside the struct/class.
	// With the current parameters: name, position, and salary -- whenever we use a proper STL function like emplace_back, we can update all of the parameters
	// simultaneously without having to use backups or additional overhead/declarations.
	//
	// Example: if the struct's member called "employee_name" is called i.e employee 
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
	std::cout << std::endl;
	employee_Details.erase(employee_Details.begin()+1);
	std::cout << employee_Details[1].employee_name << "      " << employee_Details[1].employee_salary << std::endl;
	std::cout << employee_Details.size();
	return 0;
	
}
