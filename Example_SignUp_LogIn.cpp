#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
//If you use namespace std; just remove all of the std:: calls prior to specific code.
// This is ONE approach (out of many) on how to do the sign-up + log-in system.
// You can use arrays for update, delete and search, for those not familiar with vectors or C++ arrays
// It will be up to you if you want to use functions.


//programmed in around 20 minutes as of May 9;

//file streams (using CCS102 convention)
std::fstream writeFile;
std::fstream readFile;

//global variables
bool signup_run=true;
bool login_run=false;
int signup_choice;
int foo_btn;
std::string input_user, read_user;
std::string input_pass, read_pass;


int main(){

	readFile.open("users.txt", std::ios::in);
		if(!readFile.is_open()){
			std::cout << "No existing file detected." << std::endl;
		}else{
			std::cout << "Existing file detected." << std::endl;
		}
	readFile.close();
	system("PAUSE");
	system("CLS");
	
	
	do{
	system("CLS");
	std::cout << "1. Sign up" << std::endl;	
	std::cout << "2. Log-in" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cin >> signup_choice;
	
	switch(signup_choice){
		
		case 1:{
			std::cin.ignore(); //this line is to prevent the cin stream from interfering with getline() functions;
			writeFile.open("users.txt", std::ios::app); //use std::ios::out if you want to overwrite the entire file
			std::cout << "\n\n";
			
			std::cout << "Input new username: ";
			getline(std::cin, input_user);
			std::cout << "Inpue new password: ";
			getline(std::cin, input_pass);
			
			writeFile << input_user << std::endl;
			writeFile << input_pass << std::endl;
			
			writeFile.close();
			std::cout << "User registered!";
			system("PAUSE");
			break;
		}
		
		case 2:{
			std::cin.ignore();
			
			readFile.open("users.txt", std::ios::in);
			if(!readFile.is_open()){
				std::cout << "\nNo Existing file found, please sign up first.\n";
				readFile.close();
				break;
			}
			std::cout << "Input username: ";
			getline(std::cin, input_user);
			
			std::cout << "Input password: ";
			getline(std::cin, input_pass);
			
			
			bool user_found = false;
			
			while(getline(readFile, read_user)){
				if(read_user==input_user){
					getline(readFile, read_pass);
					if(read_user==input_user && input_pass==read_pass){
						std::cout << "User found!" << std::endl;
						signup_run=false;
						login_run=true;
						user_found=true;
						break;
					}
				}
			}
			
			if(user_found==false){
				std::cout << "\nUser not found.\n";
			}
			
			system("PAUSE");
			readFile.close();
			break;
		}
		
		case 3:{
			return 0;
			break;
		}
		
		default: {
			
			break;
		}

	}
			
		
	}while(signup_run==true);
	
	system("CLS");
	do{
	
		std::cout << "Do/implement your main stuff here!" << std::endl;
		std::cout << "Button 1" << std::endl;
		std::cout << "Button 2" << std::endl;
		std::cout << "Button 3" << std::endl;
		std::cout << "Button 4: Exit" << std::endl;
		std::cout << "Input button [0 to exit]: ";
		std::cin >> foo_btn;
			if(foo_btn==0){
				return 0;
			}
		system("CLS");
		
		switch(foo_btn){
			case 1:{
				std::cout << "Never gonna give you up" << std::endl;
				std::cout << "Never gonna let you down" << std::endl;
				std::cout << "\n\n";
				break;
			}
			case 2:{
				std::cout << "Never gonna run around and desert you" << std::endl;
				std::cout << "Never gonna make you cry" << std::endl;
				std::cout << "\n\n";
				break;
			}
			case 3:{
	
				std::cout << "Never gonna say goodbye" << std::endl;
				std::cout << "Never gonna tell a lie and hurt you" << std::endl;
				std::cout << "\n\n";
				break;
			}
			case 4:{
				return 0;
				break;
			}
			
			default: {
	
				break;
			}
				
		}
		
	}while(login_run==true);
	
	
	return 0;
}




