//sleeping teaching assistant 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*check list :)
//FEITO// TA is sleeping. //comeco do codigo, ja e o ta sleeping
//FEITO// TA went back to sleep. //nao tem estudantes para ajudar na fila
//FEITO// TA is teaching student #?. // ajuda sendo executada
//FEITO// TA finished teaching student #?. //random time terminou
//FEITO// Student #? is going to TA room. //checar a disponibilidade da sala da 
//FEITO// Student #? is awaking the TA.  //semaforo awake
//FEITO// Student #? is getting inside TA room. //muda a desponibilidade da sala p ocupada
//FEITO// Student #? left TA room. //muda a sala p disponivel
//FEITO// There is no available chair to student #?. The student will return late. //vai voltar depois ficando no while
//FEITO// Student #? sat on chair #?. #? chair(s) remain. //students podem sentar e ocupam na cadeira que estiver usando
//FEITO// There is no more students to help. TA left the room. //final e quando o ta ajudar todos os argv[1] estudantes*/

//FUNÇÕES DOS ESTUDANTES E TA
void *students_Actions(void *variable);
void *ta_Actions(void *variable);

//VARIÁVEIS GLOBAIS
int chairs[3] = {0,0,0};
int room_state = 0;
int quant_chairs;
int student_number = 0; 
int student_check;
int current_student;

//CRIAR MUTEX
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//CRIAR SEMÁFORO
sem_t *semaphore; 

int main(int argc, char *argv[]){

	int quantity = atoi(argv[1]); 

	student_check = quantity; //VARIÁVEL PARA CHECAGEM

	semaphore = sem_open("/waking", O_CREAT, 0644, 0); //INICIALIZAR O SEMÁFORO

	//CRIAR X PTHREADS DOS ESTUDANTES
	pthread_t *students_pthreads = malloc(sizeof(pthread_t) *quantity);

	for(int i = 1; i < quantity+1; i++){
		pthread_create(&students_pthreads[i], NULL, students_Actions, &i);
		usleep(5000);
	}

	//CRIAR PTHREAD DO TA
	pthread_t teaching_ass; 
	pthread_create(&teaching_ass, NULL, ta_Actions, NULL);

	pthread_join(teaching_ass, NULL); //ESPERAR A THREAD TERMINAR PARA FINALIZAR O PROGRAMA


}

int chair_Available(){ //CHECAR A DISPONIBILIDADE DAS CADEIRAS

	
	for(int i  = 0; i < 3; i++){ 
								
		if(chairs[i] == 0){ //RETORNAR O ÍNDICE DA CADEIRA DISPONÍVEL
			return i;  		
		}
	}
		return -1; //RETORNA -1 SE TODAS AS CADEIRAS ESTIVEREM DISPONIVEIS
}


int student_Chair_Id(){ //RETORNAR A ID DO ESTUDANTE NA CADEIRA ATUAL

	for(int i  = 0; i < 3; i++){ 
								
		if(chairs[i] != 0){
			return i;  		
		}
	}
		return -1;
}


void *students_Actions(void* variable){ //FUNÇÃO DOS ESTUDANTES

	
	int *id_pointer = variable; //DEFINIR ALUNO QUE ESTA EXECUTANDO
	int id = *id_pointer; 

	while(1){

		sleep(2); 
		
		printf("Student #%d is going to TA room.\n", id);

		pthread_mutex_lock(&mutex); //SÓ UM ESTUDANTE PODE EXECUTAR ISSO POR VEZ 

		sem_post(semaphore); 

		if(room_state == 1){ //SE A SALA ESTIVER OCUPADA, CHECA AS CADEIRAS

			int c_state = chair_Available(); 

			if(c_state != -1){ //ESTA DISPONIVEL SE O ESTADO FOR DIFERENTE DE -1 
				chairs[c_state] = id; //INDICE DA CADEIRA MUDA PARA A ID DO ESTUDANTE 

				printf("Student #%d sat on chair #%d. #%d chair(s) remain.\n", id, c_state, 2 - c_state);
				quant_chairs++;//AUMENTAR A QUANTIDADE DE CADEIRAS DISPONIVEIS
				pthread_mutex_unlock(&mutex);
				return NULL;

			}

			else{
				printf("There is no available chair to student #%d. The student will return late.\n", id);
				pthread_mutex_unlock(&mutex);
				continue; //VOLTA PARA O COMEÇO DO WHILE, SE NAO TIVER DISPONIVEL
			}
			pthread_mutex_unlock(&mutex);
		}

		

		else{ //SE A SALA ESTIVER VAZIA

			current_student = id; //DEFINIR O ESTUDANTE ATUAL
			//so vai ser igual a id se for o 1 estudante ou um estudante que voltou depois e nao esperou nas cadeiras

			room_state = 1; //OCUPAR A SALA

			printf("Student #%d is awaking the TA.\n", id); 
			
			sem_post(semaphore); //CHAMAR TA

			pthread_mutex_unlock(&mutex); //DEIXAR A SALA DISPONIVEL PARA OUTROS CHECAREM

			return NULL; //TERMINA A THREAD DO ESTUDANTE X

		}

		if(student_number ==  student_check) //SE O NUMERO DE ESTUDANTES AJUDADOS = N TOTAL
			return NULL; //TERMINA A THREAD DOS ESTUDANTES
		}

		return NULL;
	}


void *ta_Actions(void *variable){ //FUNÇÃO DO TA

	
	while(1){ 

	int c_state = student_Chair_Id(); //CHECAR DISPONIBILIDADE DA CADEIRA

	if( room_state == 0 && c_state == -1){ //PRINT PARA O COMECO DO PROGRAMA
		if(student_number == 0){
		printf("TA is sleeping.\n");
		
		}

		if(student_number > 1){
		printf("TA went back to sleep.\n"); //PRINT SE NAO TIVER NINGUEM NA FILA
	
		}
		sem_wait(semaphore);//ESPERANDO SINAL
	}
						
	if(quant_chairs > 0 || current_student != 0 ){ //SE TIVER ALGUM ESTUDANTE NA FILA OU
													//FOR O 1 ESTUDANTE / UM QUE VOLTOU DEPOIS E NAO ENTROU NA FILA
		room_state = 1;

		if(current_student == 0){ //SE TIVER ALGUM ESTUDANTE NA CADEIRA 

			current_student = chairs[c_state]; //DEFINIR O ESTUDANTE ATUAL COMO O INDICE DA CADEIRA
			chairs[c_state] = 0 ; //LIBERAR A CADEIRA VOLTANDO O INDICE PARA ZERO
			quant_chairs--; //DIMINUIR A QUANTIDADE DE CADEIRAS DISPONIVEIS

		}

		printf("Student #%d is getting inside TA room.\n", current_student); //esta entrando na sala
 
		printf("TA is teaching student #%d.\n", current_student);

		sleep(3);

		printf("TA finished teaching student #%d.\n", current_student);

		printf("Student #%d left TA room.\n", current_student);

		room_state = 0;

		student_number++; //AUMENTAR O NUMERO DE ESTUDANTES AJUDADOS

		current_student = 0; //DEFINIR ESTUDANTE ATUAL COMO ZERO
		//se um estudate for igual a zero, quer dizer que ele estava na cadeira
		

	}
	 	//SE A SALA ESTIVER VAZIA
		if(student_number == student_check){ //NUMERO DE ESTUDANTES AJUDADOS = NUMERO TOTAL
			printf("TA went back to sleep.\n");
			printf("There is no more students to help. TA left the room.\n"); //TA é sonambulo
			return NULL; //TERMINA A THREAD DO TA
		}
	}

	return NULL;
}