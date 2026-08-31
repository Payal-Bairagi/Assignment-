#include <iostream>
#include<cmath>
using namespace std;
inline double distanceBetween(double x1, double y1, double x2, double y2){
 return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}
inline double toRadians(double degrees){
return  degrees * (M_PI / 180.0);
}
inline double clamp(double value, double minVal, double maxVal){
if(value <minVal)return minVal;
if(value > maxVal)return maxVal;
return value;
}
inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){
 double dist= distanceBetween(x,y,cx,cy);
 return dist <=radius;
}
int main() {
	//home position
	double cx=0.0,cy =0.0;
	double radius = 50.0;
	// waypoints
	double x1= 10 ,y1 =20;
	double x2 =30, y2=40;
	double x3= 50, y3=60;
	double d1 = distanceBetween(x1, y1, cx, cy);
	cout << "Waypoint 1 Distance: " << d1 << endl;
	    cout << "Safe Zone: " << (isInSafeZone(x1, y1, cx, cy, radius) ? "YES" : "NO") << endl;
	    double d2 = distanceBetween(x2, y2, cx, cy);
	    	cout << "Waypoint 2 Distance: " << d2 << endl;
	    	    cout << "Safe Zone: " << (isInSafeZone(x2, y2, cx, cy, radius) ? "YES" : "NO") << endl;
	    	    double d3 = distanceBetween(x3, y3, cx, cy);
	    	        cout << "Waypoint 3 Distance: " << d3 << endl;
	    	        cout << "Safe Zone: " << (isInSafeZone(x3, y3, cx, cy, radius) ? "YES" : "NO") << endl;

	return 0;
}
