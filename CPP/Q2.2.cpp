#include <iostream>
#include <cmath>
using namespace std;
// computeRMS
   double computeRMS(double* signal, int n)
   {
    double sum = 0;
    double* ptr=signal;

    for(int i = 0;i<n;i++){
    	sum+= (*ptr) *(*ptr);
		ptr++;
    }
    return sqrt(sum/2);
    }
//Normlise
   void normalise(double* signal, int n){
	   double* ptr=signal;
	   double maxval=0;
	   for(int i = 0;i < n;i++){
	   if(fabs(*ptr)>maxval){                       //absolute value of a floating number.
		   maxval = fabs(*ptr);
	   }
	   ptr++;
   }
   if(maxval==0)
	   return;
    ptr =signal;
   for(int i = 0;i < n;i++){
	   *ptr= (*ptr)/maxval;
   ptr++;
   }
   }
   // countzerocrossings
   int countZeroCrossings(double* signal, int n){
	   int count = 0;
	   double* ptr =signal;
	   for(int i = 0;i < n;i++){
		   if((*ptr)*(*(ptr + 1))<0){
			   count++;
		   }
		   ptr++;
	   }
	   return count;
   }
   //Applygain
   void applyGain(double* signal, int n, double gainFactor){
	   double* ptr=signal;
	   for(int i = 0;i < n;i++){
	   		cout <<*ptr<<" "<<endl;
	   		ptr++;
   }
   }
   void PrintArray(double* signal, int n) {
       double* ptr = signal;
       for (int i = 0; i < n; i++) {
           cout << *ptr << " ";
           ptr++;
       }
       cout << endl;
   }
   int main(){
	   double signal[]={0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
	   int n =7;
	   cout<< "Original Array:";
	    PrintArray (signal,n);
	    normalise(signal,n);
	   cout << "After Normalization";
	   PrintArray (signal,n);
	   applyGain(signal,n,2.0);
	   cout<< "AfterbApplying Gain:";
	   PrintArray (signal,n);
	   double RMS =computeRMS(signal,n);
	   cout<<"RMS Value:"<<RMS << endl;
	   int ZeroCross = countZeroCrossings(signal,n);
	   cout<<"ZeroCrossings"<<ZeroCross << endl;

	   return 0;
   }






