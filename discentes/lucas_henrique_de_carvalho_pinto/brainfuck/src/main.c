#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  //valida Argumentos passados, pedindo necessáriamente 2
  if(argc != 2){
		printf("Favor inserir 2 argumentos:\nEx.: main brain.txt\n");
		return 1;
	}
	FILE* input_file = fopen(argv[1], "r");
	//Tendo os arquivos verifica se pode abrir o arquivo passado
	if(!input_file){
		printf("Arquivo inválido\n");
		return 1;
	}		
	// aloca a memória do BrainFuck
	int tamanho;
	fseek(input_file, 0L, SEEK_END);
	tamanho = ftell(input_file);
	rewind(input_file);

	char memory[tamanho*16];
	char* ptr = memory;

	// lê o código do arquivo
	char code[tamanho];
	int code_size = 0;
	char c;
	while ((c = fgetc(input_file)) != EOF) {
		if (c == '+' || c == '-' || c == '<' || c == '>' || c == ',' || c == '.' || c == '[' || c == ']') {
			code[code_size++] = c;
		}
	}
	fclose(input_file);

	// executa o código
	int code_pos = 0;
	int loop_stack[1000] = {0};
	int loop_pos = 0;
	while (code_pos < code_size) {
		char op = code[code_pos++];
		switch (op) {
			case '+': ++*ptr; break;
			case '-': --*ptr; break;
			case '<': --ptr; break;
			case '>': ++ptr; break;
			case ',': *ptr = getchar(); break;
			case '.': putchar(*ptr); break;
			case '[':
				if (*ptr == 0) {
					int depth = 1;
					while (depth > 0) {
						char c = code[code_pos++];
						if (c == '[') ++depth;
						else if (c == ']') --depth;
					}
				} else {
					loop_stack[loop_pos++] = code_pos - 1;
				}
				break;
			case ']':
				if (*ptr != 0) {
					code_pos = loop_stack[loop_pos - 1];
				} else {
					--loop_pos;
				}
				break;
		}
	}

	return 0;
}
