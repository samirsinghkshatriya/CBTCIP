#include <stdio.h>

// Function to calculate and display word, line, and character count
void analyzeText(FILE *file) {
    int wordCount = 0, lineCount = 0, charCount = 0;
    char ch;

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Increment character count for each character
        charCount++;

        // Check for newline character to count lines
        if (ch == '\n') {
            lineCount++;
        }

        // Check for space or newline to count words
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordCount++;
        }
    }

    // Increment word count for the last word (no space after the last word)
    if (charCount > 0) {
        wordCount++;
    }

    // Display the results
    printf("Total Words: %d\n", wordCount);
    printf("Total Lines: %d\n", lineCount);
    printf("Total Characters: %d\n", charCount);
}

int main() {
    // Open the file for reading
    FILE *file;
    char filename[100];

    printf("Enter the filename (including extension): ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    // Check if the file is successfully opened
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit the program with an error code
    }

    // Analyze the text and display the results
    analyzeText(file);

    // Close the file
    fclose(file);

    return 0; // Exit the program successfully
}
