#pragma once
#include <iostream>
using std::string;

struct Solution {
	float refract_i;
	string name;
	Solution* up;
	Solution* down;

	Solution(float index, string n) { refract_i = index; name = n; up = NULL; down = NULL; }
};

class Beaker {

private:

	Solution* top;	  
	Solution* bottom; 

public:
	
	Beaker() { top = NULL; bottom = NULL; }

	void pour_into(float ri, string nam);
	void remove();		 // Removes the top liquid.
	void traverse();     // Displays the layers of liquid from top to bottom, AND determines whether phase changes happen. 
	int constr_int(int lambda);    // Displays minimum thickness for complete constructive interference
	int destr_int(int lambda);     // Displays minimum hickness for complete destructive interference
	int composition();   // Returns amount of different items in beaker. (Air counts as an item)
	bool emptybeaker();  // Checks if the beaker contains no liquid.


	Solution topliquid(); // returns liquid at top and its refractive index.
};