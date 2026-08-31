#include <iostream>
using namespace std;
int main() {
	 double temp;
	 int Status;
	cout << "enter temp:";
	cin >> temp;
	if(temp <0){
		Status = -1;
	}else if (temp <=29) {
		Status = 0;
	}else if (temp <= 44) {
		Status= 1;
	}else if (temp <= 59) {
		Status = 2;
	}else {
		Status= 3;
	}
	cout << "Status: ";
	switch(Status){
	case 1:
		cout<< "SENSOR_ERROR\nActionSensor fault: check wiring";
		break;
	case 2:
		cout << "NORMAL\nNo Action Required"<< endl;
		break;
	case 3:
		cout << "WARNING\nAlert sent to Supervisor";
		break;
	case 4:
		cout<< "CRITICAL\nCooling system triggered.";
		break;
	case 5:
		cout << "SHUTDOWN\nEmergency shutdown initiated.";
		break;
	}
	 double fahrenheit = (temp * 9.0 / 5.0) + 32;
	    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;

	    cout << "Comparison with 25°C: "
	            << (temp > 25 ? "Above Average" : "Below Average") << endl;



	return 0;
}
