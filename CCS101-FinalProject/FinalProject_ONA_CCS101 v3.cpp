#include <iostream>
#include <iomanip>
#include <string>
#include <vector> //new header; for enabling the use of vectors.
#include <numeric> //new header; for easier vector math handling.
#include <fstream> //new header; enables creating, reading (input), and writing (output) files.
using namespace std;

//Vector study, study of additional code (fstream and vector related), study on how specific code functions, and usage of lessons taught in class.
//Use vectors for dynamic storage; use while, for, if/else, mathemathical operators. Study on how code flows in general: which code gets called first and how to better order them.
//Functionality in as few lines as possible for easier reviewing and readability for other people.
//Goal: A fully functional dynamic program for tallying items/entries that can export and import text files.

//Trying for minimal use of goto and labels.
//Note to self: Cull/delete declarations and variables that are not needed. /* */
//Second Note to self: switch case code are determined on runtime even before getting called. Declarations/definitions must be done before

//Checklist of lessons to implement.
//Done: if/else; while; for; switch case; string compare; flags; sums/differences that carry over to the entire program function; resize inputted strings and then pad with whitespace. goto/label
//To-do: tidying up code, user interface and more comments if necessary

//changelog:
//v1: added main features
//v2: removed several redundant comments
//v3: tidied up some code for readability, added more comments, improved user interface and experience.

