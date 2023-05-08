#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>

//streams
std::ofstream writeName;
std::ifstream readName;


//functions
void _writeList(int switch_choice);
void _readList();
void _removeName();
void _searchName();
void _randomizeAndPick5();
	//trying out a new naming convention. Apparently, this should be avoided in c++. 


//global variables/declarations
std::string input_name;
std::vector<std::string> tempNames_vector;
std::vector<std::string> tempWinners_vector;
int random_number;
int run=1;
int ch;
int num_position;


//main
int main(){
	//read the list first, if it exists.
	readName.open("names.txt");
		if(readName.is_open()){
			std::cout << "!!! Existing names list detected. !!!\n\n";
			system("PAUSE");
			system("CLS");
			}
		else{
			std::cout << "!!! No existing names list detected. !!!\n\n";
			std::cout << "!!! Please input names below first !!!\n\n";
			_writeList(0);
			system("PAUSE");
			system("CLS");
			}
			
		readName.close();
		
	
	
	
	do{
		//menu
		std::cout << "========Menu========\n\n";
		std::cout << "1. Overwrite name file" << std::endl;
		std::cout << "2. List name" << std::endl;
		std::cout << "3. Add name" << std::endl;
		std::cout << "4. Remove name" << std::endl;
		std::cout << "5. Search name\n" << std::endl;
		
		std::cout << "6. Randomize and pick 5 names.\n" << std::endl;
		std::cout << "7. Exit.";
		
		std::cout << "\n\nEnter choice: ";
		std::cin >> ch;
	
		switch(ch){ //start of switch case
		
			//case 1
			case 1:
				{
					std::cin.ignore(256, '\n');
						_writeList(ch);
					system("CLS");
					break;
				}
				
			//case 2
			case 2:
				{
					std::cin.ignore(256, '\n');
					system("CLS");
					std::cout << "List of names: \n\n";
						_readList();
					std::cout << "\n\n";
					break;
					
				}
				
			//case 3
			case 3:
				{
					system("CLS");
					std::cin.ignore(256, '\n');
					
					std::cout << "List of names: \n\n";
						_readList();
					std::cout << "\n\n";
					
					
					_writeList(ch);
					
					
					system("CLS");
					std::cout << "List of names: \n\n";
						_readList();
					std::cout << "\n\n";
					
					break;
				}
				
			//case 4
			case 4:
				{
					system("CLS");
					std::cin.ignore(256, '\n');
					
					std::cout << "List of names: \n\n";
						_readList();
					std::cout << "\n\n";
				
					_removeName();
					system("PAUSE");
					system("CLS");
					std::cout << "List of names: \n\n";
						_readList();
					std::cout << "\n\n";
					break;
				}
				
			//case 5
			case 5:
				{
					system("CLS");
					std::cin.ignore(256, '\n');
					std::cout << "List of names: \n\n";
						_readList();
					std::cout << "\n\n";
					
					_searchName();
					break;
				}
			
			//case 6
			case 6:
				{
					system("CLS");
					std::cin.ignore(256, '\n');
					std::cout << "List of winners: \n";
					_randomizeAndPick5();
					std::cout << "List of winners: \n";
					
					for(int i=0; i<5; i++){
						std::cout << "Draw " << i+1 << ": " << tempWinners_vector[i] << std::endl;
					}
					
					std::cout << "\n\n";
					
					break;
				}
			
			//case 7
			case 7:
				{
					run=0;
					return 0;
				}
	
	
		}//end of switch case
	
	
		
	}while(run==1); //end of do-while
	
	
	
	return 0;
}



//functions
void _randomizeAndPick5(){
	
	tempNames_vector.clear();
	tempWinners_vector.clear();
	
	readName.open("names.txt");
	while(getline(readName, input_name)){
		tempNames_vector.push_back(input_name);
	}
	readName.close();
	
	
			std::random_device rd;
			//std::default_random_engine rand(rd()); //opinion: not "random" enough.
			std::mt19937 rand(rd()); //opinion: decently "random".
			std::uniform_int_distribution<> pick_five(0, tempNames_vector.size()-1); //for uniform distribution.
			//reference: https://en.cppreference.com/w/cpp/numeric/random
	
			for(int i=0; i<5; i++){
				tempWinners_vector.push_back(tempNames_vector[pick_five(rand)]);
				std::cout << "Draw " << i+1 << ": " << tempWinners_vector[i] << std::endl;
			}
			
	std::cout << "\n";
	system("PAUSE");
	system("CLS");
}


void _searchName(){
	std::string string_searchName;
	tempNames_vector.clear();
	
	readName.open("names.txt");
	while(getline(readName, input_name)){
		tempNames_vector.push_back(input_name);
	}
	readName.close();
	
	
	std::cout << "Input name to search for [Case Sensitive]: ";
	getline(std::cin, string_searchName);
	
	for(int i=0; i<tempNames_vector.size(); i++){
		if(tempNames_vector[i]==string_searchName){
			std::cout << "\nThe name " << string_searchName << " is found and is at position " << i+1 << " on the list.\n\n";
		}
	}
}

void _writeList(int switch_choice){
	
	int run_write=1;
	
	
	
	//choice 0 -- start of program without presence of names.txt
	//choice 1 -- overwrite
	if(switch_choice==0 || switch_choice==1){
	writeName.open("names.txt");
	
		do{
			std::cout << "Enter name [0 to exit]: ";
			getline(std::cin, input_name);
			if(input_name=="0"){
				run_write=0;
				break;
				}
			writeName << input_name << std::endl;
			
		}while(run_write=1);	
	writeName.close();
	}
	
	
	//choice 3, add/append name;
	if(switch_choice==3){
	writeName.open("names.txt", std::ios::app);
	
		do{
			system("CLS");
			_readList();
			std::cout << "\nEnter name [0 to exit]: ";
			getline(std::cin, input_name);
			if(input_name=="0"){
				run_write=0;
				break;
				}
			writeName << input_name << std::endl;
			
		}while(run_write=1);	
	writeName.close();
	}
	
	
	//choice 999
	//  !!! ONLY FOR Overwriting after removing a name !!!
	if(switch_choice==999){
	writeName.open("names.txt", std::ios::out);
		for(int i=0; i < tempNames_vector.size(); i++){
			writeName << tempNames_vector[i] << std::endl;
		}
	writeName.close();
	}
	
}


void _readList(){
	num_position=0;
	readName.open("names.txt");
	
	while(getline(readName, input_name)){
		num_position+=1;
		std::cout << num_position << ". " << input_name << std::endl;
	}
	
	readName.close();
	
}


void _removeName(){
	std::string string_removeName;
	int flag_remove=0;
	
	tempNames_vector.clear();
	
	readName.open("names.txt");
	while(getline(readName, input_name)){
		tempNames_vector.push_back(input_name);
	}
	readName.close();
	
	std::cout << "Input name to delete [Case Sensitive]: ";
	getline(std::cin, string_removeName);
	for(int i=0; i < tempNames_vector.size(); i++){
		if(tempNames_vector[i]==string_removeName){
			tempNames_vector.erase(tempNames_vector.begin()+i); 
			//iterator .begin() + i will point to the exact vector element to erase
			flag_remove=1;
		}
	}
	
	std::cout << "\n\n";
	if(flag_remove=1){
		std::cout << string_removeName << " is found on the list and has been removed.";
	}else{
		std::cout << string_removeName << " does not exist on the list (or not in Exact Case).";
	}
	std::cout << "\n";
	_writeList(999);
}
