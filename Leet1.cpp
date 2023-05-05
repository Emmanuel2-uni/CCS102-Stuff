#include <iostream>
using namespace std;

int main(){
	//solution for problem #1
	//int nums[5] = {5, 1, 3, 9, 2};
	//sum to find: 10
	//output: 9 and 1;
	
	int target, size;
	int n1, n2, sum, pos1, pos2;
	
	cout << "Input size of array: ";
	cin >> size;
	int nums[size];
	
	for (int i=0; i<size; i++){
		cout << "Input nums[" << i << "]: ";
		cin >> nums[i];
	}
	cout << "Input target sum to find: ";
	cin >> target;
	cout << endl;

	for(int rep=0; rep<size; rep++){
	n1=nums[rep];
	pos1=rep;
		for(int i=0; i<size; i++){
			
			if(n1!=nums[i]){
				pos2=i;
				n2=nums[i];
				sum = n1 + n2; 
				
			}
			
			if(sum==target){
				break;
				//break from current for loop i
			}	
		}
	
	if(sum==target){
		cout << "nums[" << pos1 << "]: " << n1 << " and nums[" << pos2 << "]: " << n2;
		break;
		//break from current for loop rep
		}
	
	}
	
	
	return 0;
}