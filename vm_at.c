/* 􏰶PASSO A PASSO
 *
 * ABRIR ADDRESSES.TXT
 * LER TODOS OS ENDERECOS DO ARQUIVO
 * CONVENTER OS ENDERECOS EM BINARIO
 * ACHAR OS NUMEROS DA PAGINA E O OFFSET DO N BINARIO
 * CONVERTER OS NUMEROS EM DECIMAL
 * ABRIR O ARQUIVO BINARIO BACK STORE
 *
 * O INDICE E O NUMERO DA PAGINA A SER ASSESADA CARREGADA
 * E O SEU VALOR E ONDE ELA ESTA NA MEMORIA FISICA VULGO EM QUE FRAME
 *
 * SE O INDICE DO PAGE_TABLE[NUMERO DA PAGINA],
 * NAO ESTIVER CARREGADO NA MEMORIA FISICA E O N DE PAGINAS CARREGADAS FOR < 128:
 *   DEVE-SE COPIAR DO BACKIN STORE A "LINHA" COM OS DADOS NA MEMORIA FISICA
 *   O NUMERO DO FRAME QUE FOI CARREGADO NA MEMORIA FISICA
 *   VIRA O CONTEUDO DO PAGE TABLE(MEM_FISICA[i] = PAGE_TAB[NUM DA PAGINA]
 *   SE CALCULA O ENDERECO FISICO E RETORNA O VALUE
 *
 * JA ESTIVER CARREGADO NA MEMORIA FISICA :
 *   SO VAI ACESSAR O FRAME CORRESPONDENTE
 *   CALCULAR O END FISICO E RETORNAR O VALUE
 *
 * SE NAO ESTIVER CARREGADO NA MEMORIA FISICA E O N DE PAGINAS CARREGADAS FOR > 128:
 *   EU COLOCO O VALOR DO PAGE_TABLE[NUMERO DA PAGINA] COMO O FRAME A SER TROCADO
 *   A CONTAGEM DO FRAME DA MEMORIA FISICA A SER TROCADO COMECA EM 0
 *   DEVE-SE COPIAR DO BACKIN STORE A "LINHA" COM OS DADOS NA MEMORIA FISICA NO FRAME TROCADO
 *
 * APOS ESSAS DUAS OPCOES JA ESCREVE NO ARQUIVO
 * O ENDERECO, O ENDERECO FISICO E O VALUE
 * AO FINAL PRINTAR NO ARQUIVO OS ENDERECOS TRADUZIDOS, PAGE FAULT E RATE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

/* CONSTANTES */
#define QT_ADDRESSES 1000         /* numero de enderecos do arquivo*/
#define FRAMES 128                /* numero de frames na memoria fisica */
#define PAGES 256                 /* tamanho da tabela de paginas && paginas */
#define MAX_ADD 32                /* tamanho do binario */
#define SIZE_BINARY 128           /* tamanho do numero binario TOTAL */
#define SIZE_NUMBIN 8             /* tamanho dos arrays para salvar o binario da pagina &offset */
#define MEM_SIZE PAGES * PAGES    /* tamanho da memoria fisica */

/* DECLARACAO DAS FUNCOES */
void getBin(int *dst, int x);                 /* transformar em binario */
int getPage(int *buf, int *page_number);      /* pegar o numero da pagina binario */
int getOffset(int *buf, int *offset_number);  /* pegar o numero do offset binario */
int getDecimal(int *num, int size);           /* transformar em decimal */

