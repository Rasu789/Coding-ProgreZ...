#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double calculate_area(triangle tr) {
    // Semi-perimeter must be a double to avoid integer division issues
    double p = (double)(tr.a + tr.b + tr.c) / 2.0;
    // Heron's formula: Area = sqrt(p * (p - a) * (p - b) * (p - c))
    double area = sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
    return area;
}

// Comparison function for qsort
int compare_triangles(const void *a, const void *b) {
    triangle *tr1 = (triangle *)a;
    triangle *tr2 = (triangle *)b;
    double area1 = calculate_area(*tr1);
    double area2 = calculate_area(*tr2);

    // qsort comparator needs to return an int:
    // < 0 if first arg < second arg
    // 0 if first arg == second arg
    // > 0 if first arg > second arg
    if (area1 < area2) return -1;
    if (area1 > area2) return 1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare_triangles);
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
