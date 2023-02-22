#include<iostream>

using namespace std ;

int main(){
	int p[5] = {25,20,15,10,5} ;
	
	int q1 = 4 ; 
	int q2 = 8 ; 
	 
	int e_time_array[5] = {0,0,0,0,0};
	int e_time = 0 ;
	
	for(int i=0 ; i<5 ; i++){
		cout<<p[i] <<" " ;
	}
	cout<<endl;
	
	//////////////////////////////////////////
	
	for(int i=0 ; i <5 ; i++){
		
		if(p[i]<q1 && p[i]>0){
			e_time = e_time + p[i] ;
			p[i] = p[i] - p[i] ;
		}else{
			p[i] = p[i] - q1 ; 
			e_time = e_time + q1 ;
		}
		
		if(p[i] == 0){
			if(e_time_array[i]==0){
				e_time_array[i] = e_time ; 
			}	
		}
		
		cout<<p[i] <<" " ;
	}
	cout<<endl ;
	
	
	for(int i=0 ; i <5 ; i++){
		if(p[i]<q2 && p[i]>0){
			e_time = e_time + p[i] ;
			p[i] = p[i] - p[i] ;
		}else{
			p[i] = p[i] - q2 ; 
			e_time = e_time + q2 ;
		}
		
		if(p[i] == 0){
			if(e_time_array[i]==0){
				e_time_array[i] = e_time ; 
			}	
		}
		
		cout<<p[i] <<" " ;
	}
	cout<<endl;
	

	for(int i=0 ; i<5 ; i++){

		if(p[i]>0){
			e_time = e_time + p[i] ;
			p[i] = p[i] - p[i];		
			if(e_time_array[i]==0){
				e_time_array[i] = e_time ; 
			} 
		}
		
		cout<<p[i] <<" " ;
	}
	cout<<endl;
	
	///////////////////////////////////
	cout<<"Execution time : " <<endl;
	for(int i=0 ; i<5 ; i++){
		cout<<e_time_array[i] <<" " ;
	}
	cout<<endl;
	
}
