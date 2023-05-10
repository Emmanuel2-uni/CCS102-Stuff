#include <iostream>
#include <string>
#include <vector> 


using namespace std;

int main(){
	string search = {"abc"};
	vector<char> vector_search;
	std::copy(search.begin(), search.end(), std::back_inserter(vector_search));
	
	
	cout << search << endl;
	for(int i = 0; i<vector_search.size(); i++){
	
	cout << vector_search[i];
	}
	
	
	return 0;
}