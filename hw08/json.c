#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "json.h"

size_t _str_len(char* str);
int _helper_value(char* str, int str_len);
void _help_free_list(Node* head);
bool _bonus_bool(bool* a_bool, char** a_pos);
bool _bonus_null(void** a_null, char** a_pos);

bool parse_int(int* a_value, char** a_pos) {
    if(isdigit(*(*a_pos)) == false && *(*a_pos) != '-'){
        return false;
    }
    else if(isdigit(*(*a_pos+1)) == false && *(*a_pos) == '-'){
        *a_pos = *a_pos + 1;
        return false;
    }
    size_t str_len = _str_len(*a_pos);
    *a_value = _helper_value(*a_pos, str_len);
    *a_pos = *a_pos + 1;
    //printf("%d", **a_pos);
    return true;
}

size_t _str_len(char* str) {
    size_t len = 0;
    if(str[len] == '-') {
        len = len + 1;
    }
    while(isdigit(str[len]) != false){
        len = len + 1;
    }
    return len;
}

int _helper_value(char* str, int str_len) {
    int val = 0;
    for(int i = 0; i < str_len; i++){
        if(str[i] == '-'){
            i++;
        }
        int pow = 1; //Using for calcualte the powder <----
        // Compute the power
        for(int j = 0; j < (str_len - (i+1)); j++){
            pow = pow* 10;
        }
        //Create an temp variable to convert to the number value
        char temp = str[i];
        int val_temp = temp;
        int val_str = val_temp - '0';
        val = val + val_str*pow;
    }
    if(str[0] == '-'){
        val *=  -1;
    }
    return val;
}


bool parse_string(char** a_s, char** a_pos) {
    if ((*a_pos)[0] != '"') {
        return false;
    }
    //Move the position of the pointer
    //To navigate the character '"'
    (*a_pos) = (*a_pos) + 1; 
    int len_str1;
    int len_str2;
    char* string_1;
    char* string_2;
    int i = 0; //Create an i variable to keep track the position 
    while((*a_pos)[i] != '\0') {
		if ((*a_pos)[i] == '\n') {
            //Looking for '\n'
            (*a_pos) += i; 
			return false;
		}
		if ((*a_pos)[i] == '"') {
            (*a_pos) = (*a_pos) - 1;
            string_1 = strchr((*a_pos),'"');
            //printf("%s\n", string_1);
            len_str1 = strlen(string_1) - 1;
            //printf("%d\n", len_str1);
            (*a_pos) = (*a_pos) + 1;
			break;
		}
        i++; 
	}
    if((*a_pos)[i] == '\0') {
        (*a_pos) = (*a_pos) - 1;
        return false;
    }
    //---------
    //Move a pointer one more step
    string_2 =  strchr((*a_pos),'"');
    //printf("%s\n", string_2);
    len_str2 = strlen(string_2);
    //printf("%d\n", len_str2);
    //Compute the len for Malloc
    int len_str = len_str1 - len_str2;
    //Malloc + 1 for the '\0'
    *a_s = malloc((len_str + 1) * sizeof(**a_s)); 
    i = 0;
    while (i < len_str){
        (*a_s)[i] = (*a_pos)[i];
        i++;
    }
    (*a_s)[i] = '\0';
    //In terms of '"', we need to plus one
    (*a_pos) = (*a_pos) + len_str + 1; 
    return true;
}


bool parse_element(Element* a_element, char** a_pos) {
    //Increase until i#isspace is FALSE
    while (isspace(*(*a_pos)) != false){
        *a_pos = *a_pos + 1;
    }
    if (parse_int(&((*a_element).value.as_int), a_pos) == true) 
    {
	    (*a_element).type = ELEMENT_INT;
	    return true;
	}
	else if(parse_string(&((*a_element).value.as_string), a_pos) == true) 
    {
	    (*a_element).type = ELEMENT_STRING;
	    return true;
	} 
    //Remember condition for #LIST
    else if(parse_list(&((*a_element).value.as_list), a_pos) == true) {
		(*a_element).type = ELEMENT_LIST;
		return true;
	}
    //Bonus 
    else if(_bonus_bool(&((*a_element).value.as_bool), a_pos) == true) {
		(*a_element).type = ELEMENT_BOOL;
		return true;
	}
	else if(_bonus_null(&((*a_element).value.as_null), a_pos) == true) {
		(*a_element).type = ELEMENT_NULL;
		return true;
	}
	else 
    {
        return false;
    }
    
}


void print_element(Element element) {
	if(element.type == ELEMENT_INT) {
		printf("%d", element.value.as_int);
	}
	else if(element.type == ELEMENT_STRING) {
		printf("\"%s\"", element.value.as_string);
	}
    //ELEMENT_LIST
    else if(element.type == ELEMENT_LIST) {
	    //Opening of the List
        printf("[");
        //Set a temp node with naming as "curr" as a current node
        Node* curr = element.value.as_list;
        while (curr != NULL) {
		    print_element(curr -> element);
		    if (curr -> next != NULL) {
			printf(",");
		}
        curr = curr -> next;
	}
        //End of the List 
		printf("]");
	}
    else if(element.type == ELEMENT_NULL) {
		printf("null");
	}
	else if(element.type == ELEMENT_BOOL) {
		if (element.value.as_bool == true) {
			printf("true");
		}
		else {
			printf("false");
		}
	}
}

