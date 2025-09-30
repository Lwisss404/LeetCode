#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) <= 1) { return strdup(s); }

    //determining the number of columns
    int lengthS = strlen(s);
    int cycleLength  =  2 * numRows - 2;
    int nbrOfFullCycles = lengthS / cycleLength;
    int nbrOfRemChars = lengthS % cycleLength;
    
    int remCols = 0;
    if (nbrOfRemChars > 0) {
        remCols += (nbrOfRemChars < numRows) ? 1 : 1 + nbrOfRemChars - numRows;
    }

    int numCols = (numRows - 1) * nbrOfFullCycles + remCols;

    char* encString = malloc((lengthS + 1) * sizeof(char));
    if (!encString) { return NULL; }
    encString[lengthS] = '\0';

    //filling for illustration purposes
    char **matrix = (char **)malloc(numRows * sizeof(char *));
    if (!matrix) { return NULL; }
    for (int i = 0; i < numRows; i++) {
        *(matrix + i) = (char *)malloc(numCols * sizeof(char));
        if (!(*(matrix + i))) { return NULL; }
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = ' ';
        }
    }

    // i is rows, j is col and idx is the index in the original string
    int i = 0, j = 0, idx = 0;
    while (idx < lengthS) {
        //filling the zigzag pattern (columns first)
        for (int i = 0; i < numRows && idx < lengthS; i++) {
            matrix[i][j] = s[idx++];
        }

        //filling the zigzag pattern (diagonal going up)
        for (int i = numRows - 2; i > 0 && idx < lengthS; i--) {
            matrix[i][++j] = s[idx++];
        }
        j++;
    }
    
    printf("Number of rows is: %d\n", numRows);
    
    //copying to new string
    idx = 0;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            if (matrix[i][j] != ' ') { 
                encString[idx++] = matrix[i][j];
                printf("%c | ", matrix[i][j]);
            } else {
                printf("  | ");
            }
            
        }
        printf("\b \n");
    }
    printf("%s \n", encString);

    //freeing the matrix
    for (i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return encString;
}

int main() {

    char string[1000];
    printf("Give a string: ");
    scanf("%999s", string);

    int numRows;
    printf("Give number of rows: ");
    scanf("%d", &numRows);

    printf("%s \n", string);
    char* encString = convert(string, numRows);
    free(encString);

    return 0;
}