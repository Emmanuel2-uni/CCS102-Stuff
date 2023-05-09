#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
//If you use namespace std; just remove all of the std:: calls prior to specific code.


bool run_randomize = true;
std::string btn;
int randomize_number();
int main(){
	
	
	do{
		
		std::cout << "Random four-digit int: " << randomize_number() << std::endl;
		std::cout << "Input anything to generate a new four-digit number [0 to exit]: ";
		std::cin >> btn;
			if(btn=="0"){
				run_randomize=false;
				return 0;
			}
		system("CLS");
	}while(run_randomize==true);
	
	

}

int randomize_number(){
		int random_fourdigit;
		
		std::random_device rd; //declare a random device "rd"
		//std::default_random_engine rand(rd()); //opinion: not "random" enough.
		
		std::mt19937 rand(rd()); //opinion: decently "random". This declares/makes a new "seed" on runtime with the name "rand" based on the random device on runtime
		
		std::uniform_int_distribution<int> random_number(10000, 99999); //for uniform distribution of the results.
			// declare uniform_real_distribution if you want something for float
			// just to make sure, inside the angle brackets <>, declare the data type you want
		
		
		random_fourdigit = random_number(rand);
					//random_number(x, y) is declared in the distribution code: line 22
					//rand is the "seed" declared in line 21, do NOT forget this parameter.
					
		return random_fourdigit;
		
}
