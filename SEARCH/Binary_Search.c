
// BINARY SEARCH  is possible only for the sorted array.
#include <stdio.h>
#include <conio.h>

int main()
{
    int c, first, last, mid, n, search, arr[100];

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    for (c = 0; c < n; c++)
        scanf("%d", &arr[c]);

    printf("Enter value to find --> ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;  // as n is  the total no. so its INDEX no. will be n-1
    mid = (first + last) / 2;

    while (first <= last)
    {
        if (search > arr[mid]  )
            first = mid + 1;

        else if (arr[mid] == search)
        {
            printf("%d found at location %d.\n", search, mid + 1);
            break;
        }
        else
            last = mid - 1;

        mid = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);
}