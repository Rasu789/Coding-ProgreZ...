#include <stdio.h>

void update(int *a,int *b) {
int temp_a=*a;
int temp_b=*b;

*a =temp_a+temp_b;
*b =(temp_a - temp_b);
if (*b<0){
    *b=*b*-1;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