bool parse_list(Node** a_head, char** a_pos) {
	if (**a_pos != '[') {
		return false;
	}
    //Move into the next position to check the linked list
	*a_pos += 1; 
	*a_head = NULL;
	Node* tail = NULL;
	Node* inserted_node = NULL;
    //Set a condition to check the connection between two node
	bool node_connected = false; 
    while (**a_pos != '\0') { 
        //Condition to check in order to insert a new node
        int i = 0; 
		inserted_node = NULL;
		node_connected = false;
        while (isspace(*(*a_pos)) == true) { //Check space
            *a_pos += 1;
        }
		if (isdigit(**a_pos) != false || **a_pos == '-') {
			inserted_node = malloc(sizeof(*inserted_node));
			if (parse_int(&(inserted_node -> element.value.as_int), a_pos) == false) 
            {
				break;
			}
			else 
            {
				inserted_node -> element.type = ELEMENT_INT;
			}
		}
		else if (**a_pos == '"') {
			inserted_node = malloc(sizeof(*inserted_node));
			if (parse_string(&(inserted_node -> element.value.as_string), a_pos) == false) 
            {
				break;
			}
			else 
            {
				inserted_node -> element.type = ELEMENT_STRING;
			}
		}
        else if (**a_pos == '[') {
			inserted_node = malloc(sizeof(*inserted_node));
			if (parse_list(&(inserted_node -> element.value.as_list), a_pos) == false) 
            {
				break;
			}
			else 
            {
				inserted_node -> element.type = ELEMENT_LIST;
			}
		}
        
		else if (**a_pos == 't' || **a_pos == 'f') { //Set the first letter of a string to regconize
			inserted_node = malloc(sizeof(*inserted_node));
			if (_bonus_bool(&(inserted_node -> element.value.as_bool), a_pos) == false) {
                break;
            }
			else {
				inserted_node -> element.type = ELEMENT_BOOL;
			}
		}
		else if (**a_pos == 'n') {
			inserted_node = malloc(sizeof(*inserted_node));
			if (_bonus_null(&(inserted_node -> element.value.as_null), a_pos) == false) {
                break;
            }
			else {
				inserted_node -> element.type = ELEMENT_NULL;
			}
		}

		if (inserted_node != NULL) {
			inserted_node -> next = NULL;
			if (i == 0) 
            {
				*a_head = inserted_node;
				tail = inserted_node;
			}
			else 
            {
				tail -> next = inserted_node;
				tail = inserted_node;
			}
			node_connected = true; //two nodes are connected
		}
        while (isspace(*(*a_pos)) != false) {
            *a_pos += 1;
        }
		
		if (**a_pos == ']') {
			if (inserted_node != NULL) {
				tail -> next = NULL;
			}
			*a_pos += 1;
			return true;
		}
        else if (**a_pos == ',') {
			if (inserted_node == NULL) break;
		}
		else {
            break;
        }
        //Keep increasing imto keep track
		i = i + 1;
        *a_pos += 1; // Go to the next position to check
	}
	if (inserted_node != NULL && !node_connected) { 
		free(inserted_node);
	}
	_help_free_list(*a_head);
	return false;
}


void free_element(Element element) {
    if(element.type == ELEMENT_STRING) free(element.value.as_string);
    else if (element.type == ELEMENT_LIST) {
        _help_free_list(element.value.as_list);
    }
}

void _help_free_list(Node* head) {
	while (head != NULL) {
		Node* temp_node = head;
		head = head -> next;
		free_element(temp_node -> element);
		free(temp_node);
	}
}

bool _bonus_bool(bool* a_bool, char** a_pos) {
	//A sample string of true and false to compare
    char* str_false = "false";
    char* str_true = "true";
	int i = 0; //initialize the position
	if (**a_pos == 't') {
        while (i < 4){
			if ((*a_pos)[i] != str_true[i]) break;
            i = 1 + 1;
		}
		*a_pos += i;
		if (i != 4) {
			return false;
		}
		else {
			*a_bool = true;
			return true;
		}
	}
	else if (**a_pos == 'f') { 
        while (i < 5){
			if ((*a_pos)[i] != str_false[i]) break;
            i = i + 1; 
		}
		*a_pos += i;
		if (i != 5) {
			return false;
		}
		else {
			*a_bool = false;
			return true;
		}
	}
	return false;
}

bool _bonus_null(void** a_null, char** a_pos) {
	char* str_null = "null";
	//Creata a string of a corrected null
    int i = 0; //initialize the position
    while (i < 4) {
		if ((*a_pos)[i] != str_null[i]) {
			break;
		}
        i = i + 1;
	}
	*a_pos = *a_pos + i;
	if (i != 4) {
		return false;
	}
	*a_null = NULL;
	return true;
}