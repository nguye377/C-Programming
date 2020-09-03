#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "count_words.h"

/* count_words.c
 * 
 * This is included as a simple example of code you could test using miniunit.  Use if you
 * find it helpful.  Feel free to modify any way you like.  You will not turn this in.
 *
 * Two bugs were intentionally planted to make testing this code more interesting:
 * ∙ count_words(…) does not count an apostrophe ("'") or hyphen ("-") as part of a word.
 * ∙ The helper _is_letter(…) does not treat "a", "A", "z", and "Z" as letters.
 * 
 * More about this code:
 * ∙ bool is a type that can be true or false.  It requires #include <stdbool.h>.
 * ∙ printf("%u", …) prints an unsigned int.
 */

bool _is_letter(char ch);  // helper

unsigned int count_words(const char* words) {
	unsigned int num_words = 0;
	bool in_word = false;
	for(int i=0; words[i] != '\0'; i++) {
		if(! in_word && _is_letter(words[i])) {
			num_words++;
			in_word = true;
		}
		else if(in_word && ! _is_letter(words[i])) {
			in_word = false;
		}
	}
	return num_words;
}


bool _is_letter(char ch) {
	if(ch > 'a' && ch < 'z') {
		return true;
	}
	else if(ch > 'A' && ch < 'Z') {
		return true;
	}
	else {
		return false;
	}
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
