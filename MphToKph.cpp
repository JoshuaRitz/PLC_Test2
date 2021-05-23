#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

enum Speed{
	slow = 30, 
	average = 60, 
	fast = 80
};

enum MphConverter{
	Mph, 
	Kph
};

void SpeedLevel(int convertedValue);

int main() {
	while(true) {
		MphConverter Converter;
		int userInput, choice, convertedValue;
		cout << "-------------------" << endl;
		cout << "Please enter your choice: " << endl;
		cout << "Enter " << Mph << " to convert from Mph to Kph" << endl;
		cout << "Enter " << Kph << " to convert from Kph to Mph" << endl;
		cout << "Choice: ";
		cin >> choice;
		
		switch(choice) {
			case Mph:
			cout << "Please enter the speed in Mph: ";
			cin >> userInput;
			convertedValue = (userInput*1.609344);
			cout << "Your speed in Kph is " << convertedValue << endl;
			SpeedLevel(userInput);
			break;
			
			case Kph:
			cout << "Please enter the speed in Kph: ";
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
		
		cout << (slow + fast) << endl;
		cout << (fast - average) << endl;
		cout << (Mph + Kph) << endl;
		cout << ((Mph + Kph + Kph)*slow) << endl;
		cout << (Mph | Kph) << endl;
		cout << (fast & slow) << endl;
		cout << (slow + fast - average) << endl;
		cout << ((slow + fast + average)*Mph) << endl;
		cout << "-------------------" << endl;
	}
}

void SpeedLevel(int convertedValue) {
	string result;
	convertedValue <= slow ? result = "You are travelling pretty slow" : "";
	convertedValue > slow && convertedValue <= average ? result = "You are travelling at average speed" : "";
	convertedValue > average && convertedValue <= fast ? result = "You are travelling fast! Slow down!" : "";
	convertedValue > fast ? result = "You're gonna get a ticket!" : "";
	cout << result << endl;
}
