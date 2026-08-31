#include<iostream>
using namespace std;
int main(){
	int N;
	cout << "Enter the no.of Reading:";
	cin >> N;
	int arr[N];
	int Reading;
	for(int i=0;i<N;i++){
	cout << "Enter the Reading:";
	cin >> Reading;
	arr[i] = Reading;
	}
	double min, max, sum=0, count=0;
	bool first = true;
	int normal=0,warning=0,critical=0,shutdown=0;
	int firstindex=-1;
	for(int i=0; i<N; i++)
	{
		if(arr[i] < 0){
		    continue;
		}
		cout << arr[i] << endl;

		if(firstindex == -1 && arr[i] >= 45)
			firstindex=i;
		if(first){
		    min = max = arr[i];
		    first = false;
		} else {
		    if(arr[i] < min) min = arr[i];
		    if(arr[i] > max) max = arr[i];
		}
		if(arr[i] > max)
		sum+=arr[i];
		count++;
		if(arr[i]<30)
			normal++;
		else if(arr[i]<40)
			warning++;
		else if(arr[i]<50)
			critical++;
		else
			shutdown++;

	if(firstindex == -1)
		cout<< "First Reading >=45C at index:"<<firstindex<<endl;
	else
		cout<< "NoReading >=45C found.";
	if(count==0){
		cout<<"No valid Readings"<<endl;
	}else{
	cout<<"Min:"<<min;
	cout<<"Max"<<max;
	cout<<"avg"<<(sum/count)<<endl;
}
	 cout << "Normal: " << normal << endl;
	    cout << "Warning: " << warning << endl;
	    cout << "Critical: " << critical << endl;
	    cout << "Shutdown: " << shutdown << endl;
	    return 0;
	
}
}

