#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"
#include "miniunit.h"

int _test_sixbysix() {
	FILE* open_test = fopen("6x6_24bit.bmp", "r");
	const char* a_error = NULL;
	mu_start();
	BMPImage* read_image = read_bmp(open_test, &a_error); 
	fclose(open_test);
	BMPImage* crop = crop_bmp(read_image, 0, 0, 6, 6, &a_error);	
	if (a_error != NULL) {
		printf("%s", a_error);
		free_bmp(read_image);
		mu_end();
	}
	open_test = fopen("6x6.bmp", "w");
	mu_check(write_bmp(open_test, crop, &a_error));
	if (a_error != NULL) {
		printf("%s", a_error);
		free_bmp(read_image);
		free_bmp(crop);
		mu_end();
	}
	mu_check(check_bmp_header(&(crop -> header), open_test));
	free_bmp(read_image);
	free_bmp(crop);
	fclose(open_test);
	mu_end();
}

int _test_size() {
	FILE* open_test = fopen("corrupt_carw.bmp", "r");
	const char* a_error = NULL;
	mu_start();
	BMPImage* image = read_bmp(open_test, &a_error); 
	if (a_error != NULL) {
		printf("%s", a_error);
		fclose(open_test);
		mu_end();
	}
	bool check_header = check_bmp_header(&(image -> header), open_test);
	mu_check(check_header);
	if (!check_header) {
		free_bmp(image);
		printf("%s", a_error);
		fclose(open_test);
		mu_end();
	}
	fclose(open_test);
	BMPImage* crop = crop_bmp(image, 0, 0, 6, 6, &a_error);	
	if (a_error != NULL) {
		printf("%s", a_error);
		free_bmp(image);
		mu_end();
	}
	open_test = fopen("gray.bmp", "w");
	mu_check(write_bmp(open_test, crop, &a_error));
	if (a_error != NULL) {
		printf("%s", a_error);
		free_bmp(image);
		free_bmp(crop);
		mu_end();
	}
	mu_check(check_bmp_header(&(crop -> header), open_test));
	free_bmp(image);
	free_bmp(crop);
	fclose(open_test);
	mu_end();
}


int main(int argc, char* argv[]) {
	mu_run(_test_sixbysix);
	mu_run(_test_size);
    const char* a_error = NULL;
	//Change name of input file for other test in line 42
    FILE* test = fopen("airplane.bmp", "r");
    if(test == NULL || ferror(test)) {
        a_error = strerror(errno);
    }
    else{
        BMPImage* test_bmp = read_bmp(test, &a_error);
        if(test_bmp != NULL) {
			//Change size of BMP for other test 
            BMPImage* bmp_crop = crop_bmp(test_bmp, 150, 200, 100, 150, &a_error);
            if(bmp_crop!=NULL) {
                FILE* output = fopen("cropped_airplane.bmp", "w");
                write_bmp(output, bmp_crop, &a_error);    
                free_bmp(bmp_crop);
	    		fclose(output);
            }
            free_bmp(test_bmp);
        }
    }
    fclose(test);
    return EXIT_SUCCESS;
}