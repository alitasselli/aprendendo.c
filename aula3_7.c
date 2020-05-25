#include <stdio.h>
#include <stdlib.h>

int sequence(int n){ //fibonacci+soma

	int f1=1,f2=1,f=0,sum_even=0,comp;
	
	for(int i=3;i<n;i++){
		f=f1+f2;
		f1=f2;
		f2=f;
		
		if(f%2 == 0 && f<=4000000){
			sum_even+=f;
		}
	}

	return sum_even;
}

int main(int argc, char*argv[]){

	int n=atoi(argv[1]);

	int soma=sequence(n);
	
	printf("soma %d\n",soma );

}