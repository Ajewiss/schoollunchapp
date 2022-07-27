//Program execution beginsand ends there.


#include <iostream>
#include <fstream>
#include <string>
#include "schoollunchapp.h"
using namespace std;

struct Order
{
	string student;
	string classRoom;
	int menuItem = 0;
};

int getChoice() {
	cout << endl << "LOGIN TO SCHOOL LUNCH SYSTEM" << endl;
	cout << "(1) Create account" << endl;
	cout << "(2) Login" << endl;
	cout << "(3) Quit application" << endl;
	int choice;
	cin >> choice;
	return choice;
}

string getEmail() {
	string email;
	cout << "Email: ";
	cin >> email;
	return email;
}

string getPassword() {
	string password;
	cout << "Password: ";
	cin >> password;
	return password;
}

bool auth(string email, string password) {
	string line;
	bool foundEmail = false;
	fstream fs;
	fs.open("data.txt", fstream::in);
	while (getline(fs, line)) {
		if (line == email) {
			foundEmail = true;
		}
		if (line == password && foundEmail) {
			fs.close();
			return true;
		}
	}
	return false;
}

void createAccount(string email, string password) {
	fstream fs;
	fs.open("data.txt", fstream::app);
	fs << endl << email << endl << password;
	fs.close();
}

int showMenu()
{
	int menuItem;
	cout << "\n\tLunch Menu\n\n";
	cout << "\n 1. American Hot dogs";
	cout << "\n 2. Chicken and bacon pasta with pesto and spinach";
	cout << "\n 3. Sushi";
	cout << "\n 4. Beef Lasagna with sour cream";
	cout << "\n 5. Creamy chicken and corn soup with bread\n";
	cin >> menuItem;

	return menuItem;
}

Order getOrder()
{
	system("cls");
	Order name;
	cout << "\nenter students name: ";
	cin >> name.student;
	cout << "\nenter classrom: ";
	cin >> name.classRoom;
	name.menuItem = showMenu();

	return name;
}

int main() {
	Order orders[100];
	int orderNumber = 0;
	bool running = true;
	bool login = false;

	string email, password;
	int choice;
	while (running) {
		choice = getChoice();
		system("cls");
		switch (choice) {
		case 1:
			email = getEmail();
			password = getPassword();
			createAccount(email, password);
			cout << endl << "ACCOUNT CREATED" << endl;
			break;

		case 2:
			email = getEmail();
			password = getPassword();
			if (auth(email, password) == true) {
				cout << endl << "LOGGED IN" << endl;
				login = true;
				running = false;
				break;
			}
			else {
				cout << endl << "INVALID CREDENTIALS" << endl;
				break;
			}
			break;

		case 3:
			running = false;
			break;
		}
	}
	if (login == true)
	{
		system("cls");
		cout << "\n\nSchool Lunch System\n\n";
		cout << "1. enter order : \n";
		cout << "2. view orders : \n";
		cout << "3. quit: \n";
		cout << "Enter option\n";
		int menuOption;
		cin >> menuOption;
		
		switch (menuOption)
		{
		case 1:
			orders[orderNumber] = getOrder();
			orderNumber++;
			break;
		case 3:
			showMenu();
			break;
		default:
			break;
		}
	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
// 1. Use the Solution Explorer window to add/manage files
// 2. Use the Team Explorer window to connect to source control
// 3. Use the Output window to see build output and other messages
// 4. Use the Error List window to view errors
// 5. Go to Project > Add New Item to create new code files, or
//Project > Add Existing Item to add existing code files to the project
// 6. In the future, to open this project again, go to File > Open >
//Project and select the.sln file