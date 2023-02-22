#include <iostream>

using namespace std;

int main(){
	int s1 = 40;
	int s2 = 24; 
	int j = -1;
	int arr[]={25, 20, 15, 10, 5};
	
	while(true){
	
		for(int i=0; i<5; i++){
			if(s1>0){
				if(arr[i]>0){
					if(arr[i]>4){
						arr[i] = arr[i] - 4;
					}else{
						arr[i] = arr[i] - arr[i];
					}
					
					cout<<"Process # "<<i+1<<": "<<arr[i]<<endl;
					s1 = s1-4;
		}
		
	}
	}
	

		for(int i=0; i<5; i++){
			if(s2>0){
				if(arr[i]>0){
					if(arr[i] > 8 ){
					arr[i] = arr[i] - 8;
					}
				else{
					arr[i] = arr[i] - arr[i];
				}
				cout<<"Process # "<<i+1<<": "<<arr[i]<<endl;
				s2=s2-8;
		}
		
	}
	}
	
	
	j = j + 1;
		if(arr[j]>0){
			if(arr[j]>10){
				arr[j] = arr[j] - 10;
			}else{
				arr[j] = arr[j] - arr[j];
			}
			cout<<"Process # "<<j+1<<": "<<arr[j]<<endl;
		}
		
	if(s1 == 0 && s2==0 && arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0 ){
		return 0;
	}
	
	}
	
}
