#include<iostream>
#include<vector> //for vectors
#include<iomanip>
#include<fstream>
#include<random>

//functions
void displayGuessing(int flag); //flag 1 for just displaying, flag 2 for checking the input letter then updating the blanked out word.
void debug_displayWord();
void draw_Stickman();
void obsoletecode(); //for documenting previous code that are now obsolete.
void importwordlist(int flag);

//declarations/variables
std::vector<char> vector_word; //vectors without any declared size or elements will start with nothing. Push_back is recommended to populate list.
std::vector<char> blank_word;
std::string string_word;
std::random_device rd;
char letter;
int random;

//flags
int countfail=0;
int flagrungame=0, flagnewword=0;	
int count_success=0;
int count_fail=0;
int found=0;
int new_game=0;

//for inputting new words and imports
std::ifstream import;
std::ofstream write_new_list;
std::string new_word;
int maxentry;


//main start
int main(){
	importwordlist(1);
	
	
	while(flagnewword==0){ //start while new word
		//string_word = entry_word[random];
		//std::default_random_engine (random_num);
		//importwordlist(2);
	
		system("CLS");
		vector_word.clear();
		std::cout << "Input new word: ";
		//std::cin >> string_word;
		std::cout << "Size of the word is: " << string_word.size() << "\n";	
	
	

	
		std::copy(string_word.begin(), string_word.end(), std::back_inserter(vector_word));
	
		for(int i=0; i<string_word.size(); i++){
			vector_word[i] = std::tolower(vector_word[i]);
			}
			
		//
		//  Read: https://cplusplus.com/reference/string/string/copy/
		//  This will copy the string in [string_word]. 
		// 	Template: .copy(x, y, z)
		// 	Where x = name of array to copy to.
		// 	Where y = length of characters.
		// 	Where z = starting position of the copying function (0 starts at the very first letter).
		//
		// Optional further reading: 
		//	https://en.cppreference.com/w/cpp/string/basic_string/c_str
		//	https://stackoverflow.com/questions/8263926/how-to-copy-stdstring-into-stdvectorchar
		//
		
	
	
	
		std::cout << "\n\n";


	
		//shows the letters stored in the array
		debug_displayWord();
	
	
		//output number of _;
		std::cout << "\n\n";
			for(int i=0; i<vector_word.size(); i++){
				std::cout << "_ ";
			}
		flagrungame=0;
		flagnewword=1;
	} //end while new word
	
	
	
	
	//check letters that are input; start of actual game
	std::cout << "\n\n";
	
	
		
		while(flagrungame==0){	//start while run
			system("CLS");		//remove this line to keep track of inputs
			std::cout << "DEBUG: Word number " << random+1 << ".\n";
			draw_Stickman();
			
			std::cout << 5-count_fail << " guesses/tries left.";
			std::cout << "\nCurrent word progress: ";
			displayGuessing(1);
			
			std::cout << "\n\nEnter letter: ";
			std::cin >> letter;
			letter = std::tolower(letter);

			
			if(letter=='1'){
				flagrungame=1;
				flagnewword=0;
				return main();
				}
			displayGuessing(2);
			
		}//end while run
	
	system("CLS");
	
	std::cout << "\n\nEnd result is: "; 
	displayGuessing(1);
	std::cout << "\nFull word is: ";
	debug_displayWord();
	
	std::cout << "\n\n";
	draw_Stickman();
	
	
	return 0;
}
//main end



void displayGuessing(int flag){

	
	if(flag==1){
		for(int i=0; i<vector_word.size(); i++){
				blank_word.push_back('a');
				std::cout << blank_word[i];
				std::cout << "   " << vector_word.size();
			}
	}

	if(flag==2){
		found = 0;
		for(int i=0; i<vector_word.size(); i++){
			//these lines will check if the letter input will correspond to any of the letters inside vector_word.
			//additional condition (&& blank_word[i]!=letter) is added so that if the input is a previous success (aka no longer blank), then it will no longer count up towards success.
			if( vector_word[i]==letter && blank_word[i]!=letter ){
				blank_word[i] = letter;
				count_success++;
				found=1;
					if( count_success == vector_word.size()){
						flagrungame=1;
					}//		
			}	//
			
			//std::cout << blank_word[i] << " ";
		}//
		
		if(found==0){
			count_fail++;
			if(count_fail==5){
				flagrungame=1;
			}//
		}//
	}//
	
}


