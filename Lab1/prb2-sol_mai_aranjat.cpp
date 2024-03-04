#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afisare(char** array) {
	while (*array != NULL)
		printf("%s\n", *array), * array++;
}

bool compara(char* s, char* t) {
	if (strlen(s) < strlen(t))
		return 1;
	return 0;
}

void sortare(char** array) {
	while (*array != NULL) {
		char** copie = array;
		*copie++;
		while (*copie != NULL) {
			if (compara(*array, *copie)) {
				char* aux = *array;
				*array = *copie;
				*copie = aux;
			}
			*copie++;
		}
		*array++;
	}
}

int main() {
	char* text = (char*)malloc(100 * sizeof(char));
	scanf_s("%[^\n]%*c", text, 100);
	char** array = (char**)malloc(100 * sizeof(char));
	char** inceput = array;
	*array = text;
	array++;
	char* temp = text;
	while (*temp != NULL) {
		if (*temp == ' ') {
			char* aux = temp;
			aux++;
			*array = aux;
			*array++;
			*temp = NULL;
			temp = aux;
		}
		else temp++;
	}
	*array = NULL;
	//afisare(inceput);
	char** copie = inceput;
	sortare(copie);
	afisare(inceput);
	//free(array);
	return 0;
}
