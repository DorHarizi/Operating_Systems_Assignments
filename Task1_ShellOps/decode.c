#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codecA.h" // Including the header files where the codec functions are declared.
#include "codecB.h" 

int main(int argc, char* argv[]){

    // Ensure that the user has entered the correct number of arguments.
    if(argc < 3){
        printf("Usage: decode <codec> <message>\n");
        return 1;
    }

    // Storing command line arguments in variables for easier reference.
    char* codec = argv[1];
    char* message = argv[2];

    // Determine which decoding function to use based on the user's input.
    if(strcmp(codec, "codecA") == 0){
        decode_codecA(message); // If user specified codecA, decode using codecA.
    } else if(strcmp(codec, "codecB") == 0){
        decode_codecB(message); // If user specified codecB, decode using codecB.
    } else {
        printf("Invalid codec\n"); // If the codec is neither A nor B, output an error.
        return 1;
    }

    // Print the decoded message to the console.
    printf("%s\n", message);

}
