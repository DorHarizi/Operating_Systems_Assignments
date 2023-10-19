#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to copy content from one file to another
int copy(int verbose, int force, char *src_file_path, char *dest_file_path){
	FILE *src_file = NULL;
	FILE *dest_file = NULL;
	int result = 0;

	// Open source file in read-binary mode
	src_file = fopen(src_file_path,"rb");
	if(src_file == NULL){
		fprintf(stderr,"Error opening source file:%s\n", strerror(errno));
		result = 1;
		goto cleanup;
	}

	// Check whether to overwrite the destination file or not
	if(force == 1) 
	{
    	dest_file = fopen(dest_file_path, "wb");
	} 
	else 
	{
    	// If the file exists, and the force flag is not set, don't overwrite
    	dest_file = fopen(dest_file_path, "ab+");
		if (dest_file) {
			fclose(dest_file);
			dest_file = fopen(dest_file_path, "wb");
		}
	}

	// Error handling for destination file
	if(dest_file == NULL){
		if(errno == EEXIST && !(force)){
			fprintf(stderr,"Target file already exists\n");
			result = 1;
			goto cleanup;
		}else{
			fprintf(stderr,"Error opening dest file:%s\n", strerror(errno));
			result = 1;
			goto cleanup;
		}
	}

	// Copy content from source to destination file
	int c;
	while(((c = fgetc(src_file)) != EOF)){
		fputc(c, dest_file);
	}
	
	// Output a success message if verbose flag is set
	if (verbose){
		printf("Success\n");
	}

	// Cleanup and close files
	cleanup:
	if (src_file != NULL)
	{
		fclose(src_file);
	}
	if (dest_file != NULL)
	{
		fclose(dest_file);
	}
	
	// Output general failure message in case of error
	if (result == 1)
	{
		printf("General failure\n");
	}
	return result;
}

// Main function to execute the copy function with arguments and flags
int main(int argc, char *argv[]) {
    int force = 0, verbose = 0, ret = 0;
    
    // Check for the correct number of arguments and display usage if incorrect
    if (argc < 3) {
        fprintf(stderr, "Usage: copy <file1> <file2> [-v] [-f]\n");
        exit(1);
    }

    // Parse optional flags for verbosity and forcing file overwrite
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "[-v]") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "[-f]") == 0) {
            force = 1;
        }
    }
    ret = copy(verbose, force, argv[1], argv[2]);
    return ret;
}
