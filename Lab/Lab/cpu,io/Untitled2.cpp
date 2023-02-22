#include<iostream>


using namespace std ;

int main(){
	int cpu[] = {10,19,25,10,19,25} ;
	int io[]  = {20,10,40,20,20,40} ;
	
	int cpusize = 6 ; 
	int iosize  = 6 ; 
	
	int ctime = 0 ; 
	int itime = 0 ; 
	
	int c = 0 ; 
	int i = 0 ;
	
	while(true){
		ctime = ctime+cpu[c];
		c++;
		if(c==cpusize-1){
			break;	
		}
	}
	
}
