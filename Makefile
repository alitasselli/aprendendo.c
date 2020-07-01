CC = gcc 
abacate: aux_at.o q3c_at.o
	$(CC) -o abacate aux_at.o q3c_at.o
q3c_at.o: q3c_at.c q3_at.h
	$(CC) -c q3c_at.c
aux_at.o: aux_at.c q3_at.h
	$(CC) -c aux_at.c
clean:
	rm aux_at.o q3c_at.o abacate