#include <stdio.h>

int main()
{
    int i, n, k, j, arr[20], temp, min;

    printf("Enter the number of elements in the Array : ");
    scanf("%d", &n);

    printf("\nEnter elments:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for ( i = 0; i < n - 1; i++)
    {
        min = i;
        for ( j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                min = j;
            }
            
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        
        
    }
    

    printf("\nSorted Array is : \n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }


    return 0;
}