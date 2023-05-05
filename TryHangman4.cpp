#include<iostream>
#include<vector> //for vectors
#include<cctype> //to be able to replicate case insensitivity

void inputWord();
void displayWord();

//std::vector<char> vector_word;
std::vector<char> vector_word;
std::string string_word;
char letter;

int main(){
	

int run=0;	
	
	

	std::cin >> string_word;
	std::cout << "Size of the word is: " << string_word.size() << "\n";	
	//char array_word[string_word.size()] = {0};
	
	
	
	//
	// ======  ORDER OF WRITING CODE IS IMPORTANT ======
	// 	If cin >> string_word comes last, then the array will not have a size.	
	// Dynamic sizing of the array that is dependent on the length of the string entered.
	// Example: 
	// 		input == "Hello"
	//		output == 5 ; since there are 5 letters in the word "Hello"
	//		array_word will now have a size of 5.
	//
	
	
	//string_word.copy(array_word, string_word.size(), 0);
	std::copy(string_word.begin(), string_word.end(), std::back_inserter(vector_word));
	
	//
	// Read: https://cplusplus.com/reference/string/string/copy/
	// This will copy the string in [string_word]. 
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


	
	for(int i=0; i<string_word.size(); i++){
		//std::cin >> letter;
		letter = tolower(vector_word[i]);
		vector_word.push_back(letter);
	}
	
	
	std::cout << "The letters in the array are: \n";
	for(int i=0; i<string_word.size(); i++){
		std::cout << vector_word[i] << " ";
	}
	
	
	
	std::cout << "\n\n";
	for(int i=0; i<vector_word.size(); i++){
		std::cout << "_ ";
	}
	
	std::cout << "\n\n";
	
		while(run==0){
			
			std::cout << "\n\nEnter letter: ";
			std::cin >> letter;
			letter = tolower(letter);
			
			for(int i=0; i<string_word.size(); i++){
				if( vector_word[i]==letter ){
					std::cout << "\nSuccess!";
					}
			}
		
		
		
		}
	

	
	
	return 0;
}