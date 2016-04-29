#include <iostream>
#include "qbit.h"

int main(int argc, char* argv[]) {
	Qbit qbit1(LOW), qbit2(LOW); // Start with two classic bits at LOW state
	
	for (int i = 0 ; i < 100 ; i++)
		cout << (qbit1 & qbit2) << " " << (qbit1 | qbit2) << " " << (qbit1 ^ qbit2) << endl; // All should be always 0
	cout << endl;
	
	qbit1.add_state(HIGH); // Superpose the HIGH state on the LOW state of the first qbit
	
	for (int i = 0 ; i < 100 ; i++)
		cout << (qbit1 & qbit2) << " " << (qbit1 | qbit2) << " " << (qbit1 ^ qbit2) << endl; // & should be always 0 ; | should be 50% 0 and 50% 1 ; ^ should be 50% 0 and 50% 1
	cout << endl;
	
	qbit2.add_state(HIGH); // Superpose the HIGH state on the LOW state of the second qbit
	
	for (int i = 0 ; i < 100 ; i++)
		cout << (qbit1 & qbit2) << " " << (qbit1 | qbit2) << " " << (qbit1 ^ qbit2) << endl; // & should be 75% 0 and 25% 1 ; | should be 25% 0 and 75% 1 ; ^ should be 50% 0 and 50% 1
	
	return 0;
}

