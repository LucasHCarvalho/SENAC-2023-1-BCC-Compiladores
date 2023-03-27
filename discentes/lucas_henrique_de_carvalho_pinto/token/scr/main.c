#include <stdio.h>

typedef enum Token {
  Mais,
	Menos,
	Indeterminado,
	Nulo
} Token;

typedef struct Digito {
  Token token;
  char caracter;
}Digito;

typedef Digito * Texto;

char tokenizar(char *texto){
	Texto novo;
  novo = malloc (sizeof(Digito));
  
	int i = 0;
	for (i = 0; texto[i] != '\0'; i++) {
    if(texto[i] == ' '){
			novo->token = Nulo;
			novo->caracter = ' ';
		}
		else if(texto[i] == '+'){
			novo->token = Mais;
			novo->caracter = '+';
		}
		else if(texto[i] == '-'){
				novo->token = Menos;
				novo->caracter = '-';
		}
		else{
			novo->token = Indeterminado;
			novo->caracter = texto[i];
		}				

		if(novo->token != Nulo){
			printf("\t%s -> %c,\n", 
					(novo->token == Mais) ? "Mais" :
	      	(novo->token == Menos) ? "Menos" :
       		(novo->token == Indeterminado) ? "Indeterminado" : "", novo->caracter
				);
			printf("", novo->caracter);
		}			
  }
	
	free(novo);
}

int main(void) {
	
  printf("Token: [\n");
		tokenizar("-+ a ");
	printf("]");
	
  return 0;
}
