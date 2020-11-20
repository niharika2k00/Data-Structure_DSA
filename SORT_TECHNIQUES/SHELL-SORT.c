#include <stdio.h>
#include <conio.h>

void shellsort(int arr[], int num)
{
    int gap, j, k, tmp;
    for (gap = num / 2; gap > 0; gap = gap / 2)
    {
        for (j = gap; j < num; j++)
        {
            for (k = j - gap; k >= 0; k = k - gap)
            {
                if (arr[k + gap] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k + gap];
                    arr[k + gap] = tmp;
                }
            }
        }
    }
}
int main()
{
    int arr[30], k, num;

    printf("Enter total no. of elements : ");
    scanf("%d", &num);
    printf("\nEnter %d numbers:\n ", num);

    for (k = 0; k < num; k++)
        scanf("%d", &arr[k]);

    shellsort(arr, num);

    printf("******** After SHELL-SORT ********\n");
    printf("SORTED ARRAY ------>\n");
    for (k = 0; k < num; k++)
        printf("%d\t", arr[k]);
}
