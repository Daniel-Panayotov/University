#include <stdio.h>
#include <conio.h>

int main()
{

    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    for (int iteration = 0; iteration < size; iteration++)
    {
        printf("Enter number on position %d: ", iteration + 1);
        scanf("%d", &arr[iteration]);
    }

    int compareNum = arr[0];

    for (int iteration = 1; iteration < size; iteration++)
    {
        if (compareNum < arr[iteration])
        {
            compareNum = arr[iteration];
        }
    }

    printf("Biggest number is: %d", compareNum);

    getch();
    return 0;
}
