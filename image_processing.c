#include <stdio.h>

void image_header_IO();
void reduce_rows();
void reduce_columns();
/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
	// input/output for image header
	image_header_IO();

	int pixel_value;
	int count = 0;
	
	/* image body input/output */

	// loop until end of file
	while (scanf("%d", &pixel_value) != EOF){
		// every third input is the first value of a pixel, which is the red value
		if (count % 3 == 0){
			// remove red value
			pixel_value = 0;
		}

		printf("%d\n", pixel_value);
		count++; 
	}
	
}

/*
 * Read an image from the standard input and convert it from colour to black and white.
 */
void convert_to_black_and_white()
{
	// input/output for image header
	image_header_IO();

	int pixel_value;
	int total = 0;
	int average;
	int count = 0;
	// amount of colour numbers for a pixel 
	int pixel_num = 3;

	/* image body input/output */

	// loop until end of file
	while (scanf("%d", &pixel_value) != EOF){
		// considering each value in a pixel (amount of values is 3)
		if (count < pixel_num){
			// obtain the total value by adding all three colour values
			total += pixel_value;
			count++;
		}
		// all values of a pixel (3 values) have been inputted
		if (count == pixel_num){
			// total values divided by all 3 values of a pixel is the average
			average = total / pixel_num;
			/* output average value for red, green, 
			   and blue values to convert to black and white */
			int i;
			for (i = 0; i < pixel_num; i++){
				printf("%d\n", average);
			}
			// reset count and total for next pixel
			count = 0;
			total = 0;
		}
	}

}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
	char PPM_type[2];
	int rows;
	int columns;
	int max_value;

	/* image header input/ouput */

	// read PPM type and output
	scanf("%s", PPM_type);
	printf("%s\n", PPM_type);
	// read number of columns and rows
	scanf("%d", &columns);
	scanf("%d", &rows);
	// reduce either columns or rows to make square
	if (columns <= rows){
		// rows will reduce to the number of columns
		printf("%d\n", columns);
		printf("%d\n", columns);
		// read maximum value and output 
		scanf("%d", &max_value);
		printf("%d\n", max_value);
		// function call to reduce rows
		reduce_rows(columns);
	}
	else {
		// columns will reduce to the number of rows
		printf("%d\n", rows);
		printf("%d\n", rows);
		// read maximum value and output 
		scanf("%d", &max_value);
		printf("%d\n", max_value);
		// function call to reduce columns
		reduce_columns(rows, columns);
	}
	
}

/*
 * Read input for image header and ouput it
 */
void image_header_IO(){

	char PPM_type[2];
	int rows;
	int columns;
	int max_value;

	/* image header input/ouput */

	// read PPM type and output
	scanf("%s", PPM_type);
	printf("%s\n", PPM_type);
	// read number of columns and output 
	scanf("%d", &columns);
	printf("%d\n", columns);
	// read number of rows and output 
	scanf("%d", &rows);
	printf("%d\n", rows);
	// read maximum value and output 
	scanf("%d", &max_value);
	printf("%d\n", max_value);
}

/*
 * Reduce bottom rows of an image
 */
void reduce_rows(int columns){

	int pixel_value;
	// amount of colour numbers for a pixel 
	int pixel_num = 3;
	// area to include (excludes extra rows at bottom)
	int inclusion = columns * columns * pixel_num;
	int count = 0;

	/* image body input/output */

	// loop until end of file or until inclusion area
	while ((scanf("%d", &pixel_value) != EOF) && count < inclusion){
		
		printf("%d\n", pixel_value);
		count++; 
	}

}

/*
 * Reduce right columns of an image
 */

void reduce_columns(int rows, int columns){

	int pixel_value;
	int count = 0;
	// amount of colour numbers for a pixel 
	int pixel_num = 3;
	// area to include 
	int inclusion = rows * pixel_num;
	// excludes extra columns on right side
	int exclusion_area = (columns - rows) * pixel_num;
	// particular pixel of exlusion area
	int exclusion_pixel = 0;

	/* image body input/output */

	// loop until end of file or until inclusion area
	while (scanf("%d", &pixel_value) != EOF){
		// if exclusion area has been reached
		if ((exclusion_pixel < exclusion_area) && 
			(count % inclusion == 0) && count != 0){
			exclusion_pixel++;
		}
		// reached end of exclusion area, so next value is valid
		else if (exclusion_pixel == exclusion_area){
			exclusion_pixel = 0;
			printf("%d\n", pixel_value);
			count++;
		}
		// ouput values in inclusion area
		else{
			printf("%d\n", pixel_value);
			count++;
		} 

	}

}
