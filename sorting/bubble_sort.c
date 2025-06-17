#include <stdio.h>

int main()
{
    int i, n, temp, j, arr[20];

    printf("Enter the number of elements in the Array : ");
    scanf("%d", &n);

    printf("\nEnter elments:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array is : \n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}