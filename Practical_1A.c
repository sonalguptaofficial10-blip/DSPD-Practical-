#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];
    int sumOdd = 0, sumEven = 0;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            sumEven = sumEven + arr[i];
        else
            sumOdd = sumOdd + arr[i];
    }

    printf("\nSum of numbers at even positions = %d", sumEven);
    printf("\nSum of numbers at odd positions = %d", sumOdd);

    return 0;
}
