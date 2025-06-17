#include <stdio.h>

int main()
{
    int i, n, k, j, arr[20], temp;

    printf("Enter the number of elements in the Array : ");
    scanf("%d", &n);

    printf("\nEnter elments:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for ( k = 1; k < n; k++)
    {
        temp = arr[k];
        j = k - 1;

        while(temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
    

    printf("\nSorted Array is : \n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }


    return 0;
}