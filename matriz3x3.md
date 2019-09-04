# aprendendo.c
exercícios aula/estudo
//calcular matriz 3x3

#include <stdio.h>
int main(){

int det1,det2,det3,det4,det5,det6;
int soma;
int matriz[3][3]={{1,2,3},{2,3,4},{4,5,2}};

for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){	
		printf("%i " , matriz[i][j]);
		printf("\n");
		}
	
	}

det1=(matriz[0][0]*matriz[1][1]*matriz[2][2]);
det2=(matriz[0][1]*matriz[1][2]*matriz[2][0]);
det3=(matriz[0][2]*matriz[1][0]*matriz[2][1]);

det4=(matriz[2][0]*matriz[1][1]*matriz[0][2]);
det5=(matriz[2][1]*matriz[1][2]*matriz[0][0]);
det6=(matriz[2][2]*matriz[1][0]*matriz[0][1]);

soma=det1+det2+det3-det4-det5-det6;

printf("%i", soma);

}
