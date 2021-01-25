#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Interference_Beaker.h"

using std::cout;
using std::cin;
using std::endl;

	/***********************************************
		This program demonstrates the optical physics behind
	 thin film interference and interference of light in
	 materials with a specific refractive index.
 
	 The thin films will represent the standard doubly
	 linked list. (Assume that the films have tabs in
	 which they can be removed in between other films
	 that have been placed.)
	 
	 A beaker containing liquid will represent a stack
	 created from a doubly linked list.

	 The limit for both types of containers/media will
	 be 3 different materials at a time.
	 
	***********************************************/

// Air = 1
// Water = 1.33 
// Ethyl Alcohol = 1.36
// Soap (Arbitrary Brand) = 1.4
// Corn Oil = 1.47
// Egg Yolk = 1.53
// Carved Glass (Max Refractive Index) = 1.7
// Carved Diamond = 2.42

// Film 1 = 1.10
// Film 2 = 1.25
// Film 3 = 1.35
// Film 4 = 1.40
// Film 5 = 1.50
// Film 6 = 1.60
// Film 7 = 1.90
// Carved Glass = 1.7

						 //  V    I    B    G    Y    O    R
const int lowerbounds[] = { 380, 425, 445, 520, 565, 590, 625 };
const int upperbounds[] = { 424, 444, 519, 564, 589, 624, 740 };

struct Color {
	string name;
	int wavelength;
};

int main()
{
		srand( (unsigned int)time(0));
		Color rainbow[7] = { {"Red"}, {"Orange"}, {"Yellow"}, {"Green"}, {"Blue"}, {"Indigo"}, {"Violet"} };

		cout << "Color Wavelengths of Visible Light: " << endl;
		cout << R"(
				  Red = 625 - 740 nm
				  Orange = 590 - 624 nm
				  Yellow = 565 - 589 nm
				  Green = 520 - 564 nm
				  Blue = 445 - 519 nm
			          Indigo = 425 - 444 nm
				  Violet = 380 - 424 nm)";
		cout << '\n';
		cout << '\n';
		cout << "Chosen Color Wavelengths: " << endl << endl;

		for (int i = 0; i < 7; i++) {
			rainbow[i].wavelength = rand() % (upperbounds[6 - i] - lowerbounds[6-i] + 1) + lowerbounds[6-i];
			cout << rainbow[i].name << ": " << rainbow[i].wavelength << " nm" << endl;
		}

	// Part 1: Beaker

	// Trial 1: Soap Bubble (Air, Soap, Air)
	// Trial 2: Liquid Density Mixture (Air, Ethyl Alcohol, Corn Oil, Egg Yolk)
	// Trial 3: Liquid Density Mixture (Water, Carved Glass, Carved Diamond) (NOTE: Neglects light passing through air)
	// Trial 4: Liquid Density Mixture (Air, Egg Yolk, Water, Carved Glass)

	// Part 2: Thin Films

	// Trial 1: Films 1, 4, and 8
	// Trial 2: Films 1, 7, and 3
	// Trial 3: Films 2, 3, 5, and 6
	// Trial 4: Films 4, 1, 6, and 2

	Beaker container1;

	cout << "\n";
	cout << "Trial 1: Soap Bubble (Air, Soap, Air)" << endl;
	cout << "\n";
	
	if (container1.emptybeaker() == false) {
		cout << "Beaker is currently filled." << endl;
		cout << "\n";
	}
	else {
		cout << "Beaker is currently empty." << endl;
		cout << "\n";
	}
	
	cout << "Creating a soap bubble: " << endl;
	container1.pour_into(1, "Air");
	container1.pour_into(1.4f, "Soap");
	container1.pour_into(1, "Air");

	
	container1.traverse();

	cout << "\n";
	cout << "Testing scenarios: Minimal thickness of soap layer for full constructive interference and destructive interference." << endl;

	cout << "\n";
	cout << "Constructive Interference:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << rainbow[i].name << ": " << container1.constr_int(rainbow[i].wavelength) << " nm" << endl;
	}

	cout << "\n";
	cout << "Destructive Interference:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << rainbow[i].name << ": " << container1.destr_int(rainbow[i].wavelength) << " nm" << endl;
	}



	Beaker container2;

	cout << "\n";
	cout << "Creating a mixture of corn oil and egg yolk." << endl;
	container2.pour_into(1.53f, "Egg Yolk");
	container2.pour_into(1.47f, "Corn Oil");
	container2.pour_into(1, "Air");
	
	cout << "\n";
	
	container2.traverse();

	cout << "\n";
	cout << "Testing same process for solution." << endl;

	cout << "\n";
	cout << "Constructive Interference:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << rainbow[i].name << ": " << container2.constr_int(rainbow[i].wavelength) << " nm" << endl;
	}

	cout << "\n";
	cout << "Destructive Interference:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << rainbow[i].name << ": " << container2.destr_int(rainbow[i].wavelength) << " nm" << endl;
	}

		return 0;
}

// Referendum
// https://www.uib.no/sites/w3.uib.no/files/styles/content_main/public/media/visible_light.jpg?itok=Q14T4a9e