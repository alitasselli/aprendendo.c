
//questao media

#include <stdio.h>
int main() {

int um;
int dois;
int tres;
int maior=-99999;

scanf("%d",&um);
scanf("%d",&dois);
scanf("%d",&tres);

if (um>=dois && um>=tres) {
  maior=um;
}

else if (dois>=um && dois>=tres) {
  maior=dois;
}
else if (tres>=dois && tres>=um) {
  maior=tres;
}

printf("o maior numero e %d\n", maior);

return 0;
}
