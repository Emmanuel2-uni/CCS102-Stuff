#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int maxmin(int flag);
int countposneg(int flag);
int countevenodd(int flag);
void list_summary();
vector<int> number_list(1); //vector is used to have a dynamic list. (1) to initialize the vector and avoid errors.
//Why not a double vector? Double data types cannot take modulus operators, so counting evens and odds won't be possible with the data type.
int i, imax=0; //Global variables to be used in the entire program.


int main()
{
	
	int num; //user input number
	int run=1; //flag for running various parts of the program
	int choice; //case choice variable for summary features
	number_list.clear(); // clears the vector list and makes it empty.
	
	cout << "==============\nDoing things with integer numbers.\n\n";
	cout << "[input a-z or other symbols to finish] \n\n";
	
	while(run==1)
	{
	cout << "Input number: ";
	cin >> num;
	imax++;
	number_list.push_back(num); //since .clear() had been done prior, the first push_back will be at element 0.
	
	
	if(cin.fail()){ //If anything other than an Integer is input by the user, the loop breaks and the program proceeds to the summary.
		cin.clear(); //clears the cin stream
		cin.ignore(256, '\n'); //ignores 256 characters in the stream and finds the next new line (\n)
		imax-=1;
		number_list.resize(number_list.size()-1); //Downsizes the vector. Will also remove the wrong data stored (non-integer in this case).
		//NOTE: .erase() will not work for some reason. Investigate further. Used resize instead.
		run=2; //proceed to the next part of the program
		}
	}
	
		
	system ("PAUSE");
	system ("CLS");
	

	while(run==2){
		
		list_summary(); //void function for listing. Since the i, imax and the number_list vector are global variables, this should have no problem being called.
		
		cout << "\n\n\n" << "Max/Highest number is: " << maxmin(1);
		cout << "\n" << "Min/Lowest number is: " << maxmin(2);
		cout << "\n\n" << "Number of Even integers is: " << countevenodd(1);
		cout << "\n" << "Number of Odd integers is: " << countevenodd(2);
		cout << "\n\n" << "Number of Positive integers is: " << countposneg(1);
		cout << "\n" << "Number of Negative integers is: " << countposneg(2);
	
		//cout << "\n\n imax = " << imax; //debug code, remove as comment when needed.
		//cout << "\n Vector size is " << number_list.size(); //debug code, remove as comment when needed.
	
		cout << "\n\n\n=================================";
		cout << "\n-Options- ";
		cout << "\n 1. List of Positive Numbers.";
		cout << "\n 2. List of Negative Numbers.";
		cout << "\n 3. List of Even Numbers.";
		cout << "\n 4. List of Odd Numbers.";
		cout << "\n 5. Exit.";
		
		cout << "\nEnter choice: ";
		cin >> choice;
		cout << "\n\n";
		
		switch(choice){
			
			//=========Shows a list of all positive numbers.
			case 1:
			{
			system ("CLS");
			list_summary();
			cout << "\n\nPositive numbers found are: \n";
			for(i=0; i<imax; i++){
				if(number_list[i]>=0)
					cout << number_list[i] << " ";
				}
			run=2;
			cout << "\n\n";
			system ("PAUSE");
			system ("CLS");
			break;
			}	
				
			//=========Shows a list of all negative numbers.
			case 2:
			{
			system ("CLS");
			list_summary();
			cout << "\n\nNegative numbers found are: \n";
			for(i=0; i<imax; i++){
				if(number_list[i]<0)
					cout << number_list[i] << " ";
				}
			run=2;
			cout << "\n\n";
			system ("PAUSE");
			system ("CLS");
			break;
			}
			
			//=========Shows a list of all even numbers.
			case 3:
			{
			system ("CLS");
			list_summary();
			cout << "\n\nEven numbers found are: \n";
			for(i=0; i<imax; i++){
				if((number_list[i]%2)==0)
					cout << number_list[i] << " ";	
				}
			run=2;
			cout << "\n\n";
			system ("PAUSE");
			system ("CLS");
			break;

			}
			
			//=========Shows a list of all odd numbers.
			case 4:
			{
			system ("CLS");
			list_summary();
			cout << "\n\nOdd numbers found are: \n";
			for(i=0; i<imax; i++){
				if((number_list[i]%2)!=0)
					cout << number_list[i] << " ";	
				}
			run=2;
			cout << "\n\n";
			system ("PAUSE");
			system ("CLS");
			break;
				
			}			
			
			//=========Exit
			case 5:
			return 0;	
				
				
		}
		
	}
	return 0;
	
}

//=====Finding Max and Min function
int maxmin(int flag){
	int result;
	
	if (flag==1){	
		result=number_list[0];
		for(i=1; i<imax; i++){
			if( result<number_list[i] ){
				result=number_list[i];
				}		
			}
			
	}
	
		
	if (flag==2){		
		result=number_list[0];
		for(i=1; i<imax; i++){
			if( result>number_list[i] ){
				result=number_list[i];
				}		
			}
			
	}
		
		
		return result;
}


//=====Counting number of positives/negatives function
int countposneg(int flag){
	int count=0;
	
	if(flag==1){
		for(i=0; i<imax; i++){
			if(number_list[i]>=0)
				count++;
			}			
	}
	
	if(flag==2){
		for(i=0; i<imax; i++){
			if(number_list[i]<0)
				count++;
			}			
		}
		return count;
}


//=====Counting number of odds/evens function
int countevenodd(int flag){
	int count=0;
	
	if (flag==1){
		for(i=0; i<imax; i++){
			if((number_list[i]%2)==0)
				count++;
			}					
	}
	
	if (flag==2){	
		for(i=0; i<imax; i++){
			if((number_list[i]%2)!=0)
				count++;	
		}
	}
	return count;
	
}


//=====Number list summary function
void list_summary(){
	cout << "\n\n===Number list summary===\n\n";
	
	for(i=0; i<imax; i++){
		cout << number_list[i] << " ";
			if(i>0 && i%7==0)
				cout << "\n"; //This part of the function is to make the list readable by going down vertically after a set number of inputs.
		}
}
