#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void SpeedLevel(int convertedValue);

int main() {
	while(true) {
		int userInput, choice, convertedValue;
		cout << "-------------------" << endl;
		cout << "Please enter your choice: " << endl;
		cout << "Enter 0 to convert Mph to Kph" << endl;
		cout << "Enter 1 to convert Kph to Mph" << endl;
		cout <<"Choice: ";
		cin >> choice;
		
		switch(choice) {
			case 0:
			cout << "Please enter your speed in Mph: ";
			cin >> userInput;
			convertedValue = (userInput*1.609344);
			cout << "Your speed in Kph is: " << convertedValue << endl;
			SpeedLevel(convertedValue);
			break;
			
			case 1:
			cout << "Please enter your speed in Kph: ";
			cin >> userInput;
			convertedValue = (userInput/1.609344);
			cout << "Your speed in Mph is: " << convertedValue << endl; 
			SpeedLevel(convertedValue);
			break;
			
			
			default:
			cout << "Invalid Option" << endl;
			exit(0);
			break;
		}
		
		cout << "-------------------" << endl;
		//Some additional frivolous operations in case the conversion operations weren't enough
		cout << "Here's what happens if we do some operations on the slow, average, and fast" << endl;
		cout << "enumerations. We will combine these with the Mph and Kph enumerations as well" << endl;
		cout << "just to see what kind of weird things we can do!!" << endl;
		
		cout << (30 + 80) << endl;
		cout << (80 - 60) << endl;
		cout << (0 + 1) << endl;
		cout << ((0 + 1 + 1)*30) << endl;
		cout << (0 | 1) << endl;
		cout << (80 & 30) << endl;
		cout << (30 + 80 - 60) << endl;
		cout << ((30 + 80 + 60)*0) << endl;
		cout << "-------------------" << endl;
	}
}

void SpeedLevel(int convertedValue) {
	string result;
	convertedValue <= 30 ? result = "You are travelling pretty slow" : "";
	convertedValue > 30 && convertedValue <= 60 ? result = "You are travelling at average speed" : "";
	convertedValue > 60 && convertedValue <= 80 ? result = "You are travelling fast! Slow down!" : "";
	convertedValue > 80 ? result = "You're gonna get a ticket!" : "";
	cout << result << endl;
}