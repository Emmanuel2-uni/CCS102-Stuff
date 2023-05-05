#include <iostream>
#include <vector>
#include <string>

using namespace std;


string input_string;
vector<string> names;

int main(){
	getline(cin, input_string);
	names.push_back(input_string);
	
	cout << names[0];
	return 0;	
}