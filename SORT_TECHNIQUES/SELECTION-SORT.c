#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, min, temp, a[100000], t;
    // using clock_t to store time
    clock_t start, end;
    double time_taken;

    printf("Enter the no. of elements in the array : ");
    scanf("%d", &n);

    printf("Enter %d the values of the array : \n", n);
    for (i = 0; i < n; i++)
    {
        // scanf("%d", &a[i]);
        a[i] = (rand() % 50) + 10;
        printf("%d\n",a[i]);
        //  scanf("%d", rand());
    }

    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    end = clock();
    t = (end - start);
    time_taken = (double)t / CLOCKS_PER_SEC;

    printf("******** Äfter SELECTION_SORT ********\n");
    printf("SORTED ARRAY ------>\n");
/*     for (i = 0; i < n; i++)
        printf("%d\t", a[i]); */
    printf("\n TIME-TAKEN for %d no. in an array : %lf", n, time_taken);
}