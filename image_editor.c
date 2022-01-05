#include <stdio.h>
#include <stdlib.h>

/*
 * Include the function prototypes of all those functions implemented in image_processing.c.
 * Do not remove or modify them in any way.
 */

void remove_red();
void convert_to_black_and_white();
void instagram_square();
// void check_errors(int argc, char argv);

int main(int argc, char *argv[]) {
        /* Task 1 needs to be completed here: Make sure that the command line arguments are correct. In case an error exists,
         * print the error message and terminate the program. Otherwise, invoke the corresponding
         * image processing function. */

        // terminate program if there's more than one command-line argument
        if (argc > 2){
            printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.");
            exit(1);
        }
        // users input is not a valid number
        if (atoi(argv[1]) == 0){
            printf("Error: Expecting one command-line argument, "
                "which needs to be either 1, 2, or 3.");
            exit(1);
        }
        // check for decimals or combinations of words and numbers
        char *extra;
        strtol(argv[1], &extra, 10);
        // if there are extra characters, terminate program
        if (*extra != '\0'){
            printf("Error: Expecting one command-line argument, "
                "which needs to be either 1, 2, or 3.");
            exit(1);
        }
        // input numbers aren't 1, 2, or 3
        if (atoi(argv[1]) != 1 && atoi(argv[1]) != 2 && 
            atoi(argv[1]) != 3 ){
            printf("Error: Expecting one command-line argument, "
                "which needs to be either 1, 2, or 3.");
            exit(1);
        }

        // check_errors(argc, argv);

        /* Call corresponding image processing functions, based on a 
         * command-line argument of 1, 2, or 3 */

        if (atoi(argv[1]) == 1){
            remove_red();
        }

        if (atoi(argv[1]) == 2){
            convert_to_black_and_white();
        }

        if (atoi(argv[1]) == 3){
            instagram_square();
        }

        return 0;
}

// void check_errors(int argc, char argv){
//         // terminate program if there's more than one command-line argument
//         if (argc > 2){
//             printf("Error: Expecting one command-line argument, "
//                 "which needs to be either 1, 2, or 3.");
//             exit(1);
//         }
//         // users input is not a valid number
//         if (atoi(argv[1]) == 0){
//             printf("Error: Expecting one command-line argument, "
//                 "which needs to be either 1, 2, or 3.");
//             exit(1);
//         }
//         // check for decimals or combinations of words and numbers
//         char *extra;
//         strtol(argv[1], &extra, 10);
//         // if there are extra characters, terminate program
//         if (*extra != '\0'){
//             printf("Error: Expecting one command-line argument, "
//                 "which needs to be either 1, 2, or 3.");
//             exit(1);
//         }
//         // input numbers aren't 1, 2, or 3
//         if (atoi(argv[1]) != 1 && atoi(argv[1]) != 2 && 
//             atoi(argv[1]) != 3 ){
//             printf("Error: Expecting one command-line argument, "
//                 "which needs to be either 1, 2, or 3.");
//             exit(1);
//         }
//    }