int main(int argc, char **argv){
    
    FILE *fp = fopen(argv[1], "r");
    
    int address;                     /* guardar o endereco virtual */
    int buf[SIZE_BINARY];            /* array para salvar o numero binario */
    int page_number[SIZE_NUMBIN];    /* array para salvar o numero da pagina */
    int offset_number[SIZE_NUMBIN];  /* array para salvar o numero do offset */
    int transl_add = 0;              /* contador para o number of translated addresses */
    int page_faults = 0;             /* numero de paginas carregadas no page table */
    signed char value;               /* retorno do value */
    int index = 0;                   /* index do page table */
    int replace = 0;                 /* contador das substituicoes de pagina */
    
    signed char physical_memory[PAGES][FRAMES];  /* criar memoria fisica de 128 x 256 */
    
    int page_table[PAGES];                        /* criar a page table */
    for (int i = 0; i < PAGES; i++) {
        page_table[i] = -1;
    }
    
    const char * bin_file = "BACKING_STORE.bin"; /* abrir o arquivo binario */
    signed char *backing_ptr;
    int backing_store_fp = open(bin_file, O_RDONLY);
    backing_ptr = mmap(0, MEM_SIZE, PROT_READ, MAP_PRIVATE, backing_store_fp, 0);
    
    
    FILE *output;                               /* abrir arquivo do output */
    output = fopen("output.txt", "w");
    
    /****************************************************************************/
    
    for (int i = 0; i < QT_ADDRESSES; i++) {    /* lendo os enderecos do arquivo */
        
        fscanf(fp, "%d\n", &address);
        getBin(buf, address);          /* pegar o numero binario do endereco virtual */
        getPage(buf, page_number);     /* pegar o numero binario da pagina */
        getOffset(buf, offset_number); /* pegar o numero binario do offset */
        
        int pageSize = sizeof (page_number)/sizeof(page_number[0]);     /* passar o tamanho do array para a funcao */
        int p_number = getDecimal(page_number, pageSize);               /* retorna o numero decimal da pagina */
        int offSize = sizeof (offset_number)/sizeof(offset_number[0]);  /* passar o tamanho do array para a funcao */
        int p_offset = getDecimal(offset_number, offSize);              /* retorna o numero decimal do offset */
        
        /****************************************************************************/
        int physical = page_table[p_number];
        
        if (page_table[p_number] == -1 && page_faults < FRAMES) { /* indice p_number vazio = pagina nao carregada na memoria */
            
            physical = index;
            
            /* copiando do arquivo binario para a memoria fisica */
            memcpy(physical_memory[physical], backing_ptr + p_number * PAGES, PAGES);
            
            int phy_add = physical * 256 + p_offset;          /* achar o endereco fisico */
            int value = physical_memory[physical][p_offset];  /* achar o valor */
            page_table[p_number] = index; /* Atualizar o valor do page table com o valor do frame */
            
            page_faults++;
            index++;
            
            fprintf(output, "Virtual address: %d Physical address: %d Value: %d\n",address, phy_add, value);
            
        } else if (page_table[p_number] != -1) { /* se a pagina ja estiver carregada na memoria, so acessa */
            
            int aux = page_table[p_number];
            int phy_add = aux * 256 + p_offset;
            int value = physical_memory[aux][p_offset];
            
            fprintf(output, "Virtual address: %d Physical address: %d Value: %d\n",address, phy_add, value);
            
        } else if (page_table[p_number] == -1 &&  page_faults >= FRAMES ){
            
            for (int i = 0; i < PAGES; i++){
                if (page_table[i] == replace)
                    page_table[p_number] = page_table[i]; /*colocou o page number x como o frame do replace */
            }
            
            /* copiando do arquivo binario para a memoria fisica no frame que quero substituir */
            memcpy(physical_memory[replace], backing_ptr + p_number * PAGES, PAGES);
            
            int phy_add = replace * 256 + p_offset;          /* achar o endereco fisico */
            int value = physical_memory[replace][p_offset];  /* achar o valor */
            
            page_faults++;
            index++;
            replace++;
            
            fprintf(output, "Virtual address: %d Physical address: %d Value: %d\n",address, phy_add, value);
            
        } transl_add++;
    }/* FINAL FOR */
    
    /* escrita final do arquivo */
    fprintf(output, "Number of Translated Addresses = %d\n",transl_add);
    fprintf(output, "Page Faults = %d\n", page_faults);
    fprintf(output, "Page Fault Rate = %f\n", (float)page_faults/transl_add);
    
    fclose(output);
}/* FINAL MAIN */

void getBin(int *dst, int x) /* TRANSFORMAR O ENDERECO LOGICO EM BINARIO */
{
    
    for (int i = MAX_ADD - 1; i >= 0; i--)
        *dst++ = x >> i & 1;
}

int getPage(int *buf, int *page_number) /* ACHAR O NUMERO BINARIO DA PAGINA */
{
    int j = 0;
    
    for (int i = 16; i < 24; i++)
        page_number[j++] = buf[i];
    
    return *page_number;
}

int getOffset(int *buf, int *offset_number) /* ACHAR O NUMERO BINARIO DO OFFSET */
{
    
    int j = 0;
    
    for (int i = 24; i < 32; i++)
        offset_number[j++] = buf[i];
    
    return *offset_number;
}

int getDecimal(int *number,int size) /* TRANSFORMAR EM DECIMAL */
{
    int j = 0;
    int decimal = 0;
    
    for(int i = size - 1; i >= 0; i--)
        decimal += pow(2,i) * number[j++];
    
    return decimal;
}
