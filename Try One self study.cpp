#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int number_list1[50];
int number_list2[50];

int main()
{
	int choice, element, element_new, position;
	int flag_list=0;
	int i=0, maxsize=1;
	
	while(flag_list==0){
	for(i=0; i<maxsize; i++){
		cout << "Enter number: ";
		cin >> element;
	
		if(cin.fail()){
			i=maxsize+1;
			cin.clear();
			cin.ignore(256, '\n');
			maxsize--;
			flag_list=1;
			}
		else{
			number_list1[i]=element;
			number_list2[i]=element;
			maxsize++;
			}
		
		}
	}
	
	
	
	while(flag_list==1){
	cout << "\n\n";
	for(i=0; i<maxsize; i++){
		cout << number_list1[i] << " ";
		number_list2[i]=number_list1[i]; //This line is to renew the second/"backup" list with the new updated list that includes new numbers and replacements.
		}

	cout << "\n\nOptions.";
	cout << "\n1. Insert new number.";
	cout << "\n2. Replace number.";
	cout << "\n3. Exit.\n";
	cout << "Choice: ";
	cin >> choice;
	
	switch(choice)
	{
		
		case 1:
		{
		cout << "Enter new number: ";
		cin >> element_new;
		cout << "Enter position in the list: ";
		cin >> position;
		position=position-1;
		maxsize++;
		number_list1[position]=element_new;
		
			for(position; position<maxsize; position++){
				number_list1[(position+1)]=number_list2[position];
				}
				
		//DEBUG: cout << "\n" << position;
		//Learned: position's value in the for loop, since it was not declared as a new variable within the for loop itself, will carry over. Debug code above confirms it, it will result into maxsize.
		//As a result, and when position is called for again, its new value will be whatever the final value that [position] has at the end of the for loop.
		//Solution: number_list1[position]=element should be called first before the for loop above.
		//number_list1[position]=element_new;
		//Solution 2: declare a new iterative. Example: for(int i=position; i<maxsize; i++) instead of using position.
		
		break;
		}	
		
		case 2:
		{
		cout << "Enter new number: ";
		cin >> element_new;
		cout << "Enter position in the list: ";
		cin >> position;
		position=position-1;
		number_list1[position]=element_new;
		break;
		}
		
		
		case 3:
		{
		
		return 0;
		}
	}
	
	
	
	}
	
}