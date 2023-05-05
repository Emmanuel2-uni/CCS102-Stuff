#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void _CharCompare();
void _SuccessStrength();
void _ShowNames();
int _CharSize(char name[]);

	string search;
	int first, second;
	int flag;
	int pointer=0;
	int i;
	int success[3];
	
	char name[5][10] = {"Elgene", "ten", "en", "tenten", "gene"};
	vector<char> vector_search;
	

int main(){

	

	_ShowNames();
	
	cout << "\nSearch term: ";
	cin >> search;
	
	std::copy(search.begin(), search.end(), std::back_inserter(vector_search));
	
	while(i<5){
	_CharCompare();
	
	
	i++;
	}
	
	_SuccessStrength();
	
	return 0;
}




//Approach 1: compare each character of input to each letter of each word.
//Approach 2: compare word input to one word at a time.
//Approach 3:
//Approach 4: Using success "Strength"


void _CharCompare(){
	
	for(int pointer=0; pointer<vector_search.size(); pointer++){
	
		for(int j=0; j<10; j++){
			if(   (vector_search[pointer]==name[i][j] && vector_search[pointer+1]==name[i][j+1])  && (vector_search[pointer-1]==name[i][j-1] && vector_search[pointer]==name[i][j])  ){
				//cout << "Found letter " << vector_search[j] << " in " << i << " " << j << "\n";
				success[i]++;
			}
			
			else if((vector_search[pointer-1]==name[i][j-1] && vector_search[pointer]==name[i][j])){
				success[i]++;
			}
			
		}	
	}
}


void _SuccessStrength(){
	for(int j=0; j<5; j++){
		
	cout << success[j];
	
	if(success[j] >= _CharSize(name[j]) - 1){
	 cout << " Large success rate, close to search term.";
	}
	
	cout << "\n";
	}
}

void _ShowNames(){
	for(int j=0; j<5; j++){
	cout << name[j] << endl;
	}
}


int _CharSize(char name[]){
	int size;
	for (int i=0; name[i] !=0; i++){
		size++;
	}
	
	return size;
}

/*
void _CharCompare(){
	
		for(int j=0; j<10; j++){
			if(vector_search[j]==name[i][j]){
				//cout << "Found letter " << vector_search[j] << " in " << i << " " << j << "\n";
				success[i]++;
			}
		}	
	}
}

*/


/*
void _CharCompare(){
	for(int i=0; i<2; i++){
	
		for(int j=0; j<10; j++){
			if(vector_search[pointer]==name[i][j]){
				cout << "Found letter " << vector_search[pointer] << " in " << i << " " << j << "\n";
			}
		}	
	}
	
	
}
*/
