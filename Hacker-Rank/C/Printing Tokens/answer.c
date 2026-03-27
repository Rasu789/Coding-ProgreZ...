#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    // Read the entire line including spaces
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        // Remove the trailing newline character if present
        sentence[strcspn(sentence, "\n")] = '\0';

        // Use strtok to split the string by space or tab
        char* token = strtok(sentence, " \t");

        // Loop through all tokens
        while (token != NULL) {
            printf("%s\n", token);
            // Get the next token
            token = strtok(NULL, " \t");
        }
    }

    return 0;
}
