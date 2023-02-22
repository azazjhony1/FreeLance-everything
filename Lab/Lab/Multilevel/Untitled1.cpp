#include <iostream>
using namespace std;

int main(){
	int arr[5];
	for(int k = 0; k<5; k++){
		cout<<"Please enter the burst time for the process # "<<k+1<<": ";
		cin>>arr[k];
		cout<<endl;
	}
	
	for(int i=0; i<5; i++){
		if(arr[i]>0){
			arr[i] = arr[i] - 4;
			cout<<"Process # "<<i+1<<": "<<arr[i]<<endl;
		}
		
	}
	
	for(int i=0; i<5; i++){
		if(arr[i]>0){
			if(arr[i] > 8 ){
				arr[i] = arr[i] - 8;
			}
			else{
				arr[i] = arr[i] - arr[i];
			}
			cout<<"Process # "<<i+1<<": "<<arr[i]<<endl;
		}
		
	}
	
	for(int i=0; i<5; i++){
		if(arr[i]>0){
			arr[i] = arr[i] - arr[i];
			cout<<"Process # "<<i+1<<": "<<arr[i]<<endl;
		}
		
	}
	
}
