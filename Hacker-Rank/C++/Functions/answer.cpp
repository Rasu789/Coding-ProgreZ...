#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int arr[], int n)
{
    for (int i = 1; i < n; i++ ){
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > k){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
    return n - 1;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int arr[] = {a ,b, c, d};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int ans = max_of_four(arr, n);
    cout << arr[ans];
    
    return 0;
}
