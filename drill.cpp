#include <iostream>
#include <fstream>
#include <string>


using namespace std;

 

int main() {
	
string username, password;
bool loggedIn = false;
char choice;

 

	while (true) {

	// Display menu

	cout << "Choose an option:" << endl;
	cout << "1. Sign up" << endl;
	cout << "2. Log in" << endl;
	cout << "3. Exit" << endl;
	cout << "Choice: ";
	cin >> choice;

 
	if (choice == '1') {
	
		// Sign up
		cout << "Enter a username: ";
		cin >> username;
		cout << "Enter a password: ";
		cin >> password;

		// Open the output file stream
		ofstream outfile("login.txt", ios::app);
		
		// Check if the file was successfully opened
		if (!outfile.is_open()) {
			cout << "Error opening file!" << endl;	
			return 1;
		}

 

		// Write the username and password to the file
		outfile << username << " " << password << endl;
		
		// Close the output file stream
		outfile.close();
		cout << "Account created successfully!" << endl;

		}


	else if (choice == '2') {

	// Log in
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	// Open the input file stream

	ifstream infile("login.txt");

	 

	// Check if the file was successfully opened

	if (!infile.is_open()) {
		cout << "Error opening file!" << endl;
		return 1;
	}

 

	string fileUsername, filePassword;
	bool found = false;

 

	// Read each line of the file and check if the username and password match

	while (infile >> fileUsername >> filePassword) {
		
		if (username == fileUsername && password == filePassword) {
			found = true;
			break;
		}

	}

 

	// Close the input file stream
	infile.close();
 
		if (found) {
			cout << "Logged in successfully!" << endl;
			loggedIn = true;
		}else{
			cout << "Invalid username or password." << endl;
		}	

	}

else if (choice == '3') {

// Exit the program

break;

}

else {

cout << "Invalid choice. Please try again." << endl;

}

 

// Check if the user is logged in and display the appropriate menu

if (loggedIn) {

cout << "Choose an option:" << endl;

cout << "1. Logout" << endl;

cout << "2. Exit" << endl;

cout << "Choice: ";

cin >> choice;

 

if (choice == '1') {

// Log out

loggedIn = false;

}

else if (choice == '2') {

// Exit the program

break;
}
	else {
	cout << "Invalid choice. Please try again." << endl;
	}
}
}

 

return 0;

}