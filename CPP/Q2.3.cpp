#include <iostream>
using namespace std;
	int statusReg = 0b10110001; // Read-only from firmware side
	int controlReg = 0b00000000; // Firmware writes here
	int dataReg = 0b11001010; // For reassignment demo
	int main() {
		const int* regPtr1=&statusReg;                              // ERROR: assignment of read-only location '* regPtr1'
		cout << "regPtr1"<< regPtr1 << "\n";                           // OK: repointing allowed.
	 int* const regPtr2=&controlReg;                            // regPtr2 = &dataReg;     // ERROR: assignment of read-only variable 'regPtr2'
		 *regPtr2 = 0b11110000;
		 // regPtr2 = &dataReg; ERROR: assignment of read-only variable 'regPtr2'
		    // but *regPtr2 is alloweds
		 cout << "controlReg"<<controlReg<<"\n";
		const int* regPtr3=&dataReg;
		cout << "regPtr3"<< regPtr3 << "\n";
		//ERROR: assignment of read-only location '* regPtr3'
		    // regPtr3 = &dataReg; ERROR: assignment of read-only variable 'regPtr3'

		    return 0;
}