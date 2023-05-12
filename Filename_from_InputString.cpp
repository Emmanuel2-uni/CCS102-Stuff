#include <iostream>
#include <string>
#include <fstream>


int main(){
	std::string filename; 
	
	getline(std::cin, filename);

	
	filename.append(".txt");
	std::cout << filename << " file created.";
	
	std::ofstream write_text;
	write_text.open(filename.c_str());
	
	//alternatively, and is way easier:
	// write_text.open(filename);
	
	write_text.close();
}
