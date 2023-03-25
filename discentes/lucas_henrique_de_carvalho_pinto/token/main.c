#include <stdio.h>

typedef enum Token {
  Mais,
	Menos,
	Indeterminado
} Token;

struct Digito {
  Token token;
  char caracter;
};

char tokenizar(s: &str) -> Vec<Token>{
	let mut tokens: Vec<Token> = Vec::new();
	let mut it = s.chars().peekable();
	while let Some(c) = it.peek(){
		switch(valorToken) {
    case '+':
      printf("Mais.\n");
      break;
    case '-':
      printf("Menos.\n");
      break;
		default:
      printf("Ind: %c", valorToken);
      break;
  	}
	}
	return tokens
}

int main(void) {
  printf("Token:", tokenizar("+"));
  return 0;
}
