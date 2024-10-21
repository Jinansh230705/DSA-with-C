#include<stdio.h>

void binarySearch() {
    int i, n, x, fe, le, me;
    int arr[] = {5, 9, 14, 23, 31, 42, 50};  
    n = sizeof(arr) / sizeof(arr[0]);     

    printf("\nGiven Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &x);

    fe = 0; le = n - 1; me = (fe + le) / 2;
    while (fe <= le) {
        if (arr[me] < x) {
            fe = me + 1;
        } else if (arr[me] == x) {
            printf("\nElement %d is found at index %d\n", arr[me], me);
            return;
        } else {
            le = me - 1;
        }
        me = (fe + le) / 2;
    }

    if (fe > le) {
        printf("\nElement %d is not present in the array.\n", x);
    }
}

void interpolationSearch() {
    int i, len, x, l, h, pos;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80}; 
    len = sizeof(arr) / sizeof(arr[0]);

    printf("\n\nGiven Array: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &x);

    l = 0; h = len - 1;

    while (l <= h && x >= arr[l] && x <= arr[h]) {
        if (l == h) {
            if (arr[l] == x) {
                printf("\nElement %d found at index position %d\n", arr[l], l);
            } else {
                printf("\nElement %d is not present in the array.\n", x);
            }
            return;
        }
        
        pos = l + (((double)(x - arr[l]) / (arr[h] - arr[l])) * (h - l));
        if (arr[pos] == x) {
            printf("\nElement %d found at index position %d\n", arr[pos], pos);
            return;
        }

        if (arr[pos] < x) {
            l = pos + 1;
        }
        else {
            h = pos - 1;
        }
    }
    printf("\nElement %d is not present in the array.\n", x);
}

int main() {
    binarySearch();
    interpolationSearch();
    return 0;
}
