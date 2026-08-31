#include<iostream>
using namespace std;
bool parsePacket(const int* rawData, int size,
 int** outMin, int** outMax){
// If size <= 0 : return false, leave output pointers unchanged
// Otherwise : set *outMin to point at the minimum element in rawData
// set *outMax to point at the maximum element in rawData
// return true
if (size<=0)
	return false;
int* minPtr = (int*)&rawData[0];
int* maxPtr = (int*)&rawData[0];
for(int i = 1; i < size; i++){
	if (rawData[i] < *minPtr)
	    minPtr = (int*)&rawData[i];
	if (rawData[i] > *maxPtr)
	    maxPtr = (int*)&rawData[i];
}
*outMin = minPtr;
*outMax = maxPtr;
return true;
}
int main(){
	int packet[] = {45, 12, 67, 8, 55, 31};
	int* minPtr = nullptr;
	int* maxPtr = nullptr;
	if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
	 cout << "Calibration Min : " << *minPtr << endl;
	 cout << "Calibration Max : " << *maxPtr << endl;
	}

}
