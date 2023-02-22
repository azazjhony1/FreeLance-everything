#include<iostream>

using namespace std ;

int main(){
	int p[5] = {10,6,5,7,4} ;
	int time = 5 ; 
	
	cout<<"Array : " ;
	for(int i=0 ; i<5 ; i++){
			cout<<p[i] << " " ;
	}
	cout<<endl;
	
	
	int e_time_array[5] = {0,0,0,0,0};
	int e_time = 0 ;
	while(true){
		
	
		for(int i=0 ; i<5 ; i++){			
			if(p[i]<time){
				e_time = e_time + p[i] ;
				p[i] = p[i] - p[i] ;
			}else{
				p[i] = p[i] - time ; 
				e_time = e_time + time ;
			}
			
			if(p[i] == 0){
				if(e_time_array[i]==0){
					e_time_array[i] = e_time ; 
				}	
			}
			
		}
		
		
		bool c = true ; 
		for(int i=0 ; i<5 ; i++){
			if(p[i] != 0){
				c = false ; 
			}
		}
		
		cout<<"Execution: " ;
		for(int i=0 ; i<5 ; i++){
			cout<<p[i] << " " ;
		}
		
		cout<<endl ; 
		if(c==true){
			break ; 
		}
			
	}
	
	cout<<"Total Execution Time: " ;
		for(int i=0 ; i<5 ; i++){
			cout<<e_time_array[i] << " " ;
	}
	
}
