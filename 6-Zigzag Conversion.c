#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) <= 1) { return s; }

    //determining the number of columns
    int lengthS = strlen(s);
    int cycleLength  =  2 * numRows - 2;
    int nbrOfFullCycles = lengthS / cycleLength;
    int nbrOfRemChars = lengthS % cycleLength;
    
    int remCols;
    if (nbrOfRemChars == 0) {
        remCols = 0;
    } else if (nbrOfRemChars <= numRows) {
        remCols = 1;
    } else {
        remCols = nbrOfRemChars - numRows;
    }
    int numCols = (numRows - 1) * nbrOfFullCycles + remCols;

    char* encString = malloc((lengthS + 1) * sizeof(char));
    if (!encString) { return NULL; }
    encString[lengthS] = '\0';

    char **matrix = (char **)malloc(numRows * sizeof(char *));
    if (!matrix) { return NULL; }

    //filling for illustration purposes
    for (int i = 0; i < numRows; i++) {
        *(matrix + i) = (char *)malloc(numCols * sizeof(char));
        if (!(*(matrix + i))) { return NULL; }
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = ' ';
        }
    }

    int i = 0, j = 0, idx = 0; // i is columns, j is rows and idx is the index in the original string
    //filling the zigzag pattern (columns first)
    for (i = 0;  i < numCols; i += numRows - 1) {
        for (j = 0; j < numRows; j++) {
            matrix[j][i] = s[idx++];
        }
        idx += cycleLength - numRows;
    }

    //filling the zigzag pattern (diagonal going up)
    idx = numRows;
    for (i = 1; i < numCols; i++) {
        for (j = numRows - 2; j > 0; j--) {
            matrix[j][i++] = s[idx++];
        }

        idx += numRows;
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