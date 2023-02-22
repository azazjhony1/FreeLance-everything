#include <iostream>


using namespace std;

int main(){
	int a[5] = {25,20,15,10,5}  ;
	int b[5] = {0,0,0,0,0}		;
	int c[5] = {0,0,0,0,0}		;
	
	int s1 = 12 ;
	int s2 = 24 ;
	
	int q1 = 4 ; 
	int q2 = 8 ;
	int q3 = 10 ; 
	
	cout<<"Start " <<endl ; 
	cout<<"A : ";	for(int i=0 ; i <5 ;i++){	cout<<a[i] <<" ";	}	cout<<endl;
	cout<<"B : ";	for(int i=0 ; i <5 ;i++){	cout<<b[i] <<" ";	}	cout<<endl;
	cout<<"C : ";	for(int i=0 ; i <5 ;i++){	cout<<c[i] <<" ";	}	cout<<endl;
	cout<<endl <<endl ;
	
	while(true){
	
	int e = 0 ; 
	for(int i=0 ; i<5 ; i++){
		if(a[i]>0){
	
		a[i] = a[i] - q1 ;
		e = e + q1 ;
		
		if(a[i]<0){	a[i] = -1;	}
		
		if(a[i] > 0){
			b[i] = a[i];
			a[i] = -1  ;
		}
		
		if(e>=s1){
			break;
		} 
		
		} 
	}
	
	cout<<"After First: " <<endl ; 
	cout<<"A : ";	for(int i=0 ; i <5 ;i++){	cout<<a[i] <<" ";	}	cout<<endl;
	cout<<"B : ";	for(int i=0 ; i <5 ;i++){	cout<<b[i] <<" ";	}	cout<<endl;
	cout<<"C : ";	for(int i=0 ; i <5 ;i++){	cout<<c[i] <<" ";	}	cout<<endl;
	cout<<endl <<endl ;

	
	e = 0 ;
	for(int i=0 ; i<5 ; i++){
		if(b[i]>0){
	
		b[i] = b[i] - q2 ;
		e = e + q2 ;
		
		if(b[i]<0){	b[i] = -1;	}
		
		if(b[i] > 0){
			c[i] = b[i];
			b[i] = -1  ;
		}
		
		if(e>=s2){
			break;
		} 
		
		} 
	}
	
	cout<<"After Second " <<endl ; 
	cout<<"A : ";	for(int i=0 ; i <5 ;i++){	cout<<a[i] <<" ";	}	cout<<endl;
	cout<<"B : ";	for(int i=0 ; i <5 ;i++){	cout<<b[i] <<" ";	}	cout<<endl;
	cout<<"C : ";	for(int i=0 ; i <5 ;i++){	cout<<c[i] <<" ";	}	cout<<endl;
	cout<<endl <<endl ;

	
 
	for(int i=0 ; i<5 ; i++){
		if(c[i]>0){
		c[i] = -1 ;
		break ;
		} 
	}
	
	cout<<"After Third " <<endl ; 
	cout<<"A : ";	for(int i=0 ; i <5 ;i++){	cout<<a[i] <<" ";	}	cout<<endl;
	cout<<"B : ";	for(int i=0 ; i <5 ;i++){	cout<<b[i] <<" ";	}	cout<<endl;
	cout<<"C : ";	for(int i=0 ; i <5 ;i++){	cout<<c[i] <<" ";	}	cout<<endl;
	cout<<endl <<endl ;
	
	bool x = true ; 
	for(int i=0 ; i<5 ; i++){
		if(c[i]>0){
			x = false ;
		}
	}
	
	if(x == true){
		break;
	}
	
}
	
	

}
