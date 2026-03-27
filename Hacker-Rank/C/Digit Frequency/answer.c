#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    int count[10] = {0}; // Initialize counts for digits 0-9 to zero
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count[s[i] - '0']++; // Increment the index corresponding to the digit
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]); // Print frequencies separated by spaces
    }
    return 0;
}
