#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

// Function to compare two files
int compareFiles(char *file1, char *file2, int verbose, int ignoreCase){
	FILE *f1, *f2;
	char ch1, ch2;
	int result = 0;

	// Opening the files for reading
	f1 = fopen(file1, "r");
	f2 = fopen(file2, "r");

	// Check if files are opened successfully
	if (f1 == NULL || f2 == NULL)
	{
		fprintf(stderr, "Error opening one of the files: %s\n", strerror(errno));
		goto cleanup;
	}

	while (1)
	{
		// Reading one character from each file at a time
		ch1 = fgetc(f1);
		ch2 = fgetc(f2);

		// Check if the files have ended
		if (ch1 == EOF || ch2 == EOF)
		{
			break;
		}

		// Converting characters to lowercase if ignoreCase is enabled
		if (ignoreCase)
		{
			ch1 = tolower(ch1);
			ch2 = tolower(ch2);
		}

		// Comparing characters from both files
		if (ch1 != ch2)
		{
			result = 1;
			return result;
		}
	}
	
cleanup:
	// Closing the files if they are opened
	if (f1 != NULL)
	{
		fclose(f1);
	}
	if (f2 != NULL)
	{
		fclose(f2);
	}
	return result;
}

int main(int argc, char *argv[]) {
    int verbose = 0, ignoreCase = 0;

    // Checking if enough arguments are passed
    if (argc < 3) {
        printf("Usage: cmp <file1> <file2> [-v] [-i]\n");
        return 1;
    }

	// Parsing optional arguments for verbosity and ignore case
	for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "[-v]") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "[-i]") == 0) {
            ignoreCase = 1;
        }
    }

    // Calling the compareFiles function to compare the files
    int result = compareFiles(argv[1], argv[2], verbose, ignoreCase);

    // Displaying the result based on the verbosity
    if (result == 0) {
        if (verbose) {
            printf("equal\n");
        }
        return 0;
    }
    else {
        if (verbose) {
            printf("distinct\n");
        }
        return 1;
    }
}
