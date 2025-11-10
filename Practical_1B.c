#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1, mid;

    while(start <= end)
    {
        mid = (start + end) / 2;
        printf("Checking middle value: %d at index %d\n", arr[mid], mid);

        if(arr[mid] == key)
        {
            return mid;  // found
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1; // not found
}

int main()
{
    int arr[50], n, i, key, result;

    printf("Enter how many elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if(result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}
