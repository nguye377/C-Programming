#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include "frequencies.h"
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>

bool calc_frequencies(Frequencies freqs, const char* path, const char** a_error) {
    //Open file 
    FILE* fp_open = fopen(path, "r");
    //Check the file is valid or not
    if(fp_open != NULL) {
        //Find the freqencies
        for(uchar ch = fgetc(fp_open); !feof(fp_open); ch = fgetc(fp_open))
        {
            freqs[ch]+=1;
        }
        //--------Print all the "char" and their frequencies------------
        // for(int k=0; k<256; k++) {
        //     if(freqs[k] > 0) {
        //         printf("Char %c: %" PRIu64 " times \n", k, freqs[k]);
        //     }
        // }
    }
    //If file is not valid
    else {
        *a_error = strerror(errno);
        return false;
    }
    fclose(fp_open);
    return true;
}