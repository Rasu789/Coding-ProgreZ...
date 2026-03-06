#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n, m;
    float f1, f2;
    
    scanf("%d %d", &n, &m);
    scanf("%f %f", &f1, &f2);
    
    printf("%d %d\n", n + m, n - m);
    
    printf("%.1f %.1f\n", f1 + f2, f1 - f2);
    
    
    return 0;
}
