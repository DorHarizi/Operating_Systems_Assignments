#include <ctype.h>

// Function to encode a string using codecA
void encode_codecA(char* str){
    int i = 0;
    while (str[i])
    {
        // If the character is lowercase, convert it to uppercase
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        }else{
            // If the character is uppercase, convert it to lowercase
            if(isupper(str[i])){
                str[i] = tolower(str[i]);
            }
        }
        i++;  // Move on to the next character in the string
    }
}

// Function to decode a string using codecA
// Since encoding and decoding are the same for codecA, we just call the encode function
void decode_codecA(char* str){
    encode_codecA(str);  // Call the encode function to decode, as the process is the same
}
