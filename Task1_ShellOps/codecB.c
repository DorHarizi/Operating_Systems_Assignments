// Function to encode a string using codecB
void encode_codecB(char* str){
    int i = 0;
    while(str[i]){
        str[i] = str[i] + 3;  // Shift each character 3 places forward in the ASCII table
        i++;  // Move on to the next character in the string
    }
}

// Function to decode a string using codecB
void decode_codecB(char* str){
    int i = 0;
    while(str[i]){
        str[i] = str[i] - 3;  // Shift each character 3 places backward in the ASCII table to decode
        i++;  // Move on to the next character in the string
    }
}