int main()
{
	//system flags/counters
	//i is for "for" loops, imax is for limiting "for" loops and to handle increasing vector sizes, runtally for running the tally function, init is for "initializing" vectors through first run.
	int i=0, imax=0, progrun=0, runtally=0, ch=0, init=0, searchfound=0, easylist=0, access=0, login=0, exit;
	int pricelistrun=0, imaxlist=0, btninput;
	
	//For Log-on program function, will read from a text file.
	string user1, user2;
	string pass1, pass2;
	int attempt=0;
	
	//Vectors from the <vector> header, enables the use of vectors.
	vector<string> item(1); 	 //starts at 0 posiition, with size (1) to initialize str vector; name of item.
	vector<float> prc(1);		 //starts at 0 position, with size (1) to initialize prc vector; price of item.
	vector<int> qty(1);     	//starts at 0 position, (1) to initialize qty vector; quantity of item.
	vector<float> trtotal(1); 	//starts at 0 position, (1) to initialize trtotal vector; total payment due.
	
	//Vectors for the pricelist button based function of the program.
	vector<int> listbtn(1);
	vector<string> listitem(1);
	vector<float> listprc(1);
	vector<int> listqty(1);
	
	//tally feature uses these
	string add; 
	string initem;
	float inprc; //initem, inprc, inqt for input vector push_back functions
	int inqt;
	
	float total=0, truetotal=0;
	int delentry=0, delflag=0;
	string search, listconfirm;
	
	//file handling stream declarations
	ofstream receipt; //From the <fstream> header, ofstream declares a new stream for file writing and output. Functions similarly to cout of the iostream header.
	ofstream receiptexport; 
	ifstream import; //From the <fstream> header, ifstream declares a new stream for file reading and input. Functions similarly to cin of the iostream header.
	ifstream importpricelist;
	ofstream importlistfirsttime;
	
	ofstream newaccount;
	ifstream account;



//Program first checks if there is an existing account. If not, it will create a text file containing the new username and password input by the user.
while(login==0){
	
account.open ("account.txt");	 	//opens the "account" input stream, enables the program to read from the text file "account.txt" present in the current root folder.

	//is_open is functionally for checking if the file was successfully opened by the ifstream (input filestream) in conjunction with the If conditional
	if (account.is_open()){
		
		//code below will execute if there exists an account text file
		//will prompt the program to end the current while loop and proceed to the next loop.
		cout << "\nExisting user detected.\n";
		account >> user2;							//account input stream buffer will read from the account.txt file line by line. This is read from the first line.
		account >> pass2;							//This is read from the second line.
			if (user2.empty() || pass2.empty()){ 		//X.empty() is a boolean that will determine if the string received from [user2] or [pass2] is empty or consists only of a whitespace.
				cout << "Invalid field found.\n";
				cout << "Creating new account...\n\n";
				system("PAUSE");
				system("CLS");
				login=2; 								//sets the login flag to go through account creation
				}
		}
	else //If no account.txt has been detected, sets flag to 2 for account creation.
		login=2;
			
	//Account creation ==== if there is no existing user account text file or if there is an invalid field, this code will allow the user to create one.
	if (login==2){
		account.close(); //closes the account read/input stream.
		
		newaccount.open("account.txt"); 	//opens newaccount output stream enabling the program to write to account.txt
		cout << "Input details for new account.\n";
		cout << "Please input new username: ";
		cin >> user2;				
		newaccount << user2 << "\n";		
		cout << "Please input new password: ";
		cin >> pass2;
		newaccount << pass2;
		newaccount.close();					//newaccount stream close
		login = 0;							//for tracking; lets the login screen to loop again and checks if a proper account had been created through prior code
		cout << "\nAccount created!\n";
		system("PAUSE");
		system("CLS");
		}
		
account.close();
login=1;
}
//account function end.


//access function start.
while (access==0){

	cout << "Input username: ";
	cin >> user1;
	cout << "Input password: ";
	cin >> pass1;
	cout << "\n";
	
	if(user1==user2 && pass1==pass2){
		cout << "Successfully logged in!\n";
		system("PAUSE");
		access=1; //This flag will end the while loop.
		}
		
		
	else{
		access=0; //guarantees that the while loop continues and that the user will have to input another user1 and pass1.
		cout << "Incorrect username and/or password.\n\n";
		attempt+=1;
		cout << 3-attempt << " of 3 log-in attempts left.\n";
		cout << "\n";
			if (attempt==3)
				return 0;	//terminates the program
		system("PAUSE");
		system("CLS");
		}
}
//access function end.



//main program feature start.
while(ch==0 && access==1) //IMPORTANT NOTE TO SELF: "==" is a determinator/comparison; it does -=NOT=- function as an equal sign "=".
{
	
	mainprogram: //label is just for demonstration purposes.
	system("CLS");
	
	
	cout << "|||\n|||\n|||          This program is for tallying/listing items for various purposes.";
	cout << "\n|||    Please see the about screen (option 10) for more information regarding this program.\n|||\n|||\n";
	cout << "=====================Basic Options=======================\n\n\n";
	
	cout << "1. Delete\n";
	cout << "2. Run tally of items.\n";
	cout << "3. Display item list and total.\n";
	cout << "4. Search (Prototype - Exact case only)\n";
	cout << "5. Exit\n";
	cout << "6. Export to text file.";
	cout << "\n\n10. About";
	
	cout << "\n\n\n\n_______________________________________________\n\n";	
	
	
	//options below appear if tally hasn't been done or nothing has been imported yet.
	if (init==0)
		cout << "7. Import from text file and continue a tally. \t(Available only at the start of program)\n";
		
	if (easylist==0)
		cout << "8. (For Advanced Users only) Import from text file and implement button list.\n"; 
		else if(easylist==1)
			cout << "8. Access button list.\n";  	
	cout << "\n-----------------------------------\n";	
	
	
	//cout << "\ni = " << i << "\n"; 							//Debug; to keep track of i and observe how it works. Remove comment as needed.
	//cout << "imax = " << imax << "\n"; 						//Debug; to keep track if imax is carried over.
	//cout << "List has a size of " << imax+1 << ". \n\n";		//Debug; to keep track of the size of the list. Initial runtime will have a list of 1 due to vector(1) declaration.
	
	
	cout << "Input choice: ";
	cin >> ch;
	
	
	
	//Attempt for error "handling" if user input is outside of scope.
		if((ch<=0 || ch>10 || ch==9) && init==0){
			cout << "\nInvalid Choice. Please try again.\n";
			system("PAUSE");
			goto mainprogram; //for demonstrating goto. This will be the only instance of goto and a label.
			}
		if((ch<=-1 || ch==7 || ch>10 || ch==9) && init==1){
			cout << "\nInvalid Choice. Please try again.\n";
			system("PAUSE");
			ch=0; //overrides initial user input and flags the while main menu to keep running.
			}
		else if (cin.fail()){ 		//[If cin.fail()] detects if the input received by the "cin" stream  is invalid.			
			cin.clear();			//cin.clear() is for clearing the cin stream  of errors and removes the failure state (in this case, when a string/char is input by the user instead of an integer).
			cin.ignore(256, '\n'); 	//cin.ignore(x, y) clears the buffer of any characters; As specified, 256 characters in the buffer are ignored/cleared and looks for the next new line (\n) in the console. 
									//These prevent the buffer from being evaluated again and again resulting in an endless fail state.
			ch=0;
			}


//============ switch case start
switch(ch)
{
	
	//========  main function of the program, tallying
	case 2: 
		{
		system("CLS");
		//Quick summary of what has been added so far. Added after all the features were sorted out first. Code copied from case 3.
		cout << "\n\n_________Current list of items________\n\n||";
		cout << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
		for (int i=0; i<=imax; i++){
				cout << "||" << left << setw(5) << i+1 << setw(25) << item[i];
				cout << fixed << setprecision(2) << setw(15) << prc[i] << setw(15) << qty[i]  << setw(15) << trtotal[i] << "\n";
				}
				truetotal = accumulate(trtotal.begin(), trtotal.end(), 0.00); 
				cout << "\nTotal payment due is: " << fixed << setprecision(2) << truetotal;
			
			
		trtotal.clear(); 	 //used at the start of tally so that the previous tally (if any) does not count twice towards price sum totals. The function .clear() removes ALL elements inside the vector.
		truetotal=0;		 //same reason as above, but is used as an example for a simpler price sum total code later.
		runtally=0; 	   	 //flag to execute the tally.
		cout << "\n\nRunning tally feature...\n\n";
		
		
		while(runtally==0)
		{
		if(init==0){
			cin.ignore(256, '\n');
			cout << "Input first item [EXIT to exit]:  ";
			getline(cin, item[0]);
				if(item[0]=="EXIT"){
					cin.clear();
					item[0].clear();
					runtally=1;
					ch=0;
					break;
					}
			item[0].append(20, ' '); 		//from the <string> header, adds whitespace [' '] until a 20 character length has been reached.
			item[0].resize(20); 			//forcibly resizes string length to 20. This line and .append() helps in \t use later when printing.
			cout << "Input price of first item:   ";
			cin >> fixed >> setprecision(2) >> prc[0];
			cout << "Input quantity of first item:   ";
			cin >> qty[0];
			init=1; 		//vectors are now initialized, lines of code involving init=0 should ideally no longer be called for the rest of runtime or after import.
			}
			
		else{	
			cin.ignore(256, '\n'); 		//clear stream buffer of residing characters
			cout << "\nInput name of item [EXIT to exit]:   "; 

			//The input stream will be checked first if the user wants to exit. If not, the item name will be stored in the initem string and imax will go up by 1.
			getline(cin, initem);
				if(initem=="EXIT"){
					cin.clear();
					initem.clear();
					runtally=1;
					ch=0;
					break;
					}
			imax+=1; 						//======VERY IMPORTANT====== 1 is added to imax to expand the list and maximum repeats for "for" loops. 
			initem.append(20, ' ');
			initem.resize(20);
			item.push_back(initem);					//<vector> function .push_back(X) expands the max vector size by 1 and makes it so that element X is added to the end of the vector's list.
			cout << "Input price of item:   ";		//In this case, string (initem) will be added to the end of the vector as an element and the new vector size becomes 2 with elements: item[0] and item[1].
			cin >> fixed >> setprecision(2) >> inprc;
			prc.push_back(inprc);
			cout << "Input quantity of item:   ";
			cin >> inqt;
			qty.push_back(inqt);
			}
		
		system("CLS");
		
		cout << "\n\n\n\n================================================================\n||";
		cout << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
		for (int i=0; i<=imax; i++){ 	//here is where imax is first used.			
			//setw(X) sets the width of a cout stream, where X is the character length. Setw() starts from the left, so setw(5) will "reserve" 5 characters worth of length starting from the left up until the next output.
			cout << "||" << left << setw(5) << i+1 << setw(25) << item[i] << setw(15) << prc[i] << setw(15) << qty[i] << setw(15) << prc[i]*qty[i] << "\n";
			}
			
		//Prompts the user to decide if the program should add one more item.
		cin.ignore(256, '\n');
		cout << "\nAdd one more? [N for no; Y to add one more]"; //Option is present to make adding things to the list incremental.
		cin >> add;

		if(add=="N" || add=="n"){
			runtally=1; //Ends current tally while loop
			cin.ignore(256, '\n');
			}
		else if(add=="Y" || add=="y"){
			runtally=0; //Goes back to the start of the tally function.
			}
			
		} 
		//runtally while end

		system("CLS");
		cout << "Max: " << imax+1 << "\n\n"; //for debugging reasons
		
		//Code below summarizes the tally at the end of the loop.
		cout << "\n\n=======================================================================\n";
		cout << "||" <<left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
		for (int i=0; i<=imax; i++){ 					//here is where imax is first used.
			trtotal.push_back(prc[i]*qty[i]); 			//since trtotal.clear() was used at the start of this case's code, the first push_back will be at element 0 position rather than at element 1.
			cout << "||" <<  left << setw(5) << i+1 << setw(25) << item[i] << setw(15) << prc[i] << setw(15) << qty[i] << setw(15) << trtotal[i] << "\n";
			truetotal = truetotal+trtotal[i]; 			//this is one, simpler option to get the sum payment, but a problem arises when multiple functions need to interact with each other.
			}
			
		cout << "\n\n=====================================";
		cout << "\nTotal payment due is: " << fixed << setprecision(2) << truetotal;
		cout << "\n\nDone\n";
		system("PAUSE");
		
		ch=0; //reruns the main while loop	
		break;
		} 
		//switch 2 end

	//======== For checking the total
	case 3:
		{
			system("CLS");
			cout << "Max: " << imax+1 << "\n\n"; //Debug purposes
			cout << "\n\n=======================================================================\n";
			cout << "||" << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
			
			for (int i=0; i<=imax; i++){
				cout << "||" << left << setw(5) << i+1 << setw(25) << item[i];
				cout << fixed << setprecision(2) << setw(15) << prc[i] << setw(15) << qty[i]  << setw(15) << trtotal[i] <<"\n";
				}
				
			//<numeric> function 'accumulate()' sums the elements starting from the beginning of the vector trtotal [.begin()] up to the final element of the vector [.end()] defined by imax.
			//ideal solution to get the sum payment as this doesn't rely on a for loop and is more flexible when multiple functions need to interact.
			//0.0 at the end for initializing the sum first. Changing 0.0 to a different number Y will lead to Y being the initial sum.
			//Note: 0 instead of 0.0 will call for an Int number and will not display sums involving float numbers correctly; instead, use 0.0.
			truetotal = accumulate(trtotal.begin(), trtotal.end(), 0.00); 
			cout << "\n\n=====================================";
			cout << "\nTotal payment due is: " << fixed << setprecision(2) << truetotal;
			cout << "\n\nDone.\n";
			system("PAUSE");
		ch=0;
		break;
		}
		//switch 3 end
		
	
	//======== Implementation of an erase element function	
	case 1: 
		{
			system("CLS");
			
			
			cout << "Deleting Items...\n\n" << "_________Current list of items________\n\n";
			//List of items code from case 3
			cout << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
			for (int i=0; i<=imax; i++){
				cout << left << setw(5) << i+1 << setw(25) << item[i];
				cout << fixed << setprecision(2) << setw(15) << prc[i] << setw(15) << qty[i]  << setw(15) << trtotal[i] << "\n";
				}
				
				
				truetotal = accumulate(trtotal.begin(), trtotal.end(), 0.00); 
				cout << "\nTotal is payment due is: " << fixed << setprecision(2) << truetotal << "\n\n";
				
				
			if(init==0){
				cout << "\nNo initial entry found. Please run or import a tally first.\n\n";
				system("PAUSE");
				ch=0;
				break;
				}
				
				
			cout << "Input entry number to be deleted [0 or below to exit delete menu]: ";
			cin >> delentry;
			delentry = delentry-1; //1 is substracted from the user input in order to point exactly to the element needed. An input of 1 will return a 0 which will point to the true first element.
			if (imax==-1 || (imax-delentry)<0 || delentry<=-1){ //Disables the user from going down below an empty list. If user tries to, case breaks before heading to the main erase function and goes back to the switch menu.
				cout << "\n\nSize of list cannot go below 0 or user is exiting the delete menu.\n";
				system("PAUSE");
				ch=0;
				break;
				}
				
				
			cout << "\nDeleting entry number " << delentry+1 << " with the name " << item[delentry] << "...\n\n" << "Removing " << trtotal[delentry] << " from the total payment due...\n\n";
			system("PAUSE");
			item.erase(item.begin()+(delentry)); 		 //erase is to erase the element pointed within ().
			prc.erase(prc.begin()+(delentry));			 //erase also rearranges the elements automatically.
			qty.erase(qty.begin()+(delentry));		 	//vector.begin() serves as a pointer; it points to element 0 of the vector.
			trtotal.erase(trtotal.begin()+(delentry)); 	//delentry - 1 is used to accurately point at the vector element (input of 1 outputs 0 which will delete the element at the 0th position).
			imax = imax-1;									 //1 is substracted to imax to better appropriate the "for" loops that are dependent on imax.

		ch=0;
		break;
		}
		//switch 1 end


	//======== Implementation of a search function
	case 4: 
	{	
		cin.clear();
		cin.ignore(256, '\n');
		searchfound=0; //initializes the search flag
		cout << "\n\n_______Search prototype_______\n\n";
		cout << "|||Input search string (Exact case and name only): ";
		getline(cin, search); //A simple cin stream (cin >>) will not be able to search properly when append/resize is used for the string as it is a stricter command.
			search.append(20, ' ');
			search.resize(20);
			
			
		while(searchfound==0){
			for (int i=0; i<=imax; i++) //matches input "search" with every vector element to find matching string
				if (search==item[i]){
					cout << "\nString found!\n";
					cout << "\t" << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
					cout << "\t" << left << fixed<< setprecision(2) << setw(5) << i+1 << setw(25) << item[i] << setw(15) << prc[i] << setw(15) << qty[i] << setw(15) << trtotal[i] << "\n";
					cout << "\n";
					searchfound=1; //Will keep finding until imax is reached
					}	
				else
					searchfound=2; //if nothing is found, flag 2 is set
	
			//flag 2 will be triggered, the screen will say that string is not found, and will end the while loop.
			//if (searchfound==2)
			//	cout << "\nString not found.";	
				
						
			}
			//search while loop end
			
		cout << "\nString search finished.\n\n\n";
		system("PAUSE");	
		
	ch=0;
	break;
	}
	//case 4 end
	
	
	//======== Implementation of an export function.
	case 6:
	{ 
	//Write two files: one for reading (receipt), one for exporting (receiptexport).
	if(init==1 && imax>=0){
    	receipt.open ("receipt.txt"); 							 //opens a file named receipt, or creates one if there is none, then enables read/write access for that file.
    	receipt << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
    		for (int i=0; i<=imax; i++){
				receipt << left << setw(5) << i+1 << setw(25) << item[i];
				receipt << fixed << setprecision(2) << setw(15) << prc[i] << setw(15) << qty[i]  << setw(15) << trtotal[i] <<"\n";
			}	//prints list of items on receipt.txt
		receipt.close();										 //closes the text file and clears the "receipt" stream buffer, enabling for new stream to be declaration and to avoid stream content overlap.
	
	
		//generate an export friendly text file
		receiptexport.open ("receiptexport.txt");
			receiptexport << imax << "\n";
			for (int i=0; i<=imax; i++){
				receiptexport << item[i] << "\n";
				receiptexport << fixed << setprecision(2) << prc[i] << "\n";
				receiptexport << qty[i] << "\n";
				}
		receiptexport.close();
		
		cout << "\n\nExport successful! The text files \"receipt.txt\" and \"receiptexport.txt\" have been successfully created.\n\n";
		system("PAUSE");
		}
		
		
	else if(init!=1 || imax==-1){
		cout << "\nList has not been initialized or there is no existing item in the list.\n\n";
		cout << "Exiting export function...\n";
		system("PAUSE");
		}
		
		
	ch=0;
	break;
	}
	

	//======== Implementation of an export function.
	case 7:
	{ //Import and read from a file.
		trtotal.clear();
		import.open ("receiptexport.txt");
			if (import.is_open()){ //is_open is functionally for checking if file is opened by the ifstream (input filestream) in conjunction with the If conditional
				cout << "\nFile found and opened.\n";
				//system("PAUSE"); //remove comment for debug
				}
			else{
				cout << "\nNo existing export/previous list text file exists.\n\n";
				system("PAUSE");
				ch=0;
				break;
				}
		
		
		import >> imax; //reads the first line of the text as the new imax.
		cout << "\nNew max number of items is " << imax+1 << "\n\n";		 //Debug, checking if it manages to read the first line.
		import.ignore(256, '\n'); 										 	 //clears the import input buffer stream, similar to cin.ignore from the tally function of the program.
			if (init==0){ 													 //if importing first, init will be 0 as explained in the comments of the tally function
				getline(import, item[0]); 									 //reads second line as the name of the item
					item[0].append(20, ' ');								 //ideally this code is for when the user modifies receiptexport.txt and exceeds 20 characters on a specific name
					item[0].resize(20);										 //ideally this code is for when the user modifies receiptexport.txt and exceeds 20 characters on a specific name
				import >> fixed >> setprecision(2) >> prc[0];				 //reads the third line as the price of the item
				import >> qty[0];
				init=1;
				}
				
				
			for (int i=1; i<=imax; i++){
					import.ignore(256, '\n');
					getline(import, initem);
						initem.append(20, ' ');		//ideally this code is for when the user modifies receiptexport.txt and exceeds 20 characters on a specific name
						initem.resize(20);			//ideally this code is for when the user modifies receiptexport.txt and exceeds 20 characters on a specific name
					item.push_back(initem);
					import >> fixed >> setprecision(2) >> inprc;
					prc.push_back(inprc);
					import >> inqt;
					qty.push_back(inqt);
					}
					
					
		system("CLS");
		cout << "\nFile found and opened.\n";
		cout << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << "\n";
		for (int i=0; i<=imax; i++){ //reused code from tally case
			cout << left << setw(5) << i+1 << setw(25) << item[i] << setw(15) << prc[i] << setw(15) << qty[i] <<"\n";
			trtotal.push_back(prc[i]*qty[i]);
			}
			
			
		//closes the import stream
		import.close();
		cout << "\n================================================\nImport successful!\n\n\n";
		system("PAUSE");	
	ch=0;
	break;
	}

	
	//============ Implementation of a new menu for when user knows the items that are going to be entered.
	case 8:
	{
		system("CLS");
		importpricelist.open("pricelist.txt");
		
		
		importpricelist >> imaxlist;
		importpricelist >> listconfirm;
		//Code below determines if there is an existing list or if a list has an invalid format.
		if(listconfirm!="Start"){
			importpricelist.close();
			cout << "\n!!!\n\nInvalid list format found.\n\nCreating example format in root folder... \nPlease contact an advanced user. \n\n!!!\n\n";
			
			//Code below will write a help txt file for writing a properly formatted list that can be used by the program.
			importlistfirsttime.open("pricelist_formathelp.txt");
			importlistfirsttime << "1st line: write number of items then subtract 1." << "\n";
			importlistfirsttime << "2nd line: write 'Start' in exact case." << "\n";
			importlistfirsttime << "3rd Line: Write name of item 1" << "\n";
			importlistfirsttime << "4th Line: Write price of item 1" << "\n";
			importlistfirsttime << "5th Line: Write name of item 2." << "\n";
			importlistfirsttime << "6th Line: Write price of item 2." << "\n";
			importlistfirsttime << "Repeat the pattern (from line 3 and onwards) until finished. Name of item should be readable in 20 characters.";
			importlistfirsttime.close();
			system("PAUSE");
			ch=0;
		 	break;
		 }
		 
		 easylist=1; //flag to change the main menu option text
		 
		//Imports a price list defined by the user.
			for (int i=0; i<=imaxlist; i++){
				if(i==0){
					listitem.clear(); //clears all the elements including the initial declaration. 
					listprc.clear();
					}				
				importpricelist.ignore(256, '\n');
				getline(importpricelist, initem);
				listitem.push_back(initem);
					listitem[i].append(20, ' '); //automatically adjusts the item name to 20 characters by padding with whitespace
					listitem[i].resize(20);		//if the item exceeds 20 characters, it will limit it to 15 which will cut the name.
				importpricelist >> fixed >> setprecision(2) >> inprc;
				listprc.push_back(inprc);
				}		
		importpricelist.close();
		
		if (init==1){
				system("CLS");		
				cout << "\n\nItem/Items added so far:";
				cout << "\n=================================================================\n||";
				//cout << "Max: " << imax+1 << "\n\n"; //Debug purposes
				cout << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
					for (int i=0; i<=imax; i++){
						cout << "||" << left << setw(5) << i+1 << setw(25) << item[i] << setw(15) << prc[i] << setw(15) << qty[i] << setw(15) << trtotal[i] << "\n";
						}	
				truetotal = accumulate(trtotal.begin(), trtotal.end(), 0.00); 
				cout << "\n\n\n=====================================";
				cout << "\nTotal is payment due is: " << fixed << setprecision(2) << truetotal;
				cout << "\n\n\n";	
				}
			
		
		//Start of Pricelist functionality
		pricelistrun=1;
		while(pricelistrun==1){		
			//cout << "\nimaxlist = " << imaxlist << "\n"; //debugging, remove comment if needed
			cout << right << setw(8) << "Button" << left << setw(25) << "  Item Name" << setw(15) << "Price" << "\n";
			for (int i=0; i<=imaxlist; i++) //reused code from tally case
				cout << left << fixed << setprecision(2) << right << setw(8) << i+1 << ". "<< left << setw(25) << listitem[i] << setw(15) << listprc[i] << "\n";
			
			//Each numbered item on the pricelist vector will now correspond to a specific button input (btninput).
			//If the user input 1, then btninput will return as 0 which will point to the very first element on the custom price list.
			cout << "\n\nInput item to add to tally [input 0 or " << imaxlist+2 << " and above to exit]: ";
			cin >> btninput;
			btninput = btninput-1;
			
			//Exit input code. If user inputs 0 or if the input is higher than the maximum list, the list menu exits.
			if(btninput<=-1 || (btninput>imaxlist) ){
				pricelistrun=0;
				ch=0;
				cout << "\nExiting user-defined price list...\n\n";
				}
			
			//Code below will be for actually adding items.
			//If no tally has been initialized yet, first if group will do it for the user; the next code group will function using imax and without using a "for" loop, as the current while will keep it running.
			else{
				if(init==0){
					item[0] = listitem[btninput];
					prc[0] = listprc[btninput];
					cout << "Input quantity of item: ";
					cin >> inqt;
					qty[0] = inqt;
					trtotal[0]=(prc[0]*qty[0]);
					init=1;
					system("CLS");
					}
			//btninput will now serve as the "pointer" to which element that the user needs. An input of 1 will return btninput=0, which will point to element 0 of the imported pricelist.
				else{
					imax+=1;
					cin.ignore(256, '\n');
					item.push_back(listitem[btninput]);
					prc.push_back(listprc[btninput]);
					cout << "Input quantity of item: ";
					cin >> inqt;
					qty.push_back(inqt);
					trtotal.push_back(prc[imax]*qty[imax]);
					system("CLS");
					}		
				}
				
			if (init==1){
				system("CLS");
				
				cout << "\n\nItem/Items added so far:";
				cout << "\n=================================================================\n||";
				//cout << "Max: " << imax+1 << "\n\n"; //Debug purposes, remove comment as necessary
				cout << left << setw(5) << "No." << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(10) << "Total Price" << "\n";
					for (int i=0; i<=imax; i++){
						cout << "||" << left << setw(5) << i+1 << setw(25) << item[i] << setw(15) << prc[i] << setw(15) << qty[i] << setw(15) << trtotal[i] << "\n";
						}	
				truetotal = accumulate(trtotal.begin(), trtotal.end(), 0.00); 
				cout << "\n\n\n=====================================";
				cout << "\nTotal is payment due is: " << fixed << setprecision(2) << truetotal;
				cout << "\n\n\n";	
				}
				
			}		
			//pricelist end	
	importpricelist.close();
	system("PAUSE");
	ch=0;
	break;
	}
	//case 8 end
	
	//=======Making sure that the user wants to exit.
	case 5:
	{
	system("CLS");
	//Makes sure the user wants to exit and that the user has the correct input.
	while(ch=5){
	cout << "\nDo you want to exit the program [1 - Yes /// 2 - No]?\n";
	cin >> exit;
	
		if (exit==1){
		return 0;
		}
		else if(exit==2){
		ch=0;
		break;
		}
		else if(cin.fail()){
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\nInvalid option.";
		ch=5; //prevents exit from the while loop
		}
		else{
		cout << "\nInvalid option.";
		ch=5;
		}	
	}
	//exit while loop end
	
	break;
	}
	//case 5 end
	
	
	//======An about "page" to describe the program.
	case 10:
	{
		system("CLS");
		cout << "\n\n\n==============================================================================================\n\n";
		cout << "       This program is to help in tallying/listing items without having to rely\n";
		cout << "       on a fixed list and instead be more dynamic/flexible in its approach.\n\n\n\n";
		cout << "       The program's main features are:\n";
		cout << "       1.__Letting the user input custom items (Name, price and quantity) manually without a list size restriction.\n\n";
		cout << "       2.__Letting the user delete entries.\n\n";
		cout << "       3.__Letting the user search for entries and pinpoint the entry's price and order on the list.'\n\n";
		cout << "       4.__Letting the user export their current list into a readable receipt and presenting the capability\n";
		cout << "      	    to continue an existing list from a previous run of the program.\n\n";
		cout << "       5.__Letting an advanced user implement a buttoned list for easier listing;\n";
		cout << "           the buttoned list is without size restriction as well and is defined by the user.\n\n";
		cout << "       6.__An option to view the existing list summary that expands without additional user input;\n";
		cout << "           In addition to the list being present to the user after each handled input on most functions.\n";
		cout << "\n\n\n==============================================================================================\n\n\n";
		ch=0;
		system("Pause");
	ch=0;
	break;
	}
} 
//switch case end

} 
//choice menu end

return 0;
} 
//main program feature end