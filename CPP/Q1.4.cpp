#include <iostream>
#include <ctime>
using namespace std;

	int main (int argc , char*argv[]){
		if (argc !=4){
			cout<< "Usage : /sensor_monitor <warn_threshold> <critical_threshold><num_reading>"<<endl;
			return 1; //stop program if argument missing
		}
		int warn =atoi(argv[1]);               // warn threshold
		int critical = atoi(argv[2]);          // critical threshold
		int n =atoi(argv[3]);                  // number of reading;
		if (warn >= critical){
			cout << "Error : warn_threshold must be less than critical threshold."<< endl;
			return 1;
		}
		if(n < 1 || n > 0500 ){
			cout << "num_reading must be between 1 to 500." << endl;

			return 1;    // stop if invalid
		}
		srand(time(0));   // check if n is between 1 and 500
		int normal = 0, warning =0, criticalcount=0, shutdown=0;

		// loop for n readings
		for(int i =0;i<n;i++){
			int temp = rand() % 70;    // random temperature (0 - 69)
		if(temp <warn)
			normal++;        // low temp
		else if (temp< critical)
			warning++;        // high temp
		else if (temp < 60)
			critical++;       // very high temp
		else
			shutdown; // @suppress("Statement has no effect")
		}
		cout << "Config :warn=" <<warn << "°C critical="<< critical <<"°C readings="<<n << endl;
        cout << "argc=" << argc << endl;
		cout << "Normal" <<normal;
		cout << "Warning" << warning;
		cout << "Critical" << criticalcount;
        cout << "shutdown" << shutdown;
        return 0;

		}




