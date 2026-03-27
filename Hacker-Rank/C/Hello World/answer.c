#include <stdio.h>

int main() {

    
    char sentence[100];            
    scanf("%[^\n]%*c", sentence);
    printf("Hello, World!\n");
    printf("%s\n", sentence);

    return 0;
}
