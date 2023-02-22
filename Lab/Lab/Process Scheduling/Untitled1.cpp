#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

int main(){
	int size = 5 ; 

	int x[size] = {5,8,11,4,2};
	
//	sort(x , x + size) ;
	
	int wait_time[size] ; 
	int sum = 0 ; 
	
	for(int i = 0 ; i<size ; i++){
		wait_time[i] = sum ; 
		sum = sum + x[i];
	}
	
	float total_sum = 0 ; 
	cout<<"Waiting time array : " <<endl ;
	for(int i=0 ; i<size ;  i++ ){
		total_sum = total_sum + wait_time[i];
		cout<<wait_time[i] <<" " ;
	}
	float avr = total_sum / size ; 
	
	cout<<"Avr = " <<avr ; 
	
} 

