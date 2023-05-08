#include <random>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

int main(){
		bool repeat=true;
		std::string btn;
		
			std::random_device rd;
			std::mt19937 rand(rd());
			std::uniform_real_distribution<float> stock(-1, 1); //for uniform distribution.
			//reference: https://en.cppreference.com/w/cpp/numeric/random
			
			
			do{
				system("CLS");
				std::cout << "Randomized number: " << std::setprecision(4) << std::fixed << stock(rand) << std::endl;
				std::cout << "Input anything to generate a new number: ";
				std::cin >> btn;
				if(btn=="0"){
					repeat=false;
					return 0;
				}
				
			}while(repeat==true);	
			
			
	return 0;
			
}
