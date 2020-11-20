#include <stdio.h>
#include <conio.h>

int main()
{
    int n, i, j, key, a[100];
    printf("Enter the no. of elements in the array : ");
    scanf("%d", &n);

    printf("Enter %d the values of the array : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > key))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("******** Äfter INSERTION_SORT ********\n");
    printf("SORTED ARRAY ------>\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}