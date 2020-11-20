#include <stdio.h>
#include <conio.h>

int main()
{
    int n, i, found = 0, a[20], p;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);
    printf("Enter elements :  ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    printf("Enter the element to be searched :  ");
    scanf("%d", &p);

    for (i = 0; i < n; i++)
    {
        if (p == a[i])
        {
            found = 1;
            printf("**-- Element %d is found in the position %d having INDEX %d --**", p,i+1,i);
            break;
        }
    }

    if (found == 0)
        printf("-- Element %d is NOT found --", p);
}