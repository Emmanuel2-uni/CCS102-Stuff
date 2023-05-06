#include <iostream>
using namespace std;
void debug_displaylist();
void displaylist();
void copylist1();
int identifyNumber(int number_list[], int position);

int size;
int number_list1[20];
int number_list2[20];
int compare_list[20];


int main(){

	//three declarations used in the ordering
	//current for current number to compare. Adjust to adjust and move the current number up.
	int current=0;
	int adjust=0;
	int run=0;
	int position;
	
	cout << "\nEnter a non-integer or letter to end inputs.\n\n";
	for(int i=0; i<=size; i++){
		
		cout << "(Max 20) Enter number for element " << size << ": ";
		cin >> number_list1[i];
		size++;
	
		if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			size--;
			}
		else if(size==21){
			size--;
		}
			
	}
	
	copylist1(); //copies number_list1 to the other two lists for referencing.
	
	cout << "\nLists: (Unmodified)\n\n";
	displaylist();
	
	//debug, confirm size.
	//cout << "\n\n\nSize: " << size << "\n";
	
	for(int current=0; current<size; current++){
		
		for(int swap=current; swap<size; swap++){

			if(number_list1[current] >= number_list2[swap]){
				
				number_list1[current] = number_list2[swap]; 
				number_list1[swap] = number_list2[current]; 
				
				copylist1(); //copies the new, modified list to both 
				}
			
		}
		
		
		//debug
		//cout << debug_displaylist();
		//cout << "\nCurrent is: " << current;
		//cout << "\nAdjust is: " << adjust;
		
	}
	
	cout << "\n\nLists: (Corrected)\n\n";

	displaylist();
	system("PAUSE");
	system("CLS");

	while(run==0){
		
		displaylist();
		cout << "\nCurrent Size of Array: " << size << " [0 to " << size-1 << "] \n\n" ; 
		cout << "\n\nPinpoint an element's position to identify [Input non-integer to exit]: ";
		cin >>	position;
		
		
		if( position>=0 && position<=(size-1) ){
			cout << "\nNumber in position " << position << " is: " << identifyNumber(number_list1, position) << "\n\n";
			system("PAUSE");
			system("CLS");
			}
			
		else if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			run=1;
			}
		else{
			cin.ignore(256, '\n');
			cout << "\nWrong index/position. Please reenter.\n";
			system("PAUSE");
			system("CLS");
		}		
		
	}
	return 0;
}


void displaylist(){
	
	cout << "List of numbers: ";
	for(int i=0; i<size; i++){
		cout << number_list1[i] << " ";	
	}
	
	
}

void debug_displaylist(){
	
	cout << "List 1: ";
	for(int i=0; i<size; i++){
		cout << number_list1[i] << " ";	
	}
	
	cout << "\n\nList 2: ";
	for(int i=0; i<size; i++){
		cout << number_list2[i] << " ";	
	}
	
	cout << "\n\nCompare List: ";
	for(int i=0; i<size; i++){
		cout << compare_list[i] << " ";	
	}
	
}



void copylist1(){
	for(int i=0; i<size; i++){
		number_list2[i]=number_list1[i];
		compare_list[i]=number_list1[i];	
	}
	
}

int identifyNumber(int number_list1[], int position){
	return number_list1[position];
}
