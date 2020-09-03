// OK TO COPY / ADAPT this snippet---but ONLY if you understand it completely.
// 
// This test is nowhere near adequate on its own.  It is provided to illustrate how to
// use helper functions to streamline your test code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"
#include "miniunit.h"

int _test_parse_int_valid() {
    mu_start();
 
    int result;  // will be initialized in parse_int(&)
    char* input = "0";
    char* pos = input;
    bool is_success = parse_int(&result, &pos);
    mu_check(is_success);   // because the input is valid_
    mu_check(pos == input + 1);
    mu_check(result == 0);
    mu_end();
}

int _test_parse_int_invalid() {
    mu_start();
  
    int   result;  // will be initialized in parse_int(&)
    char* input = "A";
    char* pos = input;
    bool is_success = parse_int(&result, &pos);
    mu_check(!is_success);  // because the input is valid
    mu_check(pos == input); // failure should be at the first character in the input
    mu_end();
}

int parse_e() {
	char* str = " \"a\\bC\"8a";
    //char* str = "\"abc\"";
    //char* str = "\"abc\z\\";
	char* pos = str;
	Element element; 
	mu_start();
	mu_check(parse_element(&element, &pos) == true);
	mu_check(*pos == '8');
	mu_check(strcmp(element.value.as_string, "a\\bC") == 0);
    //mu_check(strcmp(element.value.as_string, "abc") == 0);
    //mu_check(strcmp(element.value.as_string, "abc") == 0);
	mu_check(element.type == ELEMENT_STRING);
	print_element(element);
	free_element(element);
	mu_end();
}

int test_int_more() {
	int value;	
	char* str = "9856-1";
	char* pos = str;
	mu_start();
	mu_check(parse_int(&value, &pos) == true);
	mu_check(value == 9856);
	mu_end();
}

int test_o() {
	int value;
	char* str = "-1231,stop]";
	char* pos = str;
	mu_start();
	mu_check(parse_int(&value, &pos) == true);
	mu_check(value == -1231);
	//mu_check(*pos == ',');
	mu_end();
}

// int test_list_10_11_12() {
//     mu_start();
//     char* json_input = "[1339, 7226, 8829]";
//     char* pos = json_input;
//     Element element;
//     bool is_success = parse_element(&element, &pos);
//     //CHECK
//     mu_check(pos - json_input == 18);
//     mu_check(*pos =='\0');
//     mu_check(is_success);
//     mu_check(element.type == ELEMENT_LIST);
//     Node* head  = element.value.as_list;
//     mu_check((head -> element.value.as_list) == 1339);
//     mu_check(head -> next -> element.value.as_list == 7226);
//     mu_check(head -> next -> next -> element.value.as_list == 8829);
//     //FREE
//     free_element(element);
//     mu_end();
// }

int test_syntax_error_due_to_newline_in_strings() {
    mu_start();
    char* json_input = "\"GARTIN\nTIBOOD\"";
    char* pos = json_input;
    Element element;
    bool is_success = parse_element(&element, &pos);
    mu_check(!is_success);
    //mu_check(element.type == ELEMENT_STRING);
    mu_check(*pos == '\n');
    mu_check(pos - json_input == 7);
    mu_end();
}

int test_list_0() {
	char* str = "[-a85, 77, 77]";
	char* pos = str;
	Node* head = NULL;
	mu_start();
	mu_check(parse_list(&head, &pos) == false);
	mu_check(*pos == 'a');
	mu_end();
}

int test_list_1() {
	char* str = "[[-a32, 55], 455]";
	char* pos = str;
	Node* head = NULL;
	mu_start();
	mu_check(parse_list(&head, &pos) == false);
	mu_check(*pos == 'a');
	mu_end();
}
/////////
int bool_check() {
	char* str = "fatse";
	char* pos = str;
	Element element;
	mu_start();
	mu_check(parse_element(&element, &pos) == false);
	mu_check(*pos == 't');
	mu_end();
}

int bool_checkk() {
	char* str = "null";
	char* pos = str;
	Element element;
	mu_start();
	mu_check(parse_element(&element, &pos) == true);
	mu_check(element.value.as_null == NULL);
	mu_check(element.type == ELEMENT_NULL);
	mu_check(*pos == '\0');
	print_element(element);
	mu_end();
}

int check_null() {
	char* str = "[nuol]";
	char* pos = str;
	Element element;
	mu_start();
	mu_check(parse_element(&element, &pos) == false);
	mu_check(*pos == 'o');
	mu_end();
}
/////////
int main(int argc, char* argv[]) {
    mu_run(_test_parse_int_valid);
    mu_run(_test_parse_int_invalid);
    mu_run(parse_e);
    mu_run(test_int_more);
    mu_run(test_o);
    //mu_run(test_list_10_11_12);
    mu_run(test_list_0);
    mu_run(test_syntax_error_due_to_newline_in_strings);
    mu_run(test_list_1);

    mu_run(bool_check);
    mu_run(bool_checkk);
    mu_run(check_null);
    return EXIT_SUCCESS;
}