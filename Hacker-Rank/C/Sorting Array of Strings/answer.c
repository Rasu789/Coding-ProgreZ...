#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_distinct_characters(const char* s) {
    int count[128] = {0}; // Assuming ASCII characters
    int distinct_count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[(int)s[i]] == 0) {
            distinct_count++;
            count[(int)s[i]] = 1;
        }
    }
    return distinct_count;
}

/* 
 * Compares two strings lexicographically.
 * Returns a negative value if a < b, 0 if a == b, and a positive value if a > b.
 */
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

/* 
 * Compares two strings in reverse lexicographical order.
 * Returns a negative value if a > b, 0 if a == b, and a positive value if a < b.
 */
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

/* 
 * Compares two strings based on the number of distinct characters.
 * If the counts are different, the one with fewer distinct characters comes first.
 * If the counts are the same, they are sorted lexicographically.
 */
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = count_distinct_characters(a);
    int count_b = count_distinct_characters(b);
    if (count_a != count_b) {
        return count_a - count_b;
    }
    return lexicographic_sort(a, b);
}

/* 
 * Compares two strings based on length.
 * If lengths are different, the shorter one comes first.
 * If lengths are the same, they are sorted lexicographically.
 */
int sort_by_length(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    if (len_a != len_b) {
        // Cast to int for comparison as per function signature
        return (int)len_a - (int)len_b;
    }
    return lexicographic_sort(a, b);
}

/* 
 * Sorts an array of strings using a provided comparison function.
 * This function uses the standard library's `qsort` for efficient sorting.
 * Note: `qsort` comparison function for an array of pointers requires special handling 
 * to cast the void pointers back to char pointers before passing them to the user's `cmp_func`.
 */
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // A wrapper function is needed to adapt the user's cmp_func for `qsort`'s signature
    int qsort_cmp_wrapper(const void* pa, const void* pb) {
        // `pa` and `pb` are pointers to elements of the array, which are char* (pointers to pointers to char)
        const char* a = *(const char**)pa;
        const char* b = *(const char**)pb;
        return cmp_func(a, b);
    }

    qsort(arr, len, sizeof(char*), qsort_cmp_wrapper);
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