void draw_Stickman(){
	switch(count_fail){
	case 0:
	{
		std::cout << std::left << std::setw(1) << "===l\n";
		std::cout << std::left << std::setw(5) << "   O";
		std::cout << "\n\n";
		break;
	}
	
	case 1:
	{
		std::cout << std::left << std::setw(1) << "===l\n";
		std::cout << std::left << std::setw(5) << "   O";
		std::cout << std::left << std::setw(5) << "\n   |" ;
		std::cout << "\n\n";
		break;
	}
	
	case 2:
	{
		std::cout << std::left << std::setw(1) << "===l\n";
		std::cout << std::left << std::setw(5) << "   O";
		std::cout << std::left << std::setw(5) << "\n  /|" ;
		std::cout << "\n\n";
		break;
	}
	
	case 3:
	{
		std::cout << std::left << std::setw(1) << "===l\n";
		std::cout << std::left << std::setw(5) << "   O";
		std::cout << std::left << std::setw(5) << "\n  /|\\" ;
		std::cout << "\n\n";
		break;
	}
	
	case 4:
	{
		std::cout << std::left << std::setw(1) << "===l\n";
		std::cout << std::left << std::setw(5) << "   O";
		std::cout << std::left << std::setw(5) << "\n  /|\\" ;
		std::cout << std::left << std::setw(5) << "\n  / ";
		std::cout << "\n\n";
		break;
	}
	
	case 5:
	{
		std::cout << std::left << std::setw(1) << "===l\n";
		std::cout << std::left << std::setw(5) << "   O";
		std::cout << std::left << std::setw(5) << "\n  /|\\" ;
		std::cout << std::left << std::setw(5) << "\n  / \\";
		std::cout << "\n\n";
		break;
	}
	
	
	
	}//
	
}




void importwordlist(int flag){

import.open("hangmanwords.txt");

	if(import.is_open()){
		import >> maxentry;
		std::vector<std::string> entry_word(maxentry);
	
		for(int i=0; i<=maxentry; i++){
			import >> entry_word[i];
		}
	
		import.close();
			std::default_random_engine e(rd());
			std::uniform_int_distribution<> random_num(0, maxentry);
			random = random_num(e);
			string_word = entry_word[random];
		 

		flag=2;
	}
	
	else{
		import.close();
		std::vector<std::string> entry_word(maxentry);
		
		write_new_list.open("hangmanwords.txt");
		for(int i=0; i<=maxentry; i++){
			//system("CLS");
			std::cout << "\nInput word [Write NONE to be done] " << maxentry+1 << ": ";
			std::cin >> new_word;
			maxentry++;
			if(new_word=="NONE"){
				maxentry--;
				break;
			}
			entry_word.push_back(new_word);
		}
		
		write_new_list << maxentry << "\n";
		
		for(int i=0; i<=maxentry; i++){
			write_new_list << entry_word[i] << "\n";
		}
		write_new_list.close();
		flagnewword=1;
		flagrungame=1;
	}
}	





void debug_displayWord(){
	
	for(int i=0; i<string_word.size(); i++){
		std::cout << vector_word[i];
	}	
	
}


void obsoletecode(){
		//
		// ======  ORDER OF WRITING CODE IS IMPORTANT ======
		// 	If cin >> string_word comes last, then the array will not have a size.	
		//  Dynamic sizing of the array that is dependent on the length of the string entered.
		//  Example: 
		// 		input == "Hello"
		//		output == 5 ; since there are 5 letters in the word "Hello"
		//		array_word will now have a size of 5.
		//
	
	//1
	/*
	for(int i=0; i<string_word.size(); i++){
		//std::cin >> letter;
		letter = tolower(vector_word[i]);
		vector_word.push_back(letter);
	}
	*/
	
	//2 
	/*
	string_word.copy(array_word, string_word.size(), 0);
	*/
	
	//char array_word[string_word.size()] = {0};
	
	/*
				else{
				countfail++;
				if(countfail==vector_word.size()){
					flagrungame=1;
					flagnewword=0;
				}
			}
	*/
	
	
	/*
			for(int i=0; i<string_word.size(); i++){
				
				if( vector_word[i]==letter ){
					std::cout << "\nSuccess!";
				}
					
			}
	*/
			
}


