 /* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
#include <stdio.h>
#include <stdlib.h>

char* my_strdup(const char* original) {
	// TODO
	const char *copy_original;
	copy_original = original;
	int len_str = 0;
	for(;*copy_original != '\0'; copy_original++){
		len_str++;
	}
	//Heap memory
	char * copy = malloc((len_str+1)*sizeof(char));
	int i = 0; // index
	for(i = 0; original[i] != '\0'; i++){
		copy[i] = original[i]; //Until in heap i=2
	}
	copy[i] = '\0'; //When i = 3, added in heap memory!
	return copy;
}

int main(int argc, char *argv[]) {
	char s[] = "abc\n";
	fputs(s, stdout);  // Should print "abc" followed by a newline ('\n')

	char* t = my_strdup(s);
	fputs(t, stdout);  // Should print "abc" followed by a newline ('\n')
	free(t);

	return EXIT_SUCCESS;
}
