#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float temp[3][3];
	cout << "Temprature of 3 Floor and 3 Room.";
	for(int i = 0;i<3; i++) {
		for (int j= 0;j<3; j++) {
			cout << "Floor " << i+1 << " Room " << j+1 << "  " << endl ;
			cin >> temp[i][j];
              }
	}
	cout<< "Temprature Table \n:";
			for (int i = 0;i<3; i++) {
				cout << "Floor " << i+1 << " : ";
					for(int j= 0;j<3; j++) {

						cout << temp[i][j] << "\t";
					}
					cout<< endl;
			}
	float maxtemp = temp[0][0];
	int maxfloors = 0,maxroom = 0;
	for (int i = 0;i<3; i++) {
						for (int j= 0;j<3; j++) {
	if (temp[i][j] > maxtemp ) {
	maxtemp = temp[i][j];
	maxfloors = i;
	maxroom = j;
           }
		}
	}
	cout << "\nHottest Room : Floor " << maxfloors + 1
	     << ", Room " << maxroom + 1
	     << " -> " << maxtemp << "°C\n";
	float maxavg =0;
	int bestfloor = 0;
	for (int i = 0;i<3; i++) {
		float sum =0;
	for (int j= 0;j<3; j++) {
		sum += temp[i][j];
	}
	float avg = sum /3;
	if(i == 0 || avg > maxavg) {
		maxavg = avg ;
		bestfloor = i;
	}
}
	cout << "Hottest Floor : Floor " << bestfloor + 1
	     << " (avg " << maxavg << "°C)\n";
			   int count = 0;
			    for (int i = 0; i <3; i++) {
			        for (int j = 0; j < 3; j++) {
			            if (temp[i][j] >= 30) {
			                count++;
			            }
			                    }
			                }

			    cout << "Rooms at WARNING or above : " <<count ;

			                return 0;
			            }
