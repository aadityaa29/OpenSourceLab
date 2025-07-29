#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH 1000
#define MAX_WORDS 100

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove punctuation
void removePunctuation(char *str) {
    int i, j = 0;
    char clean[MAX_PARAGRAPH];
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i]) || isspace(str[i])) {
            clean[j++] = str[i];
        }
    }
    clean[j] = '\0';
    strcpy(str, clean);
}

int main() {
    char paragraph[MAX_PARAGRAPH];
    char words[MAX_WORDS][50];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_PARAGRAPH, stdin);

    // Preprocess: make lowercase and remove punctuation
    toLowerCase(paragraph);
    removePunctuation(paragraph);

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \n");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], token);
            count[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n");
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}
