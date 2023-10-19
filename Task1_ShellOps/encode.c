#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codecA.h" // Including the header files where the codec functions are declared.
#include "codecB.h" 

int main(int argc, char* argv[]){

    // Ensure that the correct number of arguments have been passed.
    if(argc < 3){
        printf("Usage: encode <codec> <message>\n"); // If not, print usage information.
        return 1;
    }

    // Assign the command line arguments to variables for easier use.
    char* codec = argv[1];
    char* message = argv[2];

    // Based on the codec specified in the command line, call the corresponding encoding function.
    if(strcmp(codec, "codecA") == 0){
        encode_codecA(message); // If codecA is specified, encode the message using codecA.
    }else if(strcmp(codec, "codecB") == 0){
        encode_codecB(message); // If codecB is specified, encode the message using codecB.
    }else{
        printf("Invalid codec\n"); // If neither codec is specified, print an error message.
        return 1;
    }

    // Print the encoded message to the console.
    printf("%s\n", message);

}
