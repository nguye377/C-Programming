#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "bmp.h"

BMPImage* read_bmp(FILE* fp, const char** a_error) {
    //Write code below this line
    fseek(fp,0, SEEK_END);
	long int size_file = ftell(fp);
	fseek(fp, 0, SEEK_SET);
    BMPImage *image = malloc(sizeof(*image));
    //Check Mallocc for the Image
    if(image == NULL){ *a_error = "Failed! Can not MALLOC\n"; return NULL;
	}
    //Check the header
	fseek(fp, 0, SEEK_SET);
    //long int check_header = fread(&(image->header),BMP_HEADER_SIZE,1,fp);	
	long int check_header = fread(&(image->header), sizeof(image->header), 1, fp);
	if(check_header != 1){ *a_error = "Failed! Can not read the file HEADER\n"; *a_error = strerror(errno); free(image); return NULL;
	}
    //Check the header which is valid or n
    if((check_bmp_header(&(image->header),fp) == false)){
		*a_error = "Failed! This header is INVALID\n";
		free(image);
		return NULL;
	}
    //Check to malloc for the data
	image->data = NULL;
	image->data = malloc(sizeof(*(image->data))*(size_file - BMP_HEADER_SIZE));
	if(image->data ==NULL){ *a_error = "Failed! Can NOT Malloc for the Data\n"; free(image); return NULL;
	}
    //Checking  the reading data???????????????????????
	size_t  data_check = fread(image->data, sizeof(*(image->data)), size_file - BMP_HEADER_SIZE, fp);
	if(data_check!=(size_file - BMP_HEADER_SIZE)){ *a_error = "Failed! Can NOT read Data\n"; free_bmp(image); return NULL;
	}
	return image;

}

bool check_bmp_header(const BMPHeader* bmp_header, FILE* fp) {
    //Write code below this line
    fseek(fp,0,SEEK_END);
	long int size = ftell(fp); 
	fseek(fp,BMP_HEADER_SIZE,SEEK_SET);	
    if (bmp_header->type != 0x4d42 
			|| bmp_header->offset != BMP_HEADER_SIZE 
			|| bmp_header->dib_header_size != DIB_HEADER_SIZE 
			|| bmp_header->num_planes != 1
			|| bmp_header-> compression != 0
			|| bmp_header->num_colors != 0
			|| bmp_header->important_colors != 0
			|| bmp_header->bits_per_pixel != 24) { return false; } 

	size_t width_byte_temp = (bmp_header->bits_per_pixel) * (bmp_header->width_px)/8;
	if((width_byte_temp %4) != 0){
		width_byte_temp += (4-(width_byte_temp %4));
	}
	if((width_byte_temp*(bmp_header->height_px)!= bmp_header->image_size_bytes)
              || (size - BMP_HEADER_SIZE != bmp_header->image_size_bytes)){
		return false;
	}			
	return true;

}

bool write_bmp(FILE* fp, BMPImage* image, const char** a_error) {
    //Write code below this line
    if(image == NULL) { *a_error = "Failed! Image is INVALID!\n"; return false;
    }
    if(fp == NULL || ferror(fp)) { *a_error = strerror(errno); return false;
    }
    fwrite(&image->header, sizeof(BMPHeader), 1, fp);
    if(ferror(fp)) { *a_error = strerror(errno); return false;
    }
	int len_data;
	len_data = image -> header.image_size_bytes;
    fwrite(image->data, sizeof(*image->data), len_data, fp);
    if(ferror(fp)) { *a_error = strerror(errno); return false;
    }
    *a_error = NULL;
    return true;
}

void free_bmp(BMPImage* image) {
	if (image != NULL)
	{
		if (image -> data != NULL)
		{
			free(image -> data);	
			image -> data = NULL;
		}
		free(image);
		image = NULL;
	}
}

BMPImage* crop_bmp(const BMPImage* image, int x, int y, int w, int h, const char** a_error) {
    // Write my code below this line
	BMPImage* crop_image = malloc(sizeof(*crop_image));
	if(crop_image == NULL){ *a_error = "Failed to allocate the malloc() memory\n"; return NULL;
	}
    if (*a_error == NULL) {	
		crop_image -> data = NULL;
		if(x < 0 || y < 0 || w <= 0|| h <= 0) { *a_error = "Failed! Dimension is invalid\n"; return NULL;
        }
		if (*a_error == NULL) {
			crop_image -> header = image -> header;
			crop_image -> header.width_px = w;
			crop_image -> header.height_px = h;
			size_t byte_per_pixel = crop_image -> header.bits_per_pixel / 8;
            //-------------------------
            size_t padding_temp_1 = 0;
            if((byte_per_pixel*w) % 4 != 0) {
                padding_temp_1 = 4 - ((byte_per_pixel*w) % 4);
            }
            // size_t new_padding_per_row = padding_temp_1;
            //-------------------------
			size_t padding_new = padding_temp_1 * h;
			crop_image -> header.image_size_bytes = w * h * byte_per_pixel + padding_new; 
			crop_image -> header.size = crop_image -> header.image_size_bytes + BMP_HEADER_SIZE;
			crop_image -> data = malloc(sizeof(*(crop_image -> data)) * crop_image -> header.image_size_bytes);
            if(crop_image -> data == NULL) { *a_error = "Failed to allocate the malloc() memory\n"; return NULL;
            }
			if (*a_error == NULL) {
                //-------------------------------------
                size_t padding_temp_2 = 0;
                if((byte_per_pixel * image -> header.width_px) % 4 != 0) {
                padding_temp_2 = 4 - ((byte_per_pixel * image -> header.width_px) % 4);
                }
				size_t old_padding_per_row = padding_temp_2;
                //------------------------------------- 
				size_t y_temp = y + h - 1;
				size_t ignored_rows = image -> header.height_px - (y_temp + 1);
				//Ignore the columns
                size_t x_temp = x;
				size_t old_bytes_each_row = byte_per_pixel * image -> header.width_px + old_padding_per_row;
				size_t starting_index = old_bytes_each_row * ignored_rows + byte_per_pixel *x_temp;
				size_t counter = 0;
				for (size_t idx = starting_index; idx < image -> header.image_size_bytes; idx += old_bytes_each_row) {
					memcpy(crop_image -> data + counter, image -> data + idx, crop_image -> header.width_px * byte_per_pixel);
					counter += crop_image -> header.width_px * byte_per_pixel;
                    size_t j = 0;
                    while(j < padding_temp_1) {
                        crop_image -> data[counter] = 0;
						counter++;
                        j++;
                    }
					if (counter >= crop_image -> header.image_size_bytes) {
						break;
					}
				}
			}
		}
	}
	if (*a_error != NULL) { if (crop_image != NULL) { free_bmp(crop_image); } return NULL;
	}
	return crop_image;
}




